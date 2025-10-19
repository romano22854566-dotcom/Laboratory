#include "Rectangle.hpp"
#include <iostream>

Rectangle::Rectangle(double w,double h): width(w),height(h) {}
Rectangle::~Rectangle() {}

double Rectangle::area() const {
    return width * height;
}

double Rectangle::perimeter() const {
    return 2 * (width + height);
}

void Rectangle::print() const {
    std::cout << "������: �������������\n";
    std::cout << "������ = " << width << ", ������ = " << height << std::endl;
}
