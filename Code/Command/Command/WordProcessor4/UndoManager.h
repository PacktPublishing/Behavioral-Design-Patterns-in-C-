#pragma once
#include <list>
#include <memory>
#include <stack>

class Command ;
class UndoManager
{
	inline static std::stack<std::shared_ptr<Command>> m_Undo{} ;
	inline static std::stack<std::shared_ptr<Command>> m_Redo{} ;
	inline static bool m_IsUndo{false} ;
public:
	static void AddCommand(std::shared_ptr<Command>pCommand) ;
	static void RemoveCommand(std::shared_ptr<Command> pCommand) ;
	static bool Undo() ;
	static bool Redo() ;
};

