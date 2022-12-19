/*
Parker Haynie
12/15/2022
The Main File For The New & Improved Expanded C++ Calculator
*/

// This includes my own header file that I created for this project.
#include "finProj.h"
// This is the header file that includes built-in support for threads, atomic operations, mutual exclusions, condition variables, and futures.
#include <thread>

int main()
{
	// This line creates the "t1" and tells it to use the "displayTitle" function.
	thread t1{ displayTitle };
	// This line means that the "t1" thread will execute after the thread completion process.
	t1.join();
	// This line creates the "t2" and tells it to use the "loginOptions" function.
	thread t2{ loginOptions };
	// This line means that the "t2" thread will execute after the thread completion process.
	t2.join();
	//This line returns the value "0" after main has already ran through everything.
	return 0;
}
