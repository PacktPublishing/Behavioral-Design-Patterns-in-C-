#pragma once
#include "Command.h"
class DataList;

class Largest :
    public Command
{
	DataList *m_pData{} ;

public:

	Largest(DataList* mPData)
		: m_pData{mPData} {
	}

	void Execute() override;
};

