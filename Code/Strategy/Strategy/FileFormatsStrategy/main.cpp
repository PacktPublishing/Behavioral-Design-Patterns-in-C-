#include <iostream>

#include "DataModel.h"
#include "HTMLFormat.h"

void Input(DataModel& model) {
	int rows{};
	int element{};
	std::cout << "Rows?";
	std::cin >> rows;
	for (int i = 0; i < rows; ++i) {
		std::vector<int> rowElements{};
		std::cout << "Columns?";
		int columns{};
		std::cin >> columns;
		for (int j = 0; j < columns; ++j) {
			std::cin >> element;
			rowElements.push_back(element);
		}
		model.AddRow(std::move(rowElements)) ;
	}
}
int main() {
	DataModel model{};
	//Input(model) ;
	model.AddRow({1,2,3,4}) ;
	model.AddRow({5,6,7,8}) ;
	//CSVFormat fmt{"data.csv"} ;
	HTMLFormat fmt{"num.html"} ;
	model.SetExportType(&fmt) ;
	model.Export() ;
	
	//model.Load() ;
	model.Display() ;

}
