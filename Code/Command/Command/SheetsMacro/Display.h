#pragma once
#include "Command.h"
class DataList;

class Display :
    public Command
{
	DataList *m_pData{} ;

public:
	Display(DataList* mPData)
		: m_pData{mPData} {
	}

	void Execute() override;
};

