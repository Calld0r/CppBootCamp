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
    public:
        // METHODS
        void PrintArea() { cout << this->CalcArea() << endl; }
        void PrintPerimeter() { cout << this->CalcPerimeter() << endl; }
        void SetWidth(int _width) { this->width = _width; };
        void SetHeight(int _height) { this->height = _height; };
        void SetRadius(int _radius) { this->radius = _radius; };
    protected:
        // ATTRIBUTES6
        int width{}, height{}, radius{}, area{}, perimeter{};
        // METHODS
        Shape(int _radius) { this->radius = _radius; cout; };
        Shape(int _width, int _height) { this->width = _width; this->height = _height; };
        virtual int CalcArea() = 0;
        virtual int CalcPerimeter() = 0;
};

class Rectangle : public Shape {
    private:
        // METHODS
        int CalcArea() { this->area = this->width * this->height; return this->area; };
        int CalcPerimeter() { this->perimeter = this->width * 2 + this->height * 2; return this->perimeter; };
    public:
        // METHODS
        Rectangle(int _width, int _height) : Shape(_width, _height) {};
};

// class Square : public Rectangle {
//     // METHODS
//     public:
//         Square() = default;
//         Square(int _width, int _height) { this->width = _width; this->height = _height; cout << "A Square was born" << endl; };
//         void CalcArea() { this->area = this->width * this->height; };
// };

// class Circle : public Shape {
//     // METHODS
//     public:
//         Circle() = default;
//         Circle(int _radius) { this->radius = _radius; cout << "A Circle was born" << endl; };
//         void CalcArea() { this->area = PI * radius * radius; };
// };

int main () {
    Rectangle r(10,10);
    // Circle c(5);
    // Square s(5,5);
    r.PrintArea();
    r.PrintPerimeter();
    r.SetHeight(20);

    // cout << c.area << endl;
    // c.CalcArea();
    // cout << c.area << endl;
    // cout << s.area << endl;
    // s.CalcArea();
    // cout << s.area << endl;
    return 0;
}