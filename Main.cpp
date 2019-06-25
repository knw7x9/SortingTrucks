// Main.cpp
// CS 4499
// Written By: Katherine Wilsdon
// 8 April 2019
// Dr. Kerby
// Description - Finds the total current value of 10 trucks and the total estimated value in 5 years.
// Sorts the trucks alphabetically and by mileage using a lambda.

#include "Vehicle.h"
#include "Truck.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

vector<double> estVal(vector<Truck>, float);
void printTruck(vector<Truck>);

// returns a vector containing each truck price at the estimated date
vector<double> estVal(vector<Truck> const& vectorOfTrucks, double const& futureDate) {
  vector<double> truckEstimatedValue;
  for (int i = 0; i < vectorOfTrucks.size(); i++){
    truckEstimatedValue.push_back(vectorOfTrucks[i].EstimateValue(futureDate));
  }
  return truckEstimatedValue;
}

// Member function declaration
void printTruck(vector<Truck> vectorOfTrucks) {
  for (Truck truck : vectorOfTrucks) {
    cout << truck.getName() << endl;
    // cout << truck.getName() << " " << fixed << setprecision(0) << truck.getMiles()<< " miles" << endl;
  }
}

int main(){
  // Create a vector of trucks
  vector<Truck> trucks;
  //https://www.toyota.com/tacoma/features/mpg/7594/7544/7582
  trucks.push_back(Truck(2019, 0, 31815, "Toyota", "Tacoma SR", true, 6400, 2019.041));
  //https://www.ford.com/trucks/ranger/
  trucks.push_back(Truck(2019, 0, 24300, "Ford", "Ranger XL", true, 7500, 2019.098));
  //https://eastidaho.craigslist.org/ctd/d/osburn-2014-ford-150-4x4-4wd-f150-4/6859458763.html
  trucks.push_back(Truck(2014, 90508, 28498, "Ford", "F-150", true, 5500, 2014.147));
  //https://www.chevrolet.com/trucks/colorado-mid-size-truck
  trucks.push_back(Truck(2015, 65871, 37000, "Chevrolet", "Colorado", true, 5000, 2015.501));
  //https://www.chevrolet.com/previous-year/silverado-1500-pickup-truck
  trucks.push_back(Truck(2018, 78, 28300, "Chevrolet", "Siverado", true, 7600, 2018.767));
  // https://eastidaho.craigslist.org/ctd/d/idaho-falls-loaded-2011-ford-150-crew/6858273506.html
  trucks.push_back(Truck(2011, 129500, 16995, "Ford", "F-150", true, 5500, 2011.959 ));
  // https://eastidaho.craigslist.org/ctd/d/idaho-falls-reduced-pricenavigation/6858284267.html
  trucks.push_back(Truck(2011, 118016, 18900, "Chrysler", "Ram 1500 Laramie", true, 5000, 2011.890 ));
  // https://eastidaho.craigslist.org/ctd/d/rexburg-2008-toyota-tacoma-122k-miles/6858302567.html
  trucks.push_back(Truck(2008, 122425, 15995, "Toyota" , "Tacoma", true, 3500, 2008.274 ));
  // https://eastidaho.craigslist.org/ctd/d/idaho-falls-navigation-heated-seats/6859037635.html
  trucks.push_back(Truck(2015, 83890, 24500, "Chevrolet", "Colorado Z71", true, 3500, 2015.411));
  // http://www.chevytrucklegends.com/us/en/100-year-history-of-chevy-trucks.html
  // https://www.autotrader.com/car-reviews/1999-2006-chevrolet-silverado-1500-used-car-review-196196
  trucks.push_back(Truck(1999, 188691, 31384, "Chevrolet", "Silverado 1500", true, 5000, 1999.548 ));

  // Update truck value to April 8th 2019
  for (int i = 0; i < trucks.size(); i++) {
    trucks.at(i).UpdateValue(2019.268);
  }

  // Print out the current values of the trucks
  cout << "Current value in all trucks: " << endl;
  for (Truck truck : trucks) {
    cout << truck.getYear() << " "<< truck.getManufacturer()<< " " << truck.getModel() << ": $" << fixed << setprecision(2) <<
    truck.getValue() << " on 4/8/2019" << endl;
  }

  // Add all the values of the trucks for a total sum
  double sumofValues = accumulate(begin(trucks), end(trucks), 0.0, [] (double total, Truck& truck)
  {
    return total + truck.getValue();
  });

  // Output the sum and explanation to the console
  cout << endl << "Total current value of all " << trucks.size() << " Trucks: " << sumofValues << endl;
  cout << endl << "The trucks vector was updated to the current value on 4/8/2019. The value was depreciated by 15% each year. The accumulate function added the current value of each truck in the vector. The sum was printed in the console." << endl << endl;

  //Create a vector of the estimated values of the trucks from the truck vector
  vector<double> estimatedValueOfTrucks = estVal(trucks, 2024.268);

  // Print the estimated values for each truck in the vector
  cout << "Estimated value in 5 years: " << endl;
  for (int i = 0; i < trucks.size(); i++) {
    cout << trucks.at(i).getYear() << " "<< trucks.at(i).getManufacturer()<< " " << trucks.at(i).getModel() << " has a value of $" << fixed << setprecision(2) <<
    estimatedValueOfTrucks.at(i) << " on 4/8/2024" << endl;
  }

  // Add all the values of the trucks for a total sum
  double sumofFutureValues = accumulate(begin(estimatedValueOfTrucks), end(estimatedValueOfTrucks), 0.0, [] (double total, double i)
  {
    return total + i;
  });

  // Output the sum and explanation to the console
  cout << endl << "Total total future value of all " << trucks.size() << " Trucks: " << sumofFutureValues << endl << endl;
  cout << endl << "A vector was created with each truck's estimated value on 4/8/2024. The value of the truck was depreciated by 15% each year. The accumulate function added the future value of each truck in the vector. The sum was printed in the console." << endl << endl;

  // Output of the printTruck method
  cout << "PrintTrucks method: " << endl;
  printTruck(trucks);

  // Sorted 10 Trucks alphabetically
  cout << endl << "Sorted by alphabetically: " << endl;
  sort(begin(trucks), end(trucks), [](Truck truck1, Truck truck2)
  {
    return truck1.getName() < truck2.getName();
  });
  printTruck(trucks);

  // Sorted vector of 10 Trucks by mileage
  stable_sort(begin(trucks), end(trucks), [](Truck truck1, Truck truck2)
  {
    return truck1.getMiles() < truck2.getMiles();
  });
  cout << endl << "Sorted by mileage: " << endl;
  printTruck(trucks);

  return 0;

}
