package com.docs.android.pro.best;




import android.content.Context;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.BaseAdapter;
import android.widget.TextView;

class GraphAdapter extends BaseAdapter {
	private String[] stringArray;
	private String[] previewArray;
	private Context mContext;
	private LayoutInflater inflator;

	public GraphAdapter(Context context, String[] previewArray,
			String[] stringArray) {
		this.mContext = context;
		this.stringArray = stringArray;
		this.previewArray = previewArray;
		this.inflator = (LayoutInflater) mContext
				.getSystemService(Context.LAYOUT_INFLATER_SERVICE);

	}

	public int getCount() {
		return stringArray.length;
	}


	public Object getItem(int position) {
		return position;
	}


	public long getItemId(int position) {
		return position;
	}

	public View getView(int position, View convertView, ViewGroup parent) {

		final MainListHolder mHolder;
		View v = convertView;
		if (convertView == null) {
			mHolder = new MainListHolder();
			v = inflator.inflate(R.layout.files, null);
			mHolder.txt1 = (TextView) v.findViewById(R.id.preview);
			mHolder.txt2 = (TextView) v.findViewById(R.id.filename);
			v.setTag(mHolder);
		} else {
			mHolder = (MainListHolder) v.getTag();
		}
		mHolder.txt1.setText(previewArray[position]);
		mHolder.txt2.setText(stringArray[position]);

		return v;
	}

	class MainListHolder {
		private TextView txt1;
		private TextView txt2;

	}

}