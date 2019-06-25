#include "Vehicle.h"
#include "Truck.h"
#include <iostream>
#include <string>


// Default constructor
Vehicle::Vehicle(){
  setYear(2015);
  setMiles(55000);
  setValue(20000);
  setManufacturer("Chevrolet");
  setModel("Colorado");
  setValue_Date(2019.0227);
}

// Overload constructor with 6 parameters
Vehicle::Vehicle(int year, double miles, double value, std::string manufacturer, std::string model, double value_date){
  setYear(year);
  setMiles(miles);
  setValue(value);
  setManufacturer(manufacturer);
  setModel(model);
  setValue_Date(value_date);
}
