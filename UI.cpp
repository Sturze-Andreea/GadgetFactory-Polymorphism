#include "stdafx.h"
#include "UI.h"
#include <iostream>
using namespace std;


UI::~UI() {
}

void UI::printMenu() {
	cout << endl;
	cout << "Menu:" << endl;
	cout << "\t 1.Login" << endl;
	cout << "\t 2.Operare" << endl;
	cout << "\t 3.Logout" << endl;
	cout << "\t 0.Exit" << endl;
	cout << "Choose option: ";
}

void UI::printAll(list<Serie*> all) {
	for (list<Serie*>::iterator it = all.begin(); it != all.end(); it++)
	{
		cout << (*it)->toString(' ') << endl;
	}
}

void UI::searchByProducerName() {
	cout << "Producer Name: "; 
	char x[20];
	cin >> x;
	string pr = x;
	printAll(service.searchByProducer(pr));
}

void UI::login() {
	if (service.loggedIn() == true)
		cout << "You are already logged in!" << endl;
	else {
		cout << "User Name: ";
		char* userName = new char[20];
		cin >> userName;
		cout << "Password: ";
		char* password = new char[20];
		cin >> password;
		if (service.login(userName, password) == true)
		{
			cout << "Log in successful!" << endl;
			cout << endl;
			printAll(service.getFromRepo());
		}
		else
			cout << "Wrong username or password!" << endl;
		delete[] userName, password;
	}
}
void UI::printMenuOperare() {
	cout << endl;
	cout << "\t 1.Add" << endl;
	cout << "\t 2.Print all" << endl;
	cout << "\t 3.Search by producer name" << endl;
	cout << "\t 0.Home" << endl;
	cout << "Choose option: ";
}

void UI::operare() {
	if (service.loggedIn() == true)
	{
		int option;
		bool works = true;
		while (works != false)
		{
			printMenuOperare();
			cin >> option;
			switch (option)
			{
			case 1: {
				add();
				break;
			}
			case 2: {
				printAll(service.getFromRepo());
				break;
			}
			case 3: {
				searchByProducerName();
				break;
			}
			case 0: {
				works = false;
				break;
			}
			}
		}
	}
	else
		cout << "You are not logged in!" << endl;
}

void UI::logout() {
	try {
		service.logout();
		cout << "Logout successful!" << endl;
	}
	catch (const char* exc) {
		cout << exc << endl;
	}
}

void UI::add() {
	cout << "What do you want to add?" << endl;
	cout << "\t 1.Phone" << endl;
	cout << "\t 2.Drone" << endl;
	cout << "Choose option:" << endl;
	int option;
	cin >> option;
	switch (option)
	{
	case 1: {
		try {
			Phone p;
			cin >> p;
			Serie* s = new Phone(p);
			service.addToRepo(s);
			delete s;
		} 
		catch (SerieException e) {
			for (int i = 0; i < e.getErrors().size(); i++)
				cout << e.getErrors()[i];
		}
		break;
	}
	case 2: {
		try {
			Drone d;
			cin >> d;
			Serie* s = new Drone(d);
			service.addToRepo(s);
			delete s;
		}
		catch(SerieException e){
			for (int i = 0; i < e.getErrors().size(); i++)
				cout << e.getErrors()[i];
		}
		break;
	}
	}
}

void UI::run() {
	int option;
	bool works = true;
	while (works != false)
	{
		printMenu();
		cin >> option;
		switch (option)
		{
		case 1: {
			login();
			break;
		}
		case 2: {
			operare();
			break;
		}
		case 3: {
			logout();
			break;
		}
		case 0: {

			works = false;
			break;
		}
		default: {
			cout << "There is no such option." << endl;
		}
		}
	}
}
