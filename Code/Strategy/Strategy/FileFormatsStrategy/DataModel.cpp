#include "DataModel.h"

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "Format.h"
void DataModel::SetExportType(Format *pFormat) {
	m_pFormat = pFormat ;
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
	if(m_pFormat) {
		m_pFormat->Export(this) ;
	}else {
		std::cout << "Choose a format before exporting\n" ;
	}
	
}

size_t DataModel::RowCount() const {
	return m_Sheet.size() ;
}

const std::vector<int> & DataModel::GetRow(size_t index) const {
	return m_Sheet[index] ;
}
