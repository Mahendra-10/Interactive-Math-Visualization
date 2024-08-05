#ifndef FILL_H
#define FILL_H

#include <string>
#include "color.h"
#include "func.h"
#include "image.h"

// abstract base class
class Fill {
  private:
    Color color;
    double opacity;

  public:
    // constructor 
    Fill(const Color&colorFill, double opacityFill) : color(colorFill), opacity(opacityFill){}

    // virtual destructor 
    ~Fill();

    /* Getters */
    Color getColor()const;
    double getOpacity() const;

    // pure virtual function which indicates whether a point should be filled
    virtual bool shouldFill(double x, double y) const = 0;
};

// FillAbove class
class FillAbove: public Fill{
  private:
  const Function *fun1; // pointer to the function (based on the type of fill)
  Color color;

  public:
   bool shouldFill(double x, double y) const override;

   FillAbove(Color color, double Opacity, const Function* fun1): 
   Fill(color, Opacity), fun1(fun1) {}
};

// FillBelow class 
class FillBelow: public Fill{
  private:
    const Function* fun1;
    Color color;

  public:
    bool shouldFill(double x, double y) const override;

    // constructor 
    FillBelow(Color color, double Opacity, const Function* fun1): 
    Fill(color, Opacity), fun1(fun1) {}
};

// FillBetween class
class FillBetween: public Fill{
  private:
  const Function* fun1;
  const Function* fun2;
  Color color;

  public:
    bool shouldFill(double x, double y) const override;
    FillBetween(Color color, double Opacity, const Function* fun1,const  Function* fun2): 
    Fill(color, Opacity), fun1(fun1), fun2(fun2){}

};

#endif // FILL_H
