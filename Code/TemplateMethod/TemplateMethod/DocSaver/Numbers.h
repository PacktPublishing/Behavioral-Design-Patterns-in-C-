#pragma once
#include "DocSaver.h"
class Numbers :
    public DocSaver
{
	int m_Number{} ;
public:
	void SetNumber(int num) ;
	void Load() override;
	void Save() override;
	void Print() ;
};

