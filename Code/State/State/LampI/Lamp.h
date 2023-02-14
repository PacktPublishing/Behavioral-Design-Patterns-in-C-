#pragma once
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
	enum class State{OFF, ON};
	State m_State{State::OFF} ;
public:
	void SwitchOn() ;
	void SwitchOff() ;
	void SetState(State *pState) ;
};

