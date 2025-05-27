#include<bits/stdc++.h>
using namespace std;

//this program is to see the strategy pattern desgin in c++
// The strategy pattern is a behavioral design pattern that enables selecting an algorithm's behavior at runtime.

//Interface for walking behavior
class WalkBehavior {
public:
    virtual void walk () = 0;
    virtual ~WalkBehavior() {}
};

// Concrete implementation of walking behavior
class NormalWalk : public WalkBehavior {
public:
    void walk () override {
        cout << "Normally walking Robot" << endl;
    }
};

// Concrete implementation of walking behavior
class NoWalk : public WalkBehavior {
public:
    void walk () override {
        cout << "Not walking Robot" << endl;
    }
};

//Interface for flying behavior
class FlyBehavior {
public:
    virtual void fly () = 0;
    virtual ~FlyBehavior() {}
};

// Concrete implementation of flying behavior
class NormalFly : public FlyBehavior {
public:
    void fly () override {
        cout << "Normally flying Robot" << endl;
    }
};

// Concrete implementation of flying behavior
class NoFly : public FlyBehavior {
public:
    void fly () override {
        cout << "Not flying Robot" << endl;
    }
};

//Interface for talking behavior
class TalkBehavior {
public:
    virtual void talk () = 0;
    virtual ~TalkBehavior() {}
};

// Concrete implementation of talking behavior
class NormalTalk : public TalkBehavior {
public:
    void talk () override {
        cout << "Normally talking Robot" << endl;
    }
};

// Concrete implementation of talking behavior
class NoTalk : public TalkBehavior {
public:
    void talk () override {
        cout << "Not talking Robot" << endl;
    }
};


// Abstract class for Robot
class Robot {
private:
    WalkBehavior* walkType;
    FlyBehavior* flyType;
    TalkBehavior* talkType;
public:
    Robot (WalkBehavior* w, TalkBehavior* t, FlyBehavior* f) {
        this -> walkType = w;
        this -> talkType = t;
        this -> flyType = f;
    }

    void walk () {
        walkType -> walk();
    }

    void fly () {
        flyType -> fly();
    }

    void talk () {
        talkType -> talk();
    }

    virtual void projection() = 0; //Abstract method for subclasses

};


// Concrete implementation of Robot types

class CompanionRobot : public Robot {
public:
    CompanionRobot (WalkBehavior* w, TalkBehavior* t, FlyBehavior* f) : Robot(w, t, f) {}

    void projection() override {
        cout << "Companion Robot: showing all the friendly nature as a companion" << endl;
    }
};

class WorkerRobot : public Robot {
public:
    WorkerRobot (WalkBehavior* w, TalkBehavior* t, FlyBehavior* f) : Robot(w, t, f) {}

    void projection() override {
        cout << "Worker Robot: showing all the work nature as a worker" << endl;
    }
};



int main() {
    Robot* robot1 = new WorkerRobot(new NoWalk(), new NormalTalk(), new NormalFly());
    Robot* robot2 = new CompanionRobot(new NormalWalk(), new NormalTalk(), new NoFly());

    robot1 -> talk();
    robot1 -> walk();
    robot1 -> fly();
    robot1 -> projection();

    cout << "----===----===----===----===----===----===----" << endl;

    robot2 -> walk();
    robot2 -> talk();
    robot2 -> fly();
    robot2 -> projection();

    cout << "----===----===----===----===----===----===----" << endl;

    // Clean up
    delete robot1;
    delete robot2;
    return 0;
}