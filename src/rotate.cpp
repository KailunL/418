#include "rotate.h"

void rotate(
        const std::vector<unsigned char> & input,
        const int width,
        const int height,
        const int num_channels,
        std::vector<unsigned char> & rotated) {
    rotated.resize(height * width * num_channels);
    ////////////////////////////////////////////////////////////////////////////
    // Add your code here
    ////////////////////////////////////////////////////////////////////////////
    int color1 = 0;
    int color2 = 0;
    for (int i = width; i > 0; i--) {
        for (int j = 0; j < height; j++) {
            color2 = j * width * num_channels + (i-1) * num_channels;
            for (int channel = 0; channel < num_channels; channel++) {
                rotated[color1+channel] =
                        input[color2 + channel];
                //reflected[color2+channel] = input[color2+channel];
            }
            color1+=num_channels;
        }
    }


}
//#include "rotate.h"
//
//void rotate(
//  const std::vector<unsigned char> & input,
//  const int width,
//  const int height,
//  const int num_channels,
//  std::vector<unsigned char> & rotated)
//{
//    rotated.resize(height*width*num_channels);
//    
//    // starting from the last column, treat each colum as the new row
//    int write = 0;
//    for (int i=width-1; i>=0; i--) {
//        for (int j=0; j<height; j++) {
//            for (int k=0; k<num_channels; k++) {
//                rotated[write++] = input[k+num_channels*(i+width*j)];
//            }
//        }
//    }
//}