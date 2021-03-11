#pragma once
#include <string>
using namespace std;


class User
{
private:
	string userName;
	string password;
public:
	User();
	User(string, char);
	User(string, string);
	string getUserName();
	string getPassword();
	void setUserName(string);
	void setPassword(string);
	bool operator==(const User& u);
	string toString(char);
	User* clone();
	~User();
};