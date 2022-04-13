/*
    Write a function template which receives two of any shapes from last week’s assignment, compares them, and
    prints out the result.
*/

#include <iostream>
#include <string>
#include <math.h>
#define PI 3.14159265359

using namespace std;

/* ============================== IMPORTED CLASSES FROM SHAPE INTERFACE ============================== */

class Shape
{
public:
    // Methods
    void InitObj()
    {
        this->CalcArea();
        this->CalcPerimeter();
    }
    string GetName() { return this->name; }
    int GetArea() { return this->CalcArea(); }
    int GetPerimeter() { return this->CalcPerimeter(); }
    void SetWidth(int _width) { this->width = _width; }
    void SetHeight(int _height) { this->height = _height; }
    void SetRadius(int _radius) { this->radius = _radius; }
    bool operator==(Shape &_shape)
    {
        if (this->area == _shape.area && this->perimeter == _shape.perimeter)
        {
            return true;
        }
        return false;
    }

protected:
    // Attributes
    string name;
    int width{}, height{}, radius{}, sideA{}, sideB{}, sideC{}, area{}, perimeter{};
    // Methods
    Shape(string _name, int _radius) { this->name = _name, this->radius = _radius; }
    Shape(string _name, int _width, int _height)
    {
        this->name = _name, this->width = _width;
        this->height = _height;
    }
    Shape(string _name, int _sideA, int _sideB, int _sideC)
    {
        this->name = _name;
        this->sideA = _sideA;
        this->sideB = _sideB;
        this->sideC = _sideC;
    }
    virtual int CalcArea() = 0;
    virtual int CalcPerimeter() = 0;
};

class Rectangle : public Shape
{
private:
    // Methods
    int CalcPerimeter()
    {
        this->perimeter = this->width * 2 + this->height * 2;
        return this->perimeter;
    }
    int CalcArea()
    {
        this->area = this->width * this->height;
        return this->area;
    }

public:
    // Methods
    Rectangle(string _name, int _width, int _height) : Shape(_name, _width, _height) {}
};

class Square : public Shape
{
private:
    // Methods
    int CalcArea()
    {
        this->area = this->width * this->height;
        return this->area;
    }
    int CalcPerimeter()
    {
        this->perimeter = this->width * 2 + this->height * 2;
        return this->perimeter;
    }

public:
    // Methods
    Square(string _name, int _width, int _height) : Shape(_name, _width, _height) {}
};

class Circle : public Shape
{
private:
    // Methods
    int CalcArea()
    {
        this->area = PI * radius * radius;
        return this->area;
    }
    int CalcPerimeter()
    {
        this->perimeter = PI * 2 * this->radius;
        return this->perimeter;
    }

public:
    // Methods
    Circle(string _name, int _radius) : Shape(_name, _radius) {}
};

class Triangle : public Shape
{
private:
    // Methods
    int CalcArea()
    {
        int s = (this->sideA + this->sideB + this->sideC) / 2;
        this->area = sqrt(s * (s - this->sideA) * (s - this->sideB) * (s - this->sideC));
        return this->area;
    }
    int CalcPerimeter()
    {
        this->perimeter = (this->sideA + this->sideC + this->sideC) / 2;
        return this->perimeter;
    }

public:
    // Methods
    Triangle(string _name, int _sideA, int _sideB, int _sideC) : Shape(_name, _sideA, _sideB, _sideC) {}
};

/* =================================================================================================== */

template <class S1, class S2>
void shapeCompare(S1 &_s1, S2 &_s2)
{
    cout << "----------------------------------------------------------------" << endl;
    if (_s1.operator==(_s2))
    {
        cout << ">> MATCH: The Area and Perimeter of " << _s1.GetName() << " matches " << _s2.GetName() << endl;
        cout << ">> THE OBJECTS ARE EQUAL" << endl;
    }
    else
    {
        cout << "The Area and Perimeter of " << _s1.GetName() << " does not match " << _s2.GetName() << endl;
    }
    cout << "----------------------------------------------------------------" << endl;
    cout << endl;
}

int main()
{
    Square s1("Square 1", 2, 3);
    s1.InitObj();
    Square s2("Square 2", 2, 3);
    s2.InitObj();

    Circle c1("Circle 1", 3);
    c1.InitObj();
    Triangle t1("Triangle 1", 6, 4, 8);
    t1.InitObj();

    shapeCompare(s1, s2);
    shapeCompare(c1, t1);

    return 0;
}