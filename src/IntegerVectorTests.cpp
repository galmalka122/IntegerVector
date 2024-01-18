#include <vector>
#include "IntegerVector.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <cassert>

// Function declarations
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
        assert(pop_back_test() && "pop_back_test failed");
        assert(push_back_test() && "push_back_test failed");
        assert(swap_test() && "swap_test failed");
        assert(resize_test() && "resize_test failed");
        assert(clear_test() && "clear_test failed");
        assert(size_test() && "size_test failed");
        assert(data_test() && "data_test failed");
        assert(empty_test() && "empty_test failed");
        assert(operators_test() && "operators_test failed");
        assert(insert_test() && "insert_test failed");
        assert(erase_test() && "erase_test failed");

        std::cout << "Passed iteration " << (i + 1) << std::endl;
    }

    return 0;
}

/**
 * @brief Test the pop_back function for IntegerVector object against std::vector object.
 *
 * This function generates random data, pushes it into both a IntegerVector and a std::vector,
 * pops the values using pop_back, and checks if the resulting sums are equal.
 *
 * @return True if the test passes, false otherwise.
 */
bool pop_back_test()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int limit = rand() % 1000;

    // Additional test cases
    assert(IntegerVector().size() == 0 && "pop_back_test failed for an empty IntegerVector");
    assert(std::vector<int>().size() == 0 && "pop_back_test failed for an empty std::vector");

    for (int rangeIndex = 0; rangeIndex < limit; rangeIndex++) {
        std::vector<int> stdvector;
        int sum = 0;
        IntegerVector myvector;
        int sum1 = 0;

        for (int numbersInRange = 0; numbersInRange < rangeIndex; numbersInRange++) {
            stdvector.push_back(numbersInRange);
            myvector.push_back(numbersInRange);
        }

        while (!stdvector.empty()) {
            sum += stdvector.back();
            stdvector.pop_back();
        }

        while (!myvector.empty()) {
            sum1 += myvector.back();
            myvector.pop_back();
        }

        assert(sum1 == sum && "pop_back_test failed");
    }

    return true;
}

/**
 * @brief Additional test cases for push_back function.
 *
 * This function generates random data, pushes it into both a IntegerVector and a std::vector,
 * and checks if the resulting vectors are equal.
 *
 * @return True if the test passes, false otherwise.
 */
bool push_back_test()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int limit = rand() % 1000;

    std::vector<int> stdvector;
    IntegerVector myvector;
    int randint;

    IntegerVector emptyIntegerVector;
    std::vector<int> emptyStdIntegerVector;

    assert(emptyIntegerVector.size() == 0 && "push_back_test failed for an empty IntegerVector");
    assert(emptyStdIntegerVector.size() == 0 && "push_back_test failed for an empty std::vector");

    do {
        randint = rand() % 1000;;
        myvector.push_back(randint);
        stdvector.push_back(randint);

    } while (limit-- != 0);

    return myvector == stdvector;
}

/**
 * @brief Additional test cases for swap function.
 *
 * This function generates random vectors, swaps them using swap,
 * and checks if the resulting vectors are equal.
 *
 * @return True if the test passes, false otherwise.
 */
bool swap_test()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int length = rand() % 1000;
    int value = rand() % 1000;

    std::vector<int> foo(length, value);
    IntegerVector foo1(length, value);

    length = rand() % 1000;
    value = rand() % 1000;

    std::vector<int> bar(length, value);
    IntegerVector bar1(length, value);

    foo.swap(bar);

    IntegerVector emptyIntegerVector;
    std::vector<int> emptyStdIntegerVector;

    assert(emptyIntegerVector == emptyStdIntegerVector && "swap_test failed for empty vectors");

    if (foo != bar1 || bar != foo1) {
        return false;
    }

    foo1.swap(bar1);

    return foo == foo1 || bar == bar1;
}

/**
 * @brief Additional test cases for resize function.
 *
 * This function generates random vectors, resizes them using resize,
 * and checks if the resulting vectors are equal.
 *
 * @return True if the test passes, false otherwise.
 */
bool resize_test()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int limit = rand() % 1000;

    IntegerVector myvector;
    std::vector<int> stdvector;

    for (int i = 1; i < limit; i++) { myvector.push_back(i); stdvector.push_back(i); }

    stdvector.resize(5);
    myvector.resize(5);
    stdvector.resize(8, 100);
    myvector.resize(8, 100);
    stdvector.resize(12);
    myvector.resize(12);

    IntegerVector emptyIntegerVector;
    std::vector<int> emptyStdIntegerVector;

    assert(emptyIntegerVector == emptyStdIntegerVector && "resize_test failed for empty vectors");

    return myvector == stdvector;
}

/**
 * @brief Additional test cases for clear function.
 *
 * This function generates random vectors, clears them using clear,
 * and checks if the resulting vectors are equal.
 *
 * @return True if the test passes, false otherwise.
 */
bool clear_test()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int length = rand() % 1000;
    int value;

    IntegerVector myvector;
    std::vector<int> stdvector;

    while (length--) {
        value = rand() % 1000;
        myvector.push_back(value);
        stdvector.push_back(value);
    }

    IntegerVector emptyIntegerVector;
    std::vector<int> emptyStdIntegerVector;

    assert(emptyIntegerVector == emptyStdIntegerVector && "clear_test failed for initial empty vectors");

    emptyIntegerVector.clear();
    emptyStdIntegerVector.clear();

    assert(emptyIntegerVector == emptyStdIntegerVector && "clear_test failed for cleared vectors");

    return myvector == stdvector;
}

/**
 * @brief Additional test cases for size function.
 *
 * This function generates random vectors, checks their sizes,
 * and ensures they are equal.
 *
 * @return True if the test passes, false otherwise.
 */
bool size_test()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int limit = rand() % 1000;

    IntegerVector myvector;
    std::vector<int> stdvector;

    for (int i = 1; i < limit; i++) { myvector.push_back(i); stdvector.push_back(i); }

    return myvector.size() == stdvector.size();
}

/**
 * @brief Additional test cases for data function.
 *
 * This function generates random vectors, accesses their data,
 * and checks if the resulting vectors are equal.
 *
 * @return True if the test passes, false otherwise.
 */
bool data_test()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int value = rand() % 1000;

    IntegerVector myvector(5);
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

/**
 * @brief Additional test cases for empty function.
 *
 * This function generates a IntegerVector, checks if it's empty,
 * and ensures it's empty after popping all elements.
 *
 * @return True if the test passes, false otherwise.
 */
bool empty_test()
{
    // Case 1: Empty IntegerVector
    IntegerVector emptyIntegerVector;
    assert(emptyIntegerVector.empty() && "empty_test failed for an empty IntegerVector");

    // Case 2: Non-empty IntegerVector
    IntegerVector nonEmptyIntegerVector = { 1, 2, 3 };
    assert(!nonEmptyIntegerVector.empty() && "empty_test failed for a non-empty IntegerVector");

    // Case 3: IntegerVector becomes empty after popping all elements
    while (!nonEmptyIntegerVector.empty()) {
        nonEmptyIntegerVector.pop_back();
    }
    assert(nonEmptyIntegerVector.empty() && "empty_test failed for a IntegerVector after popping all elements");

    // Case 4: Empty IntegerVector after clear
    IntegerVector clearedIntegerVector = { 1, 2, 3 };
    clearedIntegerVector.clear();
    assert(clearedIntegerVector.empty() && "empty_test failed for a IntegerVector after clear");

    // Case 5: Non-empty IntegerVector after push_back
    IntegerVector pushedIntegerVector;
    pushedIntegerVector.push_back(42);
    assert(!pushedIntegerVector.empty() && "empty_test failed for a non-empty IntegerVector after push_back");

    return true;
}

/**
 * @brief Additional test cases for operators.
 *
 * This function generates vectors, reverses them using operators[],
 * and checks if the resulting vectors are equal.
 *
 * @return True if the test passes, false otherwise.
 */
bool operators_test()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int value = rand() % 1000;

    std::vector<int> stdvector(10);
    IntegerVector myvector(10);

    size_t sz = myvector.size();
    size_t sz1 = stdvector.size();

    for (int i = 1; i < 10; i++) { myvector.push_back(i); stdvector.push_back(i); }

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

/**
 * @brief Additional test cases for insert function.
 *
 * This function generates vectors, inserts elements using insert,
 * and checks if the resulting vectors are equal.
 *
 * @return True if the test passes, false otherwise.
 */
bool insert_test()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    int length = rand() % 1000;

    IntegerVector a = { 1,2,3,4,5,6,7,8,9,10 };
    std::vector<int> b = { 1,2,3,4,5,6,7,8,9,10 };

    int position = rand() % 10;

    int value = rand() % 1000;

    a.insert(position, length, value);
    b.insert(b.begin() + position, length, value);

    return a == b;
}

/**
 * @brief Additional test cases for erase function.
 *
 * This function generates vectors, erases elements using erase,
 * and checks if the resulting vectors are equal.
 *
 * @return True if the test passes, false otherwise.
 */
bool erase_test()
{
    IntegerVector a = { 1,2,3,4,5,6,7,8,9,10 };
    std::vector<int> b = { 1,2,3,4,5,6,7,8,9,10 };

    int position = rand() % 10;

    a.erase(position);
    b.erase(b.begin() + position);

    return a == b;
}
