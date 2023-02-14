#include "Button.h"
#include "LocalHelp.h"
#include "OnlineHelp.h"
#include "QuickHelp.h"

int main() {
	OnlineHelp online{} ;
	LocalHelp local{} ;
	QuickHelp quick{} ;

	quick.SetSuccessor(&local) ;
	local.SetSuccessor(&online) ;

	Button btn ;
	btn.SetHelpHandler(&quick) ;
	btn.RequestHelp("connection") ;
}
