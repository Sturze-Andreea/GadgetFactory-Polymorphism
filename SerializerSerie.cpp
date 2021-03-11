#include "stdafx.h"
#include "SerializerSerie.h"

Serie* SerializerSerie::fromString(string line, char delim) {
	vector<string> tokens;
	stringstream ss(line);
	string item;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	if (tokens.size() == 4) {
		try {
			int i = stoi(tokens[3]);
			Serie* a = new Drone(line, delim);
			return a;
		}
		catch (...) {
			Serie* a = new Phone(line, delim);
			return a;

		}
	}

}

string SerializerSerie::toString(Serie* s, char delim) {
	return s->toString(delim);
}

Serie* SerializerSerie::goodObj(Serie* s) {
	return s->clone();
}

bool SerializerSerie::isEqual(Serie* s1, Serie* s2){
	return s1->toString(' ') == s2->toString(' ');
}