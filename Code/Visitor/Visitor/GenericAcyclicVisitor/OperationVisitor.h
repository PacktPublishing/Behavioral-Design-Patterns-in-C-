#pragma once
template<typename Visitable>
class OperationVisitor {
public:
	virtual void Visit(Visitable *pVisitable) = 0 ;
	virtual ~OperationVisitor()=default ;
};
