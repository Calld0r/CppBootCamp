/*
================================================================================================================

Implement an interface for shape, and derive circle, triangle, rectangle, square as children. Overload all three
comparison operators to compare the shapes based on their area -- if equal then their perimeter should be
considered. Only, and if only both area and perimeter are equal then the objects should be considered equal.

================================================================================================================
*/

#include <iostream>
#include <string>
#define PI 3.14159265359

using namespace std;

class Shape {
    // ATTRIBUTES
    public:
        int width{}, height{}, radius{}, area{};
    // METHODS
    protected:
        void SetWidth(int _width) { this->width = _width; };
        void SetHeight(int _height) { this->height = _height; };
        void SetRadius(int _radius) { this->radius = _radius; };
        Shape() = default;
        Shape(int _radius) { this->radius = _radius; };
        Shape(int _width, int _height) { this->width = _width; this->height = _height; };
        ~Shape() { cout << "Im Dead!" << endl; };
        virtual void CalcArea() = 0;
    private:
};

class Rectangle : public Shape {
    // METHODS
    public:
        Rectangle() = default;
        Rectangle(int _width, int _height) { this->width = _width; this->height = _height; cout << "A Rectangle was born" << endl; };
        void CalcArea() { this->area = this->width * this->height; };
};

class Circle : public Shape {
    // METHODS
    public:
        Circle() = default;
        Circle(int _radius) { this->radius = _radius; cout << "A Circle was born" << endl; };
        void CalcArea() { this->area = PI * radius * radius; };
};

int main () {
    Rectangle r(10,10);
    Circle c(5);
    cout << r.area << endl;
    r.CalcArea();
    cout << r.area << endl;
    cout << c.area << endl;
    c.CalcArea();
    cout << c.area << endl;
    return 0;
}