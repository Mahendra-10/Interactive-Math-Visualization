#include <cassert>
#include "bounds.h"
#include "plot.h"
#include "exception.h"

Plot::Plot() {
//set width and height to zero

}

Plot::~Plot()
{
  // TODO: delete dynamically-allocated objects
  //delete the functions

}

void Plot::addBounds(const Bounds& newBounds) {
    if (newBounds.getXmin() >= newBounds.getXmax() || newBounds.getYmin() >= newBounds.getYmax()) {
        throw PlotException("Invalid plot bound");
    }
  bound = newBounds;
}

void Plot::addColor(Color color, int position){

  if (position < 0 || position >= colors.size()) {
        throw PlotException("Invalid color position");
    }

  colors.at(position) = color;
}
void Plot::addColor(Color color){
  colors.push_back(color);
}

void Plot::addFunctions(Function *function) {
  functions.push_back(function);
}

void Plot::addFill(Fill &fill, int position) {
  fills.at(position) = &fill;
}

void Plot::addFill(Fill *fill) {
  fills.push_back(fill);
}

Color Plot::getColor(int position) {
  return colors.at(position);
}

 Function* Plot::getFunction (int position) {
  return functions.at(position);
}

const Fill* Plot::getFill(int position){
  return fills.at(position);
}

Bounds Plot::getBounds() {
  return bound;
}

int Plot::getFuncPosition(string funcName){
  for(int i=0; i < (int)functions.size(); i++){
    if (functions[i]->get_name() == funcName)
      return i;
  }
  return -1;
}

/*
vector<Fill*> getFills(){

}
*/
vector<Fill*> *Plot::getFills() {
    return &fills;
}

vector<Function*> *Plot::getFunctionss() {
    return &functions;
}

