#include "ValueExpression.h"

ValueExpression::ValueExpression(const std::string& context): m_Context{context} {
}

bool ValueExpression::Interpret() {
	return std::stoi(m_Context) != 0;
}
