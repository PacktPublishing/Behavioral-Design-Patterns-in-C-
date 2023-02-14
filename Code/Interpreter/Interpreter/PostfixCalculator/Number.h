#pragma once
#include "Expression.h"
class Number :
    public Expression
{
	int m_Number{} ;

public:
	explicit Number(int number);
	int Interpret() override;
};

