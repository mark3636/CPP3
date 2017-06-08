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
#include "Menu.h"
#include "Book.h"
#include "Subscriber.h"

//Predicats, Comparators and Accumulators
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

class IssueDatePred {
protected:
	Date date;

public:
	IssueDatePred(Date _date) {
		date = _date;
	}

	bool operator() (Book book) {
		return date == book.issueDate;
	}
};

class PublicationYearPred {
protected:
	int year;

public:
	PublicationYearPred(int n) :year(n) {}

	bool operator() (Book book) {
		return year == book.publicationYear;
	}
};

class PricePred {
protected:
	dec::decimal<2> price;

public:
	PricePred(dec::decimal<2> _price) :price(_price) {}

	bool operator() (Book book) {
		return price == book.price;
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

class IssueDateComp {
public:
	bool operator()(Book book1, Book book2) {
		return book1.issueDate < book2.issueDate;
	}
};

class PublicationYearComp {
public:
	bool operator()(Book book1, Book book2) {
		return book1.publicationYear < book2.publicationYear;
	}
};

class PriceComp {
public:
	bool operator()(Book book1, Book book2) {
		return book1.price < book2.price;
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

class IssueDateAcc {
protected:
	Date date;
	std::vector<Book> *v;

public:
	IssueDateAcc(Date _date) {
		date = _date;
		v = new std::vector<Book>();
	}

	std::vector<Book> getSet() {
		return *v;
	}

	void operator()(Book book) {
		if (date == book.issueDate)
			(*v).push_back(book);
	}
};

class PublicationYearAcc {
protected:
	int year;
	std::vector<Book> *v;

public:
	PublicationYearAcc(int n) {
		year = n;
		v = new std::vector<Book>();
	}

	std::vector<Book> getSet() {
		return *v;
	}

	void operator()(Book book) {
		if (year == book.publicationYear)
			(*v).push_back(book);
	}
};

class PriceAcc {
protected:
	dec::decimal<2> price;
	std::vector<Book> *v;

public:
	PriceAcc(dec::decimal<2> _price) {
		price = _price;
		v = new std::vector<Book>();
	}

	std::vector<Book> getSet() {
		return *v;
	}

	void operator()(Book book) {
		if (price == book.price)
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


	P operator[](int index) {
		return vect[index];
	}

	bool add(P p) {
		if (!find(p)) {
			vect.push_back(p);
			return true;
		}
		std::cout << "-------------------------------------" << std::endl;
		std::cout << "Element with such library card already exists!" << std::endl;
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

	void sortByIssueDate() {
		sort(IssueDateComp());
	}

	void sortByPublicationYear() {
		sort(PublicationYearComp());
	}

	void sortByPrice() {
		sort(PriceComp());
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

	bool findByIssueDate(Date date, my_iterator &it) {
		return find(IssueDatePred(date), it);
	}

	bool findByPublicationYear(int year, my_iterator &it) {
		return find(PublicationYearPred(year), it);
	}

	bool findByPrice(dec::decimal<2> price, my_iterator &it) {
		return find(PricePred(price), it);
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

	bool findByIssueDateBinary(Date date, my_iterator &it) {
		Book book = Book(0, date, Date(), "", "", 1990, "", dec::decimal_cast<2>(0));
		return find(IssueDateComp(), book, it);
	}

	bool findByPublicationYearBinary(int year, my_iterator &it) {
		Book book = Book(0, Date(), Date(), "", "", year, "", dec::decimal_cast<2>(0));
		return find(PublicationYearComp(), book, it);
	}

	bool findByPriceBinary(dec::decimal<2> price, my_iterator &it) {
		Book book = Book(0, Date(), Date(), "", "", 1990, "", price);
		return find(PriceComp(), book, it);
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

	BookContainer findSubSetByIssueDate(Date date) {
		return BookContainer(findSubset(IssueDateAcc(date)));
	}

	BookContainer findSubSetByPublicationYear(int year) {
		return BookContainer(findSubset(PublicationYearAcc(year)));
	}

	BookContainer findSubSetByPrice(dec::decimal<2> price) {
		return BookContainer(findSubset(PriceAcc(price)));
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
		printSubscriberCaption();
		cont.output(std::ostream_iterator<Subscriber>(std::cout, "\n"));
	}
}

void consoleOutput(BookContainer cont) {
	if (cont.size() == 0) {
		std::cout << "Container is empty!" << std::endl;
	}
	else {
		printBookCaption();
		cont.output(std::ostream_iterator<Book>(std::cout, "\n"));
	}
}

const int MAX_LEVEL = 2;

void findSubscribers(SubscriberContainer &cont, int level) {
	int n;
	std::string str;

	if (cont.size() > 0)
		consoleOutput(cont);

	if (cont.size() <= 1 || level == MAX_LEVEL)
		return;

	printMenuFindSubscribers();
	n = inputInt("Enter rhe command: ", 0, 3);
	switch (n) {
	case 1://Library card
		cont = cont.findSubSetByLibraryCard(inputInt("Enter library card: "));
		break;
	case 2://Surname
		std::cout << "Enter surname: ";
		std::cin >> str;
		cont = cont.findSubSetBySurname(str);
		break;
	case 3:
		consoleOutput(cont);
		return;
	case 0:
		throw "Exit";
	}

	return findSubscribers(cont, level + 1);
}

void findBooks(BookContainer &cont, int level) {
	int n;
	std::string str;

	if(cont.size() > 0)
		consoleOutput(cont);

	if (cont.size() <= 1 || level == MAX_LEVEL)
		return;

	printMenuFindBooks();
	n = inputInt("Enter the command: ", 0, 9);
	switch (n) {
	case 1://Library card
		cont = cont.findSubSetByLibraryCard(inputInt("Enter library card: "));
		break;
	case 2://Issue date
		cont = cont.findSubSetByIssueDate(inputDate("Enter issue date: "));
		break;
	case 3://Return date
		cont = cont.findSubSetByReturnDate(inputDate("Enter return date: "));
		break;
	case 4://Author
		std::cout << "Enter author: ";
		std::cin >> str;
		cont = cont.findSubSetByAuthor(str);
		break;
	case 5://Title
		std::cout << "Enter title: ";
		std::cin >> str;
		cont = cont.findSubSetByTitle(str);
		break;
	case 6://Publication year
		cont = cont.findSubSetByPublicationYear(inputInt("Enter publication year: ", 1900, 2017));
		break;
	case 7://Publishing house
		std::cout << "Enter publishing house: ";
		std::cin >> str;
		cont = cont.findSubSetByPublishingHouse(str);
		break;
	case 8://Price
		cont = cont.findSubSetByPrice(inputPrice("Enter price: "));
		break;
	case 9://Enter position
		consoleOutput(cont);
		return;
	case 0://Exit
		throw "Exit";
	}

	findBooks(cont, level + 1);
}

void findSubBooks(BookContainer &cont, int level) {
	int n;
	std::string str;

	if (cont.size() > 0)
		consoleOutput(cont);

	if (cont.size() <= 1 || level == MAX_LEVEL)
		return;

	printAuthorAndTitleFind();
	n = inputInt("Enter the command: ", 0, 3);
	switch (n) {
	case 1://Author
		std::cout << "Enter author: ";
		std::cin >> str;
		cont = cont.findSubSetByAuthor(str);
		break;
	case 2://Title
		std::cout << "Enter title: ";
		std::cin >> str;
		cont = cont.findSubSetByTitle(str);
		break;
	case 3://Position
		consoleOutput(cont);
		return;
	case 0:
		throw "Exit";
	}

	return findSubBooks(cont, level + 1);
}

int main() {
	BookContainer bookContainer = BookContainer();
	SubscriberContainer subscriberContainer = SubscriberContainer();
	BookContainer subcontBook = BookContainer();
	SubscriberContainer subcontSubscriber = SubscriberContainer();
	std::string str;
	int n, currentSubscriber;
	bool binarSearch;
	bool found;
	std::string fileName;
	std::vector<Book>::iterator itBook;
	std::vector<Subscriber>::iterator itSubscriber;
	const std::string BOOKS_FILE = "books.txt";
	const std::string SUBS_FILE = "subs.txt";

	subscriberContainer.fileInput(std::fstream(SUBS_FILE, std::ios::in));
	bookContainer.fileInput(std::fstream(BOOKS_FILE, std::ios::in));

	while (true) {
		printModeMenu();
		n = inputInt("Enter the command: ", 0, 2);
		switch (n) {
		case 1:
			printLibrarianMenu();
			n = inputInt("Enter the command: ", 0, 4);
			while (n != 0) {
				switch (n) {
				case 1://Output subs
					consoleOutput(subscriberContainer);
					break;
				case 2://Output books
					consoleOutput(bookContainer);
					break;
				case 3://Edit subs
					printSubEdit();
					n = inputInt("Enter the command: ", 0, 3);
					while (n != 0) {
						switch(n) {
						case 1://Add sub
							try {
								subscriberContainer.add(inputSubscriber());
								subscriberContainer.fileOutput(std::fstream(SUBS_FILE, std::ios::out));
							}
							catch (const char*) {
								break;
							}
							break;
						case 2://Find subs
							subcontSubscriber = subscriberContainer;
							try {
								findSubscribers(subcontSubscriber, 0);
								if (subcontSubscriber.size() == 0) {
									std::cout << "-------------------------------------" << std::endl;
									std::cout << "There are no such subscribers!" << std::endl;
								}
								else {
									if (subcontSubscriber.size() > 1) {
										n = inputInt("Enter subscriber's position in the list(1.."
											+ std::to_string(subcontSubscriber.size()) + ") or \"exit\" to exit: ", 1, subcontSubscriber.size());
										subscriberContainer.find(subcontSubscriber[n - 1], itSubscriber);
										printSubscriberCaption();
										std::cout << *itSubscriber << std::endl;
									}
									else
										subscriberContainer.find(subcontSubscriber[0], itSubscriber);
									printAction();
									n = inputInt("Enter the command: ", 0, 3);
									while (n != 0) {
										switch (n) {
										case 1://Print sub
											printSubscriberCaption();
											std::cout << *itSubscriber;
											break;
										case 2://Change sub
											try {
												inputSubscriberChanged(itSubscriber);
												subscriberContainer.fileOutput(std::fstream(SUBS_FILE, std::ios::out));
											}
											catch (const char*) {
												subscriberContainer.fileOutput(std::fstream(SUBS_FILE, std::ios::out));
												break;
											}
											break;
										case 3://Remove sub
											subscriberContainer.remove(itSubscriber);
											std::cout << "Record was deleted" << std::endl;
											subscriberContainer.fileOutput(std::fstream(SUBS_FILE, std::ios::out));
											break;
										case 0://Exit
											break;
										}
										if (n == 3) break;
										printAction();
										n = inputInt("Enter the command: ", 0, 3);
									}
								}
							}
							catch (const char*) {}
							break;
						case 3://Sort subs
							printMenuSortSubscriber();
							n = inputInt("Enter the command: ", 0, 2);
							switch(n) {
							case 1://By library card
								subscriberContainer.sortByLibraryCard();
								consoleOutput(subscriberContainer);
								subscriberContainer.fileOutput(std::fstream(SUBS_FILE, std::ios::out));
								break;
							case 2://By surname
								subscriberContainer.sortBySurname();
								consoleOutput(subscriberContainer);
								subscriberContainer.fileOutput(std::fstream(SUBS_FILE, std::ios::out));
								break;
							case 0://Exit
								break;
							}
						case 0://Exit
							break;
						}
						printSubEdit();
						n = inputInt("Enter the command:", 0, 3);
					}
					break;
				case 4://Edit books
					printBookEdit();
					n = inputInt("Enter the command:", 0, 3);
					while (n != 0) {
						switch (n) {
						case 1://Add book
							try {
								bookContainer.add(inputBook());
								bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
							}
							catch (const char*) {
								break;
							}
							break;
						case 2://Find books
							subcontBook = bookContainer;
							try {
								findBooks(subcontBook, 0);
								if (subcontBook.size() == 0) {
									std::cout << "-------------------------------------" << std::endl;
									std::cout << "There are no such books!" << std::endl;
								}
								else {
									if (subcontBook.size() > 1) {
										bookContainer.find(subcontBook[inputInt("Enter book's position in the list(1.."
											+ std::to_string(subcontBook.size()) + ") or \"exit\" to exit: ", 1, subcontBook.size()) - 1], itBook);
										printBookCaption();
										std::cout << *itBook << std::endl;
									}
									else
										bookContainer.find(subcontBook[0], itBook);
									printAction();
									n = inputInt("Enter the command: ", 0, 3);
									while (n != 0) {
										switch (n) {
										case 1://Print book
											printBookCaption();
											std::cout << *itBook;
											break;
										case 2://Change book
											try {
												inputBookChanged(itBook);
												bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
											}
											catch (const char*) {
												bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
												break;
											}
											break;
										case 3://Remove book
											bookContainer.remove(itBook);
											std::cout << "Record was deleted" << std::endl;
											bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
											break;
										case 0://Exit
											break;
										}
										if (n == 3) break;
										printAction();
										n = inputInt("Enter the command: ", 0, 3);
									}
								}
							}
							catch (const char*) {
							}
							break;
						case 3://Sort books
							printMenuSortBook();
							n = inputInt("Enter the command: ", 0, 8);
							switch (n) {
							case 1://By library card
								bookContainer.sortByLibraryCard();
								consoleOutput(bookContainer);
								bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
								break;
							case 2://By issue date
								bookContainer.sortByIssueDate();
								consoleOutput(bookContainer);
								bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
								break;
							case 3://By return date
								bookContainer.sortByReturnDate();
								consoleOutput(bookContainer);
								bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
								break;
							case 4://By author
								bookContainer.sortByAuthor();
								consoleOutput(bookContainer);
								bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
								break;
							case 5://By title
								bookContainer.sortByTitle();
								consoleOutput(bookContainer);
								bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
								break;
							case 6://By publication year
								bookContainer.sortByPublicationYear();
								consoleOutput(bookContainer);
								bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
								break;
							case 7://By publishing house
								bookContainer.sortByPublishingHouse();
								consoleOutput(bookContainer);
								bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
								break;
							case 8://By price
								bookContainer.sortByPrice();
								consoleOutput(bookContainer);
								bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
								break;
							case 0://Exit
								break;
							}
						case 0://Exit
							break;
						}
						printBookEdit();
						n = inputInt("Enter the command:", 0, 3);
					}
				}
				printLibrarianMenu();
				n = inputInt("Enter the command: ", 0, 4);
			}
			break;
		case 2://Subscriber
			if (subscriberContainer.size() == 0)
				std::cout << "Please, load materials via librarian!" << std::endl;
			else {
				consoleOutput(subscriberContainer);
				try {
					std::cout << "-------------------------------------" << std::endl;
					currentSubscriber = inputInt("Enter your library card or \"exit\" to exit:  ", 1);
					if (!subscriberContainer.findByLibraryCard(currentSubscriber, itSubscriber)) {
						std::cout << "-------------------------------------" << std::endl;
						std::cout << "You are not registered. Please, enter another LC or contact librarian!" << std::endl;
					}
					else {
						printSubscriberMenu();
						n = inputInt("Enter the command: ", 0, 3);
						while (n != 0) {
							switch (n) {
							case 1://Find books
								subcontBook = bookContainer;
								try {
									findSubBooks(subcontBook, 0);
									std::cout << "-------------------------------------" << std::endl;
									if (subcontBook.size() == 0) 
										std::cout << "There are no such books!" << std::endl;
									else {

										if (subcontBook.size() > 1) {
											n = inputInt("Enter book's position in the list(1.."
												+ std::to_string(subcontBook.size()) + ") or \"exit\" to exit: ", 1, subcontBook.size());
											bookContainer.find(subcontBook[n - 1], itBook);
											printBookCaption();
											std::cout << *itBook << std::endl;
										}
										else
											bookContainer.find(subcontBook[0], itBook);
										if (itBook->libraryCard == currentSubscriber) {
											printSubReturn();
											n = inputInt("Enter the command: ", 0, 1);
											switch (n) {
											case 1://Return book
												itBook->libraryCard = 0;
												std::cout << "-------------------------------------" << std::endl;
												std::cout << "You return the book!" << std::endl;
												bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
												break;
											case 0://Exit
												break;
											}
										}
										else
											if (itBook->libraryCard == 0) {
												printSubTake();
												n = inputInt("Enter the command: ", 0, 1);
												switch (n) {
												case 1://Take book
													itBook->libraryCard = currentSubscriber;
													itBook->issueDate = Date(20, 06, 2017);
													itBook->returnDate = Date(20, 07, 2017);
													std::cout << "-------------------------------------" << std::endl;
													std::cout << "You take the book!" << std::endl;
													bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
													break;
												case 0://Exit
													break;
												}
											}
									}
								}
								catch (const char*) {}
								break;
							case 2://Output my books
								subcontBook = bookContainer.findSubSetByLibraryCard(currentSubscriber);
								std::cout << "-------------------------------------" << std::endl;
								if (subcontBook.size() == 0)
									std::cout << "You don't have any books!" << std::endl;
								else {
									std::cout << "Your books:" << std::endl;
									try {
										findSubBooks(subcontBook, 0);
										if (subcontBook.size() == 0)
											std::cout << "There are no such books!" << std::endl;
										else {
											if (subcontBook.size() > 1) {
												n = inputInt("Enter book's position in the list(1.."
													+ std::to_string(subcontBook.size()) + ") or \"exit\" to exit: ", 1, subcontBook.size());
												bookContainer.find(subcontBook[n - 1], itBook);
												printBookCaption();
												std::cout << *itBook << std::endl;
											}
											else
												bookContainer.find(subcontBook[0], itBook);
											printSubReturn();
											n = inputInt("Enter the command: ", 0, 1);
											switch (n) {
											case 1://Return
												itBook->libraryCard = 0;
												std::cout << "You return the book!" << std::endl;
												bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
												break;
											case 0://Exit
												break;
											}
										}
									}
									catch (const char*) {}
								}
								break;
							case 3://Output available books
								subcontBook = bookContainer.findSubSetByLibraryCard(0);
								std::cout << "-------------------------------------" << std::endl;
								if (subcontBook.size() == 0)
									std::cout << "There are no available books! Please, come again later!" << std::endl;
								else {
									try {
										std::cout << "Available books:" << std::endl;
										findSubBooks(subcontBook, 0);
										if (subcontBook.size() == 0)
											std::cout << "There are no such books!" << std::endl;
										else {
											if (subcontBook.size() > 1) {
												n = inputInt("Enter book's position in the list(1.."
													+ std::to_string(subcontBook.size()) + ") or \"exit\" to exit: ", 1, subcontBook.size());
												bookContainer.find(subcontBook[n - 1], itBook);
												printBookCaption();
												std::cout << *itBook << std::endl;
											}
											else
												bookContainer.find(subcontBook[0], itBook);
											printSubTake();
											n = inputInt("Enter the command: ", 0, 1);
											switch (n) {
											case 1://Take
												itBook->libraryCard = currentSubscriber;
												std::cout << "You take the book!" << std::endl;
												bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
												break;
											case 0://Exit
												break;
											}
										}
									}
									catch(const char*) {}
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
		case 0://Exit(main)
			subscriberContainer.fileOutput(std::fstream(SUBS_FILE, std::ios::out));
			bookContainer.fileOutput(std::fstream(BOOKS_FILE, std::ios::out));
			return 0;
		}
	}
}