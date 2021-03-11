#pragma once
#include "Serializer.h"

template<class T> class SerializerWithoutP :public Serializer<T>
{
public:
	SerializerWithoutP(){}
	virtual T fromString(string line, char delim);
	virtual string toString(T, char);
	T goodObj(T);
	bool isEqual(T, T);
	~SerializerWithoutP(){}
};

template<class T> T SerializerWithoutP<T>::fromString(string line, char delim) {
	T ob(line, delim);
	return ob;
}

template<class T>string SerializerWithoutP<T>::toString(T ob , char delim) {
	return ob.toString(delim);
}

template<class T> T SerializerWithoutP<T>::goodObj(T ob) {
	return ob;
}

template<class T> bool SerializerWithoutP<T>::isEqual(T ob1, T ob2) {
	return ob1 == ob2;
}