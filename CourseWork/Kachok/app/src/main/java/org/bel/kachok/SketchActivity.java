package org.bel.kachok;

import android.Manifest;
import android.app.AlarmManager;
import android.app.DatePickerDialog;
import android.app.PendingIntent;
import android.app.TimePickerDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.content.pm.PackageManager;
import android.database.Cursor;
import android.graphics.Bitmap;
import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Matrix;
import android.graphics.drawable.BitmapDrawable;
import android.media.MediaScannerConnection;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.preference.PreferenceManager;
import android.support.annotation.NonNull;
import android.support.v4.app.ActivityCompat;
import android.support.v4.content.ContextCompat;
import android.support.v4.content.FileProvider;
import android.support.v4.view.MenuItemCompat;
import android.support.v4.widget.CursorAdapter;
import android.support.v4.widget.SimpleCursorAdapter;
import android.support.v7.app.AlertDialog;
import android.support.v7.app.AppCompatActivity;
import android.support.v7.widget.ShareActionProvider;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.view.WindowManager;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.DatePicker;
import android.widget.EditText;
import android.widget.PopupMenu;
import android.widget.Spinner;
import android.widget.TimePicker;
import android.widget.Toast;

import com.simplify.ink.InkView;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.Calendar;
import java.util.Date;

import petrov.kristiyan.colorpicker.ColorPicker;

public class SketchActivity extends AppCompatActivity implements View.OnClickListener, DatePickerDialog.OnDateSetListener, TimePickerDialog.OnTimeSetListener, PopupMenu.OnMenuItemClickListener {
    public static final String EXTRA_ID = "org.bel.kachok.ID";

    private static final int REQUEST_CODE_EXTERNAL_STORAGE = 1;

    EditText etName;
    InkView drawView;
    Button btnColorSelector;
    Spinner spinner;

    private ShareActionProvider mShareActionProvider = null;

    private String mFileName = "finde_die_datei.mp4";
    private String mFilePath;

    private int dayOfMonth, monthOfYear, year;

    private boolean edit = false;
    private boolean hasAlarm = false;
    private boolean shouldSave = true;
    private int id = -1;
    private int notification_id = -1;
    private int currentCat;
    Cursor noteCursor = null;
    Cursor notificationCursor = null;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_sketch);
        findViewById(R.id.btn_cancel).setOnClickListener(this);
        findViewById(R.id.btn_delete).setOnClickListener(this);
        findViewById(R.id.btn_save).setOnClickListener(this);

        etName = (EditText) findViewById(R.id.etName);
        drawView = (InkView) findViewById(R.id.draw_view);
        btnColorSelector = (Button) findViewById(R.id.btn_color_selector);
        spinner = (Spinner) findViewById(R.id.spinner_category);

        btnColorSelector.setOnClickListener(this);
        drawView.setColor(Color.BLACK);
        drawView.setMinStrokeWidth(1.5f);
        drawView.setMaxStrokeWidth(6f);

        loadActivity(true);
    }

    private void loadActivity(boolean initial){
        //Look for a note ID in the intent. If we got one, then we will edit that note. Otherwise we create a new one.
        if (id == -1) {
            Intent intent = getIntent();
            id = intent.getIntExtra(EXTRA_ID, -1);
        }
        edit = (id != -1);

        SimpleCursorAdapter adapter = null;
        // Should we set a custom font size?
        SharedPreferences sp = PreferenceManager.getDefaultSharedPreferences(this);
        if (sp.getBoolean(SettingsActivity2.PREF_CUSTOM_FONT, false)) {
            etName.setTextSize(Float.parseFloat(sp.getString(SettingsActivity2.PREF_CUTSOM_FONT_SIZE, "15")));
        }

        //CategorySpinner
        Cursor c = DbAccess.getCategories(getBaseContext());
        if (c.getCount() == 0) {
            displayCategoryDialog();
        } else {
            String[] from = {DbContract.CategoryEntry.COLUMN_NAME};
            int[] to = {R.id.text1};
            adapter = new SimpleCursorAdapter(getApplicationContext(), R.layout.simple_spinner_item, c, from, to, CursorAdapter.FLAG_AUTO_REQUERY);
            adapter.setDropDownViewResource(R.layout.simple_spinner_dropdown_item);
            spinner.setAdapter(adapter);
            spinner.setOnItemSelectedListener(new AdapterView.OnItemSelectedListener() {
                @Override
                public void onItemSelected(AdapterView<?> parent, View view, int position, long id) {
                    Cursor c = (Cursor) parent.getItemAtPosition(position);
                    currentCat = c.getInt(c.getColumnIndexOrThrow(DbContract.CategoryEntry.COLUMN_ID));
                }

                @Override
                public void onNothingSelected(AdapterView<?> parent) {

                }
            });
        }
        //fill in values if update
        if (edit) {
            getWindow().setSoftInputMode(WindowManager.LayoutParams.SOFT_INPUT_STATE_HIDDEN);
            noteCursor = DbAccess.getNote(getBaseContext(), id);
            noteCursor.moveToFirst();
            etName.setText(noteCursor.getString(noteCursor.getColumnIndexOrThrow(DbContract.NoteEntry.COLUMN_NAME)));
            mFileName = noteCursor.getString(noteCursor.getColumnIndexOrThrow(DbContract.NoteEntry.COLUMN_CONTENT));
            mFilePath = getFilesDir().getPath() + "/sketches" + mFileName;

            //find the current category and set spinner to that
            currentCat = noteCursor.getInt(noteCursor.getColumnIndexOrThrow(DbContract.NoteEntry.COLUMN_CATEGORY));

            for (int i = 0; i < adapter.getCount(); i++){
                c.moveToPosition(i);
                if (c.getInt(c.getColumnIndexOrThrow(DbContract.CategoryEntry.COLUMN_ID)) == currentCat) {
                    spinner.setSelection(i);
                    break;
                }
            }
            //fill the notificationCursor
            notificationCursor = DbAccess.getNotificationByNoteId(getBaseContext(), id);
            hasAlarm = notificationCursor.moveToFirst();
            if (hasAlarm) {
                notification_id = notificationCursor.getInt(notificationCursor.getColumnIndexOrThrow(DbContract.NotificationEntry.COLUMN_ID));
            }
            findViewById(R.id.btn_delete).setEnabled(true);
            ((Button) findViewById(R.id.btn_save)).setText(getString(R.string.action_update));
            drawView.setBackground(new BitmapDrawable(getResources(), mFilePath));
        } else {
            findViewById(R.id.btn_delete).setEnabled(false);
            mFileName = "/sketch_" + System.currentTimeMillis() + ".PNG";
            mFilePath = getFilesDir().getPath() + "/sketches";
            new File(mFilePath).mkdirs(); //ensure that the file exists
            mFilePath = getFilesDir().getPath() + "/sketches" + mFileName;

            // = false; // will be set to true, once we have a drawing
        }
        if(!initial) {
            invalidateOptionsMenu();
        }
    }

    @Override
    protected void onPause() {
        super.onPause();
        //The Activity is not visible anymore. Save the work!
        if (shouldSave ) {
            if (edit) {
                updateNote();
            } else {
                saveNote();
            }
        } else {
            if(!edit) {
                //TODO do nothing here
                //new File(mFilePath).delete();
            }
        }
    }

    @Override
    protected void onResume(){
        super.onResume();
        loadActivity(false);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        if (edit){
            getMenuInflater().inflate(R.menu.audio, menu);
            MenuItem item = menu.findItem(R.id.action_share);
            mShareActionProvider = (ShareActionProvider) MenuItemCompat.getActionProvider(item);
            setShareIntent();
        }
        return true;
    }

    @Override
    public boolean onPrepareOptionsMenu(Menu menu) {
        MenuItem item = menu.findItem(R.id.action_reminder);
        if (hasAlarm) {
            item.setIcon(R.drawable.ic_alarm_on_white_24dp);
        }
        return super.onPrepareOptionsMenu(menu);
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();

        setShareIntent();

        //noinspection SimplifiableIfStatement
        if (id == R.id.action_reminder) {
            //open the schedule dialog
            final Calendar c = Calendar.getInstance();
            if (hasAlarm) {
                //ask whether to delete or update the current alarm
                PopupMenu popupMenu = new PopupMenu(this, findViewById(R.id.action_reminder));
                popupMenu.inflate(R.menu.reminder);
                popupMenu.setOnMenuItemClickListener(this);
                popupMenu.show();
            } else {
                //create a new one
                int year = c.get(Calendar.YEAR);
                int month = c.get(Calendar.MONTH);
                int day = c.get(Calendar.DAY_OF_MONTH);

                DatePickerDialog dpd = new DatePickerDialog(SketchActivity.this, this, year, month, day);
                dpd.getDatePicker().setMinDate(c.getTimeInMillis());
                dpd.show();
            }
            return true;
        } else if (id == R.id.action_save) {
            if (ContextCompat.checkSelfPermission(SketchActivity.this,
                    Manifest.permission.WRITE_EXTERNAL_STORAGE)
                    != PackageManager.PERMISSION_GRANTED) {
                // Should we show an explanation?
                if (ActivityCompat.shouldShowRequestPermissionRationale(SketchActivity.this,
                        Manifest.permission.WRITE_EXTERNAL_STORAGE)) {
                    // Show an expanation to the user *asynchronously* -- don't block
                    // this thread waiting for the user's response! After the user
                    // sees the explanation, try again to request the permission.
                    ActivityCompat.requestPermissions(SketchActivity.this,
                            new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE},
                            REQUEST_CODE_EXTERNAL_STORAGE);
                } else {
                    // No explanation needed, we can request the permission.
                    ActivityCompat.requestPermissions(SketchActivity.this,
                            new String[]{Manifest.permission.WRITE_EXTERNAL_STORAGE},
                            REQUEST_CODE_EXTERNAL_STORAGE);
                }
            } else {
                saveToExternalStorage();
            }
            return true;
        }

        return super.onOptionsItemSelected(item);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btn_cancel:
                Toast.makeText(getBaseContext(), R.string.toast_canceled, Toast.LENGTH_SHORT).show();
                shouldSave = false;
                finish();
                break;
            case R.id.btn_delete:
                if (edit) { //note only exists in edit mode
                    displayTrashDialog();
                }
                break;
            case R.id.btn_save:
                shouldSave = true; //safe on exit
                finish();
                break;
            case R.id.btn_color_selector:
                displayColorDialog();
                break;
            default:
        }
    }

    private void updateNote(){
        fillNameIfEmpty();
        Bitmap oldSketch = new BitmapDrawable(getResources(), mFilePath).getBitmap();
        Bitmap newSketch = drawView.getBitmap();
        try {
            FileOutputStream fo = new FileOutputStream(new File(mFilePath));
            overlay(oldSketch, newSketch).compress(Bitmap.CompressFormat.PNG, 0, fo);
            fo.flush();
            fo.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        DbAccess.updateNote(getBaseContext(), id, etName.getText().toString(), mFileName, currentCat);
        Toast.makeText(getApplicationContext(), R.string.toast_updated, Toast.LENGTH_SHORT).show();
    }

    private void saveNote(){
        fillNameIfEmpty();
        Bitmap bitmap = drawView.getBitmap();
        try {
            FileOutputStream fo = new FileOutputStream(new File(mFilePath));
            bitmap.compress(Bitmap.CompressFormat.PNG, 0, fo);
            fo.flush();
            fo.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }

        id = DbAccess.addNote(getBaseContext(), etName.getText().toString(), mFileName, DbContract.NoteEntry.TYPE_SKETCH, currentCat);
        Toast.makeText(getApplicationContext(), R.string.toast_saved, Toast.LENGTH_SHORT).show();
    }

    private void fillNameIfEmpty(){
        if (etName.getText().toString().isEmpty()) {
            SharedPreferences sp = getSharedPreferences(Preferences.SP_VALUES, Context.MODE_PRIVATE);
            int counter = sp.getInt(Preferences.SP_VALUES_NAMECOUNTER, 1);
            etName.setText(String.format(getString(R.string.note_standardname), counter));
            SharedPreferences.Editor editor = sp.edit();
            editor.putInt(Preferences.SP_VALUES_NAMECOUNTER, counter+1);
            editor.commit();
        }
    }

    private void displayCategoryDialog() {
        new AlertDialog.Builder(SketchActivity.this)
                .setTitle(getString(R.string.dialog_need_category_title))
                .setMessage(getString(R.string.dialog_need_category_message))
                .setNegativeButton(android.R.string.no, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        finish();
                    }
                })
                .setPositiveButton(R.string.dialog_ok, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        startActivity(new Intent(SketchActivity.this, ManageCategoriesActivity.class));
                    }
                })
                .setIcon(android.R.drawable.ic_dialog_alert)
                .show();
    }

    private void displayTrashDialog() {
        SharedPreferences sp = getSharedPreferences(Preferences.SP_DATA, Context.MODE_PRIVATE);
        if (sp.getBoolean(Preferences.SP_DATA_DISPLAY_TRASH_MESSAGE, true)){
            //we never displayed the message before, so show it now
            new AlertDialog.Builder(SketchActivity.this)
                    .setTitle(getString(R.string.dialog_trash_title))
                    .setMessage(getString(R.string.dialog_trash_message))
                    .setPositiveButton(R.string.dialog_ok, new DialogInterface.OnClickListener() {
                        @Override
                        public void onClick(DialogInterface dialog, int which) {
                            shouldSave = false;
                            DbAccess.trashNote(getBaseContext(), id);
                            finish();
                        }
                    })
                    .setIcon(android.R.drawable.ic_dialog_alert)
                    .show();
            SharedPreferences.Editor editor = sp.edit();
            editor.putBoolean(Preferences.SP_DATA_DISPLAY_TRASH_MESSAGE, false);
            editor.commit();
        } else {
            shouldSave = false;
            DbAccess.trashNote(getBaseContext(), id);
            finish();
        }
    }

    private void displayColorDialog() {
        new ColorPicker(this)
                .setOnFastChooseColorListener(new ColorPicker.OnFastChooseColorListener() {
                    @Override
                    public void setOnFastChooseColorListener(int position, int color) {
                        drawView.setColor(color);
                        btnColorSelector.setBackgroundColor(color);
                    }
                })
                .setColors(R.array.mdcolor_500)
                .setTitle("")
                .show();
    }

    @Override
    public void onRequestPermissionsResult(int requestCode, @NonNull String[] permissions, @NonNull int[] grantResults) {
        switch (requestCode) {
            case REQUEST_CODE_EXTERNAL_STORAGE:
                if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
                    //Save the file
                    saveToExternalStorage();
                } else {
                    Toast.makeText(getApplicationContext(), R.string.toast_need_permission_write_external, Toast.LENGTH_LONG).show();
                }
                break;
        }
    }

    @Override
    public void onDateSet(DatePicker view, int year, int monthOfYear, int dayOfMonth) {
        this.dayOfMonth = dayOfMonth;
        this.monthOfYear = monthOfYear;
        this.year = year;
        final Calendar c = Calendar.getInstance();
        if (hasAlarm) {
            c.setTimeInMillis(notificationCursor.getLong(notificationCursor.getColumnIndexOrThrow(DbContract.NotificationEntry.COLUMN_TIME)));
        }
        TimePickerDialog tpd = new TimePickerDialog(SketchActivity.this, this, c.get(Calendar.HOUR_OF_DAY), c.get(Calendar.MINUTE), true);
        tpd.show();
    }

    @Override
    public void onTimeSet(TimePicker view, int hourOfDay, int minute) {
        Calendar alarmtime = Calendar.getInstance();
        alarmtime.set(year, monthOfYear, dayOfMonth, hourOfDay, minute);

        if (hasAlarm) {
            //Update the current alarm
            DbAccess.updateNotificationTime(getBaseContext(), notification_id, alarmtime.getTimeInMillis());
        } else {
            //create new alarm
            notification_id = (int) (long) DbAccess.addNotification(getBaseContext(), id, alarmtime.getTimeInMillis());
        }
        //Store a reference for the notification in the database. This is later used by the service.

        //Create the intent that is fired by AlarmManager
        Intent i = new Intent(this, NotificationService.class);
        i.putExtra(NotificationService.NOTIFICATION_ID, notification_id);

        PendingIntent pi = PendingIntent.getService(this, notification_id, i, PendingIntent.FLAG_UPDATE_CURRENT);

        AlarmManager alarmManager = (AlarmManager) getSystemService(Context.ALARM_SERVICE);

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.KITKAT) {
            alarmManager.setExact(AlarmManager.RTC_WAKEUP, alarmtime.getTimeInMillis(), pi);
        } else {
            alarmManager.set(AlarmManager.RTC_WAKEUP, alarmtime.getTimeInMillis(), pi);
        }
        Toast.makeText(getApplicationContext(), String.format(getString(R.string.toast_alarm_scheduled), dayOfMonth + "." + (monthOfYear+1) + "." + year + " " + hourOfDay + ":" + String.format("%02d",minute)), Toast.LENGTH_SHORT).show();
        loadActivity(false);
    }

    private void cancelNotification(){
        //Create the intent that would be fired by AlarmManager
        Intent i = new Intent(this, NotificationService.class);
        i.putExtra(NotificationService.NOTIFICATION_ID, notification_id);

        PendingIntent pi = PendingIntent.getService(this, notification_id, i, PendingIntent.FLAG_UPDATE_CURRENT);

        AlarmManager alarmManager = (AlarmManager) getSystemService(Context.ALARM_SERVICE);
        alarmManager.cancel(pi);
        DbAccess.deleteNotification(getBaseContext(), notification_id);
        loadActivity(false);
    }

    @Override
    public boolean onMenuItemClick(MenuItem item) {
        int id = item.getItemId();
        if (id == R.id.action_reminder_edit) {
            final Calendar c = Calendar.getInstance();
            c.setTimeInMillis(notificationCursor.getLong(notificationCursor.getColumnIndexOrThrow(DbContract.NotificationEntry.COLUMN_TIME)));
            int year = c.get(Calendar.YEAR);
            int month = c.get(Calendar.MONTH);
            int day = c.get(Calendar.DAY_OF_MONTH);
            DatePickerDialog dpd = new DatePickerDialog(SketchActivity.this, this, year, month, day);
            dpd.getDatePicker().setMinDate(new Date().getTime());
            dpd.show();
            return true;
        } else if (id == R.id.action_reminder_delete) {
            cancelNotification();
            return true;
        }
        return false;
    }

    private void saveToExternalStorage(){
        String state = Environment.getExternalStorageState();
        if (Environment.MEDIA_MOUNTED.equals(state)) {
            File path;
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.KITKAT){
                path = new File(Environment.getExternalStoragePublicDirectory(
                        Environment.DIRECTORY_DOCUMENTS), "/PrivacyFriendlyNotes");
            } else{
                path = new File(Environment.getExternalStorageDirectory(), "/PrivacyFriendlyNotes");
            }
            File file = new File(path, "/" + etName.getText().toString() + ".jpeg");
            try {
                // Make sure the directory exists.
                boolean path_exists = path.exists() || path.mkdirs();
                if (path_exists) {
                    Bitmap bm = overlay(new BitmapDrawable(getResources(), mFilePath).getBitmap(), drawView.getBitmap());
                    Canvas canvas = new Canvas(bm);
                    canvas.drawColor(Color.WHITE);
                    canvas.drawBitmap(overlay(new BitmapDrawable(getResources(), mFilePath).getBitmap(), drawView.getBitmap()), 0, 0, null);
                    bm.compress(Bitmap.CompressFormat.JPEG, 100, new FileOutputStream(file));

                    // Tell the media scanner about the new file so that it is
                    // immediately available to the user.
                    MediaScannerConnection.scanFile(this,
                            new String[] { file.toString() }, null,
                            new MediaScannerConnection.OnScanCompletedListener() {
                                public void onScanCompleted(String path, Uri uri) {
                                    Log.i("ExternalStorage", "Scanned " + path + ":");
                                    Log.i("ExternalStorage", "-> uri=" + uri);
                                }
                            });

                    Toast.makeText(getApplicationContext(), String.format(getString(R.string.toast_file_exported_to), file.getAbsolutePath()), Toast.LENGTH_LONG).show();
                }
            } catch (IOException e) {
                // Unable to create file, likely because external storage is
                // not currently mounted.
                Log.w("ExternalStorage", "Error writing " + file, e);
            }
        } else {
            Toast.makeText(getApplicationContext(), R.string.toast_external_storage_not_mounted, Toast.LENGTH_LONG).show();
        }
    }

    private void setShareIntent(){
        if (mShareActionProvider != null) {
            String tempPath = mFilePath.substring(0, mFilePath.length()-3) + "jpg";
            File sketchFile = new File(tempPath);

            Bitmap bm = overlay(new BitmapDrawable(getResources(), mFilePath).getBitmap(), drawView.getBitmap());
            Canvas canvas = new Canvas(bm);
            canvas.drawColor(Color.WHITE);
            canvas.drawBitmap(overlay(new BitmapDrawable(getResources(), mFilePath).getBitmap(), drawView.getBitmap()), 0, 0, null);
            try {
                bm.compress(Bitmap.CompressFormat.JPEG, 100, new FileOutputStream(sketchFile));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }

            Uri contentUri = FileProvider.getUriForFile(getApplicationContext(), "org.bel.kachok", sketchFile);
            Intent sendIntent = new Intent();
            sendIntent.setAction(Intent.ACTION_SEND);
            sendIntent.setType("image/*");
            sendIntent.putExtra(Intent.EXTRA_STREAM, contentUri);
            sendIntent.setFlags(Intent.FLAG_GRANT_READ_URI_PERMISSION);
            mShareActionProvider.setShareIntent(sendIntent);
        }
    }
    //taken from http://stackoverflow.com/a/10616868
    public static Bitmap overlay(Bitmap bmp1, Bitmap bmp2) {
        Bitmap bmOverlay = Bitmap.createBitmap(bmp1.getWidth(), bmp1.getHeight(), bmp1.getConfig());
        Canvas canvas = new Canvas(bmOverlay);
        canvas.drawBitmap(bmp1, new Matrix(), null);
        canvas.drawBitmap(bmp2, 0, 0, null);
        return bmOverlay;
    }
}
