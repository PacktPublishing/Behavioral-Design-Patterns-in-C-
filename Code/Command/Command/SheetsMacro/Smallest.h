#pragma once
#include "Command.h"
class DataList;

class Smallest :
    public Command
{
	DataList *m_pData{} ;
public:
	Smallest(DataList* mPData)
		: m_pData{mPData} {
	}

	void Execute() override;
};

