#include<iostream>
using namespace std;

class Car {
    protected:
        int speed;
    
    public:
        Car() {
            speed = 0;
        }

        void accelerate() {
            cout << "Acceleration " << endl;
            speed += 20;
        }

        virtual void brake() {
            cout << "Applying brakes" << endl;
            speed -= 20;
        }
};

class HybridCar : public Car {
    private:    
        int charge;
    
    public:
        HybridCar() : Car() {
            charge = 0;
        }

        void brake() {
            cout << "Applying brakes" << endl;
            speed -= 20;
            charge += 10;
        }
};

int main() {
    Car* car = new Car();
    Car* hybridCar = new HybridCar();

    car->accelerate();
    car->accelerate();
    car->brake();

    hybridCar->accelerate();
    hybridCar->accelerate();
    hybridCar->brake();

    return 0;
}