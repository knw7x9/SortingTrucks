#include "Vehicle.h"
#pragma once
#include <string>
#include <iostream>

class Truck : public Vehicle{
private:
  bool _Awd;
  int _Towing_Capacity;

public:
  // Get and set all wheel drive of the truck
  std::string getAwd() const {
    return _Awd ? "4x4" : "4x2";
  };
  void setAwd(bool awd){_Awd = awd;};

  // Get and set the towing capacity of the truck
  int getTowing_Capacity() const {return _Towing_Capacity;};
  void setTowing_Capacity(int towingCapacity){_Towing_Capacity = towingCapacity;};

  // Get the name of the truck
  std::string getName() const {
    std::string name = std::to_string(getYear()) + " " + getManufacturer() + " " + getModel() + " " + getAwd();
    return name;
  }

  // Default Constructor
  Truck();

  //Overload Constructor with 8 parameters
  Truck(int year, double miles, double value, std::string manufacturer, std::string model, bool awd, int towingCapacity, double value_date);
};
