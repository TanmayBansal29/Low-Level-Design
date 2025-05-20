#include<iostream>
using namespace std;

class Car {
    protected:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
    
    public:
        Car(string b, string m) {
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
        }

        // Common methods for all the cars
        void startEngine() {
            isEngineOn = true;
            cout << brand << " " << model << " : Engine Started." << endl;
        }

        void stopEngine() {
            isEngineOn = false;
            currentSpeed = 0;
            cout << brand << " " << model << " : Engine turned off." << endl;
        }

        virtual void accelerate() = 0; // Abstract Method for dynamic polymorphism
        
        virtual void accelerate(int speed) = 0;
        
        virtual void brake() = 0;
        
        virtual ~Car() {}
};

class ManualCar : public Car {
    private:
        int currentGear;
    public:
        ManualCar(string b, string m) : Car(b,m) {
            currentGear = 0;
        }

        // Specialized Method for Manual Car
        void shiftGear(int gear) {
            currentGear = gear;
            cout << brand << " " << model << " : Shifted to Gear " << currentGear << endl;
        }

        // Overriding accelerate - Dynamic Polymorphism
        void accelerate() {
            if(!isEngineOn) {
                cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
                return;
            }
            currentSpeed += 20;
            cout << brand << " " << model << " :Accelerating to " << currentSpeed << "km/h" <<endl;
        }

        // Overriding and Overloading accelerate at the same time
        void accelerate(int speed) {
            if(!isEngineOn) {
                cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
                return;
            }
            currentSpeed += speed;
            cout << brand << " " << model << " :Accelerating to " << currentSpeed << "km/h" <<endl;
        }

        // Overriding brake - Dynamic Polymorphism
        void brake() {
            currentSpeed -= 20;
            if(currentSpeed < 0) currentSpeed = 0;
            cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/hr" << endl;
        }
};

class ElectricCar : public Car {
    private:
        int batteryLevel;
    public:
        ElectricCar(string b, string m) : Car(b,m) {
            batteryLevel = 100;
        }

        // Specialized Method for Manual Car
        void chargeBattery() {
            batteryLevel = 100;
            cout << brand << " " << model << " : Battery Fully Charged!! "<< endl;
        }

        // Overriding accelerate - Dynamic Polymorphism
        void accelerate() {
            if(!isEngineOn) {
                cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
                return;
            }
            if(batteryLevel <= 0) {
                cout << brand << " " << model << " : Battery Dead! Cannot Accelerate" << endl;
                return;
            }
            batteryLevel -= 10;
            currentSpeed += 15;
            cout << brand << " " << model << " : Accelerating to " << currentSpeed << "km/h. Battery at " << batteryLevel << "%" <<endl;
        }

        void accelerate(int speed) {
            if(!isEngineOn) {
                cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
                return;
            }
            if(batteryLevel <= 0) {
                cout << brand << " " << model << " : Battery Dead! Cannot Accelerate" << endl;
                return;
            }
            batteryLevel -= 10 + speed - 20;
            currentSpeed += speed;
            cout << brand << " " << model << " : Accelerating to " << currentSpeed << "km/h. Battery at " << batteryLevel << "%" <<endl;
        }

        // Overriding brake - Dynamic Polymorphism
        void brake() {
            currentSpeed -= 15;
            if(currentSpeed < 0) currentSpeed = 0;
            cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/hr" << endl;
        }
};

int main() {
    Car* manualCar = new ManualCar("Suzuki", "wagonR");
    manualCar->startEngine();
    manualCar->accelerate();
    manualCar->accelerate(50);
    manualCar->brake();
    manualCar->stopEngine();
    delete manualCar;

    cout << "---------------------" << endl;

    Car* electricCar = new ElectricCar("Tesla", "Model 5");
    electricCar->startEngine();
    electricCar->accelerate();
    electricCar->accelerate(50);
    electricCar->brake();
    electricCar->stopEngine();
    delete electricCar;
}