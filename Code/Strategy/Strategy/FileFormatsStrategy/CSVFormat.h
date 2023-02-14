#pragma once
#include <fstream>
#include <string>

#include "Format.h"

class CSVFormat : public Format
{
	std::ofstream m_Ostream{} ; ;
public:
	CSVFormat(const std::string & fileName) ;
	void Export(DataModel *pModel) ;
};

