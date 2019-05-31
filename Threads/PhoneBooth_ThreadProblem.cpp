#include "pch.h"
#include <iostream>
#include <thread>
#include <mutex>

/*
A lot of people run to a lone phone booth (no mobiles) to talk to their loved ones.
The first person to catch the door-handle of the booth, is the one who is allowed to use the phone.
He has to keep holding on to the handle of the door as long as he uses the phone,
otherwise someone else will catch hold of the handle, throw him out and talk to his wife. 
There's no queue system as such. When the person finishes his call, comes out of the booth and leaves the door handle, 
the next person to get hold of the door handle will be allowed to use the phone.

So ->
A thread is : Each person
The mutex is : The door handle
The lock is : The person's hand
The resource is : The phone
*/

std::mutex mutex_door_handle;
int i = 1;

void make_phone_call() {
	mutex_door_handle.lock(); //hold the door knob
	std::cout << "Person: " << i << " is talking in the booth\n";
	++i;
	mutex_door_handle.unlock(); //release the door knob
}

int main() {
	std::cout << "Main thread going on...\n";

	std::thread person1(make_phone_call);
	std::thread person2(make_phone_call);
	std::thread person3(make_phone_call);

	person1.join();
	person2.join();
	person3.join();
}