#pragma once
#include "Command.h"

class DataList;

class Sum :
    public Command
{
	DataList *m_pData{} ;

public:
	Sum(DataList* mPData)
		: m_pData{mPData} {
	}

	void Execute() override;
};

