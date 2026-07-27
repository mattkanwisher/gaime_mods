package nu.hyperworks.gaimeexplorer;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.Path;
import android.view.MotionEvent;
import android.view.PointerIcon;
import android.widget.LinearLayout;

/**
 * Root layout that paints its own mouse pointer.
 *
 * This console never draws the system cursor. Everything upstream of drawing is
 * healthy — the mouse enumerates as CURSOR|EXTERNAL in POINTER mode, the pointer
 * position tracks the full 1920x1080 range, and hover events arrive with real
 * coordinates — but SurfaceFlinger has no Sprite layer at all, so the cursor
 * surface is never created and nothing is composited.
 *
 * The vendor hit the same wall and went around it. GaimeCalibration kills the
 * system pointer outright in three places, all with PointerIcon.TYPE_NULL:
 *
 *     GridRelativeLayout.onResolvePointerIcon() -> getSystemIcon(ctx, 0)
 *     getWindow().getDecorView().setPointerIcon(getSystemIcon(this, 0))
 *     imageView.setPointerIcon(getSystemIcon(this, 0))
 *
 * and the games paint their own crosshair from Unity. So we do the same: refuse
 * the system pointer so there can never be two, and draw ours from the hover
 * coordinates we already receive.
 *
 * Overriding onResolvePointerIcon (rather than only calling setPointerIcon) is
 * what makes it stick — resolution walks down to the view under the pointer, so
 * a child with its own icon would otherwise win.
 */
public class CursorLayout extends LinearLayout {

    /** Height of the drawn arrow in dp. The stock mdpi arrow is 28px, which is
     *  close to invisible across a room on a 1080p TV — this is deliberately
     *  larger. */
    private static final float ARROW_DP = 48f;

    /** Classic pointer outline, in a 12 x 19 unit box, scaled at draw time. */
    private static final float[][] ARROW = {
        {0f, 0f}, {0f, 16.5f}, {3.9f, 12.9f}, {6.4f, 18.6f},
        {8.9f, 17.5f}, {6.5f, 12.0f}, {11.2f, 11.6f},
    };

    private final Path path = new Path();
    private final Paint fill = new Paint(Paint.ANTI_ALIAS_FLAG);
    private final Paint edge = new Paint(Paint.ANTI_ALIAS_FLAG);

    private float cx, cy;
    private boolean haveCursor;
    private float w, h;

    public CursorLayout(Context ctx) {
        super(ctx);
        setWillNotDraw(false);

        float density = getResources().getDisplayMetrics().density;
        float scale = (ARROW_DP * density) / 19f;
        w = 12f * scale;
        h = 19f * scale;

        path.moveTo(ARROW[0][0] * scale, ARROW[0][1] * scale);
        for (int i = 1; i < ARROW.length; i++) {
            path.lineTo(ARROW[i][0] * scale, ARROW[i][1] * scale);
        }
        path.close();

        fill.setStyle(Paint.Style.FILL);
        fill.setColor(0xFFFFFFFF);
        // A dark drop shadow keeps the white arrow legible over light content.
        fill.setShadowLayer(4f * density, 0f, 2f * density, 0x99000000);
        setLayerType(LAYER_TYPE_SOFTWARE, null);   // shadowLayer needs software

        edge.setStyle(Paint.Style.STROKE);
        edge.setColor(0xFF000000);
        edge.setStrokeWidth(1.6f * density);
        edge.setStrokeJoin(Paint.Join.ROUND);
    }

    /**
     * Feed a pointer position in *screen* coordinates.
     *
     * Raw coordinates are used rather than event.getX()/getY() because this view
     * sits below the status bar, so window-relative coordinates would draw the
     * arrow offset by the inset.
     */
    public void onPointer(MotionEvent e) {
        int[] origin = new int[2];
        getLocationOnScreen(origin);
        float nx = e.getRawX() - origin[0];
        float ny = e.getRawY() - origin[1];
        if (haveCursor && nx == cx && ny == cy) {
            return;
        }
        // Repaint only the union of where it was and where it is going.
        if (haveCursor) {
            invalidate((int) cx - 2, (int) cy - 2,
                       (int) (cx + w) + 8, (int) (cy + h) + 8);
        }
        cx = nx;
        cy = ny;
        haveCursor = true;
        invalidate((int) cx - 2, (int) cy - 2,
                   (int) (cx + w) + 8, (int) (cy + h) + 8);
    }

    /** Drawn after children so the arrow is always on top, and without adding a
     *  view that could swallow input. */
    @Override
    protected void dispatchDraw(Canvas canvas) {
        super.dispatchDraw(canvas);
        if (!haveCursor) {
            return;
        }
        int save = canvas.save();
        canvas.translate(cx, cy);
        canvas.drawPath(path, fill);
        canvas.drawPath(path, edge);
        canvas.restoreToCount(save);
    }

    @Override
    public PointerIcon onResolvePointerIcon(MotionEvent e, int pointerIndex) {
        // TYPE_NULL. Same call the vendor's GridRelativeLayout makes. If the
        // system sprite is ever fixed, this is the line to change to TYPE_ARROW
        // (and then stop drawing our own).
        return PointerIcon.getSystemIcon(getContext(), PointerIcon.TYPE_NULL);
    }
}
