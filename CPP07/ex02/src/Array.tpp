#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(NULL), size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), size(n)
{
	for (unsigned int i = 0; i < n; ++i) {
		array[i] = T();
	}
}

template <typename T>
Array<T>::Array(const Array &src) : array(new T[src.size]), size(src.size)
{
	for (unsigned int i = 0; i < size; i++) {
		array[i] = src.array[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	if (this != &src) {
		delete[] array;
		array = new T[src.size];
		size = src.size;
		for (unsigned int i = 0; i < size; i++) {
			array[i] = src.array[i];
		}
	}
	return (*this);
}

template <typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= size) {
		throw std::out_of_range("index out of range.");
	}
	return (array[index]);
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= size) {
		throw std::out_of_range("index out of range.");
	}
	return (array[index]);
}

template <typename T>
unsigned int Array<T>::getSize() const
{
	return (size);
}

template <typename T>
Array<T>::~Array()
{
	if (array != NULL) {
		delete[] array;
	}
}