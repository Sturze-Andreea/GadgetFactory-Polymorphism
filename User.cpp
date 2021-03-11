#include "stdafx.h"
#include "User.h"
#include <vector>
#include <string>
#include <sstream>


User::User()
{
	userName = "";
	password = "";
}

User::User(string u, string p) :userName(u), password(p)
{
}

string User::getUserName()
{
	return userName;
}

string User::getPassword()
{
	return password;
}

void User::setUserName(string u)
{
	userName = u;
}

void User::setPassword(string p)
{
	password = p;
}

bool User::operator==(const User& u)
{
	return (userName == u.userName) and (password == u.password);
}

string User::toString(char delim)
{
	return userName + delim + password;
}


User::~User()
{
}

User::User(string line, char delim)
{
	vector<string> tokens;
	stringstream ss(line);
	string item;
	while (getline(ss, item, delim)) {
		tokens.push_back(item);
	}
	userName = tokens[0];
	password = tokens[1];
}

User* User::clone() {
	User* u = new User();
	u->setUserName(this->userName);
	u->setPassword(this->password);
	return u;
}
