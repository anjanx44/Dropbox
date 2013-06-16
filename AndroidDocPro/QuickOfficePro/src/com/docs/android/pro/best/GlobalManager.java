package com.docs.android.pro.best;

public class GlobalManager {
	private static String data;
	private static String parentDir;
	public static String name;
	public static String contents;
	public static String itemloaded;
	private static String directory;
	private static String filetype;
	private static boolean empty;

	public static String geteditortext() {
		return data;
	}

	public static void seteditortext(String var) {
		data = var;
	}

	public static String getdirectory() {
		return directory;
	}

	public static void setdirectory(String var) {
		directory = var;
	}

	public static String getfiletype() {
		return filetype;
	}

	public static void setfiletype(String var) {
		filetype = var;
	}

	public static String getname() {
		return name;
	}

	public static void setname(String var) {
		name = var;
	}

	public static String getcontents() {
		return contents;
	}

	public static void setcontents(String var) {
		contents = var;
	}

	public static String getloaded() {
		return itemloaded;
	}

	public static void setloaded(String var) {
		if (var == "false") {
			itemloaded = "false";
		} else {
			itemloaded = "true";
		}
	}
	
	public static boolean getstate() {
		return empty;
	}

	public static void setstate(boolean var) {
		if (var == false) {
			empty = false;
		} else {
			empty = true;
		}
	}
	
	public static void setParentDirectory(String var) {
		parentDir = var;
	}
	
	public static String getParentDircetory() {
		return parentDir;	}
}