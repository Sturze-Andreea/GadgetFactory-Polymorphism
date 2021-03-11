#include "stdafx.h"
#include "SerieValidator.h"

using namespace std;

SerieException::SerieException(vector<string> _errors) : errors{ _errors }
{
}

vector<string> SerieException::getErrors() const
{
	return this->errors;
}

void SerieValidator::validate(Serie* s)
{
	vector<string> errors;
	if (s->getNrOfProducts() <= 100)
		errors.push_back(string("You can only add series with more than 100 products!\n"));
	string x = s->toString(',');
	vector<string> tokens;
	stringstream ss(x);
	string item;
	int rez = -1;
	while (getline(ss, item, ',')) {
		tokens.push_back(item);
	}
	if (tokens.size() == 4) {
		{ int i = -1;
		try {
			i = stoi(tokens[3]);
		}
		catch (...) {

		}
		if (i == -1)
		{
			Phone* p = (Phone*)s;
			if (p->getOperatorsGSM().size() < 1)
				errors.push_back(string("There must be at least one operator GSM in the list!\n"));
		}
		}
		if (errors.size() > 0)
			throw SerieException(errors);
	}
}