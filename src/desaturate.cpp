#include "desaturate.h"
#include "hsv_to_rgb.h"
#include "rgb_to_hsv.h"

void desaturate(
        const std::vector<unsigned char> & rgb,
        const int width,
        const int height,
        const double factor,
        std::vector<unsigned char> & desaturated) {
    desaturated.resize(rgb.size());
    ////////////////////////////////////////////////////////////////////////////
    // Add your code here
    ////////////////////////////////////////////////////////////////////////////


    int color1 = 0;
    int color2 = 0;
    double red = 0;
    double blue = 0;
    double green = 0;
    double h = 0;
    double s = 0;
    double v = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            color1 = 3 * width * i + 3 * j;
            red = (double) (((double) (rgb[color1])) / 255);
            green = (double) (((double) (rgb[color1 + 1])) / 255);
            blue = (double) (((double) (rgb[color1 + 2])) / 255);

            rgb_to_hsv(red, green, blue, h, s, v);
            s=s*factor;
            hsv_to_rgb(h, s, v, red, green, blue);

            desaturated[color1] = (unsigned char) (255 * red);
            desaturated[color1 + 1] = (unsigned char) (255 * green);
            desaturated[color1 + 2] = (unsigned char) (255 * blue);
        }
    }
}
