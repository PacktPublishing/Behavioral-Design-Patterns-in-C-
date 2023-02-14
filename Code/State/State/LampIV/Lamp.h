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
	TransitionTable m_Table{} ;
	struct LampImpl ;
	std::unique_ptr<LampImpl> m_pImpl{} ;
	std::string m_CurrentState{"off_state"} ;
public:
	Lamp() ;
	~Lamp() ;
	void SwitchOn() ;
	void SwitchOff() ;
};

