#include "Figure.hpp"

class Circle: public Figure {
private:
    double radius;
public:
    Circle(double r);
    ~Circle();

    double area() const override;
    double perimeter() const override;
    void print() const override;
};
