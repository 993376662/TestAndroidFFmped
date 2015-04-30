package com.example.testffmped;

import cn.dennishucd.FFmpegNative;
import android.support.v7.app.ActionBarActivity;
import android.os.Bundle;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.TextView;

public class MainActivity extends ActionBarActivity {

	private FFmpegNative fFmpegNative;
	private TextView tv;

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_main);
		initViews();
		fFmpegNative = new FFmpegNative();
	}

	private void initViews() {
		tv = (TextView) findViewById(R.id.tv);
	}

	public void findCode(View view) {
		int codecID = 28; //28 is the H264 Codec ID
		int res = fFmpegNative.avcodec_find_decoder(codecID);
		if (res == 0) {
			tv.setText("Success!");
		} else {
			tv.setText("Failed!");
		}
	}
}
