package org.bel.kachok.activities;

/**
 * Created by BEI on 13.04.2017.
 */

import android.content.Intent;
import android.os.Bundle;
import android.support.v7.app.ActionBarActivity;
import android.support.v7.app.AppCompatActivity;
import android.view.KeyEvent;
import android.view.View;
import android.webkit.WebChromeClient;
import android.webkit.WebView;
import android.webkit.WebViewClient;
import android.widget.Button;

import org.bel.kachok.R;

public class Music_activity extends AppCompatActivity implements View.OnClickListener{ //
    private WebView view; //membuat variabel view agar bisa akses method onKeyDown

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.music_activity);

        view = (WebView) this.findViewById(R.id.WebViewmusic);
        view.getSettings().setJavaScriptEnabled(true);
        view.setWebViewClient(new MyBrowser());
        view.loadUrl("https://cloud.mail.ru/public/GdpE/HR4fe4qZZ"); //try js alert
        view.setWebChromeClient(new WebChromeClient()); // adding js alert support
        getSupportActionBar().hide();
        findViewById(R.id.getback).setOnClickListener(this);

    }

    private class MyBrowser extends WebViewClient {
        @Override
        public boolean shouldOverrideUrlLoading(WebView view, String url) {
            view.loadUrl(url);
            return true;
        }
    }

    public boolean onKeyDown(int keyCode, KeyEvent event) {
        //ketika disentuh tombol back
        if ((keyCode == KeyEvent.KEYCODE_BACK) && view.canGoBack()) {
            view.goBack(); //method goback() dieksekusi untuk kembali pada halaman sebelumnya
            return true;
        }
        // Jika tidak ada history (Halaman yang sebelumnya dibuka)
        // maka akan keluar dari activity
        return super.onKeyDown(keyCode, event);
    }
    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.getback:
                startActivity(new Intent(getApplication(), MainActivity.class));
                break;
        }
    }
}