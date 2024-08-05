#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <stdexcept>
#include <string>

// note that the compiler generates the copy constructor and assignment operator

// PlotException class (derived from std::runtime_error)
// handles exceptions when it comes to plotting
class PlotException : public std::runtime_error {
public:
  // constructor for PlotException
  PlotException(const std::string &msg);
  // copy constructor for PlotException
  PlotException(const PlotException &other);
  // deconstructor for PlotException
  ~PlotException();

};

#endif // EXCEPTION_H
