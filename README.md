# Custom Integr Vector
This is a custom IntegerVector class implemented in C++. It tries to demonstrate the implementation of the STL vector container.

## Features

- **Constructors**: The IntegerVector class provides several constructors such as the main constructor, size constructor, copy constructor, move constructor, and initializer list constructor.
- **Memory Management**: The IntegerVector class is responsible for its management, including dynamically creating and destroying memory.
- **Array Access**: The IntegerVector class supports array index access through the `operator[]` function. It has two overloaded versions, one for read-only access and one for mutable access.
- **Assignment Operators**: The IntegerVector class supports copy assignment, move assignment, and initializer list assignment.
- **Extra Functionalities**: The IntegerVector class has various handy functions such as `swap`, `push_back`, `clear`, `resize`, `copy_data`, etc.
- **Comparison**: The IntegerVector class supports comparison with `std::vector<int>` using `operator==`.
- **Data Erasure**: It supports erasing data using the `erase` function with a single position or a range (from first to last position).
- **Data Insertion**: You can insert values in a specific position or range with the `insert` function.

## Usage

To use the IntegerVector class, include `IntegerVector.h` in your C++ source file, and then create instances of IntegerVector like so:

```cpp
IntegerVector v; // Empty IntegerVector
IntegerVector v(5); // IntegerVector of size 5, all elements initialized to zero.
IntegerVector v{1, 2, 3, 4}; // IntegerVector initialized with an initializer list.
```
## Limitations
- This IntegerVector class is designed to work only with integer values.
- The IntegerVector class might perform sub-ideally for very large data sets due to its dynamic memory allocation strategy.
- Exceptions must be handled properly when using this class, several methods can throw `std::out_of_range` exception on invalid operations, so ensure sufficient error handling in your code.
## Contribution
Feel free to contribute to the IntegerVector class by creating a pull request.
