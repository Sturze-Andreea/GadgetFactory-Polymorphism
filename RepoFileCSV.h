#pragma once
#include <list>
#include <fstream>
#include <iostream>
#include "RepoFile.h"
#include "Serializer.h"
using namespace std;

template<class T> class RepoFileCSV :public RepoFile<T>
{private:
	Serializer<T>* s;
public:
	RepoFileCSV();
	RepoFileCSV(const char*, Serializer<T>*);
	int addElem(T);
	int delElem(T);
	void updateElem(T, T);
	bool findElem(T);
	void loadFromFile(const char*);
	void saveToFile();
	~RepoFileCSV();
};


template<class T> RepoFileCSV<T>::RepoFileCSV() :RepoFile<T>() {
	RepoFile<T>::fileName = "";
}

template<class T> RepoFileCSV<T>::RepoFileCSV(const char* file, Serializer<T>* sr) : RepoFile<T>() {
	RepoFile<T>::fileName = file;
	s = sr;
	loadFromFile(file);
}

template<class T> RepoFileCSV<T>::~RepoFileCSV() {
	delete s;
}

template<class T> void RepoFileCSV<T>::loadFromFile(const char* file) {
	RepoFile<T>::fileName = file;
	this->clear();
	string line;
	ifstream f(RepoFile<T>::fileName);
	while (getline(f, line)) {
		RepoFile<T>::addElem(s->fromString(line,','));
	}
	f.close();
}

template<class T> void RepoFileCSV<T>::saveToFile() {
	ofstream f(RepoFile<T>::fileName);
	for (T crt : RepoFile<T>::elem) {
		f << s->toString(crt, ',') << endl;
	}
	f.close();
}

template<class T> int RepoFileCSV<T>::addElem(T e) {
	int rez = RepoFile<T>::addElem(s->goodObj(e));
	saveToFile();
	return rez;
}

template<class T> int RepoFileCSV<T>::delElem(T e) {
	typename list<T>::iterator it;
	for (it = RepoFile<T>::elem.begin(); it != RepoFile<T>::elem.end(); ++it)
	{

		if (s->isEqual((*it),e)==true)
		{
			RepoFile<T>::elem.erase(it);
			saveToFile();
			return 0;
		}
	}
	return -1;
}

template<class T> void RepoFileCSV<T>::updateElem(T e, T newE) {
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

template<class T> bool RepoFileCSV<T>::findElem(T e) {
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