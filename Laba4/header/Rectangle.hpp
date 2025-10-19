#include "Figure.hpp"

class Rectangle: public Figure {
private:
    double width;
    double height;
public:
    Rectangle(double w,double h);
    ~Rectangle();

    double area() const override;
    double perimeter() const override;
    void print() const override;
};

