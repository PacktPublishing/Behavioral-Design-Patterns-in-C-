#pragma once
#include <vector>
namespace Old {
	template<typename T>
	class SafeVector {
		std::vector<T> m_Vector{};
		std::mutex m_Mtx{};
	public:
		void Add(const T& element) {
			std::lock_guard lck{ m_Mtx };
			m_Vector.push_back(element);
		}
		void Insert(size_t index, const T& element) {
			std::lock_guard lck{ m_Mtx };
			m_Vector.insert(begin(m_Vector) + index, element);
		}
		void Erase(size_t index) {
			std::lock_guard lck{ m_Mtx };
			m_Vector.erase(begin(m_Vector) + index);
		}
		T& operator[](int index) {
			return m_Vector[index];
		}
		const T& operator[](int index)const {
			return m_Vector[index];
		}
		size_t Size()const {
			std::lock_guard lck{ m_Mtx };
			return m_Vector.size();
		}
		void Print() {
			std::lock_guard lck{ m_Mtx };
			for (const auto& element : m_Vector) {
				std::cout << element << ' ';
			}
			std::cout << '\n';
		}
	};
}
namespace Bool {
	template<typename T>
	class SafeVector {
		std::vector<T> m_Vector{};
		std::mutex m_Mtx{};
		bool m_IsMultithreaded{ true };
	public:
		SafeVector(bool threadingModel) :m_IsMultithreaded{ threadingModel } {

		}
		void Add(const T& element) {
			if (m_IsMultithreaded) {
				m_Mtx.lock();
			}
			m_Vector.push_back(element);
			if (m_IsMultithreaded) {
				m_Mtx.unlock();
			}
		}
		void Insert(size_t index, const T& element) {
			std::lock_guard lck{ m_Mtx };
			m_Vector.insert(begin(m_Vector) + index, element);
		}
		void Erase(size_t index) {
			std::lock_guard lck{ m_Mtx };
			m_Vector.erase(begin(m_Vector) + index);
		}
		T& operator[](int index) {
			return m_Vector[index];
		}
		const T& operator[](int index)const {
			return m_Vector[index];
		}
		size_t Size()const {
			std::lock_guard lck{ m_Mtx };
			return m_Vector.size();
		}
		void Print() {
			std::lock_guard lck{ m_Mtx };
			for (const auto& element : m_Vector) {
				std::cout << element << ' ';
			}
			std::cout << '\n';
		}
	};
}
namespace Dynamic {
	class LockPolicy {
	public:
		virtual void lock() = 0;
		virtual void unlock() = 0;
		virtual ~LockPolicy() = default;
	};

	class MutexLock : public LockPolicy {
		std::mutex m_Mtx;
	public:
		void lock() override {
			m_Mtx.lock();
		}
		void unlock() override {
			m_Mtx.unlock();
		}
	};




	template<typename T>
	class SafeVector {
		class NullLock : public LockPolicy {
		public:
			void lock() override {}
			void unlock() override {}
		};
		std::vector<T> m_Vector{};
		LockPolicy* m_pLock{};
		inline static NullLock m_NullLock{};
	public:
		SafeVector(LockPolicy* p) :m_pLock{ p } {
			if (m_pLock == nullptr) {
				m_pLock = &m_NullLock;
			}
		}
		void Add(const T& element) {
			m_pLock->lock();
			m_Vector.push_back(element);
			m_pLock->unlock();
		}
		void Insert(size_t index, const T& element) {
			m_pLock->lock();
			m_Vector.insert(begin(m_Vector) + index, element);
			m_pLock->unlock();
		}
		void Erase(size_t index) {
			m_pLock->lock();
			m_Vector.erase(begin(m_Vector) + index);
			m_pLock->unlock();
		}
		T& operator[](int index) {
			return m_Vector[index];
		}
		const T& operator[](int index)const {
			return m_Vector[index];
		}
		size_t Size()const {
			m_pLock->lock();
			auto size = m_Vector.size();
			m_pLock->unlock();
			return size;
		}
		void Print() {
			m_pLock->lock();
			for (const auto& element : m_Vector) {
				std::cout << element << ' ';
			}
			std::cout << '\n';
			m_pLock->unlock();
		}
	};
}




class MutexLock {
	std::mutex m_Mtx;
public:
	void lock() {
		m_Mtx.lock();
	}
	void unlock() {
		m_Mtx.unlock();
	}
};

class NullLock {
public:
	void lock() {}
	void unlock() {}
};


template<
	typename T,
	typename LockPolicy = NullLock>
class SafeVector {
	std::vector<T> m_Vector{};
	LockPolicy m_pLock{};
public:
	void Add(const T& element) {
		m_pLock.lock();
		m_Vector.push_back(element);
		m_pLock.unlock();
	}
	void Insert(size_t index, const T& element) {
		m_pLock.lock();
		m_Vector.insert(begin(m_Vector) + index, element);
		m_pLock.unlock();
	}
	void Erase(size_t index) {
		m_pLock.lock();
		m_Vector.erase(begin(m_Vector) + index);
		m_pLock.unlock();
	}
	T& operator[](int index) {
		return m_Vector[index];
	}
	const T& operator[](int index)const {
		return m_Vector[index];
	}
	size_t Size()const {
		m_pLock.lock();
		auto size = m_Vector.size();
		m_pLock.unlock();
		return size;
	}
	void Print() {
		m_pLock.lock();
		for (const auto& element : m_Vector) {
			std::cout << element << ' ';
		}
		std::cout << '\n';
		m_pLock.unlock();
	}
};
