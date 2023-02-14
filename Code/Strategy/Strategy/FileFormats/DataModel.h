#pragma once
#include <vector>
enum class ExportType{CSV, HTML};
class DataModel
{
	std::vector<std::vector<int>> m_Sheet{} ;
	ExportType m_ExportType{ExportType::CSV} ;
public:
	void SetExportType(ExportType type);
	void AddRow(std::vector<int> data) ;
	void Display() ;
	void Load() ;
	void Save() ;
	void Export() ;
};

