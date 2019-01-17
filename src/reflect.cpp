#include "reflect.h"

void reflect(
        const std::vector<unsigned char> & input,
        const int width,
        const int height,
        const int num_channels,
        std::vector<unsigned char> & reflected) {
    reflected.resize(width * height * num_channels);
    ////////////////////////////////////////////////////////////////////////////
    // Add your code here
    ////////////////////////////////////////////////////////////////////////////


    int color1 = width * num_channels - num_channels;
    int color2 = 0;

    for (int i = 0; i < height; i++) {
        color1 = width * num_channels * (i + 1) - num_channels;
        for (int j = 0; j < width; j++) {
            for (int channel = 0; channel < num_channels; channel++) {
                reflected[color1+channel] = input[color2+channel];
                //reflected[color2+channel] = input[color2+channel];
            }
            color1 = color1-num_channels;
            color2 = num_channels + color2;
        }
    }




}
