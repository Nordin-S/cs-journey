#include "Car.h"
#include "MyBinOp.h"
#include "MyFunc.h"
#include "MyPrint.h"
#include "MyUnOp.h"
#include "Predicate.h"
#include <array>
#include <iostream>
#include <numeric>
#include <vector>

using namespace metodik_laboration05;

int main() {
  // Create an array of Car objects
  std::array<Car, 4> carsArray{{Car("Ford", 120.5),
                                Car("Ford", 200),
                                Car("Toyota", 150),
                                Car("Honda", 100.25)}};

  // Create a second array of Car objects
  std::array<Car, 2> carsArray2{{Car("Ford", 200),
                                 Car("Toyota", 150)}};

  // Create a vector of Car objects
  std::vector<Car> carsContainer(carsArray.begin(), carsArray.end());


  std::cout << "### Printing out all elements with std::for_each and myPrint(): \n";
  std::for_each(carsContainer.begin(), carsContainer.end(), MyPrint());


  // Create a Predicate object for car type with a threshold of 150 horsepower
  Predicate<Car> predHorsepower(&Car::getHorsepower, 150);

  // Use find_if to find the first Car with horsepower greater than 150
  auto iter = std::find_if(carsContainer.begin(), carsContainer.end(), predHorsepower);

  std::cout << "### Print first car found with std::find_if with horsepower over threshold of 150: \n";
  if (iter != carsContainer.end())
    MyPrint()(*iter);


  // Create a Predicate object for car type with a threshold of 150 horsepower
  Predicate<Car> predMake;

  // Use adjacent_find to find the first pair of cars with the same name
  auto iter2 = std::adjacent_find(carsContainer.begin(), carsContainer.end(), predMake);
  // Print the make of the first pair of cars with the same name
  if (iter2 != carsContainer.end()) {
    std::cout << "### First pair of cars with the same name: \n";
    MyPrint()(*iter2);
    MyPrint()(*(iter2 + 1));
  }

  std::cout << "### Checking if array and vector contents are equal using std::equal: \n";
  // Use equal to compare the contents of the array and the vector
  bool are_equal = std::equal(std::begin(carsArray), std::end(carsArray),
                              carsContainer.begin(), carsContainer.end());

  // Print whether the array and the vector are equal
  if (are_equal)
    std::cout << "# The array and the vector are equal \n";
  else
    std::cout << "# The array and the vector are not equal \n";


  // Use std::search to find a subsequence of cars
  auto iter3 = std::search(carsContainer.begin(), carsContainer.end(), std::begin(carsArray2), std::end(carsArray2));
  // Print the make of the sequence of cars found
  if (iter3 != carsContainer.end()) {
    std::cout << "### Subsequence of cars found: \n";
    std::for_each(std::begin(carsArray2), std::end(carsArray2), MyPrint());
  }

  // Use std::accumulate to find average horsepower of all cars in container
  MyBinOp<Car> myBinOp(carsContainer.size());
  std::function<double(double, const Car &)> acc_binOp = [&myBinOp](double total, const Car &car) {
    myBinOp(total + car.getHorsepower());
    return total + car.getHorsepower();
  };
  std::accumulate(carsContainer.begin(), carsContainer.end(), double(), acc_binOp);
  std::cout << "### Average horsepower of all the cars in the container using std::accumulate: \n";
  std::cout << "# " << myBinOp.average() << "\n";


  // Create another vector of Car objects
  std::vector<double> v2;
  v2.resize(carsContainer.size());

  std::cout << "### Printing v2 unsorted \n";
  std::transform(carsContainer.begin(), carsContainer.end(), v2.begin(), MyUnOp());
  std::transform(v2.begin(), v2.end(), v2.begin(), MyFunc(myBinOp.average()));
  std::for_each(v2.begin(), v2.end(), [](double const &value){
    std::cout << value << "\n";
  });
  std::sort(v2.begin(), v2.end(), std::less());
  std::cout << "### Printing v2 sorted in ascending order \n";
  std::for_each(v2.begin(), v2.end(), [](double const &value){
    std::cout << value << "\n";
  });
}
