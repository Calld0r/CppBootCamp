/*
================================================================================================================

Implement an interface for shape, and derive circle, triangle, rectangle, square as children. Overload all three
comparison operators to compare the shapes based on their area -- if equal then their perimeter should be
considered. Only, and if only both area and perimeter are equal then the objects should be considered equal.

================================================================================================================
*/

#include <iostream>
#include <string>
#include <math.h> 
#define PI 3.14159265359

using namespace std;

class Shape {
    public:
        // Methods
        void InitObj() { this->CalcArea(); this->CalcPerimeter(); }
        int GetArea() { return this->CalcArea(); }
        int GetPerimeter() { return this->CalcPerimeter(); }
        void SetWidth(int _width) { this->width = _width; }
        void SetHeight(int _height) { this->height = _height; }
        void SetRadius(int _radius) { this->radius = _radius; }
        bool operator == (Shape& _shape) { if ( this->area == _shape.area) { return true; } return false; }
        bool operator != (Shape& _shape) { if ( this->area != _shape.area) { return true; } return false; }
        bool operator > (Shape& _shape) { if ( this->area > _shape.area) { return true; } return false; }
    protected:
        // Attributes
        int width{}, height{}, radius{}, sideA{}, sideB{}, sideC{}, area{}, perimeter{};
        // Methods
        Shape(int _radius) { this->radius = _radius; }
        Shape(int _width, int _height) { this->width = _width; this->height = _height; }
        Shape(int _sideA, int _sideB, int _sideC) { this->sideA = _sideA; this->sideB = _sideB; this->sideC = _sideC; }
        virtual int CalcArea() = 0;
        virtual int CalcPerimeter() = 0;
};

class Rectangle : public Shape {
    private:
        // Methods
        int CalcPerimeter() { this->perimeter = this->width * 2 + this->height * 2; return this->perimeter; }
        int CalcArea() { this->area = this->width * this->height; return this->area; }
    public:
        // Methods
        Rectangle(int _width, int _height) : Shape(_width, _height) {}
};

class Square : public Shape {
    private:
        // Methods
        int CalcArea() { this->area = this->width * this->height; return this->area; }
        int CalcPerimeter() { this->perimeter = this->width * 2 + this->height * 2; return this->perimeter; }
    public:
        // Methods
        Square(int _width, int _height) : Shape(_width, _height) {}
};

class Circle : public Shape {
    private:
        // Methods
        int CalcArea() { this->area = PI * radius * radius; return this->area; }
        int CalcPerimeter() { this->perimeter = PI * 2 * this->radius; return this->perimeter; }
    public:
        // Methods
        Circle(int _radius) : Shape(_radius) {}
};

class Triangle : public Shape {
    private:
        // Methods
        int CalcArea() {
            int s = ( this->sideA + this->sideB + this->sideC ) / 2;
            this->area = sqrt( s * (s - this->sideA) * (s - this->sideB) * (s - this->sideC) );
            return this->area;
        }
        int CalcPerimeter() { this->perimeter = ( this->sideA + this->sideC + this->sideC ) / 2; return this->perimeter; }
    public:
        // Methods
        Triangle(int _sideA, int _sideB, int _sideC) : Shape(_sideA, _sideB, _sideC) {}
};

int main () {
    Square s1(8,8);
    s1.InitObj();

    Rectangle r1(8,8);
    r1.InitObj();

    Circle c1(12);
    c1.InitObj();

    Triangle t1(3,5,4);
    t1.InitObj();

    // Compare Square with Rectangle
    if ( s1 == r1) {
        cout << "The object area matches!" << endl;
        if (s1.GetPerimeter() == r1.GetPerimeter()) {
            cout << "The objects peremiter matches too!" << endl << "The objects are equal!" << endl;
        };
    } else { cout << "Square and Rectangle do not match" << endl; }

    // Compare Square with Circle
    if ( s1 == c1) {
        cout << "The object area matches!" << endl;
        if (s1.GetPerimeter() == c1.GetPerimeter()) {
            cout << "The objects peremiter matches too!" << endl << "The objects are equal!" << endl;
        };
    } else { cout << "Square and Circle do not match" << endl; }

    // Compare Square with Triangle
    if ( s1 == t1) {
        cout << "The object area matches!" << endl;
        if (s1.GetPerimeter() == t1.GetPerimeter()) {
            cout << "The objects peremiter matches too!" << endl << "The objects are equal!" << endl;
        };
    } else { cout << "Square and Triangle do not match" << endl; }

    // Compare Rectangle with Circle
    if ( r1 == c1) {
        cout << "The object area matches!" << endl;
        if (r1.GetPerimeter() == c1.GetPerimeter()) {
            cout << "The objects peremiter matches too!" << endl << "The objects are equal!" << endl;
        };
    } else { cout << "Rectangle and Circle do not match" << endl; }

    // Compare Rectangle with Triangle
    if ( r1 == t1) {
        cout << "The object area matches!" << endl;
        if (r1.GetPerimeter() == t1.GetPerimeter()) {
            cout << "The objects peremiter matches too!" << endl << "The objects are equal!" << endl;
        };
    } else { cout << "Rectangle and Triangle do not match" << endl; }

    // Compare Circle with Triangle
    if ( c1 == t1) {
        cout << "The object area matches!" << endl;
        if (c1.GetPerimeter() == t1.GetPerimeter()) {
            cout << "The objects peremiter matches too!" << endl << "The objects are equal!" << endl;
        };
    } else { cout << "Circle and Triangle do not match" << endl; }


    return 0;
}