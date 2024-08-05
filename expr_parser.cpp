#include <iostream>
#include <deque>
#include <memory>
#include <sstream>
#include <string>
#include "exception.h"
#include "expr.h"
#include "expr_parser.h"

using namespace std;

// constructor for ExprParser
ExprParser::ExprParser() {}

// destructor for ExprParser
ExprParser::~ExprParser() {}

// parses the expression from the input stream
// returns a pointer to the root of the tree structure 
Expr* ExprParser::parse(std::istream& in) {
  std::deque<std::string> tokens;
  std::string token;

  // tokenize the input stream into a string deque
  while (in >> token) {
    tokens.push_back(token);
  }

  // using the tokens, we parse the prefix expression
  // this handles any parsing errors by catching PlotException
  try {
    return parsePfxExpr(tokens);
  } catch (const PlotException& e) {
    cerr << "Error: " << e.what() << endl;
    exit(EXIT_FAILURE);
  }
}

// parses the prefix expression from a deque of tokens
// builds the tree and returns the root recursively 
Expr* ExprParser::parsePfxExpr(std::deque<std::string>& tokens) {
  std::string n = tokens.front();
  tokens.pop_front();

  // handling basic expression 'x'
  if (n == "x") {
    XExpr* x = new XExpr();
    return x;
  }

  // handling basic expression 'pi'
  if (n == "pi") {
    PiExpr* pi = new PiExpr();
    return pi;
  }

  // parsing literal numbers
  if (literalNumber(n)) {
    stringstream numStream;
    numStream << n;
    double num;
    numStream >> num;
    LiteralNumExpor* literaN = new LiteralNumExpor(num);
    return literaN;
  }

  // parsing compound expressions 
  else if (n == "(") {
    n = tokens.front();
    tokens.pop_front();

    if (tokens.empty()) {
      throw PlotException("Unexpected end of expression");
    }

    Expr* expr;

    // creates an expression object based on the function token
    if (n == "sin") {
      expr = new SinExpr();
    } else if (n == "cos") {
      expr = new CosinExpr();
    } else if (n == "+") {
      expr = new PlusExpr();
    } else if (n == "-") {
      expr = new MinusExpr();
    } else if (n == "*") {
      expr = new MultiExpr();
    } else if (n == "/") {
      expr = new DivExpr();
    } else {
      throw PlotException("Invalid function");
    }

    // parse and add children recursively
    while (tokens.front() != ")") {
      Expr* e = parsePfxExpr(tokens);
      expr->addChild(e);
    }

    tokens.pop_front(); // removes the closing parenthesis 
    return expr;
  } else {
    throw PlotException("Unexpected token");
  }
  return nullptr; // return null if valid expression was not parsed
}

// checking if the given string is a literal number
bool ExprParser::literalNumber(const std::string& s) {
  std::string::const_iterator it = s.begin();
  while (it != s.end() && (std::isdigit(*it) || *it == '.')) ++it;
  return !s.empty() && it == s.end();
}
