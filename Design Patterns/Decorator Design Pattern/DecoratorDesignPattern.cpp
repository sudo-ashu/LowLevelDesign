//
// Created by ashur on 31-05-2025.
//
#include<bits/stdc++.h>
using namespace std;

class ICharacter {
public:
    virtual string getAbilities() const = 0;
    virtual ~ICharacter() {}
};

class Mario : public ICharacter {
public:
    string getAbilities() const override {
        return "Mario";
    }
};

//decorator class having is-a and has-a relation with ICharacter class
class IDecorator : public ICharacter {
protected:
    ICharacter* character;
public:
    IDecorator(ICharacter* c) {
        this->character = c;
    }
};

class HeightUpDec : public IDecorator {
public:
    HeightUpDec(ICharacter* c) : IDecorator(c) {}
    string getAbilities() const override {
        return character->getAbilities() + " with Height Up";
    }
};

class GunPowerDec : public IDecorator {
public:
    GunPowerDec(ICharacter* c) : IDecorator(c) {}
    string getAbilities() const override {
        return character->getAbilities() + " with Gun Using";
    }
};

class StarPowerDec : public IDecorator {
public:
    StarPowerDec(ICharacter* c) : IDecorator(c) {}
    string getAbilities() const override {
        return character->getAbilities() + " with Start Power (limited time)";
    }

    ~StarPowerDec() {
        cout << "Destroying Star Power Decorator" << endl;
    }
};

int main () {
    ICharacter* mario = new Mario();
    cout << "Our basic character is " << mario->getAbilities() << endl;
    mario = new HeightUpDec(mario);
    cout << "Our character is now " << mario->getAbilities() << endl;
    mario = new GunPowerDec(mario);
    cout << "Our character is now " << mario->getAbilities() << endl;
    mario = new StarPowerDec(mario);
    cout << "Our character is now " << mario->getAbilities() << endl;
    delete mario;

    return 0;
}
