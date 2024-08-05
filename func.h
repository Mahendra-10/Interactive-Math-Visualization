#ifndef FUNC_H
#define FUNC_H

#include <string>
#include "expr.h"
#include "color.h"

// Function class
class Function {
private:
  // a function has a name and an expression computing its value (given x)
  std::string m_name;
  Expr *m_expr; // ptr to Expr object representing the expr that defines the function
  Color color;
  // copy constructor and assignment operator 
  // value semantics prohibited
  Function(const Function &);
  Function &operator=(const Function &);

public:
  // constructor 
  Function(const std::string &name, Expr *expr);
  // destructor 
  ~Function();
Color getColor(); // gets color associated with the function
// sets the color of the function
void setColor(Color color){
  this->color = color;
}
// implemenent this in reader.cpp 
  std::string get_name() const { 
    return m_name; 
    }
  Expr *get_expr() const       { 
    return m_expr; 
    }
};

#endif // FUNC_H
