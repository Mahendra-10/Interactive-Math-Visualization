#include "func.h"

// constructor for function class
Function::Function(const std::string &name, Expr *expr)
  : m_name(name), m_expr(expr) {
}

// deallocate memory using deconstructor
// add more if we use other dynamically allocated memory 
Function::~Function() {
  delete m_expr;
}
Color Function::getColor() {
    return color;
}
