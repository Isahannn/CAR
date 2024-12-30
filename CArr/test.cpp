#include "pch.h"
#include "Car.h"
#include <gtest/gtest.h>

TEST(CarTest, Drive) {
    Wheel wheel("R16");
    Engine engine(150);
    Car car("Toyota", wheel, engine);
    testing::internal::CaptureStdout();
    car.drive();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Car is driving\n");
}

TEST(CarTest, Refuel) {
    Wheel wheel("R16");
    Engine engine(150);
    Car car("Toyota", wheel, engine);
    testing::internal::CaptureStdout();
    car.refuel();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Car is refueling\n");
}

TEST(CarTest, ChangeWheel) {
    Wheel wheel("R16");
    Engine engine(150);
    Car car("Toyota", wheel, engine);
    testing::internal::CaptureStdout();
    car.changeWheel();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Changing the wheel\n");
}

TEST(CarTest, PrintBrand) {
    Wheel wheel("R16");
    Engine engine(150);
    Car car("Toyota", wheel, engine);
    testing::internal::CaptureStdout();
    car.printBrand();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Car brand: Toyota\n");
}

TEST(CarTest, WheelGetSize) {
    Wheel wheel("R16");
    EXPECT_EQ(wheel.getSize(), "R16");
}

TEST(CarTest, EngineGetPower) {
    Engine engine(150);
    EXPECT_EQ(engine.getPower(), 150);
}

TEST(CarTest, CarEquality) {
    Wheel wheel1("R16");
    Engine engine1(150);
    Car car1("Toyota", wheel1, engine1);

    Wheel wheel2("R16");
    Engine engine2(150);
    Car car2("Toyota", wheel2, engine2);

    EXPECT_TRUE(car1 == car2);
}

TEST(CarTest, CarInequality) {
    Wheel wheel1("R16");
    Engine engine1(150);
    Car car1("Toyota", wheel1, engine1);

    Wheel wheel2("R17");
    Engine engine2(200);
    Car car2("Honda", wheel2, engine2);

    EXPECT_FALSE(car1 == car2);
}

TEST(CarTest, CarHash) {
    Wheel wheel("R16");
    Engine engine(150);
    Car car("Toyota", wheel, engine);
    EXPECT_NE(car.hash(), 0);
}

TEST(CarTest, CarOutput) {
    Wheel wheel("R16");
    Engine engine(150);
    Car car("Toyota", wheel, engine);
    std::ostringstream oss;
    oss << car;
    EXPECT_EQ(oss.str(), "Car { brand: Toyota, wheel size: R16, engine power: 150 }");
}

TEST(CarTest, DifferentWheelSize) {
    Wheel wheel("R17");
    EXPECT_EQ(wheel.getSize(), "R17");
}

TEST(CarTest, DifferentEnginePower) {
    Engine engine(200);
    EXPECT_EQ(engine.getPower(), 200);
}

TEST(CarTest, DifferentCarBrand) {
    Wheel wheel("R16");
    Engine engine(150);
    Car car("Honda", wheel, engine);
    testing::internal::CaptureStdout();
    car.printBrand();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Car brand: Honda\n");
}

TEST(CarTest, DriveTwice) {
    Wheel wheel("R16");
    Engine engine(150);
    Car car("Toyota", wheel, engine);
    testing::internal::CaptureStdout();
    car.drive();
    car.drive();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Car is driving\nCar is driving\n");
}

TEST(CarTest, RefuelTwice) {
    Wheel wheel("R16");
    Engine engine(150);
    Car car("Toyota", wheel, engine);
    testing::internal::CaptureStdout();
    car.refuel();
    car.refuel();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Car is refueling\nCar is refueling\n");
}

TEST(CarTest, ChangeWheelTwice) {
    Wheel wheel("R16");
    Engine engine(150);
    Car car("Toyota", wheel, engine);
    testing::internal::CaptureStdout();
    car.changeWheel();
    car.changeWheel();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Changing the wheel\nChanging the wheel\n");
}

TEST(CarTest, PrintBrandTwice) {
    Wheel wheel("R16");
    Engine engine(150);
    Car car("Toyota", wheel, engine);
    testing::internal::CaptureStdout();
    car.printBrand();
    car.printBrand();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Car brand: Toyota\nCar brand: Toyota\n");
}

TEST(CarTest, DifferentCars) {
    Wheel wheel1("R16");
    Engine engine1(150);
    Car car1("Toyota", wheel1, engine1);

    Wheel wheel2("R17");
    Engine engine2(200);
    Car car2("Honda", wheel2, engine2);

    std::ostringstream oss1, oss2;
    oss1 << car1;
    oss2 << car2;
    EXPECT_NE(oss1.str(), oss2.str());
}

TEST(CarTest, CarHashDifferent) {
    Wheel wheel1("R16");
    Engine engine1(150);
    Car car1("Toyota", wheel1, engine1);

    Wheel wheel2("R20");
    Engine engine2(200);
    Car car2("Honda", wheel2, engine2);

    EXPECT_NE(car1.hash(), car2.hash());
}

TEST(CarTest, ChangeAttributes) {
    Wheel wheel("R18");
    Engine engine(0);
    Car car("BÉMW", wheel, engine);
    testing::internal::CaptureStdout();
    car.printBrand();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Car brand: BMW\n");
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
