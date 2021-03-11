#include "stdafx.h"
#include "Drone.h"
#include <string>
#include <iostream>
using namespace std;


Drone::Drone() {
	rotorsNr = 0;
}

Drone::Drone(string line, char delim) {
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
	rotorsNr = stoi(tokens[3]);
}

Drone::Drone(const char* n, const char* l, int s, int nr) :Serie(n, l, s) {
	rotorsNr =nr;
}

Drone::Drone(const Drone& s) : Serie(s) {
	rotorsNr = s.rotorsNr;
}

Drone::~Drone() {
}

int Drone::getRotorsNr() {
	return rotorsNr;
}

void Drone::setRotorsNr(int nr) {
	rotorsNr = nr;
}

Drone& Drone::operator=(const Drone& c) {
	if (this == &c)
		return *this;
	Serie::operator=(c);
	rotorsNr = c.rotorsNr;
	return *this;
}

bool Drone::operator==(const Drone& c) {
	return (Serie::operator==(c) && (rotorsNr = c.rotorsNr));
}

istream & operator>>(istream &is, Drone &c)
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
	cout << "Number of rotors: ";
	int nr;
	is >> nr;
	c.setProducerName(producerName);
	c.setModelName(modelName);
	c.setNrOfProducts(nrOfProducts);
	c.setRotorsNr(nr);
	return is;
}

string Drone::toString(char delim) {
	string x, y;
	x = modelName;
	y = producerName;	
	return y + delim + x + delim + to_string(nrOfProducts) + delim + to_string(rotorsNr);
}

Serie* Drone::clone() {
	Drone* p = new Drone();
	p->setProducerName(producerName);
	p->setModelName(modelName);
	p->setNrOfProducts(nrOfProducts);
	p->setRotorsNr(rotorsNr);
	return p;
}