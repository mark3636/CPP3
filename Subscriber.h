#pragma once
#include <string>
#include <iostream>
#include "HelpUtils.h"
#include <vector>

//Читатель
class Subscriber {
public:
	int libraryCard;
	std::string subSurname;

	Subscriber(int lC, std::string sS) {
		libraryCard = lC;
		subSurname = sS;
	}

	Subscriber() {
		libraryCard = 0;
		subSurname = "";
	}

	~Subscriber() {}

	bool operator==(const Subscriber& other) const {
		return this->libraryCard == other.libraryCard;
	}
};

std::ostream& operator<<(std::ostream &os, const Subscriber &sub) {
	os << std::to_string(sub.libraryCard) + "\t" +
		sub.subSurname + "\n";

	return os;
}

std::istream& operator >> (std::istream &is, Subscriber &sub) {
	is >> sub.libraryCard;
	is >> sub.subSurname;

	return is;
}

Subscriber inputSubscriber() {
	int libraryCard;
	std::string surname;

	std::cout << "----------SUBSCRIBER----------" << std::endl;
	std::cout << "Type \"exit\" to exit" << std::endl;

	libraryCard = inputInt("Enter library card: ");

	std::cout << "Enter subSurname: ";
	std::cin >> surname;
	if (surname == "exit") throw "exit";

	return Subscriber(libraryCard, surname);
}

void inputSubscriberChanged(std::vector<Subscriber>::iterator &it) {
	std::cout << "----------SUBSCRIBER----------" << std::endl;
	std::cout << "Type \"skip\" to skip" << std::endl;

	int intTmp;
	std::string strTmp;

	intTmp = inputInt("Enter library card(default: " + std::to_string(it->libraryCard) + "): ", 0, 1000, false);
	if (intTmp != -1) it->libraryCard = intTmp;

	std::cout << "Enter surname(dafault: " + it->subSurname + "): ";
	std::cin >> strTmp;
	if (strTmp == "exit") throw "exit";
	if (strTmp != "skip") it->subSurname = strTmp;
}