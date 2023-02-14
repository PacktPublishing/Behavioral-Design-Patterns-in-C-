#pragma once
#include <fstream>
class DocSaver
{
protected:
	std::fstream m_Stream{};
	bool m_IsModified{false} ;
public:
	virtual void Save()=0;
	virtual void Load()=0;
	virtual ~DocSaver()=default ;
};