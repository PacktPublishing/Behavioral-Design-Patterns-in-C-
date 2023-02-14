#include "HTMLFormat.h"

#include <iostream>

#include "DataModel.h"
HTMLFormat::HTMLFormat(const std::string& fileName) : m_Ostream{ fileName } {
	if (!m_Ostream) {
		throw std::runtime_error{ "Could not open file for writing" };
	}
}

void HTMLFormat::Export(DataModel* pModel) {
	m_Ostream
		<< "<!DOCTYPE hmtl>\n"
		<< "<html>\n"
		<< "<body>\n";
	m_Ostream << "<h1>Exported</h1>\n";
	for (size_t i = 0; i < pModel->RowCount(); ++i) {
		m_Ostream << "<p>";
		for (auto element : pModel->GetRow(i)) {
			m_Ostream << element << ' ';
		}
		m_Ostream << "</p>\n";
	}
	m_Ostream
		<< "</html>\n"
		<< "</body>\n";
	std::cout << "File exported successfully\n" ;
}
