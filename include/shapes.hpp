#ifndef SHAPES_HPP_
#define SHAPES_HPP_

#include <vector>

class Shape {
public:
    Shape(double x, double y) : x_(x), y_(y) {}

    virtual double area() const = 0;

    virtual ~Shape() = default;

private:
    double x_;
    double y_;
};

double calculate_total_area(const std::vector<Shape*>& shapes);

class Square : public Shape {
public:
    Square(double x, double y, double side) : Shape(x, y), _side(side) {}

    double area() const override { return _side * _side; }

    ~Square() override = default;

private:
    double _side;
};

const double PI = 3.141592;

class Circle : public Shape {
public:
    Circle(double x, double y, double radius) : Shape(x, y), _radius(radius) {}

    double area() const override { return PI * _radius * _radius; }

    ~Circle() override = default;

private:
    double _radius;
};

#endif /* SHAPES_HPP_ */
