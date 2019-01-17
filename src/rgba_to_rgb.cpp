#include "rgba_to_rgb.h"

void rgba_to_rgb(
  const std::vector<unsigned char> & rgba,
  const int & width,
  const int & height,
  std::vector<unsigned char> & rgb)
{
  rgb.resize(height*width*3);
  ////////////////////////////////////////////////////////////////////////////
  // Add your code here
  ////////////////////////////////////////////////////////////////////////////
  
  int color1=0;
  int color2=0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++){          
            rgb[color1]=rgba[color2];
            rgb[color1+1]=rgba[color2+1];
            rgb[color1+2]=rgba[color2+2];
            color1=color1+3;
            color2=color2+4;        
        }
    }
  
  
  
}
