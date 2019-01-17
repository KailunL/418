#include "rgb_to_gray.h"

void rgb_to_gray(
        const std::vector<unsigned char> & rgb,
        const int width,
        const int height,
        std::vector<unsigned char> & gray) {
    gray.resize(height * width);
    ////////////////////////////////////////////////////////////////////////////
    // Add your code here
    //i = 0.2126 r + 0.7152 g + 0.0722 b.
    ////////////////////////////////////////////////////////////////////////////
    int color1 = 0;
    int color2 = 0;
    for (int i = 0; i < height; i++) {
        
        for (int j = 0; j < width; j++) {
            gray[color2] = (unsigned char)((double)rgb[color1]*0.2126
            +(double)rgb[color1+1]*0.7152
            +(double)rgb[color1+2]*0.0722);
            color2++;
            color1 = 3 + color1;
        }
    }



}


