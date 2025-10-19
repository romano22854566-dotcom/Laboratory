#include "Figure.hpp"

class Trapezoid: public Figure {
private:
    double a,b,c,d,h; 
public:
    Trapezoid(double base1,double base2,double side1,double side2,double height);
    ~Trapezoid();

    double area() const override;
    double perimeter() const override;
    void print() const override;
};


