#pragma once
#include "Command.h"
class DataList;

class Remove :
    public Command
{
	DataList *m_pData{} ;
public:
	Remove(DataList* mPData)
		: m_pData{mPData} {
	}

	void Execute() override;
};

