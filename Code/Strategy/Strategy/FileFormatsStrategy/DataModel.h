#pragma once
#include <vector>

#include "CSVFormat.h"

class DataModel {
	std::vector<std::vector<int>> m_Sheet{};
	Format *m_pFormat{} ;
public:
	void SetExportType(Format *pFormat);
	void AddRow(std::vector<int> data);
	void Display();
	void Load();
	void Save();
	void Export();
	size_t RowCount() const;
	const std::vector<int>& GetRow(size_t index) const;
};
