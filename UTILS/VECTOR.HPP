#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stddef.h>
#include <stdlib.h>

template <class T>
class Vector {
private:
	size_t capacity;
	size_t size;
	T *data;
	void resize(size_t newSize) {
		T *newArr = new T[newSize];
		for (size_t i = 0; i < size; ++i) {
			newArr[i] = this->data[i];
		}
		delete[] this->data;
        this->data = newArr;
		this->capacity = newSize;
	}
public:
	Vector() {
		this->capacity = 8;
		this->size = 0;
		data = new T[8];
	};
	Vector(size_t size) {
		this->capacity = size;
		this->size = 0;
		this->data = new T[size];
	};
	~Vector() {
		delete[] this->data;
		this->data = NULL;
		this->capacity = 0;
		this->size = 0;
	};
	T pop() {
		return this->data[--this->size];
	}
	T& get(size_t idx) {
		return this->data[idx];
	}
	const T& get(size_t idx) const {
		return this->data[idx];
	}
	T& operator[](size_t idx) {
		return this->get(idx);
	}
	const T& operator[](size_t idx) const {
		return this->get(idx);
	}
	void push(T element) {
		if (this->size == this->capacity) {
			this->resize(this->size * 2);
		}
		this->data[this->size++] = element;
	}
	const size_t getSize() {
		return this->size;
	}
	void quickSort(int (*compare)(const void *, const void *)) {
		qsort(this->data, this->size, sizeof(this->data[0]), compare);
	}
}
#endif
