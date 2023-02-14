#pragma once
#include "Format.h"
#include <fstream>
class HTMLFormat :
    public Format
{
	std::ofstream m_Ostream{} ;
public:

	HTMLFormat(const std::string& fileName);

	void Export(DataModel* pModel) override;
};

