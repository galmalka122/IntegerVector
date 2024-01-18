#include "Vector.h"

/*
	Main consturctor - gets size and value and initalizes the vector.
	*/
Vector::Vector(size_t size = 0, int value = 0) : _size(size), _capacity(size) {

	_data = new int[_capacity];
	for (size_t index = 0; index < _size; index++) {
		_data[index] = value;
	}

}

Vector::Vector(size_t size) : _size(size), _capacity(size) {

	_data = new int[_capacity];

	for (size_t index = 0; index < _size; index++) {
		_data[index] = 0;
	}
}

Vector::Vector(const Vector& other) {

	_size = other._size;
	_capacity = other._capacity;
	_data = new int[_capacity];
	copy_data(other._data, &_data, other._size);

}

Vector::Vector(Vector&& other) noexcept {

	_size = other._size;
	_capacity = other._capacity;
	_data = other._data;
	other._data = nullptr;
}

Vector::Vector(const std::initializer_list<int> initializer) {

	_size = initializer.size();
	_capacity = _size;
	_data = new int[_capacity];
	copy_data(initializer.begin(), &_data, _size);
}

Vector::~Vector() {

	if (_data) {

		delete[] _data;
	}
}

int& Vector::operator[] (size_t index) {

	if (index < 0 || index > _size - 1) {

		throw std::out_of_range("Array index out of bounds.");
	}
	return *(_data + index);
}

const int& Vector::operator[] (size_t index) const {

	if (index < 0 || index > _size - 1) {

		throw std::out_of_range("Array index out of bounds.");
	}

	return *(_data + index);
}

Vector& Vector::operator= (const Vector& other) {

	if (this != &other) {

		_size = other._size;
		_capacity = other._capacity;
		if(_data)
			delete[] _data;
		_data = new int[_capacity];
		copy_data(other._data, &_data, other._size);
	}

	return *this;
}

Vector& Vector::operator= (Vector&& other)noexcept {

	if (this != &other) {

		delete[] this->_data;
		_size = other._size;
		_capacity = other._capacity;
		_data = other._data;
		other._data = nullptr;
	}

	return *this;
};

Vector& Vector::operator= (const std::initializer_list<int> initializer) {
	*this = Vector(initializer);
	return *this;
};



void Vector::swap(Vector& other) {

	//swap capacity
	other._capacity += _capacity;
	_capacity = other._capacity - _capacity ;
	other._capacity -= _capacity;

	//swap size
	other._size += _size;
	_size = other._size - _size;
	other._size -= _size;


	//swap data
	int* temp = other._data;
	other._data = _data;
	_data = temp;

	temp = nullptr;
}


void Vector::push_back(const int& value) {

	if (_size == _capacity) {

		if (_capacity == 0) {

			_capacity = 2;
			_data = new int[_capacity];
		}

		else {

			_capacity = _capacity < 128 ? _capacity * 2 : _capacity * 1.5;
			int* newData = new int[_capacity];
			copy_data(_data, &newData, _size);
			delete[] _data;
			_data = newData;
			newData = nullptr;
		}
	}

	*(_data +_size) = value;
	_size++;

}	

void Vector::clear() noexcept {

	_size = 0;
	_capacity = 0;
	if (_data)
		delete[] _data;
	_data = nullptr;
}

void Vector::resize(size_t newSize) {

	if (newSize > _capacity) {

		_capacity = newSize < 128 ? newSize * 2 : newSize * 1.5;
		int* temp = _data;
		_data = new int[_capacity];
		copy_data(_data, &temp, _size);
		delete[] temp;
	}

	for (; _size < newSize; _size++) {
		_data[_size] = 0;
	}

	_size = newSize;
}

void Vector::resize(size_t newSize, const int& value = 0) {

	if (newSize > _capacity) {

		_capacity = newSize < 128 ? newSize * 2 : newSize * 1.5;
		int* temp = _data;
		_data = new int[_capacity];
		copy_data(_data, &temp, _size);
		delete[] temp;
	}

	for (; _size < newSize; _size++) {
		_data[_size] = value;
	}
}

void Vector::copy_data(const int* a, int** b,const size_t& size) {
	
	for (size_t i = 0; i < size; i++) {
		*(*b + i) = *(a + i);
	}
}

bool Vector::operator==(const std::vector<int>& other) const {

	if (_size != other.size()) return false;
	for (size_t i = 0; i < _size ; i++) {
		if (_data[i] != other[i]) {
			return false;
		}
	}

	return true;
}

int& Vector::erase(const size_t position) {
	if (position < 0) {
		throw std::out_of_range("cannot seek vector before begin.");
	}
	if (position > _size - 1) {
		throw std::out_of_range("cannot seek vector after end.");
	}
	for (size_t i = position; i < _size - 1; i++) {
		_data[i] = _data[i + 1];
	}
	_size--;
	return _data[_size - 1];
}

int& Vector::erase(const size_t first, const size_t last) {
	if (first < 0) {
		throw std::out_of_range("cannot seek vector before begin.");
	}
	if (last > _size - 1) {
		throw std::out_of_range("cannot seek vector after end.");
	}
	if (first > last) {
		throw std::out_of_range("vector erase iterator outside range");
	}
	size_t dif = (last - first);
	for (size_t i = first; i < last - 1 && i + dif < _size - 1; i++) {
		_data[i] = _data[i + (last - first)];
	}
	_size -= dif;
	return _data[_size - 1];
}