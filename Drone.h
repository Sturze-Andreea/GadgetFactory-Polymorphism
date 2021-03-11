#pragma once
#include <iostream>
#include "Serie.h"
using namespace std;

class Drone:public Serie {
private:
	int rotorsNr;
public:
	Drone();
	Drone(string, char);
	Drone(const char*, const char* ,int ,int);
	Drone(const Drone&);
	int getRotorsNr();
	void setRotorsNr(int);
	Drone& operator=(const Drone&);
	bool operator==(const Drone&);
	string toString(char);
	friend istream& operator>>(istream&, Drone&);
	Serie* clone();
	~Drone();
};