#pragma once
#include "Command.h"
class DataList;

class Add :
    public Command
{
	DataList *m_pData{} ;

public:
	Add(DataList* mPData)
		: m_pData{mPData} {
	}

	void Execute() override;
};

