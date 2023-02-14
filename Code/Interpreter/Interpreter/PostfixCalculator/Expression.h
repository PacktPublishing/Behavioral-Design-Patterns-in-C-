#pragma once
class Expression {
public:
	virtual int Interpret() = 0 ;
	virtual ~Expression()=default ;
};