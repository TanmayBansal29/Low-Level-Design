#include<iostream>
#include<string>

using namespace std;

class ManualCar {
    private:
        string brand;
        string model;
        bool isEngineOn;
        int currentSpeed;
        int currentGear;
    
    public: 
        ManualCar(string b, string m) {
            this->brand = b;
            this->model = m;
            isEngineOn = false;
            currentSpeed = 0;
            currentGear = 0;
        }

        void startEngine() {
            isEngineOn = true;
            cout << brand << " " << model << " : Engine Started." << endl;
        }

        void stopEngine() {
            isEngineOn = false;
            currentSpeed = 0;
            cout << brand << " " << model << " : Engine turned off." << endl;
        }

        // Overloading - Static Polymorphism
        void accelerate() {
            if(!isEngineOn) {
                cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
                return;
            }
            currentSpeed += 20;
            cout << brand << " " << model << " :Accelerating to " << currentSpeed << "km/h" <<endl;
        }

        void accelerate(int speed) {
            if(!isEngineOn) {
                cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
                return;
            }
            currentSpeed += speed;
            cout << brand << " " << model << " :Accelerating to " << currentSpeed << "km/h" <<endl;
        }

        void brake() {
            currentSpeed -= 20;
            if(currentSpeed < 0) currentSpeed = 0;
            cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/hr" << endl;
        }

        void shiftGear(int gear) {
            currentGear = gear;
            cout << brand << " " << model << " : Shifted to Gear " << currentGear << endl;
        }
};

int main() {
    ManualCar* manualCar = new ManualCar("Suzuki", "wagonR");
    manualCar->startEngine();
    manualCar->accelerate();
    manualCar->accelerate(40);
    manualCar->brake();
    manualCar->stopEngine();

    delete manualCar;
}