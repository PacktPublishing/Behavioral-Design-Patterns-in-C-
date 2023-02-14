#pragma once
#include "Command.h"
class DataList;

class Sort :
    public Command
{
	DataList *m_pData{} ;

public:
	Sort(DataList* mPData)
		: m_pData{mPData} {
	}

	void Execute() override;
};

