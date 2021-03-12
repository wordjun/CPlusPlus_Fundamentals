#pragma once
#ifndef __ARRAY_TEMPLATE_H_
#define __ARRAY_TEMPLATE_H_

#include<iostream>
#include<cstdlib>
using namespace std;

//�迭Ŭ���� ���ø�ȭ
template<typename T>
class BoundCheckArray {
private:
	T* arr;
	int arrlen;
	//declare copy constructor and substitution operator as private in current class,
	//to prevent copy or substitution
	BoundCheckArray(const BoundCheckArray& arr);//copy constructor
	BoundCheckArray& operator=(const BoundCheckArray& arr) {}//substitution operator
public:
	BoundCheckArray(int len);
	T& operator[](int idx);
	T operator[](int idx) const;
	int GetArrLen() const;
	~BoundCheckArray();
};

template<typename T>
BoundCheckArray<T>::BoundCheckArray(int len) 
:arrlen(len){
	arr = new T[len];//T�� �迭 ����
}

template<typename T>
T& BoundCheckArray<T>::operator[](int idx) {
	if (idx < 0 || idx >= arrlen) {
		//index out of range
		cout << "Array index out of bound exception\n";
		exit(1);
	}
	return arr[idx];
}

template<typename T>
T BoundCheckArray<T>::operator[](int idx) const {
	if (idx < 0 || idx >= arrlen) {
		//index out of range
		cout << "Array index out of bound exception\n";
		exit(1);
	}
	return arr[idx];
}

template<typename T>
int BoundCheckArray<T>::GetArrLen() const {
	return arrlen;
}

template<typename T>
BoundCheckArray<T>::~BoundCheckArray() {
	delete[]arr;
}

#endif