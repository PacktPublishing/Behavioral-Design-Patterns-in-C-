#include "CSVFormat.h"

#include <iostream>

#include "DataModel.h"
CSVFormat::CSVFormat(const std::string& fileName) :m_Ostream{ fileName } {
	if(!m_Ostream) {
		throw std::runtime_error{"Could not open file for writing"} ;
	}
}

void CSVFormat::Export(DataModel* pModel) {
	for (size_t i = 0; i < pModel->RowCount(); ++i) {
		for (auto element : pModel->GetRow(i)) {
			m_Ostream << element << ',';
		}
		m_Ostream << '\n';
	}
	std::cout << "File exported successfully\n" ;
}
