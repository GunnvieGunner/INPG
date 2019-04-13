#include "gtest/gtest.h"

#include "vehicles.hpp"

TEST(DriverTest, toStringNoVehicle) {
    Driver owner("Adam Abacki");

    std::string str = to_string(owner);

    ASSERT_EQ(str, "Adam Abacki : [no vehicle]");
}

TEST(DriverTest, toStringWithVehicle) {
    Driver owner("Adam Abacki", std::make_unique<Car>("C1", "Lexus", 500.0));

    std::string str = to_string(owner);

    std::string vehicle_str = to_string(*(owner.get_vehicle()));
    ASSERT_EQ(str, "Adam Abacki : [" + vehicle_str + "]");
}

TEST(DriverAuxTest, assignVehicleToDriver) {
    std::vector<std::unique_ptr<Vehicle>> vehicles;
    vehicles.push_back(std::make_unique<Car>("C1", "Lexus", 300));
    vehicles.push_back(std::make_unique<Bicycle>("B1", "Unibike", 8));
    vehicles.push_back(std::make_unique<Car>("C2", "Honda", 200));

    Driver owner("");
    assign_vehicle_to_driver(vehicles, owner);

    ASSERT_EQ(vehicles.size(), 2U);
    EXPECT_EQ(vehicles[0]->get_id(), "C1");
    EXPECT_EQ(vehicles[1]->get_id(), "B1");

    EXPECT_EQ((owner.get_vehicle())->get_id(), "C2");
}

TEST(DriverAuxTest, copying) {
    Driver driver1("Adam Abacki", std::make_unique<Car>("C1", "Lexus", 500.0));

    Driver driver2(driver1);

    EXPECT_EQ(driver1.get_vehicle(), nullptr);
    EXPECT_EQ((driver2.get_vehicle())->get_id(), "C1");
}

TEST(DriverAuxTest, assignment) {
    Driver driver1("Adam Abacki", std::make_unique<Car>("C1", "Lexus", 500.0));
    Driver driver2("Bogdan Babacki");

    driver2 = driver1;

    EXPECT_EQ(driver1.get_vehicle(), nullptr);
    EXPECT_EQ((driver2.get_vehicle())->get_id(), "C1");
}
