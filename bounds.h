#ifndef BOUNDS_H
#define BOUNDS_H

// Bounds class which represents the boundaries of the plot
class Bounds {

private: // private member variables representing the bounds
  double Xmin; // min x-coordinate of the plot
  double Ymin; // min y-coordinate of the plot
  double Xmax; // max x-coordinate of the plot
  double Ymax; // max y-coordinate of the plot
  int width; // width of the plot for dimensions
  int height; // height of the plot for dimensions
  

public:

  // default constructor
  Bounds();

  // param. constructor
  Bounds(double xmin, double ymin, double xmax, double ymax, int w, int h);

  // getter functions for the private member variables representing the bounds
  // these functions allow the program to access the bounds and dimensions without modifying them
  double getXmin() const;
  double getYmin() const;
  double getXmax() const;
  double getYmax() const;
  int getWidth() const;
  int getHeight() const;
};

#endif // BOUNDS_H
