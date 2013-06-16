package com.docs.android.pro.best;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FilenameFilter;
import java.io.IOException;
import java.io.InputStream;
import java.nio.MappedByteBuffer;
import java.nio.channels.FileChannel;

import com.itextpdf.license.LicenseKey;
import com.itextpdf.text.Document;
import com.itextpdf.text.DocumentException;
import com.itextpdf.text.Paragraph;
import com.itextpdf.text.pdf.PdfWriter;


import android.annotation.SuppressLint;
import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.SharedPreferences;
import android.graphics.Color;
import android.graphics.drawable.BitmapDrawable;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.preference.PreferenceManager;
import android.util.Log;
import android.view.ContextMenu;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.Gravity;
import android.view.KeyEvent;
import android.view.LayoutInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.EditText;
import android.widget.GridView;
import android.widget.LinearLayout;
import android.widget.PopupWindow;
import android.widget.TextView;
import android.widget.Toast;

@SuppressLint("SdCardPath")
public class NeriaxiActivity extends Activity {

	LinearLayout bannerAdLayout;
	public String mode;
	public String external;
	File file;

	public void opensidemenu(View view) {
	}
	
	@Override
	protected void onResume() {
	
		scanfiles();
		super.onResume();
	}

	@Override
	public boolean onKeyDown(int keyCode, KeyEvent event) {
		if (keyCode == KeyEvent.KEYCODE_MENU) {
			showmenu(null);
			return true;
		}
		if (keyCode == KeyEvent.KEYCODE_SEARCH) {
			search(null);
			return true;
		}
		return super.onKeyDown(keyCode, event);
	}

	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		scanfiles();
	}

	@Override
	public boolean onContextItemSelected(MenuItem item) {
		String name = GlobalManager.getname();
		String contents = GlobalManager.getcontents();
		final SharedPreferences prefs = PreferenceManager
				.getDefaultSharedPreferences(getBaseContext());
		if (item.getTitle() == "Rename") {
			changename(item.getItemId(), name,
					prefs.getString("filetype", ".txt"));
		} if (item.getTitle() == "Delete") {
			delete(item.getItemId(), name, prefs.getString("filetype", ".txt"));
		} if (item.getTitle() == "Transfer as PDF") {
			transferasPDF(item.getItemId(), name, contents);
		} if (item.getTitle() == "Transfer as txt") {
			transfer(item.getItemId(), name, contents);
		} else {
			return false;
		}
		return true;
	}

	private void transferasPDF(int itemId, String name, String contents) {
		// TODO Auto-generated method stub
		try {
			InputStream is = null;
			try {
				is = getAssets().open("itextkey.xml");
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return;
			}
	    	LicenseKey.loadLicenseFile(is);
	        Document document=new Document();
	        PdfWriter.getInstance(document, new FileOutputStream(Environment.getExternalStorageDirectory() + "/"+name+".pdf"));
	        document.open();
	        document.add(new Paragraph(contents));
	        document.close();
	        /**** Sending File ***/
//	        Toast.makeText(getApplicationContext(), Environment.getExternalStorageDirectory().toString(),Toast.LENGTH_SHORT).show();
	        Log.i("Storage", "file://"+Environment.getExternalStorageDirectory().toString() + "/"+name+".pdf");
//	        Uri uri = Uri.fromFile(new File(Environment.getExternalStorageDirectory(), "/hello.pdf"));
	        Intent i = new Intent(Intent.ACTION_SEND);
	        i.setType("application/pdf");
			i.putExtra(Intent.EXTRA_SUBJECT, name);
			i.putExtra(Intent.EXTRA_TEXT, contents);
	        i.putExtra(Intent.EXTRA_STREAM, Uri.parse("file://"+Environment.getExternalStorageDirectory().toString() + "/"+name+".pdf"));	       
			startActivity(Intent.createChooser(i, "Transfer"));
			/*String filename = Environment.getExternalStorageDirectory() + "/hello.pdf";
			file = new File(filename);
			file.delete();*/
	    } catch (FileNotFoundException e){
	        // TODO Auto-generated catch block
	        e.printStackTrace();
	    } catch (DocumentException e){
	        e.printStackTrace();
	    }
	}

	@Override
	public void onCreateContextMenu(ContextMenu menu, View v,
			ContextMenuInfo menuInfo) {
		super.onCreateContextMenu(menu, v, menuInfo);
		AdapterView.AdapterContextMenuInfo info = (AdapterView.AdapterContextMenuInfo) menuInfo;
		GlobalManager.setname(((TextView) info.targetView
				.findViewById(R.id.filename)).getText().toString());
		GlobalManager.setcontents(((TextView) info.targetView
				.findViewById(R.id.preview)).getText().toString());
		menu.add(0, v.getId(), 0, "Rename");
		menu.add(0, v.getId(), 1, "Delete");
		menu.add(0, v.getId(), 2, "Transfer as PDF");
		menu.add(0, v.getId(), 3, "Transfer as txt");		
	}

	@Override
	protected void onStart() {
		super.onStart();
	}

	public void addnote(View view) {
		AlertDialog.Builder alert = new AlertDialog.Builder(this);
		final EditText input = new EditText(this);
		input.setBackgroundDrawable(getResources().getDrawable(
				R.drawable.text_selector));
		input.setTextColor(Color.WHITE);
		input.setHint("Document Name");
		alert.setView(input);
		alert.setPositiveButton("OK", new DialogInterface.OnClickListener() {
			public void onClick(DialogInterface dialog, int whichButton) {
				View layout = getLayoutInflater().inflate(R.layout.toast,
						(ViewGroup) findViewById(R.id.toast));
				TextView text = (TextView) layout.findViewById(R.id.toasttext);
				if (input.getText().length() == 0) {
					text.setText("Quick Note Mode");
					GlobalManager.setstate(false);
				} else {
					text.setText("Added " + input.getText().toString().trim());
					GlobalManager.setstate(true);
				}
				GlobalManager.setname(input.getText().toString().trim());
				Toast toast = new Toast(getApplicationContext());
				toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
				toast.setDuration(Toast.LENGTH_LONG);
				toast.setView(layout);
				toast.show();
				NeriaxiActivity.this.startActivity(new Intent(
						NeriaxiActivity.this, Editor.class));
			}
		});
		alert.setNegativeButton("Cancel",
				new DialogInterface.OnClickListener() {
					public void onClick(DialogInterface dialog, int whichButton) {
					}
				});
		alert.show();
	}

	public void search(View view) {
		NeriaxiActivity.this.startActivity(new Intent(NeriaxiActivity.this,
				Search.class));
	}

	public void showmenu(View view) {
		PopupWindow pw = new PopupWindow(
				((LayoutInflater) this.getSystemService(Context.LAYOUT_INFLATER_SERVICE))
						.inflate(R.layout.menu, null, false), 256, 288, true);
		pw.setBackgroundDrawable(new BitmapDrawable());
		pw.setFocusable(true);
		pw.showAsDropDown(this.findViewById(R.id.menu), 0, 0);
	}

	public void changename(int id, String name, final String extension) {
		AlertDialog.Builder alert = new AlertDialog.Builder(this);
		final EditText input = new EditText(this);
		input.setBackgroundDrawable(getResources().getDrawable(
				R.drawable.text_selector));
		input.setTextColor(Color.WHITE);
		input.setText(name);
		alert.setView(input);
		alert.setPositiveButton("OK", new DialogInterface.OnClickListener() {
			public void onClick(DialogInterface dialog, int whichButton) {
				if (input.getText().toString().length() != 0) {
					new File(GlobalManager.getdirectory().toString()
							+ GlobalManager.getname() + extension)
							.renameTo(new File(GlobalManager.getdirectory()
									.toString()
									+ input.getText().toString().trim()
									+ extension));
					View layout = getLayoutInflater().inflate(R.layout.toast,
							(ViewGroup) findViewById(R.id.toast));
					((TextView) layout.findViewById(R.id.toasttext))
							.setText("Set name to "
									+ input.getText().toString().trim());
					GlobalManager.setname(input.getText().toString().trim());
					scanfiles();
					Toast toast = new Toast(getApplicationContext());
					toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
					toast.setDuration(Toast.LENGTH_LONG);
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

	public void delete(int id, String name, String extension) {
		String filename = GlobalManager.getdirectory().toString() + name
				+ extension;
		file = new File(filename);
		file.delete();
		scanfiles();
		View layout = getLayoutInflater().inflate(R.layout.toast,
				(ViewGroup) findViewById(R.id.toast));
		TextView text = (TextView) layout.findViewById(R.id.toasttext);
		text.setText("Deleted " + filename);
		Toast toast = new Toast(getApplicationContext());
		toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
		toast.setDuration(Toast.LENGTH_LONG);
		toast.setView(layout);
		toast.show();
	}

	public void transfer(int id, String name, String contents) {
		Intent i = new Intent(Intent.ACTION_SEND);
		i.setType("text/plain");
		i.putExtra(Intent.EXTRA_SUBJECT, name);
		i.putExtra(Intent.EXTRA_TEXT, contents);
		startActivity(Intent.createChooser(i, "Transfer"));
	}

	public void about(View view) {
		NeriaxiActivity.this.startActivity(new Intent(NeriaxiActivity.this,
				About.class));
	}

	public void opensettings(View view) {
		NeriaxiActivity.this.startActivity(new Intent(NeriaxiActivity.this,
				Setting.class));
	}
	
	public boolean isOnline() {
		ConnectivityManager cm = (ConnectivityManager) getSystemService(Context.CONNECTIVITY_SERVICE);
		NetworkInfo netInfo = cm.getActiveNetworkInfo();
		if (netInfo != null && netInfo.isConnectedOrConnecting()) {
			return true;
		}
		return false;
	}

	@SuppressLint("SdCardPath")
	public void scanfiles() {
		final SharedPreferences prefs = PreferenceManager
				.getDefaultSharedPreferences(getBaseContext());
		GlobalManager.setdirectory(prefs.getString("directory", "/sdcard/"));
		GlobalManager.setParentDirectory(prefs.getString("directory", "/sdcard/"));
		GlobalManager.setfiletype(prefs.getString("filetype", ".txt"));
		GridView lv = (GridView) findViewById(R.id.fileList);
		registerForContextMenu(lv);
		File directory = new File(prefs.getString("directory", "/sdcard/"));
		final String filetype = prefs.getString("filetype", ".txt");
		if (!directory.isDirectory()) {
			return;
		}
		FilenameFilter filefilter = new FilenameFilter() {
			public boolean accept(File dir, String name) {
				return name.endsWith(filetype);
			}
		};
		String[] filenames = directory.list(filefilter);
		int iter = filenames.length;
		String[] previews = new String[iter];
		int locman = 0;
		while (iter != 0) {
			previews[locman] = fastStreamCopy(
					prefs.getString("directory", "/sdcard/")
							+ (filenames[locman])).trim();
			filenames[locman] = removeExtension(filenames[locman]);
			locman = locman + 1;
			iter = iter - 1;
		}
		lv.setAdapter(new GraphAdapter(this, previews, filenames));
		lv.setOnItemClickListener(new OnItemClickListener() {
			public void onItemClick(AdapterView<?> arg0, View view,
					int position, long arg3) {
				try {
					GlobalManager.setstate(true);
					GlobalManager.seteditortext(fastStreamCopy(
							prefs.getString("directory", "/sdcard/")
									+ ((TextView) view
											.findViewById(R.id.filename))
											.getText().toString()
									+ prefs.getString("filetype", ".txt"))
							.trim());
					GlobalManager.setname(((TextView) view
							.findViewById(R.id.filename)).getText().toString());
					GlobalManager.setloaded("true");
					NeriaxiActivity.this.startActivity(new Intent(
							NeriaxiActivity.this, Editor.class));
				} catch (Exception e) {
					View layout = getLayoutInflater().inflate(R.layout.toast,
							(ViewGroup) findViewById(R.id.toast));
					TextView text = (TextView) layout
							.findViewById(R.id.toasttext);
					text.setText(e.getMessage());
					Toast toast = new Toast(getApplicationContext());
					toast.setGravity(Gravity.CENTER_VERTICAL, 0, 0);
					toast.setDuration(Toast.LENGTH_LONG);
					toast.setView(layout);
					toast.show();
				}
			}
		});
	}

	public void exit(View view) {
		finish();
	}

	@SuppressWarnings("resource")
	private static String fastStreamCopy(String filename) {
		String s = "";
		FileChannel fc = null;
		try {
			fc = new FileInputStream(filename).getChannel();

			// int length = (int)fc.size();

			MappedByteBuffer byteBuffer = fc.map(FileChannel.MapMode.READ_ONLY,
					0, fc.size());
			// CharBuffer charBuffer =
			// Charset.forName("ISO-8859-1").newDecoder().decode(byteBuffer);

			// ByteBuffer byteBuffer = ByteBuffer.allocate(length);
			// ByteBuffer byteBuffer = ByteBuffer.allocateDirect(length);
			// CharBuffer charBuffer = byteBuffer.asCharBuffer();

			// CharBuffer charBuffer =
			// ByteBuffer.allocateDirect(length).asCharBuffer();
			/*
			 * int size = charBuffer.length(); if (size > 0) { StringBuffer sb =
			 * new StringBuffer(size); for (int count=0; count<size; count++)
			 * sb.append(charBuffer.get()); s = sb.toString(); }
			 * 
			 * if (length > 0) { StringBuffer sb = new StringBuffer(length); for
			 * (int count=0; count<length; count++) {
			 * sb.append(byteBuffer.get()); } s = sb.toString(); }
			 */
			int size = byteBuffer.capacity();
			if (size > 0) {
				// Retrieve all bytes in the buffer
				byteBuffer.clear();
				byte[] bytes = new byte[size];
				byteBuffer.get(bytes, 0, bytes.length);
				s = new String(bytes);
			}

			fc.close();
		} catch (FileNotFoundException e) {
			System.err.println("File not found: " + e);
		} catch (IOException e) {
		} finally {
			if (fc != null) {
				try {
					fc.close();
				} catch (IOException e) {
				}
			}
		}
		return s;
	}

	public static String removeExtension(String filePath) {
		File f = new File(filePath);

		if (f.isDirectory())
			return filePath;

		String name = f.getName();

		final int lastPeriodPos = name.lastIndexOf('.');
		if (lastPeriodPos <= 0) {
			return filePath;
		} else {
			return new File(f.getParent(), name.substring(0, lastPeriodPos))
					.getPath();
		}
	}

}