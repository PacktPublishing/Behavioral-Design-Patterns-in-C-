#include <iostream>
#include <memory>
#include <vector>


#include "Circle.h"
#include "Line.h"
#include "Renderer.h"
#include "Window.h"


int main() {
	std::vector<std::unique_ptr<Shape>> shapes ;
	shapes.emplace_back(new Line{{0, 0}, {100, 200}});
	shapes.emplace_back(new Circle{{400, 400}, 100}) ;
	Window window{} ;
	window.Show() ;
	Renderer renderer{window.GetWindowHandle()} ;
	for(auto &shape : shapes) {
		/*if(auto line = dynamic_cast<Line*>(shape.get())) {
			std::cout << "Drawing a line\n" ;
		}else if(auto circle = dynamic_cast<Circle*>(shape.get())) {
			std::cout << "Drawing a circle\n" ;
		}*/
		renderer.Draw(shape.get()) ;
	}
	Application::Run() ;
}
