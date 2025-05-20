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

    // This is a pure virtual function, making this class abstract
    virtual void accelerate() = 0; // Pure virtual function
    virtual void brake() = 0; // Pure virtual function
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

    // Override the accelerate method
    void accelerate() {
        if(!isEngineOn) {
            cout << brand << " " << model << " : Start the engine first!" << endl;
            return;
        }
        currentSpeed += 20; // Increase speed by 20 km/h
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h." << endl;
    }

    // Override the brake method
    void brake() {
        currentSpeed -= 20; // Decrease speed by 20 km/h
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking to " << currentSpeed << " km/h." << endl;
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

    // Override the accelerate method
    void accelerate() {
        if(!isEngineOn) {
            cout << brand << " " << model << " : Start the engine first!" << endl;
            return;
        }
        if (batterLevel <= 0) {
            cout << brand << " " << model << " : Battery is empty! go charge it first" << endl;
            return;
        }
        currentSpeed += 20; // Increase speed by 20 km/h
        batterLevel -= 10; // Decrease battery level by 10%
        cout << brand << " " << model << " : Accelerating to " << currentSpeed << " km/h. with battery " << batterLevel << "%." << endl;
    }

    // Override the brake method
    void brake() {
        currentSpeed -= 15; // Decrease speed by 20 km/h
        if (currentSpeed < 0) currentSpeed = 0;
        cout << brand << " " << model << " : Braking to " << currentSpeed << " km/h." << endl;
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