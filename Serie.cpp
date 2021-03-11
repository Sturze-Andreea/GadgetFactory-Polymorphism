#include "stdafx.h"
#include "Serie.h"
#include <string>
#include <iostream>
using namespace std;


Serie::Serie() {
	producerName = NULL;
	modelName = NULL;
	nrOfProducts = 0;
}

Serie::Serie(string line, char delim) {
	vector<string> tokens;
	stringstream ss(line);
	string item;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	producerName = new char[tokens[0].length() + 1];
	strcpy_s(producerName, tokens[0].length()+1 , tokens[0].c_str());
	modelName = new char[tokens[1].length() + 1];
	strcpy_s(modelName, tokens[1].length() +1, tokens[1].c_str());
	nrOfProducts = stoi(tokens[2]);
}

Serie::Serie( const char* n, const char* l, int s) {
	producerName = new char[strlen(n) + 1];
	strcpy_s(producerName, strlen(n) + 1, n);
	modelName = new char[strlen(l) + 1];
	strcpy_s(modelName, strlen(l) + 1, l);
	nrOfProducts = s;
}

Serie::Serie(const Serie& s) {
	if (s.producerName)
	{
		producerName = new char[strlen(s.producerName) + 1];
		strcpy_s(producerName, strlen(s.producerName) + 1, s.producerName);
	}
	if (s.modelName)
	{
		modelName = new char[strlen(s.modelName) + 1];
		strcpy_s(modelName, strlen(s.modelName) + 1, s.modelName);
	}
	nrOfProducts = s.nrOfProducts;
}

Serie::~Serie() {
	if (producerName)
	{
		delete[] producerName;
		producerName = NULL;
	}
	if (modelName)
	{
		delete[] modelName;
		modelName = NULL;
	}
	nrOfProducts = 0;
}

char* Serie::getProducerName() {
	return producerName;
}

char* Serie::getModelName() {
	return modelName;
}

int Serie::getNrOfProducts() {
	return nrOfProducts;
}

void Serie::setProducerName(const char* n) {
	if (producerName)
		delete[] producerName;
	producerName = new char[strlen(n) + 1];
	strcpy_s(producerName, strlen(n) + 1, n);
}

void Serie::setModelName(const char* l) {
	if (modelName)
		delete[] modelName;
	modelName = new char[strlen(l) + 1];
	strcpy_s(modelName, strlen(l) + 1, l);
}

void Serie::setNrOfProducts(int s) {
	nrOfProducts = s;
}

Serie& Serie::operator=(const Serie& c) {
	if (this == &c)
		return *this;
	if (c.producerName)
		setProducerName(c.producerName);
	if (c.modelName)
		setModelName(c.modelName);
	setNrOfProducts(c.nrOfProducts);
	return *this;
}

bool Serie::operator==(const Serie& c) {
	if (c.producerName and c.modelName)
		return (strcmp(producerName, c.producerName) == 0 and strcmp(modelName, c.modelName) == 0 and nrOfProducts == c.nrOfProducts);
	return false;
}

istream & operator>>(istream &is, Serie &c){
	cout << "Prodcer Name: ";
	char* producerName = new char[20];
	is >> producerName;
	cout << "Model Name: ";
	char* modelName = new char[20];
	is >> modelName;
	cout << "Number of products: ";
	int nrOfProducts;
	is >> nrOfProducts;
	c.setProducerName(producerName);
	c.setModelName(modelName);
	c.setNrOfProducts(nrOfProducts);
	return is;
}
