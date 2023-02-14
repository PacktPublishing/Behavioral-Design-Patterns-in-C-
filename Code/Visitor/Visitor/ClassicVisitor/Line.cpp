#include "Line.h"

#include "Operation.h"


void Line::Accept(Operation* pOperation) {
	pOperation->VisitLine(this) ;
}

void Line::SetStart(const Point& start) {
	m_Start = start ;
}

void Line::SetEnd(const Point& end) {
	m_End = end ;
}

Line::Line(const Point& start, const Point& end): m_Start{start},
                                                  m_End{end} {
}

const Point& Line::GetStart() const {
	return m_Start ;
}

const Point& Line::GetEnd() const {
	return m_End ;
}
