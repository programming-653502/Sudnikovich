package org.bel.kachok.fragments;

import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import org.bel.kachok.R;

public class GifFragment extends Fragment {
    private String TAG;
    private LayoutInflater inflater;
    private static int instanceCount;

    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState) {

        this.inflater = inflater;
        return inflater.inflate(R.layout.fragment_layoutgif, container, false);
    }

    public static GifFragment newInstance() {
        GifFragment fragment = new GifFragment();
        fragment.setTAG(Integer.toString(GifFragment.instanceCount++));
        return fragment;
    }

    public String getTAG() {
        return TAG;
    }

    public void setTAG(String TAG) {
        this.TAG = TAG;
    }
}
