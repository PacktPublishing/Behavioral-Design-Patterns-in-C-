#pragma once
#include <fstream>
class DocSaver
{
private:
	bool m_IsModified{false} ;
public:
	void Save() ;
	void Load() ;
	virtual ~DocSaver()=default ;
protected:
	enum class DialogType{Save, Load};
	bool IsModified()const{return m_IsModified ;}
	void SetModified(bool modified){m_IsModified = modified;}
	virtual void Write(std::ofstream & out) = 0 ;
	virtual void Read(std::ifstream &in) = 0 ;
	std::string FileDialog(DialogType type)const ;
	virtual void WriteVersion(std::ofstream & out)  ;
	virtual void ReadVersion(std::ifstream &in) ;
};

