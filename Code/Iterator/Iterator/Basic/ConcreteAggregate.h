#pragma once
#include <cassert>

#include "Aggregate.h"

class ConcreteAggregate : public Aggregate<int>{
	static constexpr size_t MAX_SIZE{5} ;
	int m_Items[MAX_SIZE]{10, 20, 30, 40, 50} ;
	size_t m_Position{} ;
public:
	Iterator<int>* CreateIterator() const override;
	const int * GetArray()const {
		return m_Items ;
	}
	size_t Size()const {
		return m_Position ;
	}
	void Push(int item) {
		assert(m_Position < MAX_SIZE) ;
		m_Items[++m_Position] = item ;
	}
};

class ConcreteIterator : public Iterator<int> {
	size_t m_Position{} ;
	const ConcreteAggregate *m_pAgg{} ;
public:
	ConcreteIterator(const ConcreteAggregate * ca)
	:m_pAgg{ca} {
	}

	const int& CurrentItem() override {
		return m_pAgg->GetArray()[m_Position] ;
	}

	void First() override {
		m_Position = 0 ;
	}

	bool IsDone() const override {
		return m_Position == m_pAgg->Size() ;
	}

	void Next() override {
		++m_Position ;
	}
};
Iterator<int>* ConcreteAggregate::CreateIterator() const {
	return new ConcreteIterator{this};

}