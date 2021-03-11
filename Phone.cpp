#include "stdafx.h"
#include "Phone.h"
#include <string.h>
#include <iostream>
using namespace std;


Phone::Phone() {
	
}

Phone::Phone(string line, char delim) {
	vector<string> tokens;
	stringstream ss(line);
	string item;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	producerName = new char[tokens[0].length() + 1];
	strcpy_s(producerName, tokens[0].length() + 1, tokens[0].c_str());
	modelName = new char[tokens[1].length() + 1];
	strcpy_s(modelName, tokens[1].length() + 1, tokens[1].c_str());
	nrOfProducts = stoi(tokens[2]);
	if (tokens[3] == "is NULL")
	{
		vector<string> x;
		operatorsGSM = x;
	}
	else {
		stringstream s(tokens[3]);
		while (getline(s, item, '-')) {
			operatorsGSM.push_back(item);
		}
	}
}

Phone::Phone(const char* n, const char* l, int s, vector<string> op) :Serie(n, l, s) {
	operatorsGSM = op;
}

Phone::Phone(const Phone& s):Serie(s) {
	operatorsGSM = s.operatorsGSM;
}

Phone::~Phone() {
}

vector<string> Phone::getOperatorsGSM() {
	return operatorsGSM;
}

void Phone::setOperatorsGSM(vector<string> op) {
	operatorsGSM = op;
}

Phone& Phone::operator=(const Phone& c) {
	if (this == &c)
		return *this; 
	Serie::operator=(c);
	operatorsGSM = c.operatorsGSM;
	return *this;
}

bool Phone::operator==(const Phone& c) {
	bool ok = true;
	for (int i = 0; i < operatorsGSM.size(); i++)
		if (operatorsGSM[i] != c.operatorsGSM[i])
			ok = false;
	return (Serie::operator==(c) && ok);
}


istream & operator>>(istream &is, Phone &c)
{
	cout << "Producer Name: ";
	char* producerName = new char[20];
	is >> producerName;
	cout << "Model Name: ";
	char* modelName = new char[20];
	is >> modelName;
	cout << "Number of products: ";
	int nrOfProducts;
	is >> nrOfProducts;
	int i;
	cout << "How many operators?" << endl;
	is >> i;
	vector<string> x;
	if (i > 0)
	{
		char ch[20];
		cout << "List of GSM operators: " << endl;
		for (int j = 0; j < i; j++)
		{
			is >> ch;
			x.push_back(ch);
		}
	}
	c.setProducerName(producerName);
	c.setModelName(modelName);
	c.setNrOfProducts(nrOfProducts);
	c.setOperatorsGSM(x);
	return is;
}

string Phone::toString(char delim) {
	string op;
	if (operatorsGSM.size() > 0)
		op = operatorsGSM[0];
	else
		op = "is NULL";
	for (int i = 1; i < operatorsGSM.size(); i++)
		op = op + "-" + operatorsGSM[i];
	string x, y;
	x = modelName;
	y = producerName;
	return y + delim + x + delim + to_string(nrOfProducts) + delim + op;
}

Serie* Phone::clone() {
	Phone* p = new Phone();
	p->setProducerName(producerName);
	p->setModelName(modelName);
	p->setNrOfProducts(nrOfProducts);
	p->setOperatorsGSM(operatorsGSM);
	return p;
}