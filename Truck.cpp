#include "Vehicle.h"
#include "Truck.h"
#include <iostream>
#include <string>

// Default Constructor
Truck::Truck(){
  setYear(2015);
  setMiles(55000);
  setValue(20000);
  setManufacturer("Chevrolet");
  setModel("Colorado");
  setAwd(true);
  setTowing_Capacity(5000);
  setValue_Date(2019.0227);
}

//Overload Constructor with 8 parameters
Truck::Truck(int year, double miles, double value, std::string manufacturer, std::string model, bool awd, int towingCapacity, double value_date){
  setYear(year);
  setMiles(miles);
  setValue(value);
  setManufacturer(manufacturer);
  setModel(model);
  setAwd(awd);
  setTowing_Capacity(towingCapacity);
  setValue_Date(value_date);
}
