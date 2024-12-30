#ifndef CAR_H
#define CAR_H

#include <string>
#include <iostream>

class Wheel {
private:
    std::string size;
public:
    Wheel(const std::string& size);
    std::string getSize() const;
};

class Engine {
private:
    int power;
public:
    Engine(int power);
    int getPower() const;
};

class Car {
private:
    std::string brand;
    Wheel wheel;
    Engine engine;
public:
    Car(const std::string& brand, const Wheel& wheel, const Engine& engine);
    void drive() const;
    void refuel() const;
    void changeWheel() const;
    void printBrand() const;
    bool operator==(const Car& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Car& car);
    size_t hash() const;
};

#endif //CAR_H
