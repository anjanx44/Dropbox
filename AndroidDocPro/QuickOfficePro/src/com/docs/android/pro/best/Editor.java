package com.docs.android.pro.best;

import java.io.File;
import java.io.FileWriter;
import java.io.IOException;


import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.os.Bundle;
import android.preference.PreferenceManager;
import android.view.Gravity;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.view.WindowManager;
import android.view.inputmethod.EditorInfo;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

public class Editor extends Activity {

	FileWriter writer;
	File file;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		final SharedPreferences prefs = PreferenceManager
				.getDefaultSharedPreferences(getBaseContext());
		if (prefs.getBoolean("fullscreen", true) == true) {
			requestWindowFeature(Window.FEATURE_NO_TITLE);
			getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
					WindowManager.LayoutParams.FLAG_FULLSCREEN);

		}
		setContentView(R.layout.editor);
		if (prefs.getBoolean("noextractui", true) == true) {
			EditText editor = (EditText) findViewById(R.id.editor);
			editor.setImeOptions(EditorInfo.IME_FLAG_NO_EXTRACT_UI);
		}
		setname();
		if (GlobalManager.getloaded() == "true") {
			((EditText) findViewById(R.id.editor)).setText(GlobalManager
					.geteditortext());
			((TextView) findViewById(R.id.editortitle)).setText(GlobalManager
					.getname());
			GlobalManager.setloaded("false");
			GlobalManager.seteditortext("");
			setactioncode();
		} else {
		}
	}
	//set OnLongClick listener to rename file
	public void setactioncode() {
		((TextView) findViewById(R.id.editortitle))
				.setOnLongClickListener(new View.OnLongClickListener() {

					public boolean onLongClick(View v) {
						changename(v);
						return false;
					}
				});
	}
	// Set the name of the doc 
	public void setname() {
		((TextView) findViewById(R.id.editortitle)).setText(GlobalManager
				.getname());
	}
	// call when the back button is pressed
	public void back(View view) {
		finish();
	}
	// change the name of the Text
	public void changename(View view) {
		AlertDialog.Builder alert = new AlertDialog.Builder(this);
		final EditText input = new EditText(this);
		input.setBackgroundDrawable(getResources().getDrawable(
				R.drawable.text_selector));
		input.setTextColor(Color.WHITE);
		final SharedPreferences prefs = PreferenceManager
				.getDefaultSharedPreferences(getBaseContext());
		TextView namebar = (TextView) findViewById(R.id.editortitle);
		input.setText(namebar.getText().toString());
		alert.setView(input);
		alert.setPositiveButton("OK", new DialogInterface.OnClickListener() {
			public void onClick(DialogInterface dialog, int whichButton) {
				TextView namebar = (TextView) findViewById(R.id.editortitle);
				if (input.getText().toString().length() != 0) {
					new File(GlobalManager.getdirectory().toString()
							+ namebar.getText().toString()
							+ prefs.getString("filetype", ".txt"))
							.renameTo(new File(GlobalManager.getdirectory()
									.toString()
									+ input.getText().toString().trim()
									+ prefs.getString("filetype", ".txt")));
					namebar.setText(input.getText().toString().trim());
					View layout = getLayoutInflater().inflate(R.layout.toast,
							(ViewGroup) findViewById(R.id.toast));
					TextView text = (TextView) layout
							.findViewById(R.id.toasttext);
					text.setText("Set name to " + input.getText().toString());
					GlobalManager.setname(input.getText().toString().trim());
					Toast toast = new Toast(getApplicationContext());
					toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
					toast.setDuration(Toast.LENGTH_SHORT);
					toast.setView(layout);
					toast.show();
				} else {
				}
			}
		});
		alert.setNegativeButton("Cancel",
				new DialogInterface.OnClickListener() {
					public void onClick(DialogInterface dialog, int whichButton) {
					}
				});
		alert.show();
	}
	// save the file 
	public void save(View view) {
		if (GlobalManager.getstate() == true) {
			EditText editor = (EditText) findViewById(R.id.editor);
			String filename;
			if (GlobalManager.getname().toString()
					.endsWith(GlobalManager.getfiletype().toString())) {
				filename = GlobalManager.getdirectory().toString()
						+ GlobalManager.getname().toString();
			} else {
				filename = GlobalManager.getdirectory().toString()
						+ GlobalManager.getname().toString()
						+ GlobalManager.getfiletype().toString();
			}
			file = new File(filename);
			try {
				file.delete();
				writer = new FileWriter(file, true);
				writer.write(editor.getText().toString());
				writer.flush();
				writer.close();
				View layout = getLayoutInflater().inflate(R.layout.toast,
						(ViewGroup) findViewById(R.id.toast));
				((TextView) layout.findViewById(R.id.toasttext))
						.setText("File Saved");
				Toast toast = new Toast(getApplicationContext());
				toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
				toast.setDuration(Toast.LENGTH_LONG);
				toast.setView(layout);
				toast.show();
			} catch (IOException e) {
				View layout = getLayoutInflater().inflate(R.layout.toast,
						(ViewGroup) findViewById(R.id.toast));
				((TextView) layout.findViewById(R.id.toasttext)).setText(e
						.getMessage());
				Toast toast = new Toast(getApplicationContext());
				toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
				toast.setDuration(Toast.LENGTH_LONG);
				toast.setView(layout);
				toast.show();
			}
		} else {
			AlertDialog.Builder alert = new AlertDialog.Builder(this);
			final EditText input = new EditText(this);
			input.setBackgroundDrawable(getResources().getDrawable(
					R.drawable.text_selector));
			input.setTextColor(Color.WHITE);
			TextView namebar = (TextView) findViewById(R.id.editortitle);
			input.setText(namebar.getText().toString());
			alert.setView(input);
			alert.setPositiveButton("OK",
					new DialogInterface.OnClickListener() {
						public void onClick(DialogInterface dialog,
								int whichButton) {
							if (input.getText().toString().length() != 0) {
								EditText editor = (EditText) findViewById(R.id.editor);
								String filename;
								if (input
										.getText()
										.toString()
										.endsWith(
												GlobalManager.getfiletype()
														.toString())) {
									filename = GlobalManager.getdirectory()
											.toString()
											+ input.getText().toString().trim();
								} else {
									filename = GlobalManager.getdirectory()
											.toString()
											+ input.getText().toString().trim()
											+ GlobalManager.getfiletype()
													.toString();
								}
								file = new File(filename);
								try {
									file.delete();
									writer = new FileWriter(file, true);
									writer.write(editor.getText().toString());
									writer.flush();
									writer.close();
									TextView title = (TextView) findViewById(R.id.editortitle);
									title.setText(input.getText().toString()
											.trim());
									GlobalManager.setstate(true);
									GlobalManager.setname(input.getText()
											.toString().trim());
									View layout = getLayoutInflater()
											.inflate(
													R.layout.toast,
													(ViewGroup) findViewById(R.id.toast));
									((TextView) layout
											.findViewById(R.id.toasttext))
											.setText("File Saved");
									Toast toast = new Toast(
											getApplicationContext());
									toast.setGravity(Gravity.CENTER_VERTICAL,
											0, 0);
									toast.setDuration(Toast.LENGTH_LONG);
									toast.setView(layout);
									toast.show();

								} catch (IOException e) {
									View layout = getLayoutInflater()
											.inflate(
													R.layout.toast,
													(ViewGroup) findViewById(R.id.toast));
									((TextView) layout
											.findViewById(R.id.toasttext))
											.setText(e.getMessage());
									Toast toast = new Toast(
											getApplicationContext());
									toast.setGravity(Gravity.CENTER_VERTICAL,
											0, 0);
									toast.setDuration(Toast.LENGTH_LONG);
									toast.setView(layout);
									toast.show();
								}
							} else {
							}
						}
					});
			alert.setNegativeButton("Cancel",
					new DialogInterface.OnClickListener() {
						public void onClick(DialogInterface dialog,
								int whichButton) {
						}
					});
			alert.show();
		}
	}

	/*public void loadfromlist() {
		GlobalManager.seteditortext(((EditText) findViewById(R.id.editor))
				.getText().toString());
	}*/
}