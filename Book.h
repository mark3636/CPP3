#pragma once
#include <iostream>
#include "Date.h"
#include "decimal.h"
#include "HelpUtils.h"

//Книга
class  Book {

public:
	int libraryCard;
	Date issueDate;
	Date returnDate;
	std::string author;
	std::string title;
	int publicationYear;
	std::string publishingHouse;
	dec::decimal<2> price;

	Book(int lC, Date &iD, Date &rD, std::string atr, std::string ttl, int pY, std::string pH, dec::decimal<2> prc) {
		libraryCard = lC;
		issueDate = iD;
		returnDate = rD;
		author = atr;
		title = ttl;
		publicationYear = pY;
		publishingHouse = pH;
		price = prc;
	}

	Book() {
		libraryCard = 0;
		issueDate = Date();
		returnDate = Date();
		author = "";
		title = "";
		publicationYear = 2000;
		publishingHouse = "";
		price = 0;
	}

	~Book() {}

	bool operator==(const Book& other) const {
		return  this->libraryCard == other.libraryCard &&
			this->issueDate == other.issueDate &&
			this->returnDate == other.returnDate &&
			this->author == other.author &&
			this->title == other.title &&
			this->publicationYear == other.publicationYear &&
			this->publishingHouse == other.publishingHouse &&
			this->price == other.price;
	}
};

std::ostream& operator<<(std::ostream &os, const Book &book) {
	std::string lCard;
	std::string iDate;
	std::string rDate;

	if (book.libraryCard == 0) {
		lCard = "-";
		iDate = "--/--/----";
		rDate = "--/--/----";
	}
	else {
		lCard = std::to_string(book.libraryCard);
		iDate = book.issueDate.ToString();
		rDate = book.returnDate.ToString();
	}

	os << lCard + "\t" +
		iDate + "\t" +
		rDate + "\t" +
		book.author + "\t" +
		book.title + "\t" +
		std::to_string(book.publicationYear) + "\t" +
		book.publishingHouse + "\t" +
		dec::toString(book.price) + "\n";

	return os;
}

std::istream& operator >> (std::istream &is, Book &book) {
	std::string lCard, iDate, rDate;
	is >> lCard;
	if (lCard == "") return is;
	if (lCard == "-") book.libraryCard = 0;
	else book.libraryCard = std::stoi(lCard);
	is >> iDate;
	if (iDate == "--/--/----") book.issueDate = Date(20, 06, 2017);
	else book.issueDate.TryStrToDate(iDate);
	is >> rDate;
	if (rDate == "--/--/----") book.returnDate = Date(20, 07, 2017);
	else book.returnDate.TryStrToDate(iDate);
	is >> book.author;
	is >> book.title;
	is >> book.publicationYear;
	is >> book.publishingHouse;
	dec::fromStream(is, book.price);

	return is;
}

Book inputBook() {
	int libraryCard;
	Date issueDate;
	Date returnDate;
	std::string author;
	std::string title;
	int publicationYear;
	std::string publishingHouse;
	dec::decimal<2> price;

	std::cout << "-------------BOOK-------------" << std::endl;
	std::cout << "Type \"exit\" to exit" << std::endl;

	libraryCard = inputInt("Enter library card(\"-\" - book without subscriber): ");

	if (libraryCard != 0) {
		issueDate = inputDate("Enter issue date(dd/mm/yyyy): ");
		returnDate = inputDate("Enter return date(dd/mm/yyyy): ");
	}
	else {
		issueDate = Date(20, 06, 2017);
		returnDate = Date(20, 07, 2017);
	}

	std::cout << "Enter author: ";
	std::cin >> author;
	if (author == "exit") throw "exit";

	std::cout << "Enter title: ";
	std::cin >> title;
	if (title == "exit") throw "exit";

	publicationYear = inputInt("Enter publication year: ", 1900, 2017);

	std::cout << "Enter publishing house: ";
	std::cin >> publishingHouse;
	if (publishingHouse == "exit") throw "exit";

	price = inputPrice("Enter price: ");

	return Book(libraryCard, issueDate, returnDate, author, title, publicationYear, publishingHouse, price);
}

void inputBookChanged(std::vector<Book>::iterator &it) {
	std::cout << "-------------BOOK-------------" << std::endl;
	std::cout << "Type \"skip\" to skip" << std::endl;
	int intTmp;
	dec::decimal<2> decTmp;
	std::string strTmp;
	Date dateTmp;
	Date defDt = Date();

	intTmp = inputInt("Enter library card(default: " + std::to_string(it->libraryCard) + "): ", 0, 1000, false);
	if (intTmp != -1) it->libraryCard = intTmp;

	strTmp = it->issueDate.ToString();
	dateTmp = inputDate("Enter issue date(dd/mm/yyyy)(default: " + strTmp + "):", false);
	if (dateTmp == defDt);
	else it->issueDate = dateTmp;

	strTmp = it->returnDate.ToString();
	dateTmp = inputDate("Enter return date(dd/mm/yyyy)(default: " + strTmp + "):", false);
	if (dateTmp == defDt);
	else it->returnDate = dateTmp;

	std::cout << "Enter author(dafault: " + it->author + "): ";
	std::cin >> strTmp;
	if (strTmp == "exit") throw "exit";
	if (strTmp != "skip") it->author = strTmp;

	std::cout << "Enter title(dafault: " + it->title + "): ";
	std::cin >> strTmp;
	if (strTmp == "exit") throw "exit";
	if (strTmp != "skip") it->title = strTmp;


	intTmp = inputInt("Enter publication year(default: " + std::to_string(it->publicationYear) + "): ", 1900, 2017, false);
	if (intTmp != -1) it->publicationYear = intTmp;

	std::cout << "Enter publishing house(dafault: " + it->publishingHouse + "): ";
	std::cin >> strTmp;
	if (strTmp == "exit") throw "exit";
	if (strTmp != "skip") it->publishingHouse = strTmp;


	decTmp = inputPrice("Enter price(default: " + dec::toString(it->price) + "): ", false);
	if (decTmp != dec::decimal_cast<2>(-1))
		it->price = decTmp;
}