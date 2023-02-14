#include "DocSaver.h"

#include <iostream>
#include <string>


void DocSaver::Save() {
	if(!m_IsModified) {
		std::cout << "Already saved\n" ;
		return ;
	}
	std::ofstream out{FileDialog(DialogType::Save)} ;
	WriteVersion(out) ;
	Write(out) ;
	m_IsModified = false;
	std::cout << "----- File saved successfully -----\n" ;
}

void DocSaver::Load() {
	if(m_IsModified) {
		std::cout << "Save current changes first\n" ;
		return ;
	}
	std::ifstream input{FileDialog(DialogType::Load)} ;
	ReadVersion(input) ;
	Read(input) ;
	std::cout << "----- File loaded successfully -----\n" ;
}

std::string DocSaver::FileDialog(DialogType type)const {
	std::string fileName{} ;
	if(type == DialogType::Save ) {
		std::cout << "Name of the file to save?";
	}else if(type == DialogType::Load) {
		std::cout << "Name of the file to load?" ;
	}
	
	std::getline(std::cin, fileName);
	return fileName ;
}

void DocSaver::WriteVersion(std::ofstream &out) {
	//Nothing to do
}

void DocSaver::ReadVersion(std::ifstream &in) {
	//Nothing to do
}
