#pragma once
#include <memory>

class Expression
{
public:
	virtual bool Interpret() =0  ;
	virtual ~Expression()=default ;
};
using ExpressionPtr = std::shared_ptr<Expression> ;
