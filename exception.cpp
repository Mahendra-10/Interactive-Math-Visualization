#include "exception.h" // include exception header file

// constructor for PlotException
// initializes PlotException with a specific runtime error (msg)
PlotException::PlotException(const std::string &msg)
  : std::runtime_error(msg) {
}

// copy constructor for PlotException
// creates a copy of the existing PlotException but
// with 'other' (reference to another PlotException object)
PlotException::PlotException(const PlotException &other)
  : std::runtime_error(other) {
}

// deconstructor for PlotException
// it is empty because we did not use any dynamic resources
// all necessary cleanup can be handled with the base deconstructor
PlotException::~PlotException() {
}
