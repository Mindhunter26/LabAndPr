#include "pch.h"
#include <iostream>

struct IntArray {
	int *data;
	int size;
};

void create(IntArray* arr, int size) {
	arr->data = new int[size];
	arr->size = size;
}

int get(IntArray* arr, int index) {
	if (index < 0 && index >= arr->size) std::cout << "Out of range" << std::endl;
	else return arr->data[index];
}

void set(IntArray* arr, int index, int value) {
	if (index < 0 && index >= arr->size) std::cout << "Out of range" << std::endl;
	else arr->data[index] = value;
}

void print(IntArray* arr) {
	std::cout << "[";
	for (int i = 0; i < arr->size - 1; i++)
		std::cout << arr->data[i] << ", ";
	std::cout << arr->data[arr->size - 1] << "]" << std::endl;
}

void resize(IntArray* arr, int newSize) {
	int* newArr = new int[newSize];
	
	for (int i = 0; i < (newSize > arr->size ? arr->size : newSize); i++)
		newArr[i] = arr->data[i];
	delete[] arr->data;
	arr->data = newArr;
	if (newSize > arr->size)
		for (int i = arr->size; i < newSize; i++) arr->data[i] = 0;
	arr->size = newSize;
}

void free(IntArray* arr, int newSize) {
	if (arr->data == 0x0) std::cout <<" ptr = NULL"<<std::endl;
	delete[] arr->data;
	arr->data = NULL;
	arr->size = 0;
}

int main() {
	IntArray arr;
	create(&arr, 31);

	for (int i = 0; i < arr.size; i++)
		set(&arr, i, i);

	print(&arr);
	resize(&arr, 50);
	print(&arr);
	resize(&arr, 11);
	print(&arr);
	free(&arr);

	return 0;
}
