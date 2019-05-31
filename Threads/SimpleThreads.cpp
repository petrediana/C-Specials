#include "pch.h"
#include <iostream>
#include <thread>

void show_int_numbers(int num1, int num2) {
	std::cout << "This is a normal function -> ";
	std::cout << "Num1: " << num1 << " Num2: " << num2 << std::endl;
}

auto lambda_function_show_ints = [](int num1, int num2) {
	std::cout << "This is a lambda function -> ";
	std::cout << "Num1: " << num1 << " Num2: " << num2 << std::endl;
};

class TestClass {
public:
	void operator()(int num1, int num2) {
		std::cout << "Using function operator from the class -> ";
		std::cout << "Num1: " << num1 << " Num2: " << num2 << std::endl;
	}
};

int main()
{
	std::thread thread_obj(show_int_numbers, 3, 4);
	//launched the thread by using function pointer as callable
	thread_obj.join();

	std::thread thread_obj2(lambda_function_show_ints, 6, 7);
	//launched the thread by using lambda function
	thread_obj2.join();

	if (thread_obj2.joinable()) {
		std::cout << "Thread 2 is joinable\n";
	}
	else {
		std::cout << "Thread 2 is not joinable. Detached/Joined was applied\n";
	}

	std::thread thread_obj3((TestClass()), 10, 11);
	//launched the thread by overriding the function operator from the class
	thread_obj3.join();

	
	//Declare in thread main a lambda function
	auto another_lambda_to_show = [](int num1, int num2) {
		std::cout << "Local lambda function from main -> ";
		std::cout << "Num1: " << num1 << " Num2: " << num2 << std::endl;
	};

	std::thread thread_obj4(another_lambda_to_show, 678, 5743);
	thread_obj4.join();

	std::cout << "Main is printing now...\n";
}
