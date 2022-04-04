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
        string GetName() { return this->name; }
        int GetArea() { return this->CalcArea(); }
        int GetPerimeter() { return this->CalcPerimeter(); }
        void SetWidth(int _width) { this->width = _width; }
        void SetHeight(int _height) { this->height = _height; }
        void SetRadius(int _radius) { this->radius = _radius; }
        bool operator == (Shape& _shape) { if ( this->area == _shape.area /*&& this->perimeter == _shape.perimeter*/) { return true; } return false; }
        bool operator != (Shape& _shape) { if ( this->area != _shape.area) { return true; } return false; }
        bool operator > (Shape& _shape) { if ( this->area > _shape.area) { return true; } return false; }
    protected:
        // Attributes
        string name;
        int width{}, height{}, radius{}, sideA{}, sideB{}, sideC{}, area{}, perimeter{};
        // Methods
        Shape(string _name, int _radius) { this->name = _name, this->radius = _radius; }
        Shape(string _name, int _width, int _height) { this->name = _name, this->width = _width; this->height = _height; }
        Shape(string _name, int _sideA, int _sideB, int _sideC) { this->name = _name, this->sideA = _sideA; this->sideB = _sideB; this->sideC = _sideC; }
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
        Rectangle(string _name, int _width, int _height) : Shape(_name, _width, _height) {}
};

class Square : public Shape {
    private:
        // Methods
        int CalcArea() { this->area = this->width * this->height; return this->area; }
        int CalcPerimeter() { this->perimeter = this->width * 2 + this->height * 2; return this->perimeter; }
    public:
        // Methods
        Square(string _name, int _width, int _height) : Shape(_name, _width, _height) {}
};

class Circle : public Shape {
    private:
        // Methods
        int CalcArea() { this->area = PI * radius * radius; return this->area; }
        int CalcPerimeter() { this->perimeter = PI * 2 * this->radius; return this->perimeter; }
    public:
        // Methods
        Circle(string _name, int _radius) : Shape(_name, _radius) {}
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
        Triangle(string _name, int _sideA, int _sideB, int _sideC) : Shape(_name, _sideA, _sideB, _sideC) {}
};

int main () {
    Shape* base[8];
    int size = sizeof(base)/sizeof(base[0]);
    
    //          Create                Initialize    Assign to array
    Square      s1("Square 1",2,3);     s1.InitObj(); base[0] = &s1;
    Rectangle   r1("Rectangle 1",3,2);  r1.InitObj(); base[1] = &r1;
    Circle      c1("Circle 1",12);      c1.InitObj(); base[2] = &c1;
    Triangle    t1("Triangle 1",3,5,4); t1.InitObj(); base[3] = &t1;
    Square      s2("Square 2",2,3);     s2.InitObj(); base[4] = &s2;
    Rectangle   r2("Rectangle 2",8,2);  r2.InitObj(); base[5] = &r2;
    Circle      c2("Circle 2",12);      c2.InitObj(); base[6] = &c2;
    Triangle    t2("Triangle 2",4,4,4); t2.InitObj(); base[7] = &t2;


    cout << "COMPARE" << endl <<
            "=======" << endl;
    for (int i = 0; i < size-1; i++) { 
        for(int j = size-1; j > i; j--) {
            if (base[i]->GetName() != base[j]->GetName()) {
                cout << "----------------------------------------------------------------" << endl; 
                if (base[i]->operator== (*base[j])) {
                    cout << ">> MATCH: Area of " << base[i]->GetName() << " matches the area of " << base[j]->GetName() << endl;
                    if (base[i]->GetPerimeter() == base[j]->GetPerimeter()) {
                        cout << ">> MATCH: Perimeter of " << base[i]->GetName() << " matches the perimeter of " << base[j]->GetName() << endl;
                        cout << ">> THE OBJECTS ARE EQUAL" << endl;
                    }
                } else { cout << "Area of " << base[i]->GetName() << " does not match the area of " << base[j]->GetName() << endl; }
                cout << "----------------------------------------------------------------" << endl; 
                cout << endl;
            }
        }
    }

    return 0;
}