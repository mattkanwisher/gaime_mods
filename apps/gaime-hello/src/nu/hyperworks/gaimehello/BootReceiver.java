package nu.hyperworks.gaimehello;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;

/** Puts HelloActivity on screen once the system finishes booting. */
public class BootReceiver extends BroadcastReceiver {
    private static final String TAG = "GaimeHello";

    @Override
    public void onReceive(Context context, Intent intent) {
        Log.i(TAG, "boot broadcast: " + intent.getAction());
        Intent go = new Intent(context, HelloActivity.class);
        go.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK
                | Intent.FLAG_ACTIVITY_CLEAR_TASK
                | Intent.FLAG_ACTIVITY_NO_HISTORY);
        try {
            context.startActivity(go);
        } catch (Exception e) {
            Log.e(TAG, "could not start activity", e);
        }
    }
}
