#include "DataModel.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void DataModel::SetExportType(ExportType type) {
	m_ExportType = type;
}

void DataModel::AddRow(std::vector<int> data) {
	m_Sheet.push_back(std::move(data));
}

void DataModel::Display() {
	for (auto row : m_Sheet) {
		for (auto element : row) {
			std::cout << element << ' ';
		}
		std::cout << '\n';
	}
}

void DataModel::Load() {
	m_Sheet.clear();
	std::ifstream input{ "data.sheet.txt" };
	if (!input) {
		std::cout << "Could not open file for writing\n";
		return;
	}
	std::string line;
	while (std::getline(input, line)) {
		std::vector<int> row{};
		int element{};
		std::istringstream istr{ line };
		while (istr >> element) {
			row.push_back(element);
		}
		AddRow(std::move(row));
	}
}

void DataModel::Save() {
	std::ofstream out{ "data.sheet.txt" };
	if (!out) {
		std::cout << "Could not open file for writing\n";
		return;
	}
	for (auto row : m_Sheet) {
		for (auto element : row) {
			out << element << ' ';
		}
		out << '\n';
	}
}

void DataModel::Export() {
	std::ofstream output;
	switch (m_ExportType) {
	case ExportType::CSV: //Default
		output.open("data.csv");
		for (auto row : m_Sheet) {
			for (auto element : row) {
				output << element << ',';
			}
			output << '\n';
		}
		break;
	case ExportType::HTML:
		output.open("data.html");
		output
			<< "<!DOCTYPE hmtl>\n"
			<< "<html>\n"
			<< "<body>\n";
		output << "<h1>Exported</h1>\n" ;
		for (auto row : m_Sheet) {
			output << "<p>" ;
			for (auto element : row) {
				output << element << ' ';
			}
			output << "</p>\n";
		}
		output
			<< "</html>\n"
			<< "</body>\n";
		break;
	}
}
