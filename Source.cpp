//4.Библиотека

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm> 
#include <vector>
#include <iterator>
#include <stdlib.h>
#include <functional>
#include <math.h>
#include "Date.h"
#include "Decimal.h"

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
	os <<	std::to_string(sub.libraryCard) + "\t" +
			sub.subSurname + "\n";

	return os;
}

std::istream& operator >> (std::istream &is, Subscriber &sub) {
	is >> sub.libraryCard;
	is >> sub.subSurname;

	return is;
}

Subscriber inputSubscriber();
void inputSubscriberChanged(std::vector<Subscriber>::iterator &it);


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

	~Book()	{}

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

std::istream& operator>>(std::istream &is, Book &book) {
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

Book inputBook();
void inputBookChanged(std::vector<Book>::iterator &it);

//Predicats and Comparators

class LibraryCardPred {
protected:
	int card;

public:
	LibraryCardPred(int n) :card(n) {}

	bool operator() (Book book) {
		return card == book.libraryCard;
	}

	bool operator() (Subscriber sub) {
		return card == sub.libraryCard;
	}
};

class SurnamePred {
protected:
	std::string surname;

public:
	SurnamePred(std::string str) :surname(str) {}

	bool operator() (Subscriber sub) {
		return surname == sub.subSurname;
	}
};

class AuthorPred {
protected:
	std::string author;

public:
	AuthorPred(std::string s) :author(s) {}

	bool operator() (Book book) {
		return author == book.author;
	}
};

class TitlePred {
protected:
	std::string title;

public:
	TitlePred(std::string s) :title(s) {}

	bool operator() (Book book) {
		return title == book.title;
	}
};

class PublishingHousePred {
protected:
	std::string house;

public:
	PublishingHousePred(std::string s) :house(s) {}

	bool operator() (Book book) {
		return house == book.publishingHouse;
	}
};

class ReturnDatePred {
protected:
	Date date;

public:
	ReturnDatePred(Date _date) {
		date = _date;
	}

	bool operator() (Book book) {
		return date == book.returnDate;
	}
};

class LibraryCardComp {
public:
	bool operator()(Book book1, Book book2) {
		return book1.libraryCard < book2.libraryCard;
	}

	bool operator()(Subscriber sub1, Subscriber sub2) {
		return sub1.libraryCard < sub2.libraryCard;
	}
};

class SurnameComp {
public:
	bool operator()(Subscriber sub1, Subscriber sub2) {
		return sub1.subSurname < sub2.subSurname;
	}
};

class AuthorComp {
public:
	bool operator()(Book book1, Book book2) {
		return book1.author < book2.author;
	}
};

class TitleComp {
public:
	bool operator()(Book book1, Book book2) {
		return book1.title < book2.title;
	}
};

class PublishingHouseComp {
public:
	bool operator()(Book book1, Book book2) {
		return book1.publishingHouse < book2.publishingHouse;
	}
};

class ReturnDateComp {
public:
	bool operator()(Book book1, Book book2) {
		return book1.returnDate < book2.returnDate;
	}
};

class SubLibraryCardAcc {
protected:
	int card;
	std::vector<Subscriber> *v;

public:
	SubLibraryCardAcc(int n) {
		card = n;
		v = new std::vector<Subscriber>();
	}

	std::vector<Subscriber> getSet() {
		return *v;
	}

	void operator()(Subscriber sub) {
		if (card == sub.libraryCard)
			(*v).push_back(sub);
	}
};

class SubSurnameAcc {
protected:
	std::string surname;
	std::vector<Subscriber> *v;

public:
	SubSurnameAcc(std::string s) {
		surname = s;
		v = new std::vector<Subscriber>();
	}

	std::vector<Subscriber> getSet() {
		return *v;
	}

	void operator()(Subscriber sub) {
		if (surname == sub.subSurname)
			(*v).push_back(sub);
	}
};

class LibraryCardAcc {
protected:
	int card;
	std::vector<Book> *v;

public:
	LibraryCardAcc(int n) {
		card = n;
		v = new std::vector<Book>();
	}

	std::vector<Book> getSet() {
		return *v;
	}

	void operator()(Book book) {
		if (card == book.libraryCard)
			(*v).push_back(book);
	}
};

class AuthorAcc {
protected:
	std::string author;
	std::vector<Book> *v;

public:
	AuthorAcc(std::string s) {
		author = s;
		v = new std::vector<Book>();
	}

	std::vector<Book> getSet() {
		return *v;
	}

	void operator()(Book book) {
		if (author == book.author)
			(*v).push_back(book);
	}
};

class TitleAcc {
protected:
	std::string title;
	std::vector<Book> *v;

public:
	TitleAcc(std::string s) {
		title = s;
		v = new std::vector<Book>();
	}

	std::vector<Book> getSet() {
		return *v;
	}

	void operator()(Book book) {
		if (title == book.title)
			(*v).push_back(book);
	}
};

class PublishingHouseAcc {
protected:
	std::string house;
	std::vector<Book> *v;

public:
	PublishingHouseAcc(std::string s) {
		house = s;
		v = new std::vector<Book>();
	}

	std::vector<Book> getSet() {
		return *v;
	}

	void operator()(Book book) {
		if (house == book.publishingHouse)
			(*v).push_back(book);
	}
};

class ReturnDateAcc {
protected:
	Date date;
	std::vector<Book> *v;

public:
	ReturnDateAcc(Date _date) {
		date = _date;
		v = new std::vector<Book>();
	}

	std::vector<Book> getSet() {
		return *v;
	}

	void operator()(Book book) {
		if (date == book.returnDate)
			(*v).push_back(book);
	}
};

template<class P>
class Container {
protected:
	std::vector<P> vect;
public:
	typedef std::_Vector_iterator<std::_Vector_val<std::_Simple_types<P>>> my_iterator;
	typedef std::_Vector_const_iterator<std::_Vector_val<std::_Simple_types<P>>> my_const_iterator;

	Container(int size) {
		vect = std::vector<P>(size);
	}

	Container() {
		vect = std::vector<P>();
	}

	void clear() {
		vect.clear();
	}

	~Container() {}

	my_const_iterator begin() {
		return vect.cbegin();
	}

	my_const_iterator end() {
		return vect.cend();
	}

	int size() {
		return vect.size();
	}

	bool add(P p) {
		if (!find(p)) {
			vect.push_back(p);
			return true;
		}

		return false;
	}

	void remove(my_iterator &it) {
		vect.erase(it);
	}

	bool find(P p) {
		return std::find(vect.begin(), vect.end(), p) != vect.end();
	}

	bool find(P p, my_iterator &it) {
		my_iterator itTmp;
		itTmp = std::find(vect.begin(), vect.end(), p);
		if (itTmp == vect.end()) return false;
		it = itTmp;
		return true;
	}

	template<class Pred>
	bool find(Pred &pred, my_iterator &it) {
		my_iterator itTmp;
		itTmp = std::find_if(vect.begin(), vect.end(), pred);
		if (itTmp == vect.end()) return false;
		it = itTmp;
		return true;
	}

	template<class Comp>
	bool find(Comp &comp, P p, my_iterator &it) {
		my_iterator itTmp;
		std::sort(vect.begin(), vect.end(), comp);
		itTmp = std::lower_bound(vect.begin(), vect.end(), p, comp);
		if (itTmp == vect.end() || comp(p, *itTmp)) return false;
		it = itTmp;
		return true;
	}

	template<class Comp>
	void sort(Comp &comp) {
		std::sort(vect.begin(), vect.end(), comp);
	}

	template<class Acc>
	std::vector<P> findSubset(Acc acc) {
		std::for_each(vect.begin(), vect.end(), acc);
		return acc.getSet();
	}
};

//Контейнер читателей
class SubscriberContainer : public Container<Subscriber> {
public:
	SubscriberContainer() {}

	SubscriberContainer(std::vector<Subscriber> _vect) {
		vect = _vect;
	}

	void sortByLibraryCard() {
		sort(LibraryCardComp());
	}

	void sortBySurname() {
		sort(SurnameComp());
	}

	bool findByLibraryCard(int card, my_iterator &it) {
		return find(LibraryCardPred(card), it);
	}

	bool findBySurname(std::string surname, my_iterator &it) {
		return find(SurnamePred(surname), it);
	}

	bool findByLibraryCardBinary(int card, my_iterator &it) {
		Subscriber sub = Subscriber(card, "");
		return find(LibraryCardComp(), sub, it);
	}

	bool findBySurnameBinary(std::string surname, my_iterator &it) {
		Subscriber sub = Subscriber(0, surname);
		return find(SurnameComp(), sub, it);
	}

	SubscriberContainer findSubSetByLibraryCard(int card) {
		return SubscriberContainer(findSubset(SubLibraryCardAcc(card)));
	}

	SubscriberContainer findSubSetBySurname(std::string surname) {
		return SubscriberContainer(findSubset(SubSurnameAcc(surname)));
	}

	void fileInput(std::fstream fin) {
		if (fin.is_open()) {
			std::istream_iterator<Subscriber> is(fin);
			vect.clear();
			if (fin.eof()) return;
			Subscriber sub = *is++;
			while (!fin.fail() && !fin.eof()) {
				add(sub);
				sub = *is++;
			}
			add(sub);
			fin.close();
		}
		else
			std::cout << "File doesn't exist!" << std::endl;
	}

	void fileOutput(std::fstream fout) {
		if (fout.is_open()) {
			copy(vect.begin(), vect.end(), std::ostream_iterator<Subscriber>(fout, "\n"));
			fout.close();
		}
		else
			std::cout << "Error while opening file!" << std::endl;
	}

	void output(std::ostream_iterator<Subscriber> os) {
		copy(vect.begin(), vect.end(), os);
	}
};

//Контейнер книг
class BookContainer : public Container<Book> {
public:
	BookContainer() {}

	BookContainer(std::vector<Book> _vect) {
		vect = _vect;
	}

	void sortByLibraryCard() {
		sort(LibraryCardComp());
	}

	void sortByAuthor() {
		sort(AuthorComp());
	}

	void sortByTitle() {
		sort(TitleComp());
	}

	void sortByPublishingHouse() {
		sort(PublishingHouseComp());
	}

	void sortByReturnDate() {
		sort(ReturnDateComp());
	}
	bool findByLibraryCard(int card, my_iterator &it) {
		return find(LibraryCardPred(card), it);
	}

	bool findByAuthor(std::string author, my_iterator &it) {
		return find(AuthorPred(author), it);
	}

	bool findByTitle(std::string title, my_iterator &it) {
		return find(TitlePred(title), it);
	}

	bool findByPublishingHouse(std::string house, my_iterator &it) {
		return find(PublishingHousePred(house), it);
	}

	bool findByReturnDate(Date date, my_iterator &it) {
		return find(ReturnDatePred(date), it);
	}

	bool findByLibraryCardBinary(int card, my_iterator &it) {
		Book book = Book(card, Date(), Date(), "", "", 1990, "", dec::decimal_cast<2>(0));
		return find(LibraryCardComp(), book, it);
	}

	bool findByAuthorBinary(std::string author, my_iterator &it) {
		Book book = Book(0, Date(), Date(), author, "", 1990, "", dec::decimal_cast<2>(0));
		return find(AuthorComp(), book, it);
	}

	bool findByTitleBinary(std::string title, my_iterator &it) {
		Book book = Book(0, Date(), Date(), "", title, 1990, "", dec::decimal_cast<2>(0));
		return find(TitleComp(), book, it);
	}

	bool findByPublishingHouseBinary(std::string house, my_iterator &it) {
		Book book = Book(0, Date(), Date(), "", "", 1990, house, dec::decimal_cast<2>(0));
		return find(PublishingHouseComp(), book, it);
	}

	bool findByReturnDateBinary(Date date, my_iterator &it) {
		Book book = Book(0, Date(), date, "", "", 1990, "", dec::decimal_cast<2>(0));
		return find(ReturnDateComp(), book, it);
	}

	BookContainer findSubSetByLibraryCard(int card) {
		return BookContainer(findSubset(LibraryCardAcc(card)));
	}

	BookContainer findSubSetByAuthor(std::string author) {
		return BookContainer(findSubset(AuthorAcc(author)));
	}

	BookContainer findSubSetByTitle(std::string title) {
		return BookContainer(findSubset(TitleAcc(title)));
	}

	BookContainer findSubSetByPublishingHouse(std::string house) {
		return BookContainer(findSubset(PublishingHouseAcc(house)));
	}

	BookContainer findSubSetByReturnDate(Date date) {
		return BookContainer(findSubset(ReturnDateAcc(date)));
	}

	void fileInput(std::fstream fin) {
		if (fin.is_open()) {
			std::istream_iterator<Book> is(fin);
			vect.clear();
			if (fin.eof()) return;
			Book book = *is++;
			while (!fin.fail() && !fin.eof()) {
				add(book);
				book = *is++;
			}
			add(book);
			fin.close();
		}
		else
			std::cout << "File doesn't exist!" << std::endl;
	}

	void fileOutput(std::fstream fout) {
		if (fout.is_open()) {
			copy(vect.begin(), vect.end(), std::ostream_iterator<Book>(fout, "\n"));
			fout.close();
		}
		else
			std::cout << "Error while opening file!" << std::endl;
	}

	void output(std::ostream_iterator<Book> os) {
		copy(vect.begin(), vect.end(), os);
	}
};


bool checkInt(std::string str) {
	if (str.length() == 0) {
		return false;
	}
	size_t i = 0;
	while ((i < str.length()) && ((str[i] == ' ') || (str[i] == '	'))) {
		++i;
	}
	if (i >= str.length()) {
		return false;
	}
	int sign = 1;
	switch (str[i]) {
	case '-': {
		sign = -1;
		++i;
		break;
	}
	case '+': {
		++i;
		break;
	}
	default: {
		break;
	}
	}

	size_t j = i;
	bool result = j < str.length();
	while ((j < str.length()) && (result)) {
		result = (str[j] >= '0') && (str[j] <= '9');
		++j;
	}

	while ((j < str.length()) && ((str[j] == ' ') || (str[j] == '	'))) {
		++j;
	}

	return (j == str.length()) && (result);
}

int inputInt(std::string message, int min = 0, int max = 10000, bool isAdd = true) {
	std::string str;
	int res;
	bool ok = false;

	while (!ok) {
		std::cout << message;
		try {
			std::cin >> str;
			if (str == "exit") throw "exit";
			if (!isAdd && str == "skip") return -1;

			if (checkInt(str)) {
				res = std::stoi(str);
				if (res < min || res > max)
					std::cout << "Wrong value. Repeat: ";
				else
					ok = true;
			}
			else
				std::cout << "Wrong value! ";
		}
		catch (std::exception&) {
			std::cout << "Wrong number!" << std::endl;
		}
	}

	return res;
}

Date inputDate(std::string message = "Input date in format dd/mm/yyyy : ", bool isAdd = true) {
	std::string res;
	Date date = Date();

	std::cout << message;
	bool ok = false;

	while (!ok) {
		std::cin >> res;
		if (res == "exit") throw "exit";
		if (!isAdd && res == "skip") return date;
		ok = date.TryStrToDate(res);
		if (!ok) std::cout << "Wrong date. Repeat: ";
	}

	return date;
}

bool checkPrice(std::string price) {
	if (price.length() == 0) {
		return false;
	}

	size_t i = 0;
	while ((i < price.length()) && ((price[i] == ' ') || (price[i] == '	'))) {
		++i;
	}

	if (i >= price.length()) {
		return false;
	}

	int sign = 1;

	switch (price[i]) {
		case '-': {
			return false;
		}

		case '+': {
			++i;
			break;
		}

		default: {
			break;
		}
	}

	size_t j = i;
	bool result = j < price.length();
	int dot_number = 0;
	while ((j < price.length()) && (result)) {
		if (price[j] == '.') {
			++dot_number;
		}
		result = ((price[j] >= '0') && (price[j] <= '9')) || ((price[j] == '.') && (dot_number <= 1));
		++j;
	}

	while ((j < price.length()) && ((price[j] == ' ') || (price[j] == '	'))) {
		++j;
	}

	return (j == price.length()) && (result);
}

dec::decimal<2> inputPrice(std::string message = "Input price : ", bool isAdd = true) {
	std::string tmp;
	dec::decimal<2> res;

	std::cout << message;
	bool ok = false;

	while (!ok) {
		std::cin >> tmp;
		if (tmp == "exit") throw "exit";
		if (!isAdd && tmp == "skip") return dec::decimal_cast<2>(-1);
		ok = checkPrice(tmp);
		if (!ok) std::cout << "Wrong price. Repeat: ";
	}
	dec::fromString(tmp, res);
	return res;
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

	libraryCard = inputInt("Enter library card(0 - book without sub): ");

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
	else it->returnDate= dateTmp;

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

void consoleInput(BookContainer &cont) {
	cont.clear();
	Book book;
	while (true) {
		try {
			book = inputBook();
		}
		catch (const char*) {
			return;
		}

		cont.add(book);
	}
}

void consoleInput(SubscriberContainer &cont) {
	cont.clear();
	Subscriber sub;
	while (true) {
		try {
			sub = inputSubscriber();
		}
		catch (const char*) {
			return;
		}

		cont.add(sub);
	}
}

//void consoleOutput(MyContainer cont) {
//	if (cont.size() == 0) {
//		std::cout << "Container is empty!" << std::endl;
//	}
//	else {
//		std::cout << "LC\tSub Surname\tIssue Date\tReturn Date\tAuthor\t\tTitle\tPYear\tPHouse\tPrice" << std::endl;
//		copy(cont.begin(), cont.end(), std::ostream_iterator<Book>(std::cout, "\n"));
//	}
//}

void consoleOutput(SubscriberContainer cont) {
	if (cont.size() == 0) {
		std::cout << "Container is empty!" << std::endl;
	}
	else {
		std::cout << "LC\tSubSurname" << std::endl;
		cont.output(std::ostream_iterator<Subscriber>(std::cout, "\n"));
	}
}

void consoleOutput(BookContainer cont) {
	if (cont.size() == 0) {
		std::cout << "Container is empty!" << std::endl;
	}
	else {
		std::cout << "LC\tIssue Date\tReturn Date\tAuthor\t\tTitle\tPYear\tPHouse\tPrice" << std::endl;
		cont.output(std::ostream_iterator<Book>(std::cout, "\n"));
	}
}

void printModeMenu() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)Librarian" << std::endl;
	std::cout << " 2)Subscriber" << std::endl;
	std::cout << " 0)Exit" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

void printSubscriberMenu() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)Find book" << std::endl;
	std::cout << " 2)Take book" << std::endl;
	std::cout << " 3)Return book" << std::endl;
	std::cout << " 0)Exit" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

void printLibrarianMenu() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)Input subscribers" << std::endl;
	std::cout << " 2)Output subscribers" << std::endl;
	std::cout << " 3)Input books" << std::endl;
	std::cout << " 4)Output books" << std::endl;
	std::cout << " 5)Edit subscribers" << std::endl;
	std::cout << " 6)Edit books" << std::endl;
	std::cout << " 0)Exit" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

void printSubEdit() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)Add subscriber" << std::endl;
	std::cout << " 2)Find subscriber" << std::endl;
	std::cout << " 3)Find subscribers(subset)" << std::endl;
	std::cout << " 4)Sort subscribers" << std::endl;
	std::cout << " 0)Exit" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

void printBookEdit() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)Add book" << std::endl;
	std::cout << " 2)Find book" << std::endl;
	std::cout << " 3)Find books(subset)" << std::endl;
	std::cout << " 4)Sort books" << std::endl;
	std::cout << " 0)Exit" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

void printMenuConsoleFile() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)Console" << std::endl;
	std::cout << " 2)File" << std::endl;
	std::cout << " 0)Exit" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

void printMenuFindParamBook() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)By library card" << std::endl;
	std::cout << " 2)By author" << std::endl;
	std::cout << " 3)By title" << std::endl;
	std::cout << " 4)By publishing house" << std::endl;
	std::cout << " 5)By return date" << std::endl;
	std::cout << " 0)Exit" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

void printMenuFindParamSubscriber() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)By library card" << std::endl;
	std::cout << " 2)By surname" << std::endl;
	std::cout << " 0)Exit" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

void printMenuSearch() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Command list:" << std::endl;
	std::cout << " 1)Simple search" << std::endl;
	std::cout << " 2)Binary search" << std::endl;
	std::cout << " 0)Exit" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

void printAction() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "Action with record:" << std::endl;
	std::cout << " 1)Print" << std::endl;
	std::cout << " 2)Change" << std::endl;
	std::cout << " 3)Delete" << std::endl;
	std::cout << " 0)Exit" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

void printBookCaption() {
	std::cout << "LC\tIssue Date\tReturn Date\tAuthor\t\tTitle\tPYear\tPHouse\tPrice" << std::endl;
}

void printSubscriberCaption() {
	std::cout << "LC\tSurname" << std::endl;
}

std::string output_file_name() {
	std::string name;
	std::cout << "Enter file name(empty string = 'defaulname'): ";
	std::getline(std::cin, name);
	std::getline(std::cin, name);
	if (name == "") name = "defaultname";
	return name + ".txt";
}

std::string input_file_name() {
	std::fstream f;
	std::string res;
	std::cout << "Enter text file name(empty string = 'defaultname'): ";
	std::getline(std::cin, res);
	std::getline(std::cin, res);
	f.open(res + ".txt");
	while (!f.is_open() && res != "") {
		std::cout << "There are no such file, repeat input(empty string = 'defaultname'): ";
		std::getline(std::cin, res);
		f.open(res + ".txt");
	};
	f.close();
	return (res == "") ? "defaultname.txt" : res + ".txt";
}

//Поиск только сабсетами и рекурсивная функция для фильтрации с коестантной глубиной

int main() {
	BookContainer bookContainer = BookContainer();
	SubscriberContainer subscriberContainer = SubscriberContainer();
	BookContainer subcontBook = BookContainer();
	SubscriberContainer subcontSubscriber = SubscriberContainer();
	std::string str;
	int n, currentSubscriber;
	bool binarSearch;
	bool found;
	std::string FName;
	std::vector<Book>::iterator itBook;
	std::vector<Subscriber>::iterator itSubscriber;

	subscriberContainer.fileInput(std::fstream("subs.txt", std::ios::in));
	bookContainer.fileInput(std::fstream("asd.txt", std::ios::in));

	while (true) {
		printModeMenu();
		n = inputInt("Enter the command: ", 0, 2);
		switch (n) {
		case 1:
			printLibrarianMenu();
			n = inputInt("Enter the command: ", 0, 6);
			while (n != 0) {
				switch (n) {
				case 1://INPUT SUB
					printMenuConsoleFile();
					n = inputInt("Enter the command: ", 0, 2);
					switch (n) {
					case 1:
						consoleInput(subscriberContainer);
						break;
					case 2:
						FName = input_file_name();
						subscriberContainer.fileInput(std::fstream(FName, std::ios::in));
						break;
					case 0:
						break;
					}
					break;
				case 2://OUTPUT SUB
					printMenuConsoleFile();
					n = inputInt("Enter the command:", 0, 2);
					switch (n) {
					case 1:
						consoleOutput(subscriberContainer);
						break;
					case 2:
						FName = output_file_name();
						subscriberContainer.fileOutput(std::fstream(FName, std::ios::out));
						break;
					case 0:
						break;
					}
					break;
				case 3://INPUT BOOK
					printMenuConsoleFile();
					n = inputInt("Enter the command: ", 0, 2);
					switch (n) {
					case 1:
						consoleInput(bookContainer);
						break;
					case 2:
						FName = input_file_name();
						bookContainer.fileInput(std::fstream(FName, std::ios::in));
						break;
					case 0:
						break;
					}
					break;
				case 4://OUTPUT BOOK
					printMenuConsoleFile();
					n = inputInt("Enter the command:", 0, 2);
					switch (n) {
					case 1:
						consoleOutput(bookContainer);
						break;
					case 2:
						FName = output_file_name();
						bookContainer.fileOutput(std::fstream(FName, std::ios::out));
						break;
					case 0:
						break;
					}
					break;
				case 5://EDIT SUBS
					printSubEdit();
					n = inputInt("Enter the command:", 0, 4);
					while (n != 0) {
						switch(n) {
						case 1://Add
							try {
								subscriberContainer.add(inputSubscriber());
							}
							catch (const char*) {
								break;
							}
							break;
						case 2://Find
							printMenuSearch();
							n = inputInt("Enter the command: ", 0, 2);
							switch (n) {
							case 1://SIMPLE
								binarSearch = false;
								break;
							case 2://BINARY
								binarSearch = true;
								break;
							}
							if (n != 0) {
								printMenuFindParamSubscriber();
								n = inputInt("Enter the command: ", 0, 2);
								switch (n) {
								case 0:
									break;
								case 1://Library card
									if (binarSearch)
										found = subscriberContainer.findByLibraryCardBinary(inputInt("Enter library card: "), itSubscriber);
									else
										found = subscriberContainer.findByLibraryCard(inputInt("Enter library card: "), itSubscriber);
									break;
								case 2://Surname
									std::cout << "Enter surname: ";
									std::cin >> str;

									if (binarSearch)
										found = subscriberContainer.findBySurnameBinary(str, itSubscriber);
									else
										found = subscriberContainer.findBySurname(str, itSubscriber);
									break;
								}
								if (n != 0) {
									if (found) {
										std::cout << "Record found \n";
										printAction();
										n = inputInt("Enter the command: ", 0, 3);
										while (n != 0) {
											switch (n) {
											case 1:
												printSubscriberCaption();
												std::cout << *itSubscriber;
												break;
											case 2:
												try {
													inputSubscriberChanged(itSubscriber);
												}
												catch (const char*) {
													break;
												}
												break;
											case 3:
												subscriberContainer.remove(itSubscriber);
												std::cout << "Record was deleted" << std::endl;
												break;
											case 0:
												break;
											}
											if (n == 3) break;
											printAction();
											n = inputInt("Enter the command: ", 0, 3);
										}
									}
									else
										std::cout << "Record not found \n";
								}
							}
							break;
						case 3://subset
							printMenuFindParamSubscriber();
							n = inputInt("Enter the command: ", 0, 2);
							switch (n) {
							case 0:
								break;
							case 1://Library card
								subcontSubscriber = subscriberContainer.findSubSetByLibraryCard(inputInt("Enter library card: "));
								break;
							case 2://Surname
								std::cout << "Enter surname: ";
								std::cin >> str;
								subcontSubscriber = subscriberContainer.findSubSetBySurname(str);
								break;
							}
							if (n != 0) {
								if (subcontSubscriber.size() == 0) {
									std::cout << "Subset is emty!" << std::endl;
									break;
								}
								else {
									std::cout << std::endl << subcontSubscriber.size() << " record(s) found!" << std::endl;
								}
								printMenuConsoleFile();
								n = inputInt("Enter the command: ", 0, 2);
								switch (n) {
								case 1:
									consoleOutput(subcontSubscriber);
									break;
								case 2:
									FName = output_file_name();
									subcontSubscriber.fileOutput(std::fstream(FName, std::ios::out));
									break;
								case 0:
									break;
								}
							}
							break;
						case 4:
							printMenuFindParamSubscriber();
							n = inputInt("Enter the command: ", 0, 2);
							switch(n) {
							case 1:
								subscriberContainer.sortByLibraryCard();
								consoleOutput(subscriberContainer);
								break;
							case 2:
								subscriberContainer.sortBySurname();
								consoleOutput(subscriberContainer);
								break;
							case 0:
								break;
							}
						case 0:
							break;
						}
						printSubEdit();
						n = inputInt("Enter the command:", 0, 4);
					}
					break;
				case 6://Edit books
					printBookEdit();
					n = inputInt("Enter the command:", 0, 4);
					while (n != 0) {
						switch (n) {
						case 1://Add
							try {
								bookContainer.add(inputBook());
							}
							catch (const char*) {
								break;
							}
							break;
						case 2://Find
							printMenuSearch();
							n = inputInt("Enter the command: ", 0, 2);
							switch (n) {
							case 1://SIMPLE
								binarSearch = false;
								break;
							case 2://BINARY
								binarSearch = true;
								break;
							}
							if (n != 0) {
								printMenuFindParamBook();
								n = inputInt("Enter the command: ", 0, 5);
								switch (n) {
								case 0:
									break;
								case 1://Library card
									if (binarSearch)
										found = bookContainer.findByLibraryCardBinary(inputInt("Enter library card: "), itBook);
									else
										found = bookContainer.findByLibraryCard(inputInt("Enter library card: "), itBook);
									break;
								case 2://Author
									std::cout << "Enter author: ";
									std::cin >> str;

									if (binarSearch)
										found = bookContainer.findByAuthorBinary(str, itBook);
									else
										found = bookContainer.findByAuthor(str, itBook);
									break;
								case 3://Title
									std::cout << "Enter title: ";
									std::cin >> str;

									if (binarSearch)
										found = bookContainer.findByTitleBinary(str, itBook);
									else
										found = bookContainer.findByTitle(str, itBook);
									break;
								case 4://Publishing house
									std::cout << "Enter publishing house: ";
									std::cin >> str;

									if (binarSearch)
										found = bookContainer.findByPublishingHouseBinary(str, itBook);
									else
										found = bookContainer.findByPublishingHouse(str, itBook);
									break;
								case 5://Return date
									if (binarSearch)
										found = bookContainer.findByReturnDateBinary(inputDate("Enter return date: "), itBook);
									else
										found = bookContainer.findByReturnDate(inputDate("Enter return date: "), itBook);
									break;
								}
								if (n != 0) {
									if (found) {
										std::cout << "Record found \n";
										printAction();
										n = inputInt("Enter the command: ", 0, 3);
										while (n != 0) {
											switch (n) {
											case 1:
												printBookCaption();
												std::cout << *itBook;
												break;
											case 2:
												try {
													inputBookChanged(itBook);
												}
												catch (const char*) {
													break;
												}
												break;
											case 3:
												bookContainer.remove(itBook);
												std::cout << "Record was deleted" << std::endl;
												break;
											case 0:
												break;
											}
											if (n == 3) break;
											printAction();
											n = inputInt("Enter the command: ", 0, 3);
										}
									}
									else
										std::cout << "Record not found \n";
								}
							}
							break;
						case 3://subset
							printMenuFindParamBook();
							n = inputInt("Enter the command: ", 0, 5);
							switch (n) {
							case 0:
								break;
							case 1://Library card
								subcontBook = bookContainer.findSubSetByLibraryCard(inputInt("Enter library card: "));
								break;
							case 2://Author
								std::cout << "Enter author: ";
								std::cin >> str;
								subcontBook = bookContainer.findSubSetByAuthor(str);
								break;
							case 3://Title
								std::cout << "Enter title: ";
								std::cin >> str;
								subcontBook = bookContainer.findSubSetByTitle(str);
								break;
							case 4://Publishing house
								std::cout << "Enter publishing house: ";
								std::cin >> str;
								subcontBook = bookContainer.findSubSetByPublishingHouse(str);
								break;
							case 5://Return date
								subcontBook = bookContainer.findSubSetByReturnDate(inputDate("Enter return date: "));
								break;
							}
							if (n != 0) {
								if (subcontBook.size() == 0) {
									std::cout << "Subset is emty!" << std::endl;
									break;
								}
								else {
									std::cout << std::endl << subcontBook.size() << " record(s) found!" << std::endl;
								}
								printMenuConsoleFile();
								n = inputInt("Enter the command: ", 0, 2);
								switch (n) {
								case 1:
									consoleOutput(subcontBook);
									break;
								case 2:
									FName = output_file_name();
									subcontBook.fileOutput(std::fstream(FName, std::ios::out));
									break;
								case 0:
									break;
								}
							}
							break;
						case 4:
							printMenuFindParamBook();
							n = inputInt("Enter the command: ", 0, 5);
							switch (n) {
							case 1:
								bookContainer.sortByLibraryCard();
								consoleOutput(bookContainer);
								break;
							case 2:
								bookContainer.sortByAuthor();
								consoleOutput(bookContainer);
								break;
							case 3:
								bookContainer.sortByTitle();
								consoleOutput(bookContainer);
								break;
							case 4:
								bookContainer.sortByPublishingHouse();
								consoleOutput(bookContainer);
								break;
							case 5:
								bookContainer.sortByReturnDate();
								consoleOutput(bookContainer);
								break;
							case 0:
								break;
							}
						case 0:
							break;
						}
						printBookEdit();
						n = inputInt("Enter the command:", 0, 4);
					}
				}
				printLibrarianMenu();
				n = inputInt("Enter the command: ", 0, 6);
			}
			break;
		case 2:
			if (subscriberContainer.size() == 0)
				std::cout << "Please, load materials via librarian!" << std::endl;
			else {
				consoleOutput(subscriberContainer);
				try {
					currentSubscriber = inputInt("Enter your library card or \"exit\" to exit:  ", 1);
					if (!subscriberContainer.findByLibraryCard(currentSubscriber, itSubscriber)) {
						std::cout << "You are not registered. Please, enter another LC or contact librarian!" << std::endl;
					}
					else {
						printSubscriberMenu();
						n = inputInt("Enter the command: ", 0, 3);
						while (n != 0) {
							switch (n) {
							case 1:
								printMenuSearch();
								n = inputInt("Enter the command: ", 0, 2);
								switch (n) {
								case 1://SIMPLE
									binarSearch = false;
									break;
								case 2://BINARY
									binarSearch = true;
									break;
								}
								if (n != 0) {
									printMenuFindParamBook();
									n = inputInt("Enter the command: ", 0, 4);
									switch (n) {
									case 0:
										break;
									case 1://Library card
										if (binarSearch)
											found = bookContainer.findByLibraryCardBinary(inputInt("Enter library card: "), itBook);
										else
											found = bookContainer.findByLibraryCard(inputInt("Enter library card: "), itBook);
										break;
									case 2://Author
										std::cout << "Enter author: ";
										std::cin >> str;

										if (binarSearch)
											found = bookContainer.findByAuthorBinary(str, itBook);
										else
											found = bookContainer.findByAuthor(str, itBook);
										break;
									case 3://Title
										std::cout << "Enter title: ";
										std::cin >> str;

										if (binarSearch)
											found = bookContainer.findByTitleBinary(str, itBook);
										else
											found = bookContainer.findByTitle(str, itBook);
										break;
									case 4://Publishing house
										std::cout << "Enter publishing house: ";
										std::cin >> str;

										if (binarSearch)
											found = bookContainer.findByPublishingHouseBinary(str, itBook);
										else
											found = bookContainer.findByPublishingHouse(str, itBook);
										break;
									case 5://Return date
										if (binarSearch)
											found = bookContainer.findByReturnDateBinary(inputDate("Enter return date: "), itBook);
										else
											found = bookContainer.findByReturnDate(inputDate("Enter return date: "), itBook);
										break;
									}
									if (n != 0) {
										if (found) {
											std::cout << "Record found \n";
											printAction();
											n = inputInt("Enter the command: ", 0, 3);
											while (n != 0) {
												switch (n) {
												case 1:
													printBookCaption();
													std::cout << *itBook;
													break;
												case 2:
													try {
														inputBookChanged(itBook);
													}
													catch (const char*) {
														break;
													}
													break;
												case 3:
													bookContainer.remove(itBook);
													std::cout << "Record was deleted" << std::endl;
													break;
												case 0:
													break;
												}
												if (n == 3) break;
												printAction();
												n = inputInt("Enter the command: ", 0, 3);
											}
										}
										else
											std::cout << "Record not found \n";
									}
								}
								break;
							case 2:
								subcontBook = bookContainer.findSubSetByLibraryCard(0);
								if (subcontBook.size() == 0)
									std::cout << "There are no available books! Please, come again later!" << std::endl;
								else {
									std::cout << "Available books:" << std::endl;
									consoleOutput(subcontBook);
									std::cout << "Enter title of book you want to take or \"exit\" to exit: ";
									std::cin >> str;
									if (str != "exit") {
										if (!subcontBook.findByTitle(str, itBook))
											std::cout << "Such book doesn't exist!";
										else {
											bookContainer.find(*itBook, itBook);
											itBook->libraryCard = currentSubscriber;
											itBook->issueDate = Date(20, 06, 2017);
											itBook->returnDate = Date(20, 07, 2017);
											std::cout << "You take the book!" << std::endl;
										}
									}
								}
								break;
							case 3:
								subcontBook = bookContainer.findSubSetByLibraryCard(currentSubscriber);
								if (subcontBook.size() == 0)
									std::cout << "You don't have any books!" << std::endl;
								else {
									std::cout << "Books, which you can return:" << std::endl;
									consoleOutput(subcontBook);
									std::cout << "Enter title of book you want to return or \"exit\" to exit: ";
									std::cin >> str;
									if (str != "exit") {
										if (!subcontBook.findByTitle(str, itBook))
											std::cout << "Such book doesn't exist!";
										else {
											bookContainer.find(*itBook, itBook);
											itBook->libraryCard = 0;
											std::cout << "You return the book!" << std::endl;
										}
									}
								}
								break;
							}
							printSubscriberMenu();
							n = inputInt("Enter the command: ", 0, 3);
						}
					}
				}

				catch (const char* str) {
					break;
				}
			}
			break;
		case 0:
			return 0;
		}
	}
}