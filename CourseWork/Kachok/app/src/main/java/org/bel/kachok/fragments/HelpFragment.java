package org.bel.kachok.fragments;

import android.os.Bundle;
import android.preference.PreferenceFragment;

import org.bel.kachok.R;


public class HelpFragment extends PreferenceFragment {
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        addPreferencesFromResource(R.xml.pref_help);
    }
}
