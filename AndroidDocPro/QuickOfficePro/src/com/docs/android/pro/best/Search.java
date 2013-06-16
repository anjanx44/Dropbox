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
import java.util.ArrayList;

import com.itextpdf.license.LicenseKey;
import com.itextpdf.text.Document;
import com.itextpdf.text.DocumentException;
import com.itextpdf.text.Paragraph;
import com.itextpdf.text.pdf.PdfWriter;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.net.ConnectivityManager;
import android.net.NetworkInfo;
import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.preference.PreferenceManager;
import android.text.Editable;
import android.text.TextWatcher;
import android.util.Log;
import android.view.ContextMenu;
import android.view.ContextMenu.ContextMenuInfo;
import android.view.Gravity;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.EditText;
import android.widget.GridView;
import android.widget.LinearLayout;
import android.widget.TextView;
import android.widget.Toast;
import android.widget.AdapterView.OnItemClickListener;

@SuppressLint("DefaultLocale")
public class Search extends Activity {

	LinearLayout bannerAdLayout;
	EditText searchfield;
	TextView searchState;
	ArrayList<String> whereprev = new ArrayList<String>();
	ArrayList<String> wherefile = new ArrayList<String>();
	ArrayList<String> setmypathDir = new ArrayList<String>();
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.search);
		searchfield = (EditText) findViewById(R.id.searchbar);
		searchState = (TextView) findViewById(R.id.tvSearchState);
		searchfield.addTextChangedListener(new TextWatcher() {
			
			public void onTextChanged(CharSequence s, int start, int before, int count) {
				// TODO Auto-generated method stub
				search(Environment.getExternalStorageDirectory());
			}
			
			public void beforeTextChanged(CharSequence s, int start, int count,
					int after) {
				// TODO Auto-generated method stub
				
			}
			
			public void afterTextChanged(Editable s) {
				// TODO Auto-generated method stub
				
			}
		});
		search(Environment.getExternalStorageDirectory());
	}

	@SuppressLint({ "SdCardPath", "DefaultLocale" })
	public void search(File directory) {
		final String term = searchfield.getText().toString();
		if (term.length() != 0) {
			searchState.setVisibility(TextView.GONE);
			final SharedPreferences prefs = PreferenceManager
					.getDefaultSharedPreferences(getBaseContext());
			GlobalManager
					.setdirectory(directory.getPath()+"/");
			GlobalManager.setfiletype(prefs.getString("filetype", ".txt"));
//			File directory = new File(prefs.getString("directory", "/sdcard/"));
			final String filetype = prefs.getString("filetype", ".txt");
			File listFile[] = directory.listFiles();
			if (listFile != null) {
			    for (int i = 0; i < listFile.length; i++) {
			        if (listFile[i].isDirectory()) {
			            search(listFile[i]);			          
			        } 
			    }
//	        	Toast.makeText(getApplicationContext(), (new File(prefs.getString("directory", "/sdcard/"))).getPath(), Toast.LENGTH_SHORT).show();
			    Log.i("Directory",directory.getPath());
			    FilenameFilter filefilter = new FilenameFilter() {
					@SuppressLint("DefaultLocale")
					public boolean accept(File dir, String name) {
						return ((name.endsWith(filetype)) && ((removeExtension(name)
								.contains(term.toLowerCase())) || (removeExtension(name)
								.contains(term.toUpperCase()))));
					}
				};
				String[] temp_filenames = directory.list(filefilter); 
				int iter = temp_filenames.length;
				while (iter!=0) {
					iter--;
					String caal = removeExtension(temp_filenames[iter]);
					String baal = fastStreamCopy(directory.getPath()+"/"+ (temp_filenames[iter])).trim();
					wherefile.add(caal);
					whereprev.add(baal);
					setmypathDir.add(directory.getPath() + "/");
					Log.i("FileNames",Integer.toString(iter) + " Filenames: " + caal + ", PrevS: "+ baal);
				}
				if(directory == Environment.getExternalStorageDirectory()){
					if(whereprev.size()==0){
						searchState.setVisibility(TextView.VISIBLE);
						searchState.setText("The search item couldn't be found");
					} else {
						GridView lv = (GridView) findViewById(R.id.searchList);
						registerForContextMenu(lv);
						String[] previews = new String[ whereprev.size() ];
						whereprev.toArray(previews); 
						String[] filenames = new String[ whereprev.size() ];
						wherefile.toArray( filenames );
						final String[] getDirPath = new String[ whereprev.size() ];
						setmypathDir.toArray(getDirPath);
						lv.setAdapter(new GraphAdapter(this, previews, filenames));
						lv.setOnItemClickListener(new OnItemClickListener() {
					public void onItemClick(AdapterView<?> arg0, View view,int position, long arg3) {
						final String getmyPath = getDirPath[position];
						try {
							GlobalManager.seteditortext(fastStreamCopy(
									getmyPath
											+ ((TextView) view
													.findViewById(R.id.filename))
													.getText().toString()
											+ prefs.getString("filetype", ".txt"))
									.trim());
							GlobalManager.setname(((TextView) view
									.findViewById(R.id.filename)).getText()
									.toString());
							GlobalManager.setdirectory(getmyPath);
							GlobalManager.setloaded("true");
							Search.this.startActivity(new Intent(Search.this,
									Editor.class));
						} catch (Exception e) {
							View layout = getLayoutInflater().inflate(
									R.layout.toast,
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
						wherefile.clear();whereprev.clear();setmypathDir.clear();
					}
				}
			}
		} else {
			searchState.setVisibility(TextView.VISIBLE);
			searchState.setText("Enter a search hints");
		}
	}

	public void back(View view) {
		finish();
	}

	public boolean isOnline() {
		ConnectivityManager cm = (ConnectivityManager) getSystemService(Context.CONNECTIVITY_SERVICE);
		NetworkInfo netInfo = cm.getActiveNetworkInfo();
		if (netInfo != null && netInfo.isConnectedOrConnecting()) {
			return true;
		}
		return false;
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

	public void callthesearch(View view) {
		search(Environment.getExternalStorageDirectory());
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

	@Override
	public boolean onContextItemSelected(MenuItem item) {
		// TODO Auto-generated method stub
		String name = GlobalManager.getname();
		String contents = GlobalManager.getcontents();
		if (item.getTitle() == "Transfer as PDF") {
			transferasPDF(item.getItemId(), name, contents);
		} if (item.getTitle() == "Transfer as txt") {
			transfer(item.getItemId(), name, contents);
		} else {
			return false;
		}
		return true;
	}

	@Override
	public void onCreateContextMenu(ContextMenu menu, View v,
			ContextMenuInfo menuInfo) {
		// TODO Auto-generated method stub
		super.onCreateContextMenu(menu, v, menuInfo);
		AdapterView.AdapterContextMenuInfo info = (AdapterView.AdapterContextMenuInfo) menuInfo;
		GlobalManager.setname(((TextView) info.targetView
				.findViewById(R.id.filename)).getText().toString());
		GlobalManager.setcontents(((TextView) info.targetView
				.findViewById(R.id.preview)).getText().toString());
		menu.add(0, v.getId(), 0, "Transfer as PDF");
		menu.add(0, v.getId(), 1, "Transfer as txt");
	}
	
	public void transfer(int id, String name, String contents) {
		Intent i = new Intent(Intent.ACTION_SEND);
		i.setType("text/plain");
		i.putExtra(Intent.EXTRA_SUBJECT, name);
		i.putExtra(Intent.EXTRA_TEXT, contents);
		startActivity(Intent.createChooser(i, "Transfer"));
	}
	
	public void transferasPDF(int itemId, String name, String contents) {
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
}