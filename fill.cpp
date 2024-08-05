#include <cassert>
#include "fill.h"
#include "exception.h"

// TODO: implement constructors
// constructor should accept opacity and color object struct;



// deconstructor 
Fill::~Fill() {
}

// getter
Color Fill::getColor() const {
  return color;
}

// getter
double Fill::getOpacity() const {
  return opacity;
}

// FillAbove class constructor


// FillAbove implementation
bool FillAbove::shouldFill(double x, double y) const {
  if (fun1 == nullptr) {
    throw PlotException("Invalid or nonexistent function in FillAbove");
}
  return y > fun1->get_expr()->eval(x);
}

// FillBelow class constructor


// FillBelow implementation
bool FillBelow::shouldFill(double x, double y) const {
   if (fun1 == nullptr) {
    throw PlotException("Invalid or nonexistent function in FillBelow");
}
  return y < fun1->get_expr()->eval(x);
}

// FillBetween class constructor

// FillBetween implementation
bool FillBetween::shouldFill(double x, double y) const {
   if (fun1 == nullptr && fun1 == nullptr ) {
    throw PlotException("Invalid or nonexistent function in FillBetween");
}
  double y1 = fun1->get_expr()->eval(x);
  double y2 = fun2->get_expr()->eval(x);
  return y > std::min(y1, y2) && y < std::max(y1, y2);
}






