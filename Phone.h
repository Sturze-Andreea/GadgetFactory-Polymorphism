#pragma once
#include <iostream>
#include <vector>
#include "Serie.h"
using namespace std;

class Phone:public Serie {
private:
	vector<string> operatorsGSM;
public:
	Phone();
	Phone(string, char);
	Phone(const char*, const char*, int, vector<string>);
	Phone(const Phone&);
	vector<string> getOperatorsGSM();
	void setOperatorsGSM(vector<string>);
	Phone& operator=(const Phone&);
	bool operator==(const Phone&);
	string toString(char);
	friend istream& operator>>(istream&, Phone&);
	Serie* clone();
	~Phone();
};