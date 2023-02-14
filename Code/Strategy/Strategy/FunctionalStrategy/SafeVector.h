#pragma once
#pragma once
#include <vector>
#include <functional>
template<typename T>
class SafeVector {
	std::vector<T> m_Vector{};
	std::function<void(const std::vector<T>)> m_Printer{} ;
public:
	void SetPrinter(std::function<void(const std::vector<T>)> printer) {
		m_Printer = printer ;
	}
	void Add(const T& element) {
		m_Vector.push_back(element);
	}
	void Insert(size_t index, const T& element) {
		m_Vector.insert(begin(m_Vector) + index, element);
	}
	void Erase(size_t index) {
		m_Vector.erase(begin(m_Vector) + index);
	}
	T& operator[](int index) {
		return m_Vector[index];
	}
	const T& operator[](int index)const {
		return m_Vector[index];
	}
	size_t Size()const {
		return m_Vector.size();
	}
	void Print() {
		//talk about switch case here
		if(m_Printer) {
			m_Printer(m_Vector) ;
			return ;
		}
		for (const auto& element : m_Vector) {
			std::cout << element << ' ';
		}
		std::cout << '\n';
	}
};
