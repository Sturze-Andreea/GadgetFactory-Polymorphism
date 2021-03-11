#pragma once
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Serie {
protected:
	char* producerName;
	char* modelName;
	int nrOfProducts;
public:
	Serie();
	Serie(string, char);
	Serie(const char*, const char*, int);
	Serie(const Serie&);
	char* getProducerName();
	char* getModelName();
	int getNrOfProducts();
	void setProducerName(const char*);
	void setModelName(const char*);
	void setNrOfProducts(int);
	virtual Serie& operator=(const Serie&);
	virtual bool operator==(const Serie&);
	virtual string toString(char) = 0;
	friend istream& operator>>(istream&, Serie&);
	virtual Serie* clone() = 0;
	virtual ~Serie();
};