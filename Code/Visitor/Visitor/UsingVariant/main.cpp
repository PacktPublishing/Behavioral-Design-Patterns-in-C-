#include <iostream>
#include <memory>
#include <numbers>
#include <vector>
#include <variant>

#include "Circle.h"
#include "Line.h"
#include "Renderer.h"
#include "Window.h"
#include "Rect.h"

template<typename...Ts>
struct Overload:Ts...{
	using Ts::operator()...;
} ;

template<typename...Ts> Overload(Ts...) -> Overload<Ts...> ;

int main() {
	std::vector<std::variant<Line, Circle, Rect>> shapes ;
	shapes.emplace_back(Line{{0, 0}, {100, 200}});
	shapes.emplace_back(Circle{{400, 400}, 100}) ;
	shapes.emplace_back(Rect{{400, 400}, {600, 700}}) ;
	Window window{} ;
	//window.Show() ;
	Renderer renderer{window.GetWindowHandle()} ;
	for(auto &shape : shapes) {
		//std::visit(renderer, shape) ;
		/*std::visit([](auto &shp) {
			using T = std::decay_t<decltype(shp)> ;
			if constexpr (std::is_same_v<T, Circle>) {
				std::cout << "Circle:" <<
					(2 * std::numbers::pi * shp.GetRadius() * shp.GetRadius()) << '\n' ;
			}else if constexpr(std::is_same_v<T, Rect>) {
				auto length = shp.GetBottomRight().x - shp.GetTopLeft().x ;
				auto height = shp.GetBottomRight().y - shp.GetTopLeft().y ;
				std::cout << "Rect:" << length * height << '\n' ;
			}
		}, shape) ;*/

		std::visit(Overload{
			[](const Circle &circle) {
				std::cout << "Circle:" <<
					(2 * std::numbers::pi * circle.GetRadius() * circle.GetRadius()) << '\n' ;

			},
			[](const Rect &rect) {
				auto length = rect.GetBottomRight().x - rect.GetTopLeft().x ;
				auto height = rect.GetBottomRight().y - rect.GetTopLeft().y ;
				std::cout << "Rect:" << length * height << '\n' ;
			},
			[](const Line &line) {
				std::cout << "Cannot compute area of a line\n" ;
			}
		}, shape) ;
	}
	//Application::Run() ;
}
