#include "BalanceMemento.h"

BalanceMemento::BalanceMemento(int mBalance): m_Balance{mBalance} {
}

int BalanceMemento::GetBalance() const {
	return m_Balance ;
}
