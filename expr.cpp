#include <cmath>

#include "exception.h" // include exception header file

#include "expr.h" // include expr header file

#include "iostream" // include input/output stream

// Expr (base class)
Expr::Expr() {} // default constructor 

// deconstructor for Expr
Expr::~Expr() {
  // deallocate child nodes (if any)
}

// adds child node to Expr
// child is a pointer to the child Expr object that will be added
void Expr::addChild(Expr * child) {
  children.push_back(child);
}

// evaluates SinExpr
// if the number of children isn't exactly 1, an exception is thrown
// returns sin of the evaluated child Expr
double SinExpr::eval(double x) const {
  if (children.size() != 1) {
    throw PlotException("Wrong number of arguments for sin function");
  }

  double res = children.at(0) -> eval(x);
  return sin(res);
}

// evaluates CosinExpr
// if the number of children isn't exactly 1, an exception is thrown
// returns cosine of the evaluated child Expr
double CosinExpr::eval(double x) const {
  if (children.size() != 1) {
    throw PlotException("Wrong number of arguments for cos function");
  }
  double res = children.at(0) -> eval(x);
  return cos(res);
}

// evaluates XExpr
// returns the input x value 
double XExpr::eval(double x) const {
  return x;
}

// evaluates PlusExpr
// if number of children is 0, returns 1 otherwise,
// returns the sum of all evaluated child Expr 
double PlusExpr::eval(double x) const {
  if(children.size() == 0)
    return 0;

  double sum = 0;
  for (int i = 0; i < children.size(); i++) {
    sum += children.at(i) -> eval(x);
  }
  return sum;
}

// evaluates MultiExpr 
// if number of children is 0, returns 1 otherwise,
// returns the product of all evaluated child Expr 
double MultiExpr::eval(double x) const {
  if(children.size() == 0)
    return 1;

  double mult = 1;
  for (int i = 0; i < children.size(); i++) {
    mult *= children.at(i) -> eval(x);
  }
  return mult;
}

// evaluates LiteralNumExpor
// returns the literal number that is stored
double LiteralNumExpor::eval(double x) const {
  return literaN;
}

// evaluates PiExpr
// returns the value of pi
double PiExpr::eval(double x) const {
  return M_PI;
}

// evaluates DivExpr
// if number of children isn't 2, an exception is thrown
// if the divisor is 0, an exception is thrown (cannot div by 0)
// returns the quotient of dividing first child by second child
double DivExpr::eval(double x) const {
  if (children.size() != 2) {
    throw PlotException("Wrong number of arguments for div function");
  }
  double divisor = children.at(1) -> eval(x);
  if (divisor == 0) {
    throw PlotException("Divison by zero");
  }
  double res = children.at(0) -> eval(x) / children.at(1) -> eval(x);
  return res;
}

// evaluates MinusExpr
// if number of children is not 2, an exception is thrown
// returns the result of subtracting second child from first child
double MinusExpr::eval(double x) const {
  if (children.size() != 2) {
    throw PlotException("Wrong number of arguments for minus function");
  }
  double res = children.at(0) -> eval(x) - children.at(1) -> eval(x);
  return res;
}
LiteralNumExpor::LiteralNumExpor(const double n) {
  literaN = n;
}
