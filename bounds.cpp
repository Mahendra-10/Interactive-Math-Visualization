#include "bounds.h" // include bounds header file

// default constructor for Bounds class
// all member variables are initialized to zero because 
// the bounds will be set later (currently they are unknown)
Bounds::Bounds() 
: Xmin(0), Ymin(0), Xmax(0), Ymax(0), width(0), height(0) {
  
}

// param constructor for Bounds class
// the Bounds object is initialized with specific values for xmin, ymin, etc...
Bounds::Bounds(double xmin, double ymin, double xmax, double ymax, int w, int h) 
: Xmin(xmin), Ymin(ymin), Xmax(xmax), Ymax(ymax), width(w), height(h) {
  
}

// getter for Xmin
// returns the min x-coordinate of the bound
double Bounds::getXmin() const {
  return Xmin;
}

// getter for Ymin
// returns the min y-coordinate of the bound
double Bounds::getYmin() const {
  return Ymin;
}

// getter for Xmax
// returns the max x-coordinate of the bound
double Bounds::getXmax() const {
  return Xmax;
}

// getter for Ymax
// returns the max y-coordinate of the bound
double Bounds::getYmax() const {
  return Ymax;
}

// getter for width
// returns the width of the bound
int Bounds::getWidth() const {
  return width;
}

// getter for height
// returns the height of the bound
int Bounds::getHeight() const {
  return height;
}
