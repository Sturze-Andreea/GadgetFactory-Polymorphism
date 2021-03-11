#pragma once
#include <string>
#include "Serie.h"
#include <vector>
#include "Phone.h"

class SerieException
{
private:
	vector<string> errors;

public:
	SerieException(vector<string>);
	vector<string> getErrors() const;
};

class SerieValidator
{
public:
	SerieValidator() {}
	void validate(Serie*);
	~SerieValidator() {}
};