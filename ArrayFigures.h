#pragma once

#ifndef ARRAYFIGURES_H
#define ARRAYFIGURES_H

template <typename T>
void createArr(T*& const arr, const short& count) {
	arr = new T[count];
}

template <typename T>
void copyArr(T*& const arr1, T*& const arr2, short count) {
	for (size_t i = 0; i < count; i++)
	{
		arr1[i] = arr2[i];
	}
}

template <typename T>
void fillArr(T*& const arr, const T& object, const short& count) {
	arr[count] = object;
}

template <typename T>
void cleanArr(T*& const arr) {
	delete[] arr;
	arr = nullptr;
 }

template <typename T>
void append(T*& const arr, const T& object, const short& count) 
{
	if (count == 0) {
		createArr(arr, count+1);
		fillArr(arr, object, count);
	}
	else 
	{
		T* arrTemp{};
		createArr(arrTemp, count);
		copyArr(arrTemp, arr, count);
		cleanArr(arr);

		createArr(arr, count + 1);
		copyArr(arr, arrTemp, count);
		fillArr(arr, object, count);
		cleanArr(arrTemp);
	}
}

#endif