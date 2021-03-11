#pragma once
#include "Service.h"
#include "Drone.h"

class UI {
private:
	Service service;
	void printMenu();
	void printMenuOperare();
	void printAll(list<Serie*>);
	void add();
	void login();
	void operare();
	void logout();
	void searchByProducerName();
public:
	UI(Service &serv) :service(serv) {};
	void run();
	~UI();
};