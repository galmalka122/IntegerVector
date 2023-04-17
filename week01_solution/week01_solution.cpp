// week01_solution.cpp : Defines the entry point for the application.
//


#include <vector>
#include "Vector.h"
#include<time.h>
#include <stdlib.h>
#include <stdio.h>

bool pop_back_test();
bool push_back_test();
bool swap_test();
bool resize_test();
bool clear_test();
bool size_test();
bool data_test();
bool empty_test();
bool operators_test();
bool insert_test();
bool erase_test();

int main()
{
	for (int i = 0; i < 10; i++) {
		bool test = pop_back_test();
		test &= push_back_test();
		test &= swap_test();
		test &= resize_test();
		test &= clear_test();
		test &= size_test();
		test &= data_test();
		test &= empty_test();
		test &= operators_test();
		test &= insert_test();
		test &= erase_test();

		if (test) {
			std::cout << "Passed" << std::endl;
		}
		else {
			std::cout << "Failed" << std::endl;
		}
	}
	return 0;
}


/*
* tests the pop_back function for Vector object against std::vector object.
*/
bool pop_back_test()
{
	//generate random number for the number of repeats
	srand(time(NULL));
	int limit = rand() % 1000;

	for (int rangeIndex = 0; rangeIndex < limit; rangeIndex++) {

		//create std::vector object, Vector object and 2 integers to sum all values inside each
		std::vector<int> stdvector;
		int sum(0);
		Vector myvector;
		int sum1(0);

		//push values to each vector
		for (int numbersInRange = 0; numbersInRange < rangeIndex; numbersInRange++) {
			stdvector.push_back(numbersInRange);
			myvector.push_back(numbersInRange);
		}

		//pop all values from std::vector
		while (!stdvector.empty())
		{
			sum += stdvector.back();
			stdvector.pop_back();
		}
		
		//pop all values from Vector
		while (!myvector.empty())
		{
			sum1 += myvector.back();
			myvector.pop_back();
		}

		//check the sum of Vector is equal to the sum of std::vector
		if (sum1 != sum) {
			return false; 
		}
	}

	return true;
}

bool push_back_test()
{
	//generate random number for the number of repeats
	srand(time(NULL));
	int limit = rand() % 1000;

	//create std::vector object, Vector object and integer to generate random number and push it to vectors
	std::vector<int> stdvector;
	Vector myvector;
	int randint;

	//generate random number and push it to vectors
	do {
		randint = rand() % 1000;;
		myvector.push_back(randint);
		stdvector.push_back(randint);

	} while (limit-- != 0);

	return myvector == stdvector;
}

bool swap_test()
{
	//generate random number for the number of repeats
	srand(time(NULL));
	int length = rand() % 1000;
	int value = rand() % 1000;


	std::vector<int> foo(length, value);
	Vector foo1(length, value);

	length = rand() % 1000;
	value = rand() % 1000;

	std::vector<int> bar(length, value);
	Vector bar1(length, value);

	foo.swap(bar);

	if (foo != bar1 || bar != foo1) {
		return false;
	}

	foo1.swap(bar1);
	
	return foo == foo1 || bar == bar1;
}

bool resize_test()
{

	//generate random number for the number of repeats
	srand(time(NULL));
	int limit = rand() % 1000;

	Vector myvector;
	std::vector<int> stdvector;

	// set some initial content:
	for (int i = 1; i < limit; i++) { myvector.push_back(i); stdvector.push_back(i); }

	stdvector.resize(5);
	myvector.resize(5);
	stdvector.resize(8, 100);
	myvector.resize(8, 100);
	stdvector.resize(12);
	myvector.resize(12);

	return myvector == stdvector;
}

bool clear_test()
{
	//generate random number for the number of repeats
	srand(time(NULL));
	int length = rand() % 1000;
	int value;

	Vector myvector;
	std::vector<int> stdvector;

	while (length--) {
		value = rand() % 1000;
		myvector.push_back(value);
		stdvector.push_back(value);
	}

	if (myvector != stdvector) return false;
	myvector.clear();
	stdvector.clear();

	value = rand() % 1000;
	myvector.push_back(value);
	stdvector.push_back(value);
;
	return myvector == stdvector;
}

bool size_test()
{
	//generate random number for the number of repeats
	srand(time(NULL));
	int limit = rand() % 1000;

	Vector myvector;
	std::vector<int> stdvector;

	// set some initial content:
	for (int i = 1; i < limit; i++) { myvector.push_back(i); stdvector.push_back(i); }

	return myvector.size() == stdvector.size();
}

bool data_test()
{
	//generate random number for the number of repeats
	srand(time(NULL));
	int value = rand() % 1000;

	Vector myvector(5);
	std::vector<int> stdvector(5);

	int* p = myvector.data();
	int* p1 = stdvector.data();
	*p = value;
	*p1 = value;
	++p;
	++p1;
	value = rand() % 1000;
	*p = value;
	*p1 = value;
	value = rand() % 1000;
	p[2] = value;
	p1[2] = value;

	return myvector == stdvector;
}

bool empty_test()
{
	//create std::vector object, Vector object and 2 integers to sum all values inside each
	Vector myvector;
	int sum(0);

	for (int i = 1; i < 10; i++) { myvector.push_back(i); }

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	return true;
}

bool operators_test()
{

	srand(time(NULL));
	int value = rand() % 1000;

	std::vector<int> stdvector(10);   // 10 zero-initialized elements
	Vector myvector(10);

	size_t sz = myvector.size();
	size_t sz1 = stdvector.size();

	// assign some values:
	for (int i = 1; i < 10; i++) { myvector.push_back(i); stdvector.push_back(i); }

	// reverse vector using operator[]:
	for (unsigned i = 0; i < sz / 2; i++)
	{
		int temp;
		temp = myvector[sz - 1 - i];
		myvector[sz - 1 - i] = myvector[i];
		myvector[i] = temp;
	}
	for (unsigned i = 0; i < sz1 / 2; i++)
	{
		int temp;
		temp = stdvector[sz1 - 1 - i];
		stdvector[sz1 - 1 - i] = stdvector[i];
		stdvector[i] = temp;
	}

	return myvector == stdvector;
}

bool insert_test()
{
	srand(time(NULL));
	int length = rand() % 1000;

	Vector a = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> b = { 1,2,3,4,5,6,7,8,9,10 };

	int position = rand() % 10;

	int value = rand() % 1000;

	a.insert(position, length, value);
	b.insert(b.begin() + position, length, value);

	return a == b;
}

bool erase_test()
{
	Vector a = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> b = { 1,2,3,4,5,6,7,8,9,10 };

	int position = rand() % 10;

	a.erase(position);
	b.erase(b.begin() + position);

	return a == b;
}
