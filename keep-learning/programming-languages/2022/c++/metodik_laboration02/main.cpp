#include "Circle.h"
#include "Cylinder.h"
#include "Parallelepiped.h"
#include "Rectangle.h"
#include "RoundedRect.h"
#include <iostream>
#include <memory>
#include <vector>

using namespace metodik_laboration02;
// using shape_list_t = std::vector<Shape *>;
using p_shape_t = std::unique_ptr<Shape>;

void getData(std::vector<p_shape_t> &p_shapeList) {
  double totalArea{};
  for (auto const &shape : p_shapeList) {
    totalArea += shape->getArea();
    //    Rectangle const* const rect = dynamic_cast<Rectangle *>(*shape);
    //    if (rect)
    std::cout << shape->getShapeType() << ": " << shape->getColour() << " - "
              << shape->getArea() << " area \n";
  }
  std::cout << "Total area for all shapes: " << totalArea << " area \n";
}

int main() {
  std::vector<p_shape_t> shapelist;
  shapelist.push_back(std::make_unique<Rectangle>("Black", 10.0, 10.0));
  shapelist.push_back(
      std::make_unique<Parallelepiped>("Orange", 10.5, 8.5, 10));
  shapelist.push_back(std::make_unique<RoundedRect>("Blue", 12, 12, 2.5));
  shapelist.push_back(std::make_unique<Circle>("Red", 2.5));
  shapelist.push_back(std::make_unique<Cylinder>("Green", 2.5, 10));

  getData(shapelist);
}