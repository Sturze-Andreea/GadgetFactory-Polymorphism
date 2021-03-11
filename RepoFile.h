#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include "RepoTemplate.h"
using namespace std;

template<class T> class RepoFile :public RepoTemplate<T>
{
protected:
	const char* fileName;
public:
	RepoFile();
	RepoFile(const char*);
	~RepoFile();
	virtual int addElem(T);
	virtual int delElem(T);
	virtual void updateElem(T, T);
	virtual void loadFromFile(const char*) = 0;
	virtual void saveToFile() = 0;
};


template<class T> RepoFile<T>::RepoFile() :RepoTemplate<T>() {
	fileName = "";
}

template<class T> RepoFile<T>::RepoFile(const char* file) : RepoTemplate<T>() {
	fileName = file;
}

template<class T> RepoFile<T>::~RepoFile() {
	
}

template<class T> int RepoFile<T>::addElem(T e) {
	int rez = RepoTemplate<T>::addElem(e);
	return rez;
}

template<class T> int RepoFile<T>::delElem(T e) {
	int rez = RepoTemplate<T>::delElem(e);
	return rez;
}

template<class T> void RepoFile<T>::updateElem(T e, T newE) {
	RepoTemplate<T>::updateElem(e, newE);
}