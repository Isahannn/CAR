#include "pch.h"
#include "Car.h"

Wheel::Wheel(const std::string& size) : size(size) {}
std::string Wheel::getSize() const { return size; }

Engine::Engine(int power) : power(power) {}
int Engine::getPower() const { return power; }

Car::Car(const std::string& brand, const Wheel& wheel, const Engine& engine)
    : brand(brand), wheel(wheel), engine(engine) {}

void Car::drive() const { std::cout << "Car is driving" << std::endl; }
void Car::refuel() const { std::cout << "Car is refueling" << std::endl; }
void Car::changeWheel() const { std::cout << "Changing the wheel" << std::endl; }
void Car::printBrand() const { std::cout << "Car brand: " << brand << std::endl; }

bool Car::operator==(const Car& other) const {
    return brand == other.brand && wheel.getSize() == other.wheel.getSize() &&
        engine.getPower() == other.engine.getPower();
}

std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << "Car { brand: " << car.brand << ", wheel size: " << car.wheel.getSize() << ", engine power: " << car.engine.getPower() << " }";
    return os;
}

size_t Car::hash() const {
    return std::hash<std::string>()(brand) ^ std::hash<std::string>()(wheel.getSize()) ^ std::hash<int>()(engine.getPower());
}
 