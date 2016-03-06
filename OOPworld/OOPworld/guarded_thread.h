#pragma once
#include <thread>

using namespace std;

struct guarded_thread : thread {
	using thread::thread;
	~guarded_thread() {
		if (joinable())
			join();
	}
};