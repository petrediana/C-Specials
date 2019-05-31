#include "pch.h"
#include <iostream>
#include <thread>
#include <mutex>

class MyTestClass {
	std::mutex class_mutex;
	int count;
public:
	MyTestClass() : count(0) {}
	
	void operator()() {
		class_mutex.lock();
		std::cout << "Hello, I have been called by: " << this->count << std::endl;
		++count;
		class_mutex.unlock();
	}

	~MyTestClass() {
		std::cout << "Bye...\n";
	}
};

std::mutex global_mutex;
int count = 0;

auto lambda_show = []() {
	global_mutex.lock();
	std::cout << "Calling from lambda function is: " << count << std::endl;
	++count;
	global_mutex.unlock();
};


int main()
{
    std::cout << "Main thread going on...\n";

	std::cout << "Threads from lambda function synchronized ->\n\n";
	std::thread thread_obj1(lambda_show);
	std::thread thread_obj2(lambda_show);

	thread_obj1.join();
	thread_obj2.join();

	std::cout << "Threads from class synchronized -> \n\n";


	/*std::thread thread_obj3((MyTestClass{}));
	std::thread thread_obj4((MyTestClass{}));
	

	thread_obj3.join();
	thread_obj4.join();*/

	MyTestClass my_test_obj;
	std::thread thread_obj5(my_test_obj);
	thread_obj5.join();
}

