#include "simulate_bayer_mosaic.h"

void simulate_bayer_mosaic(
        const std::vector<unsigned char> & rgb,
        const int & width,
        const int & height,
        std::vector<unsigned char> & bayer) {
    bayer.resize(width * height);
    ////////////////////////////////////////////////////////////////////////////
    // Add your code here
    ////////////////////////////////////////////////////////////////////////////
    int color1 = 0;
    int color2 = 0;

    int channel = 0;
    int up = 1;
    int left = 1;
    for (int i = 0; i < height; i++) {
        int left = 1;
        for (int j = 0; j < width; j++) {
            color1 = 3 * width * i + 3 * j;
            color2 = width*i+j;
            if (left == up)//top left green
                channel = 1;
            else if (left == 1 && up == 0) //red
                channel = 0;
            else
                channel = 2;

            bayer[color2] = rgb[color1 + channel];
            //reflected[color2+channel] = input[color2+channel];

            if (left == 0)
                left++;
            else
                left--;

        }

        if (up == 0)
            up++;
        else
            up--;


    }


}
