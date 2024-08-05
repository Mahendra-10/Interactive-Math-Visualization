#ifndef PLOT_H
#define PLOT_H

#include <vector>
#include <map>
#include <string>
#include "bounds.h"
#include "image.h"
#include "func.h"
#include "fill.h"

using namespace std;
class Plot {
  private:
    Bounds bound;
    vector<Function*> functions;
    vector<Fill*> fills;
    vector<Color> colors;

    Plot(const Plot &);
    Plot &operator=(const Plot &);

  public:
    Plot();
    ~Plot();

    /*  Setter methods  */
    void addBounds(const Bounds& newBounds); //creates bounds for plots
    void addColor(Color color, int position);//creates a new color at the specified location
    void addColor(Color color); 
    void addFunctions(Function *function); //creates a new function at the specified location
    void addFill(Fill &fill, int position); //creates a new fill at the specified location
    void addFill(Fill *fill); //creates a new fill at the specified location

    /* Getter methods */
      Color getColor(int position) ; //returns Color in colors at index position
      Function* getFunction (int position); //returns Function in functions at index position
      const Fill* getFill(int position); //returns Fill in fills at index position
      Bounds getBounds(); //returns Bounds 
      int getFuncPosition(string funcName);
      vector<Fill*>*getFills();  //clear these
      vector<Function*>*getFunctionss();
};

#endif // PLOT_H
