#include<bits/stdc++.h>
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
        this->isEngineOn = false;
        this->currentSpeed = 0;
    }

    // common methods for all cars
    void startEngine() {
        isEngineOn = true;
        cout << brand << " " << model << " : Engine started." << endl;
    }

    void stopEngine() {
        isEngineOn = false;
        cout << brand << " " << model << " : Engine stopped." << endl;
    }

    void accelerate() {
        if (isEngineOn) {
            currentSpeed += 20; // Increase speed by 20 km/h
            cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h." << endl;
        } else {
            cout << "Start the engine first!" << endl;
        }
    }

    void brake() {
        currentSpeed -= 20; // Decrease speed by 20 km/h
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking to " << currentSpeed << " km/h." << endl;

    }

    virtual ~Car() {}
};

class ManualCar : public Car {
private:
    int currentGear; // specific to manual cars

public:
    ManualCar(string b, string m) : Car(b, m) {
        this->currentGear = 0; // Neutral gear
    }

    // Specific methods for manual cars
    void shiftGear(int gear) {
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << "." << endl;
    }
};

class ElectricCar : public Car {
private:
    int batterLevel; // specific to electric cars

public:
    ElectricCar(string b, string m) : Car(b, m) {
        this->batterLevel = 0; // initial battery level
    }

    // Specific methods for electric cars
    void chargeBattery() {
        batterLevel = 100; // Fully charged
        cout << brand << " " << model << " : Battery charged to " << batterLevel << "%." << endl;
    }
};

int main () {
    ManualCar* myManualCar = new ManualCar("Volkswagen", "Taigun");
    myManualCar->startEngine();
    myManualCar->shiftGear(1); // Shift to 1st gear // specific to manual cars
    myManualCar->accelerate();
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout << "=== __ === __ === __ === __ === __ ===" << endl;
    
    ElectricCar* myElectricCar = new ElectricCar("Tesla", "Model S");
    myElectricCar->chargeBattery(); // specific to electric cars
    myElectricCar->startEngine();
    myElectricCar->accelerate();
    myElectricCar->brake();
    myElectricCar->stopEngine();
    delete myElectricCar;

    return 0;
}