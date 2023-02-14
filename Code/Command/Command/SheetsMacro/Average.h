#pragma once
#include "Command.h"
class DataList;

class Average :
    public Command
{
	DataList *m_pData{} ;
public:
	Average(DataList* mPData)
		: m_pData{mPData} {
	}

	void Execute() override;
};

