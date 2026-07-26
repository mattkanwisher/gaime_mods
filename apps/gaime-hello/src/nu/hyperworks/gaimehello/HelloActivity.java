package nu.hyperworks.gaimehello;

import android.app.Activity;
import android.graphics.Color;
import android.os.Bundle;
import android.util.TypedValue;
import android.view.Gravity;
import android.view.KeyEvent;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.TextView;

/**
 * Fullscreen "hello" screen shown on boot. Stays up until the user presses
 * something: the on-screen button (the light gun is an absolute pointer, so it
 * can be shot) or any key on the gun's keyboard interface.
 *
 * The UI is built in code so the APK needs no resource table beyond the
 * manifest, which keeps the build to aapt2 + javac + d8.
 */
public class HelloActivity extends Activity {

    private boolean dismissing = false;

    @Override
    protected void onCreate(Bundle saved) {
        super.onCreate(saved);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON
                | WindowManager.LayoutParams.FLAG_TURN_SCREEN_ON
                | WindowManager.LayoutParams.FLAG_SHOW_WHEN_LOCKED);

        LinearLayout root = new LinearLayout(this);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setGravity(Gravity.CENTER);
        root.setBackgroundColor(Color.parseColor("#101018"));
        root.setPadding(64, 64, 64, 64);

        TextView hello = new TextView(this);
        hello.setText("hello");
        hello.setTextColor(Color.WHITE);
        hello.setTextSize(TypedValue.COMPLEX_UNIT_SP, 96);
        hello.setGravity(Gravity.CENTER);

        TextView sub = new TextView(this);
        sub.setText("G'AIM'E console — patched firmware, adb enabled");
        sub.setTextColor(Color.parseColor("#8899AA"));
        sub.setTextSize(TypedValue.COMPLEX_UNIT_SP, 22);
        sub.setGravity(Gravity.CENTER);
        sub.setPadding(0, 24, 0, 56);

        Button go = new Button(this);
        go.setText("  Press to continue  ");
        go.setTextSize(TypedValue.COMPLEX_UNIT_SP, 28);
        go.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                dismiss();
            }
        });

        TextView hint = new TextView(this);
        hint.setText("or press any button");
        hint.setTextColor(Color.parseColor("#556677"));
        hint.setTextSize(TypedValue.COMPLEX_UNIT_SP, 18);
        hint.setGravity(Gravity.CENTER);
        hint.setPadding(0, 40, 0, 0);

        root.addView(hello);
        root.addView(sub);
        root.addView(go);
        root.addView(hint);
        setContentView(root);
    }

    private void dismiss() {
        if (dismissing) {
            return;
        }
        dismissing = true;
        finish();
    }

    @Override
    public boolean onKeyDown(int keyCode, KeyEvent event) {
        dismiss();
        return true;
    }

    @Override
    public void onBackPressed() {
        dismiss();
    }
}
