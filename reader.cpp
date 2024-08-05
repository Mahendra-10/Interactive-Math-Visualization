#include <cctype>
#include <iostream>
#include <map>
#include <sstream>
#include <cstdint>
#include "color.h"
#include "exception.h"
#include "func.h"
#include "plot.h"
#include "reader.h"
#include "expr_parser.h"
#include "fill.h"
#include <string>
#include "bounds.h"


Reader::Reader() {
}

Reader::~Reader() {
}

void Reader::read_input(std::istream &in, Plot &plot) {
  string fileinfo;

  double Xmin;
  double Ymin;
  double Xmax;
  double Ymax;
  int width;
  int height;
  string funcName;
  string funcName1;
  string funcName2;

  int r;
  int g;
  int b;
  
  double opacity;
  
  ExprParser parseEqua;
  Expr *exprPtr; 

  while (in >> fileinfo) {
   
     //When plot is read it takes in all the following data values
     //Then creates bounds using these data value and adds them to plot.
    if (fileinfo == "Plot") {
      in >> Xmin >> Ymin >> Xmax >> Ymax >> width >> height;
      Bounds bound(Xmin , Ymin, Xmax, Ymax, width, height);
      plot.addBounds(bound);
    }
    
    // When function is read it creates a function from the provided information
    // thrn dds the function to the vector of function in plot
    else if (fileinfo == "Function") {
      in >> funcName;
      string line;
      std:: getline(in, line);
      stringstream ss(line);
     
      exprPtr = parseEqua.parse(ss);
      Function *fp = new Function(funcName, exprPtr);
      plot.addFunctions(fp);
    }

    // When Color is read it sets the function with the name provided with that color
    // if function already has color throws exception
    // if r g b value aren't able to be converted to color throws exception
    // else sets function color to provided color
    else if (fileinfo == "Color") {

      if(!(in >> funcName >> r >> g >> b)) {
        throw PlotException("Invalid input type");
      }
    
      if(r > 255 || r < 0)
        throw PlotException("Invalid r value");

      if(g > 255 || g < 0)
        throw PlotException("Invalid g value");
      
      if(b > 255 || b < 0)
        throw PlotException("Invalid b value");

      Color color(r,g,b);
      int position = plot.getFuncPosition(funcName);

      if((plot.getFunction(position)->getColor().r 
        || plot.getFunction(position)->getColor().g
        || plot.getFunction(position)->getColor().b)) {
        throw PlotException("function already has a color");
      }

      plot.addColor(color);
      plot.getFunction(position)->setColor(color);
      //if i want color do getColor
    }

    // When fillabove is read it creates and instances of fillabove which is a inhertiant of fill
    // and adds this instance of fillabove to the plot.
    else if (fileinfo == "FillAbove") {
      in >> funcName >> opacity >> r >> g >> b;
   Function const *func =  plot.getFunction(plot.getFuncPosition(funcName));
      Fill *fill = new FillAbove(Color(r,g,b), opacity, func);
       plot.addFill(fill);
    }

    // When fillabove is read it creates and instances of fillbelow which is a inhertiant of fill
    // and adds this instance of fillbelow to the plot.
    else if (fileinfo == "FillBelow") {
      in >> funcName >> opacity >> r >> g >> b;
       Function const *func =  plot.getFunction(plot.getFuncPosition(funcName));
     Fill *fill = new FillBelow(Color(r,g,b), opacity, func);
     plot.addFill(fill);
    }

    // When fillabove is read it creates and instances of fillbetween which is a inhertiant of fill
    // and adds this instance of fillbetween to the plot.
    else if (fileinfo == "FillBetween") {
      in >> funcName1 >> funcName2 >> opacity >> r >> g >> b;
      std:: cout << "Opacity here:    "<< opacity << std:: endl;
      Function const *func1 = plot.getFunction(plot.getFuncPosition(funcName1));
      Function const *func2 = plot.getFunction(plot.getFuncPosition(funcName2));
      Fill *fill = new FillBetween(Color(r, g, b), opacity, func1, func2);
      plot.addFill(fill);
    }
  }
}
