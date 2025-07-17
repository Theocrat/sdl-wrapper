/** MAIN
 * 
 * For testing the library under development.
 * 
 * Currently, it draws a red circle inside a white space, like the flag of
 * Japan. In future it can contain something more cool.
 */

#include "sdl_wrapper.hh"

int main() {
    sdlw::SDLWrapper sdl(400, 600);
    int cx = 300, cy = 200, radius = 100;

    while(sdl.isRunning()) {
        sdl.setColor(255, 255, 255);
        sdl.clear();

        for (int x = -radius; x <= radius; x++) {
            for (int y = -radius; y <= radius; y++) {
                if (x*x + y*y <= radius*radius) {
                    sdl.setColor(255, 0, 0);
                    sdl.drawPoint(cx + x, cy + y);
                }
            }
        }

        sdl.render();
    }

    return 0;
}