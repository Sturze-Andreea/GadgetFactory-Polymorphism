#pragma once
#include "Serializer.h"
#include "Serie.h"
#include "Phone.h"
#include "Drone.h"

class SerializerSerie: public Serializer<Serie*>
{
public:
	SerializerSerie(){}
	Serie* fromString(string, char);
	string toString(Serie*, char);
	Serie* goodObj(Serie*);
	bool isEqual(Serie*, Serie*);
	~SerializerSerie(){}
};
