package nu.hyperworks.gaimeexplorer;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Intent;
import android.content.pm.ApplicationInfo;
import android.content.pm.PackageManager;
import android.content.pm.ResolveInfo;
import android.graphics.Color;
import android.os.Bundle;
import android.os.Environment;
import android.util.TypedValue;
import android.view.Gravity;
import android.view.MotionEvent;
import android.view.PointerIcon;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.LinearLayout;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;

/**
 * Minimal file browser and app launcher for the G'AIM'E console.
 *
 * The stock image is a kiosk: 106 packages and 24 launchable activities exist,
 * but the only way in is com.dashine.hidcommunication. This exposes them, plus
 * a filesystem browser, on the TV using the light gun as a pointer.
 *
 * Runs as a normal /data app with no special privileges, so it sees what any
 * app sees — /system, /vendor, /sdcard are readable; other apps' private data
 * is not. Nothing here needs root and nothing writes to the firmware.
 *
 * UI is built in code so the APK needs no resource table beyond the manifest.
 */
public class ExplorerActivity extends Activity {

    private static final int BG = 0xFF101018;
    private static final int FG = 0xFFE8E8F0;
    private static final int DIM = 0xFF8899AA;
    private static final int ACCENT = 0xFF22D3EE;

    private TextView header;
    private ListView list;
    private Button modeButton;
    private CursorLayout root;

    private boolean filesMode = true;
    private File cwd = new File("/");
    private final List<File> entries = new ArrayList<>();
    private final List<ResolveInfo> apps = new ArrayList<>();
    private ArrayAdapter<String> adapter;

    @Override
    protected void onCreate(Bundle saved) {
        super.onCreate(saved);

        root = new CursorLayout(this);
        root.setOrientation(LinearLayout.VERTICAL);
        root.setBackgroundColor(BG);

        LinearLayout bar = new LinearLayout(this);
        bar.setOrientation(LinearLayout.HORIZONTAL);
        bar.setPadding(24, 18, 24, 18);
        bar.setBackgroundColor(0xFF1B1B26);

        header = new TextView(this);
        header.setTextColor(ACCENT);
        header.setTextSize(TypedValue.COMPLEX_UNIT_SP, 20);
        header.setSingleLine(true);
        header.setLayoutParams(new LinearLayout.LayoutParams(0,
                ViewGroup.LayoutParams.WRAP_CONTENT, 1f));
        header.setGravity(Gravity.CENTER_VERTICAL);

        modeButton = new Button(this);
        modeButton.setText("Apps");
        modeButton.setTextSize(TypedValue.COMPLEX_UNIT_SP, 18);
        modeButton.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) { toggleMode(); }
        });

        Button upButton = new Button(this);
        upButton.setText("Up");
        upButton.setTextSize(TypedValue.COMPLEX_UNIT_SP, 18);
        upButton.setOnClickListener(new View.OnClickListener() {
            @Override public void onClick(View v) { goUp(); }
        });

        bar.addView(header);
        bar.addView(upButton);
        bar.addView(modeButton);

        list = new ListView(this);
        list.setBackgroundColor(BG);
        list.setCacheColorHint(BG);
        adapter = new ArrayAdapter<String>(this, android.R.layout.simple_list_item_1,
                new ArrayList<String>()) {
            @Override public View getView(int pos, View convert, ViewGroup parent) {
                TextView tv = (TextView) super.getView(pos, convert, parent);
                tv.setTextColor(getItem(pos).startsWith("[") ? ACCENT : FG);
                tv.setTextSize(TypedValue.COMPLEX_UNIT_SP, 19);
                return tv;
            }
        };
        list.setAdapter(adapter);
        list.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> p, View v, int pos, long id) {
                if (filesMode) {
                    onFileTap(pos);
                } else {
                    launchApp(pos);
                }
            }
        });

        root.addView(bar, new LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT, ViewGroup.LayoutParams.WRAP_CONTENT));
        root.addView(list, new LinearLayout.LayoutParams(
                ViewGroup.LayoutParams.MATCH_PARENT, 0, 1f));
        setContentView(root);

        // The system cursor is never composited on this console (see CursorLayout
        // for the evidence), so the root layout paints its own. Match the vendor
        // and refuse the system pointer on the decor view too, so there is no way
        // to end up with two.
        getWindow().getDecorView()
                .setPointerIcon(PointerIcon.getSystemIcon(this, PointerIcon.TYPE_NULL));

        showDir(new File("/"));
    }

    /** Mouse motion arrives as hover events; the gun arrives as touch. Feed both
     *  to the cursor, and pass everything through untouched. */
    @Override
    public boolean dispatchGenericMotionEvent(MotionEvent e) {
        if (root != null) {
            root.onPointer(e);
        }
        return super.dispatchGenericMotionEvent(e);
    }

    @Override
    public boolean dispatchTouchEvent(MotionEvent e) {
        if (root != null) {
            root.onPointer(e);
        }
        return super.dispatchTouchEvent(e);
    }

    private void toggleMode() {
        filesMode = !filesMode;
        modeButton.setText(filesMode ? "Apps" : "Files");
        if (filesMode) {
            showDir(cwd);
        } else {
            showApps();
        }
    }

    // ---------------------------------------------------------------- files

    private void showDir(File dir) {
        filesMode = true;
        cwd = dir;
        entries.clear();
        File[] kids = dir.listFiles();
        if (kids == null) {
            toast("Cannot read " + dir.getPath());
            kids = new File[0];
        }
        List<File> all = new ArrayList<>(Arrays.asList(kids));
        Collections.sort(all, new Comparator<File>() {
            @Override public int compare(File a, File b) {
                if (a.isDirectory() != b.isDirectory()) return a.isDirectory() ? -1 : 1;
                return a.getName().compareToIgnoreCase(b.getName());
            }
        });
        entries.addAll(all);

        List<String> rows = new ArrayList<>();
        for (File f : entries) {
            rows.add(f.isDirectory() ? "[ " + f.getName() + " ]"
                                     : f.getName() + "   " + human(f.length()));
        }
        header.setText(dir.getPath() + "   (" + rows.size() + ")");
        adapter.clear();
        adapter.addAll(rows);
        adapter.notifyDataSetChanged();
        list.setSelection(0);
    }

    private void onFileTap(int pos) {
        if (pos < 0 || pos >= entries.size()) return;
        File f = entries.get(pos);
        if (f.isDirectory()) {
            showDir(f);
        } else {
            preview(f);
        }
    }

    private void goUp() {
        if (!filesMode) { toggleMode(); return; }
        File parent = cwd.getParentFile();
        if (parent != null) showDir(parent);
    }

    /** Show the head of a file — enough to read a .prop, .rc or log. */
    private void preview(File f) {
        StringBuilder sb = new StringBuilder();
        try (BufferedReader r = new BufferedReader(new FileReader(f))) {
            String line;
            int n = 0;
            while ((line = r.readLine()) != null && n++ < 200) {
                sb.append(line).append('\n');
                if (sb.length() > 16000) break;
            }
        } catch (Exception e) {
            sb.append("cannot read: ").append(e.getMessage());
        }
        new AlertDialog.Builder(this)
                .setTitle(f.getName())
                .setMessage(sb.length() == 0 ? "(empty or binary)" : sb.toString())
                .setPositiveButton("Close", null)
                .show();
    }

    private static String human(long n) {
        if (n < 1024) return n + " B";
        if (n < 1024 * 1024) return (n / 1024) + " KiB";
        if (n < 1024L * 1024 * 1024) return (n / (1024 * 1024)) + " MiB";
        return String.format("%.1f GiB", n / (1024.0 * 1024 * 1024));
    }

    // ----------------------------------------------------------------- apps

    private void showApps() {
        apps.clear();
        PackageManager pm = getPackageManager();
        Intent main = new Intent(Intent.ACTION_MAIN, null);
        main.addCategory(Intent.CATEGORY_LAUNCHER);
        List<ResolveInfo> found = pm.queryIntentActivities(main, 0);
        Collections.sort(found, new ResolveInfo.DisplayNameComparator(pm));
        apps.addAll(found);

        List<String> rows = new ArrayList<>();
        for (ResolveInfo ri : apps) {
            rows.add(ri.loadLabel(pm) + "\n    " + ri.activityInfo.packageName);
        }
        header.setText("Launchable apps   (" + rows.size() + ")");
        adapter.clear();
        adapter.addAll(rows);
        adapter.notifyDataSetChanged();
        list.setSelection(0);
    }

    private void launchApp(int pos) {
        if (pos < 0 || pos >= apps.size()) return;
        ApplicationInfo ai = apps.get(pos).activityInfo.applicationInfo;
        Intent go = getPackageManager().getLaunchIntentForPackage(ai.packageName);
        if (go == null) {
            toast("no launch intent for " + ai.packageName);
            return;
        }
        go.addFlags(Intent.FLAG_ACTIVITY_NEW_TASK);
        try {
            startActivity(go);
        } catch (Exception e) {
            toast("failed: " + e.getMessage());
        }
    }

    private void toast(String s) {
        Toast.makeText(this, s, Toast.LENGTH_SHORT).show();
    }

    @Override
    public void onBackPressed() {
        if (filesMode && cwd.getParentFile() != null
                && !cwd.getPath().equals("/")) {
            showDir(cwd.getParentFile());
        } else {
            super.onBackPressed();
        }
    }
}
