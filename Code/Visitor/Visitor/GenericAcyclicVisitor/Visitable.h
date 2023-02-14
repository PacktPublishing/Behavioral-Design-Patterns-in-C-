#pragma once
#include <iostream>
#include "Shape.h"
#include "OperationVisitor.h"
#include "Operation.h"
template<typename ShapeVisitable>
class Visitable : public Shape {
public:
	void Accept(Operation* pOperation) override {
		if(auto visitor = dynamic_cast<OperationVisitor<ShapeVisitable>*>(pOperation)) {
			visitor->Visit(static_cast<ShapeVisitable*>(this)) ;
		}else {
			std::cout << "Cannot visit\n" ;
		}
	}
};
