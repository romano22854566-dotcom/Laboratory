#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>

class Figure {
public:
    virtual ~Figure() {}

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void print() const = 0;
};

#endif 
