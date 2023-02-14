#include "CommandUndo.h"

#include "UndoManager.h"
#include "Menu.h"

void CommandUndo::Execute(int id) {
	if(UndoManager::Undo()) {
		Message("Performed undo!") ;
	}else {
		Message("Nothing to undo") ;
	}
}

void CommandUndo::Undo() {
}

void CommandUndo::Redo() {
}
