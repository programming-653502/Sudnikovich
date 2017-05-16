package org.bel.kachok.receivers;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;

import org.bel.kachok.utils.StepDetectionServiceHelper;


public class OnBootCompletedBroadcastReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        StepDetectionServiceHelper.startAllIfEnabled(context);
    }
}
