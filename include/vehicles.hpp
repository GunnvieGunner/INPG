#ifndef VEHICLES_HPP_
#define VEHICLES_HPP_

#include <cstdlib>
#include <string>
#include <vector>
#include <functional>
#include <sstream>

class Vehicle {
public:
    Vehicle(std::string id, std::string brand) : id_(id), brand_(brand), vin_(next_vin_) {++next_vin_;}

    std::string get_id() const { return id_; }

    std::string get_brand() const { return brand_; }

    std::int64_t get_vin() const {return vin_;}

    virtual double get_max_speed() const = 0;

    virtual ~Vehicle() = default;

private:
    std::string id_;
    std::string brand_;
    static std::int64_t vin_;
    std::int64_t next_vin_=1;
};

std::string to_string(const Vehicle& vehicle);

std::string to_string(std::vector<Vehicle*>::const_iterator vehicles_begin,
                      std::vector<Vehicle*>::const_iterator vehicles_end);

class Car : public Vehicle {
public:
    Car(std::string id, std::string brand, double engine_hp) : Vehicle(id, brand), engine_hp_(engine_hp) {}

    double get_max_speed() const override { return engine_hp_; }

private:
    double engine_hp_;
};

class Bicycle : public Vehicle {
public:
    Bicycle(std::string id, std::string brand, int n_gears) : Vehicle(id, brand), n_gears_(n_gears) {}

    double get_max_speed() const override { return n_gears_ * 3; }

private:
    int n_gears_;
};

};
enum class Gender {
    Male, Female
};

class Driver {
public:
    Driver(Gender g): gender_(g) {}
    Gender get_gender() const {return gender_;}

private:
    Gender gender_;






Gender g = Gender::Male;




double compute_min_travel_duration(double distance, const Vehicle& vehicle);

std::string compute_min_travel_duration_as_string(double distance, const Vehicle& vehicle);

std::vector<Vehicle*> filter_vehicles(
        std::vector<Vehicle*>::const_iterator vehicles_begin,
        std::vector<Vehicle*>::const_iterator vehicles_end,
        std::function<bool(const Vehicle&)> predicate);


#endif /* VEHICLES_HPP_ */
