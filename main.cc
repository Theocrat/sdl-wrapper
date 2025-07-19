/** MAIN
 * 
 * For testing the library under development.
 * 
 * Currently, it just shows a red ball bouncing around. Nothing too spectacular.
 */

#include "sdl_wrapper.hh"

void drawBall(sdlw::SDLWindow &sdl, int cx, int cy, int radius) {
    for (int x = -radius; x <= radius; x++) {
        for (int y = -radius; y <= radius; y++) {
            if (x*x + y*y <= radius*radius) {
                sdl.drawPoint(cx + x, cy + y);
            }
        }
    }
}

int main() {
    const int screenHeight = 600, screenWidth = 800;

    sdlw::SDLWindow sdl(screenHeight, screenWidth, "Bouncy Ball");
    int cx = screenWidth / 2, cy = screenHeight / 2, radius = 100;
    int vx = 2, vy = 2;
    int radius_by_sqrt_2 = 71;

    while(sdl.isRunning()) {
        // Background
        sdl.setColor(0, 50, 100);
        sdl.clear();

        // Ball
        sdl.setColor(221, 68, 102);
        drawBall(sdl, cx, cy, radius);
        cx += vx;
        cy += vy;
        
        // Movement of the Ball
        if (cx < radius || cx + radius > screenWidth) {
            vx = -vx;
        }
        if (cy < radius || cy + radius > screenHeight) {
            vy = -vy;
        }

        // A Line from top-left corner to the Ball
        sdl.setColor(0, 250, 100);
        sdl.drawLine({0, 0}, {cx, cy});

        // Sample Rectangle
        sdl.setColor(80, 80, 80, 80);
        sdl.fillRect({0, 0}, {cx - radius_by_sqrt_2, cy - radius_by_sqrt_2});

        // Render Command
        sdl.render();
    }

    return 0;
}