#include<bits/stdc++.h>
using namespace std;

class ManualCar {
private:
    string brand;
    string model;
    bool isEngineOn;
    int currentSpeed;
    int currentGear;

public:
    ManualCar(string b, string m){
        this->brand = b;
        this->model = m;
        this->isEngineOn = false;
        this->currentSpeed = 0;
        this->currentGear = 0; // Neutral gear
    } 


    void shiftGear(int gear) {
        currentGear = gear;
        cout << brand << " " << model << " : Shifted to gear " << currentGear << "." << endl;
    }

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

    void accelerate(int speed) {
        if (isEngineOn) {
            currentSpeed += speed; // Increase speed by 20 km/h
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
};

int main () {
    ManualCar* myManualCar = new ManualCar("Volkswagen", "Taigun");
    myManualCar->startEngine();
    myManualCar->shiftGear(1); // Shift to 1st gear // specific to manual cars
    myManualCar->accelerate();
    myManualCar->shiftGear(2); // Shift to 2nd gear
    myManualCar->accelerate(50); // Accelerate to 50 km/h
    myManualCar->brake();
    myManualCar->stopEngine();
    delete myManualCar;

    cout << "=== __ === __ === __ === __ === __ ===" << endl;

    return 0;
}