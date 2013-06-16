package com.docs.android.pro.best;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;

public class About extends Activity {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.about);
	}

	public void back(View view) {
		finish();
	}
}