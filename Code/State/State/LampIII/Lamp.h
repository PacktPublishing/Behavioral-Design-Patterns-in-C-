#pragma once
#include "TransitionTable.h"
class State;

class Lamp
{
		const char *m_Image = 
R"(
           *********           
         *************         
        ***************        
       *****************       
       *****************       
       *****************       
        ***************        
          ***********          
           *********           
            *******            
            *******            
            *******             
             *****              
              ***              
)";
	State *m_pState{} ;
	TransitionTable m_Table{} ;
public:
	Lamp() ;
	~Lamp() ;
	const char * GetImage()const ;
	void SwitchOn() ;
	void SwitchOff() ;
	void SetState(State *pState) ;
};

