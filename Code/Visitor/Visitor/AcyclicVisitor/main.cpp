#include <iostream>
#include <memory>
#include <vector>



#include "Area.h"
#include "Circle.h"
#include "Line.h"
#include "Renderer.h"
#include "Window.h"
#include "Rect.h"

int main() {
	std::vector<std::unique_ptr<Shape>> shapes ;
	shapes.emplace_back(new Line{{0, 0}, {100, 200}});
	shapes.emplace_back(new Circle{{400, 400}, 100}) ;
	shapes.emplace_back(new Rect{{600, 400}, {800, 800}}) ;
	Window window{} ;
	window.Show() ;
	Renderer renderer{window.GetWindowHandle()} ;
	Area area{} ;
	for(auto &shape : shapes) {
		shape->Accept(&renderer) ;
	}
	std::cout << "Area of circle:" << area.GetCircleArea() << '\n' ;
	Application::Run() ;
}
