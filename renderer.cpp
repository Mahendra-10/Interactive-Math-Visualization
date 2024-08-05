#include <iostream>

#include <cmath>

#include <cassert>

#include <memory>

#include <vector>

#include "exception.h"

#include "func.h"

#include "renderer.h"

#include "image.h"


//#define DEBUG_FILL
//#define DEBUG_PLOT

Renderer::Renderer(Plot & plot): m_plot(plot), m_img(nullptr) {}

Renderer::~Renderer() {
  // Note: the Renderer object does not "own" the Image object,
  // since thrender() member function transfers ownership of
  // the Image object to the caller (in the main function)

}

Image * Renderer::render() {
  int width = m_plot.getBounds().getWidth();
  int height = m_plot.getBounds().getHeight();

  // the unique_ptr will take care of deleting the Image object
  // if an exception is thrown
  std::unique_ptr < Image > img(new Image(width, height));
  m_img = img.get();

  Bounds bound = m_plot.getBounds();

  // for the fills
  for (int i = 0; i < bound.getHeight(); ++i) {
    for (int j = 0; j < bound.getWidth(); ++j) {
      for (vector < Fill * > ::iterator it = m_plot.getFills() -> begin(); it != m_plot.getFills() -> end(); ++it) {
        double ColX = bound.getXmin() + (static_cast < double > (j) / width) * (bound.getXmax() - bound.getXmin());
        double RowY = bound.getYmin() + ((height - 1 - i) / static_cast < double > (height)) * (bound.getYmax() - bound.getYmin());

        if (( * it) -> shouldFill(ColX, RowY)) {
      
          Color colorold = m_img -> getPixelsatlocation(i, j);
          Color colorNew = ( * it) -> getColor();
          

          double Opacity = ( * it) -> getOpacity();
          

          int newRed = (1 - Opacity) * colorold.r + Opacity * colorNew.r;
          int newGreen = (1 - Opacity) * colorold.g + Opacity * colorNew.g;
          int newBlue = (1 - Opacity) * colorold.b + Opacity * colorNew.b;
          Color newColor(newRed, newGreen, newBlue);
          m_img -> set_pixels(i, j, newColor);
        }
      }
    }
  }

  for (vector < Function * > ::const_iterator it = m_plot.getFunctionss() -> begin(); it != m_plot.getFunctionss() -> end(); ++it) {
            
       
    for (int j = 0; j < bound.getWidth(); ++j) {
      double ColX = bound.getXmin() + (static_cast < double > (j) / width) * (bound.getXmax() - bound.getXmin());

      if (( * it) -> get_expr() == nullptr) {

      }
      //handles the center
      double yVal = ( * it) -> get_expr() -> eval(ColX);
      int pixelRowI = height - 1 - static_cast < int > (floor((yVal - bound.getYmin()) / (bound.getYmax() - bound.getYmin()) * height));
      // Check if the pixel is within the bounds of the image and x-coordinate is within range

      //center
      if (pixelRowI >= 0 && pixelRowI < height) {
        (m_img -> set_pixels(pixelRowI, j, ( * it) -> getColor()));

      }
      //handle right
      if (pixelRowI >= 0 && pixelRowI < height && j + 1 < width) {
        (m_img -> set_pixels(pixelRowI, j + 1, ( * it) -> getColor()));

      }
      //handle left
      if (pixelRowI >= 0 && pixelRowI < height && j - 1 >= 0) {
        (m_img -> set_pixels(pixelRowI, j - 1, ( * it) -> getColor()));

      }
      //handle above
      if (pixelRowI - 1 >= 0 && pixelRowI - 1 < height) {
        (m_img -> set_pixels(pixelRowI - 1, j, ( * it) -> getColor()));

      }
      //handle below
      if (pixelRowI + 1 >= 0 && pixelRowI + 1 < height) {
        (m_img -> set_pixels(pixelRowI + 1, j, ( * it) -> getColor()));

      }
    }
  }
  return img.release();
}