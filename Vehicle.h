#pragma once
#include <string>
#include <iostream>

class Vehicle {

private:
  int _Year;
  double _Miles;
  double _Value;
  std::string _Manufacturer;
  std::string _Model;
  float _Value_Date;

public:
  // Get and set the year of the Vehicle
  int getYear() const {return _Year;};
  void setYear(int year) { _Year = year;};

  // Get and set the miles of the Vehicle
  double getMiles() const {return _Miles;};
  void setMiles(double miles) {_Miles = miles;};

  // Get and set the value of the Vehicle
  double getValue()const {return _Value;};
  void setValue(double aValue) {_Value = aValue;};

  // Get and set the manufacturer of the Vehicle
  std::string getManufacturer() const {return _Manufacturer;};
  void setManufacturer(std::string manufacturer) {_Manufacturer = manufacturer; };

  // Get and set the model of the Vehicle
  std::string getModel() const {return _Model;};
  void setModel(std::string model){ _Model = model;};

  double getValue_Date() const {return _Value_Date;};
  void setValue_Date(float valueDate) {_Value_Date = valueDate;};

  // Default Constructor
  Vehicle();

  // Overload Constructor with 6 parameters
  Vehicle(int year, double miles, double value, std::string manufacturer, std::string model, double value_date);

  // Updates the car value and the value date by depreciating the value by 15% each year
  void UpdateValue(float const current_date) {
    int const numOfYears =(int)current_date - (int)_Value_Date;
    double valueOfVehicle= getValue();
    for (int i = 0; i < numOfYears; i++){
        valueOfVehicle -= valueOfVehicle * 0.15;
    }
    setValue(valueOfVehicle);
    setValue_Date(current_date);
  }

  // Returns the estimated value at a future date but does not update the private members
  double EstimateValue(float const& future_date) const {
    int const numOfYears = (int)future_date - (int)getValue_Date();
    double valueOfVehicle = getValue();
    for (int i = 0; i < numOfYears; i++){
      valueOfVehicle -= valueOfVehicle * 0.15;
    }
    return valueOfVehicle;
  }
};
