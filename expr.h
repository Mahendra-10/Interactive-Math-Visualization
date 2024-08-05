#ifndef EXPR_H
#define EXPR_H

#include <vector>

// Base expression class
class Expr {
private:
  // private copy constructor and assignment operator (prevents value copying)
  // value semantics are prohibited
  Expr(const Expr &);
  Expr &operator=(const Expr &);

public:
  // vector that stores child Expr pointers (for tree structure)
  std::vector<Expr *> children;  

  // adds a child Expr
  // child is a pointer to the child Expr object
  void addChild(Expr* child);
 
  Expr(); // default constructor 

  virtual ~Expr(); // virtual destructor (for cleanup in derived classes)

  // pure virtual function that evaluates the expression with a specific 'x' value
  // this must be used by all derived classes
  virtual double eval(double x) const = 0;

};

// derived sine expression class
class SinExpr: public Expr {
 double eval(double x) const override;
};

// derived cosine expression class
class CosinExpr:public Expr {
 double eval(double x) const override;
};

// derived plus expression class
class PlusExpr:public Expr {
 double eval(double x) const override;
};

// derived minus expression class
class MinusExpr:public Expr {
 double eval(double x) const override;
};

// derived multiplication expression class
class MultiExpr:public Expr {
 double eval(double x) const override;
};

// derived pi expression class
class PiExpr:public Expr {
 double eval(double x) const override;
};

// derived variable 'x' class
class XExpr:public Expr {
 double eval(double x) const override;
};

// derived division expression class
class DivExpr:public Expr {
 double eval(double x) const override;
};

// derived literal numeric expression class
class LiteralNumExpor: public Expr {
  double literaN; // the literal number stored 
public:
  // constructor 
  // n - literal number to store in the expression
  LiteralNumExpor(const double n);

   double eval(double x) const override; // returns the stored literal number
};


#endif // EXPR_H
