#pragma once
#include"libraries.h"
using namespace std;
class Quadrilateral {
protected:
    double x1, y1, x2, y2, x3, y3, x4, y4;
public:
    Quadrilateral(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
    virtual ~Quadrilateral();
    virtual double getArea() const = 0;
    virtual string getDescription() const = 0;
    void setPoints(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
};

class Trapezoid : public Quadrilateral {
public:
    Trapezoid(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
     ~Trapezoid();
     double getArea() const;
     string getDescription() const;
};

class Parallelogram : public Quadrilateral {
public:
    Parallelogram(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
     ~Parallelogram();
     double getArea() const;
     string getDescription() const;
};

class Rectangle : public Parallelogram {
public:
    Rectangle(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
     ~Rectangle();
     double getArea() const;
     string getDescription() const;
};

class Square : public Rectangle {
public:
    Square(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);
     ~Square();
     double getArea() const;
     string getDescription() const;
};
