#include<iostream>
using namespace std;

class Shape {
    public:
        virtual double area() = 0;
        virtual double volume() = 0; // 2D shaped are not having volumn
};

class Square : public Shape {
    private:
        double side;
    
    public:
        Square(double s) : side (s) {}
        double area() override {
            return side * side;
        }

        double volume() override {
            throw logic_error("Volume not applicable for Square");
        }
};

class Rectangle : public Shape {
    private:
        double length, width;
    
    public:
        Rectangle (double l, double w): length(l), width(w) {}
        double area() override {
            return length * width;
        }

        double volume() override {
            throw logic_error("Volume not applicable for Rectangle");
        }
};

class Cube : public Shape {
    private:
        double side;
    
    public:
        Cube(double s) : side (s) {}
        double area() override {
            return 6 * side * side;
        }

        double volume() override {
            return side * side * side;
        }
};

int main() {
    Shape* sq = new Square(5);
    Shape* rect = new Rectangle(3,4);
    Shape* cube = new Cube(5);

    cout << "Square Area: " << sq->area() << endl;
    cout << "Rectangle Area: " << rect->area() << endl;
    cout << "Cube Area: " << cube->area() << endl;
    cout << "Cube Volume: " << cube->volume() << endl;

    try {
        cout << "Square Volume: " << sq->volume() << endl; 
    } catch (logic_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    try {
        cout << "Rectangle Volume: " << rect->volume() << endl; 
    } catch (logic_error& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}