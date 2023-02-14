#include "CommandRedo.h"

#include "UndoManager.h"
#include "Menu.h"

void CommandRedo::Execute(int id) {
	if(UndoManager::Redo()) {
		Message("Performed redo!") ;
	}else {
		Message("Nothing to redo") ;
	}
}

void CommandRedo::Redo() {
	
}

void CommandRedo::Undo() {
}
