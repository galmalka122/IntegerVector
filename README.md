This is a custom Vector class implemented in C++. It extends beyond the Standard Library Vector class with some extra functionalities.

## Features
- ### Constructors - The Vector class provides several constructors such as main constructor, size constructor, copy constructor, move constructor and initializer list constructor.
- Memory Management - The Vector class is responsible for its own memory management including creating and destroying memory dynamically.
- Array Access - The Vector class supports array index access through the operator[] function. It has two overloaded versions, one for read-only access and one for mutable access.
- Assignment Operators - The Vector class supports copy assignment, move assignment and initializer list assignment.
- Extra Functionalities - The Vector class has various handy functions such as swap, push_back, clear, resize, copy_data, etc.
- Comparison - The Vector class supports comparison with std::vector<int> using operator==.
- Data Erasure - It supports erasing data using the erase function with a single position or a range (from first to last position).
- Data Insertion - You can insert values in a specific position or range with the insert function.
## Usage
To use the Vector class, include Vector.h in your C++ source file, and then create instances of Vector like so:
```C++
Vector v; // Empty Vector
Vector v(5); // Vector of size 5, all elements initialized to zero.
Vector v{1, 2, 3, 4}; // Vector initialized with an initializer list.
```
Limitations
This Vector class is designed to work only with integer values.
The Vector class might perform sub-ideally for very large data sets due to its dynamic memory allocation strategy.
Exceptions must be handled properly when using this class, several methods can throw std::out_of_range exception on invalid operations, so make sure to incorporate sufficient error handling in your code.
Contribution
Feel free to contribute to the Vector class by creating a pull request.