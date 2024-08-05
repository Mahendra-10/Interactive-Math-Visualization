#ifndef COLOR_H
#define COLOR_H

#include <cstdint>
#include <cassert>

// Color struct represents a color in terms of RGB values
struct Color {
  public: 
  // public member variables r (red), g (green), and b (blue)
  // each value ranges from 0-255
  uint8_t r, g, b;

  // default constructor 
  // initializes the color to black (0, 0, 0) 
  Color(): r(0), g(0), b(0) {}

  // param constructor
  // initializes the color with specific values for r, g, and b
  Color(uint8_t red, uint8_t green, uint8_t blue) : r(red), g(green), b(blue) {}

};


#endif // COLOR_H
