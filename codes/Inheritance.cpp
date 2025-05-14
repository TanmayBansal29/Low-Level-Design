#include<iostream>
#include<string>
using namespace std;

class Car{
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

        void accelerate() {
            if(!isEngineOn) {
                cout << brand << " " << model << " : Cannot accelerate! Engine is off." << endl;
            }
            currentSpeed += 20;
            cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/hr" << endl;
        }

        void brake() {
            currentSpeed -= 20;
            if(currentSpeed < 0) currentSpeed = 0;
            cout << brand << " " << model << " : Braking! Speed is now " << currentSpeed << " km/hr" << endl;
        }

        virtual ~Car() {}
};

class ManualCar : public Car { // Inherits from car
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
};

class ElectricCar : public Car { // Inherits from car
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
};

int main(){
    ManualCar* manualCar = new ManualCar("Suzuki", "wagonR");
    manualCar->startEngine();
    manualCar->shiftGear(1); // Specific to Manual Car
    manualCar->accelerate();
    manualCar->brake();
    manualCar->stopEngine();
    delete manualCar;

    cout << "---------------------" << endl;

    ElectricCar* electricCar = new ElectricCar("Tesla", "Model 5");
    electricCar->chargeBattery(); // Specific to Electric Car
    electricCar->startEngine();
    electricCar->accelerate();
    electricCar->brake();
    electricCar->stopEngine();
    delete electricCar;
}