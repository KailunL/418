#include "write_ppm.h"
#include <fstream>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <math.h>

bool write_ppm(
        const std::string & filename,
        const std::vector<unsigned char> & data,
        const int width,
        const int height,
        const int num_channels) {
    assert(
            (num_channels == 3 || num_channels == 1) &&
            ".ppm only supports RGB or grayscale images");
    ////////////////////////////////////////////////////////////////////////////
    // Replace with your code here:
    std::ofstream file;
    file.open(filename);
    if (num_channels == 3)
        file << "P3";
    else
        file << "P2";
    file << std::endl << width << " " << height
            << " " << "255" << std::endl;

    unsigned int color = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            //color = i * width *3 + j*3;
            if (num_channels == 3) {
                file << (int)data[color] << " ";
                file << (int)data[color + 1] << " ";
                file << (int)data[color + 2] << " ";
            } else
                file << (int)data[color] << " ";
            color = color + num_channels;

            file << " ";

        }

        file << std::endl;
    }

    file.close();
    return true;
    //return false;
    ////////////////////////////////////////////////////////////////////////////
}
