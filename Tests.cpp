#include "stdafx.h"
#include "Tests.h"
#include <assert.h>
#include <string.h>


void testPhone() {
	vector<string> x;
	x.push_back("aaa");
	x.push_back("bbb");
	Phone c("ion", "aaa", 7, x);
	assert(strcmp(c.getProducerName(), "ion") == 0);
	assert(strcmp(c.getModelName(), "aaa") == 0);
	assert(c.getNrOfProducts() == 7);
	assert(c.getOperatorsGSM() == x);
	Phone c1;
	vector<string> z;
	assert(c1.getProducerName() == NULL);
	assert(c1.getModelName() == NULL);
	assert(c1.getNrOfProducts() == 0);
	assert(c1.getOperatorsGSM() == z);
	Phone c2(c);
	assert(strcmp(c2.getProducerName(), "ion") == 0);
	assert(strcmp(c2.getModelName(), "aaa") == 0);
	assert(c2.getNrOfProducts() == 7);
	assert(c2.getOperatorsGSM() == x);
	c.setProducerName("ana");
	assert(strcmp(c.getProducerName(), "ana") == 0);
	c.setModelName("bbb");
	assert(strcmp(c.getModelName(), "bbb") == 0);
	c.setNrOfProducts(6);
	assert(c.getNrOfProducts() == 6);
	vector<string> y;
	y.push_back("aa");
	y.push_back("cc");
	c.setOperatorsGSM(y);
	assert(c.getOperatorsGSM() == y);
	Phone c3("ana", "bbb", 6, y);
	assert(c == c3);
	Phone c4("aa,bb,5,bb-cc", ',');
	assert(strcmp(c4.getProducerName(), "aa") == 0);
	assert(strcmp(c4.getModelName(), "bb") == 0);
	assert(c4.getNrOfProducts() == 5);
	assert(c4.getOperatorsGSM()[0] == "bb");
	assert(c4.getOperatorsGSM()[1] == "cc");
}

void testDrone() {
	Drone c("ion", "aaa", 7, 2);
	assert(strcmp(c.getProducerName(), "ion") == 0);
	assert(strcmp(c.getModelName(), "aaa") == 0);
	assert(c.getNrOfProducts() == 7);
	assert(c.getRotorsNr() == 2);
	Drone c1;
	assert(c1.getProducerName() == NULL);
	assert(c1.getModelName() == NULL);
	assert(c1.getNrOfProducts() == 0);
	assert(c1.getRotorsNr() == 0);
	Drone c2(c);
	assert(strcmp(c2.getProducerName(), "ion") == 0);
	assert(strcmp(c2.getModelName(), "aaa") == 0);
	assert(c2.getNrOfProducts() == 7);
	assert(c2.getRotorsNr() == 2);
	c.setProducerName("ana");
	assert(strcmp(c.getProducerName(), "ana") == 0);
	c.setModelName("bbb");
	assert(strcmp(c.getModelName(), "bbb") == 0);
	c.setNrOfProducts(6);
	assert(c.getNrOfProducts() == 6);
	c.setRotorsNr(8);
	assert(c.getRotorsNr() == 8);
	Drone c3("ana", "bbb", 6, 8);
	assert(c == c3);
	Drone c4("aa,bb,5,7", ',');
	assert(strcmp(c4.getProducerName(), "aa") == 0);
	assert(strcmp(c4.getModelName(), "bb") == 0);
	assert(c4.getNrOfProducts() == 5);
	assert(c4.getRotorsNr() == 7);
}

void testUser() {
	User c("ion", "aaa");
	assert(c.getUserName()== "ion");
	assert(c.getPassword()== "aaa");
	User c1;
	assert(c1.getUserName() == "");
	assert(c1.getPassword() == "");
	c.setUserName("ana");
	assert(c.getUserName()== "ana");
	c.setPassword("bbb");
	assert(c.getPassword()== "bbb");
	User c3("ana", "bbb");
	assert(c == c3);
	assert(c3.toString('/') == "ana/bbb");
	User c4("aa/bb", '/');
	assert(c4.getUserName()== "aa");
	assert(c4.getPassword()== "bb");
}

void testRepoTemplate() {
	RepoTemplate<Drone> repo;
	Drone c("ion", "AAA", 5, 3);
	Drone c1("ana", "BBB", 4, 3);
	Drone c2("maria", "BCB", 3, 6);
	Drone c3("ioana", "HHH", 2, 3);
	Drone drones[] = { c,c1,c2,c3 };
	repo.addElem(c);
	repo.addElem(c1);
	repo.addElem(c2);
	repo.addElem(c3);
	list<Drone> l = repo.getAll();
	assert(repo.getSize() == 4);
	assert(l.front() == c);
	assert(l.back() == c3);
	int i = 0;
	for (list<Drone>::iterator it = l.begin(); it != l.end(); it++)
	{
		assert(*it == drones[i]);
		i++;
	}
	repo.delElem(c2);
	assert(repo.getSize() == 3);
	assert(repo.findElem(c2) == false);
	Drone c4("dana", "LLL", 6, 5);
	repo.updateElem(c1, c4);
	assert(repo.findElem(c1) == false);
	assert(repo.getItemFromPos(1) == c4);
}

void testRepoFileCSV() {
	SerializerWithoutP<Drone>* s = new SerializerWithoutP<Drone>;
	RepoFileCSV<Drone> repo("test.csv", s);
	Drone c("ion", "AAA", 5,2);
	Drone c1("ana", "BBB", 4,2);
	Drone c2("maria", "BCB", 3,2);
	Drone c3("ioana", "HHH", 2,2);
	Drone c4("Ion", "CCC", 10,2);
	Drone c5("Ana", "AAA", 9,2);
	Drone drones[] = { c4,c5, c,c1,c2,c3 };
	repo.addElem(c);
	repo.addElem(c1);
	repo.addElem(c2);
	repo.addElem(c3);
	list<Drone> l = repo.getAll();
	assert(repo.getSize() == 6);
	int i = 0;
	for (list<Drone>::iterator it = l.begin(); it != l.end(); it++)
	{
		assert(*it == drones[i]);
		i++;
	}
	repo.delElem(c2);
	assert(repo.getSize() == 5);
	assert(repo.findElem(c2) == false);
	Drone c6("dana", "LLL", 7,2);
	repo.updateElem(c1, c6);
	assert(repo.findElem(c1) == false);
	assert(repo.getItemFromPos(3) == c6);
	repo.addElem(c1);
	repo.saveToFile();
	repo.loadFromFile("test.csv");
	assert(repo.getSize() == 6);
	assert(repo.getItemFromPos(5) == c1);
}

void testRepoFileCustom() {
	SerializerWithoutP<Phone>* s = new SerializerWithoutP<Phone>;
	RepoFileCustom<Phone> repo("test.txt",s);
	vector<string> x;
	x.push_back("Orange");
	Phone c("ion", "AAA", 5, x);
	Phone c1("ana", "BBB", 4, x);
	Phone c2("maria", "BCB", 3, x);
	Phone c3("ioana", "HHH", 2, x);
	Phone c4("Ion", "CCC", 10, x);
	Phone c5("Ana", "AAA", 9, x);
	Phone phones[] = { c4,c5, c,c1,c2,c3 };
	repo.addElem(c);
	repo.addElem(c1);
	repo.addElem(c2);
	repo.addElem(c3);
	list<Phone> l = repo.getAll();
	assert(repo.getSize() == 6);
	int i = 0;
	for (list<Phone>::iterator it = l.begin(); it != l.end(); it++)
	{
		assert(*it == phones[i]);
		i++;
	}
	repo.delElem(c2);
	assert(repo.getSize() == 5);
	assert(repo.findElem(c2) == false);
	Phone c6("dana", "LLL", 7, x);
	repo.updateElem(c1, c6);
	assert(repo.findElem(c1) == false);
	assert(repo.getItemFromPos(3) == c6);
	repo.addElem(c1);
	repo.saveToFile();
	repo.loadFromFile("test.txt");
	assert(repo.getSize() == 6);
	assert(repo.getItemFromPos(5) == c1);
}


void testRepoFileCSVP() {
	SerializerSerie* s = new SerializerSerie;
	RepoFileCSV<Serie*> repo("testP.csv",s);
	assert(repo.getSize()==2);
	Serie* c = new Drone("ion", "AAA", 5, 2);
	Serie* c1 = new Drone("ana", "BBB", 4, 2);
	vector<string> x;
	x.push_back("Orange");
	Serie* c2 = new Phone("maria", "BCB", 3, x);
	Serie* c3 = new Drone("ioana", "HHH", 2, 2);
	Serie* c4 = new Drone("Ion", "CCC", 10, 2);
	Serie* c5 = new Drone("Ana", "AAA", 9, 2);
	assert(repo.getItemFromPos(0)->toString(' ') == c4->toString(' '));
	Serie* drones[] = { c4,c5, c,c1,c2,c3 };
	repo.addElem(c);
	repo.addElem(c1);
	repo.addElem(c2);
	repo.addElem(c3);
	list<Serie*> l = repo.getAll();
	assert(repo.getSize() == 6);
	int i = 0;
	for (list<Serie*>::iterator it = l.begin(); it != l.end(); it++)
	{
		assert((*it)->toString(' ') == drones[i]->toString(' '));
		i++;
	}
	repo.delElem(c3);
	assert(repo.getSize() == 5);
	assert(repo.findElem(c3) == false);
	Serie* c6 = new Drone("dana", "LLL", 7, 2);
	repo.updateElem(c1, c6);
	assert(repo.findElem(c1) == false);
	assert(repo.getItemFromPos(3) == c6);
	repo.addElem(c1);
	repo.saveToFile();
	repo.loadFromFile("testP.csv");
	assert(repo.getSize() == 6);
	assert(repo.getItemFromPos(5)->toString(' ') == c1->toString(' '));
	delete c, c1, c2, c3, c4, c5, c6, drones;
}

void testService() {
	Serie* c= new Drone("ion", "AAA", 101,2);
	Serie* c1 = new Drone("ana", "BBB", 102, 2);
	Serie* c2 = new Drone("maria", "BCB", 300,2);
	Serie* c3 = new Drone("ioana", "HHH", 206,2);
	SerializerSerie* s = new SerializerSerie;
	RepoFileCSV<Serie*>* repo = new RepoFileCSV<Serie*>("", s);
	RepoTemplate<User>* rep = new RepoTemplate<User>;
	User u("ana", "aaa");
	rep->addElem(u);
	Service serv(repo, rep);
	serv.addToRepo(c);
	serv.addToRepo(c1);
	serv.addToRepo(c2);
	serv.addToRepo(c3);
	assert(serv.getItemFromPos(0)->toString(' ') == c->toString(' '));
	assert(serv.getItemFromPos(1)->toString(' ') == c1->toString(' '));
	assert(serv.getItemFromPos(2)->toString(' ') == c2->toString(' '));
	assert(serv.getItemFromPos(3)->toString(' ') == c3->toString(' '));
	assert(serv.getRepoSize() == 4);
	assert(serv.findElemInRepo(c) == true);
	serv.delFromRepo(c1);
	assert(serv.getRepoSize() == 3);
	assert(serv.findElemInRepo(c1) == false);
	serv.updateInRepo(c, c1);
	assert(serv.findElemInRepo(c) == false);
	assert(serv.getItemFromPos(0)->toString(' ') == c1->toString(' '));
	assert(serv.findElemInRepo(c1) == true);
	serv.login("ana", "aaa");
	assert(serv.loggedIn() == true);
	serv.logout();
	assert(serv.loggedIn() == false);
	list<Serie*> l = serv.searchByProducer("ioana");
	assert(l.front()->toString(' ') == c3->toString(' '));
	delete c, c1, c2, c3, s, repo, rep;
	for (Serie* crt : serv.getFromRepo())
		delete crt;
}