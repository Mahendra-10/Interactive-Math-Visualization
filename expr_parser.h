#ifndef FN_PARSER_H
#define FN_PARSER_H

#include <iostream>
#include "expr.h"
#include <deque>
#include <string>

// ExprParser class
class ExprParser {
private:
  // private copy constructor and assignment operator 
  // value semantics are prohibited
  ExprParser(const ExprParser &);
  ExprParser &operator=(const ExprParser &);

  // helper method to see if a given string represents a literal number 
  bool literalNumber(const std::string& s);

public:
  ExprParser(); // default constructor 
  ~ExprParser(); // destructor 

  // parses an expression from input stream
  Expr *parse(std::istream &in);
  // parses the prefix expression from a deque of tokens recursively 
  Expr* parsePfxExpr(std::deque<std::string> &tokens);
};
#endif // FN_PARSER_H
