

#include <iostream>
#include <mutex>

#include <thread>
#include "SafeVector.h"
SafeVector<int> coll;
void Operate() {
	coll[0] = 100;
	for (int i = 0; i < 50; ++i) {
		coll.Insert(i, i * 100);
	}
}
int main() {
	using namespace std;
	for (int i = 0; i < 100; ++i) {
		coll.Add(i);
	}
	std::thread t{ Operate };
	//std::this_thread::sleep_for(100ms) ;
	//mtx.lock() ;
	coll.Print();
	//mtx.unlock() ;
	t.join();

}
