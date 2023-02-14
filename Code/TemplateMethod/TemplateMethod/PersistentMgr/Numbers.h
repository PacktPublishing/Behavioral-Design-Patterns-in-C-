#pragma once
#include "DocSaver.h"
class Numbers :
    public DocSaver
{
	int m_Number{} ;
	int m_Num2{} ;
	std::string m_Version{} ;
public:
	void SetNumber(int num);
	void Print()const ;
protected:
	void Read(std::ifstream& in) override;
	void ReadVersion(std::ifstream& in) override;
	void Write(std::ofstream& out) override;
	void WriteVersion(std::ofstream& out) override;
};

