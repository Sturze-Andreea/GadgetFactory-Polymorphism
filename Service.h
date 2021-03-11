#pragma once
#include "Drone.h"
#include "User.h"
#include "RepoFile.h"
#include "RepoTemplate.h"
#include "SerieValidator.h"

class Service {
private:
	User user;
	RepoTemplate<Serie*> *repo;
	RepoTemplate<User> *repoUser;
	SerieValidator v;
public:
	Service(RepoTemplate<Serie*>* r, RepoTemplate<User>* rep) { repo = r; repoUser = rep; };
	~Service();
	int addToRepo(Serie*);
	int delFromRepo(Serie*);
	int updateInRepo(Serie*&, Serie*);
	bool findElemInRepo(Serie*&);
	Serie* getItemFromPos(int);
	list<Serie*> getFromRepo();
	int getRepoSize();
	bool login(const char*, const char*);
	void logout();
	bool loggedIn();
	list<Serie*> searchByProducer(string);
};