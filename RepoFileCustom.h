#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include "RepoFile.h"
#include "Serializer.h"
using namespace std;

template<class T> class RepoFileCustom :public RepoFile<T>
{private: 
	Serializer<T>* s;
public:
	RepoFileCustom();
	RepoFileCustom(const char*, Serializer<T>*);
	int addElem(T);
	int delElem(T);
	void updateElem(T, T);
	bool findElem(T);
	void loadFromFile(const char*);
	void saveToFile();
	~RepoFileCustom();
};


template<class T> RepoFileCustom<T>::RepoFileCustom() :RepoFile<T>() {
	this->fileName = "";
}

template<class T> RepoFileCustom<T>::RepoFileCustom(const char* file, Serializer<T>* sr) : RepoFile<T>() {
	this->fileName = file;
	s = sr;
	loadFromFile(file);
}

template<class T> RepoFileCustom<T>::~RepoFileCustom() {
	delete s;
}

template<class T> void RepoFileCustom<T>::loadFromFile(const char* file) {
	this->fileName = file;
	this->clear();
	string line;
	ifstream f(this->fileName);
	while (getline(f, line)) {
		RepoFile<T>::addElem(s->fromString(line, '/'));
	}
	f.close();
}

template<class T> void RepoFileCustom<T>::saveToFile() {
	ofstream f(this->fileName);
	for (T crt : RepoFile<T>::elem) {
		f << s->toString(crt, '/') << endl;
	}
	f.close();
}

template<class T> int RepoFileCustom<T>::addElem(T e) {
	int rez = RepoFile<T>::addElem(e);
	saveToFile();
	return rez;
}


template<class T> int RepoFileCustom<T>::delElem(T e) {
	typename list<T>::iterator it;
	for (it = RepoFile<T>::elem.begin(); it != RepoFile<T>::elem.end(); ++it)
	{

		if (s->isEqual((*it), e) == true)
		{
			RepoFile<T>::elem.erase(it);
			saveToFile();
			return 0;
		}
	}
	return -1;
}

template<class T> void RepoFileCustom<T>::updateElem(T e, T newE) {
	typename list<T>::iterator it;
	for (it = RepoFile<T>::elem.begin(); it != RepoFile<T>::elem.end(); ++it)
	{

		if (s->isEqual((*it), e) == true)
		{
			replace(RepoFile<T>::elem.begin(), RepoFile<T>::elem.end(), (*it), newE);
		}
	}
	saveToFile();
}

template<class T> bool RepoFileCustom<T>::findElem(T e) {
	typename list<T>::iterator it;
	for (it = RepoFile<T>::elem.begin(); it != RepoFile<T>::elem.end(); ++it)
	{
		if (s->isEqual((*it), e) == true)
		{
			return true;
		}
	}
	return false;
}