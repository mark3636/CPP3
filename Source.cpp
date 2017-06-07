﻿//4.Библиотека
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


	P operator[](int index) {
		return vect[index];
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

SubscriberContainer findSubscribers(SubscriberContainer &cont, int level) {
	int n;
	std::string str;

	if (cont.size() > 0)
		consoleOutput(cont);

	if (cont.size() <= 1 || level == MAX_LEVEL)
		return cont;

	printMenuFindParamSubscriber();
	n = inputInt("Enter rhe command: ", 0, 2);
	switch (n) {
	case 1://Library card
		cont = cont.findSubSetByLibraryCard(inputInt("Enter library card: "));
		break;
	case 2://Surname
		std::cout << "Enter surname: ";
		std::cin >> str;
		cont = cont.findSubSetBySurname(str);
		
	case 0://Exit
		consoleOutput(cont);
		return cont;
	}

	return findSubscribers(cont, level + 1);
}

BookContainer findBooks(BookContainer &cont, int level) {
	int n;
	std::string str;

	if(cont.size() > 0)
		consoleOutput(cont);

	if (cont.size() <= 1 || level == MAX_LEVEL)
		return cont;

	printMenuFindParamBook();
	n = inputInt("Enter the command: ", 0, 5);
	switch (n) {
	case 1://Library card
		cont = cont.findSubSetByLibraryCard(inputInt("Enter library card: "));
		break;
	case 2://Author
		std::cout << "Enter author: ";
		std::cin >> str;
		cont = cont.findSubSetByAuthor(str);
		break;
	case 3://Title
		std::cout << "Enter title: ";
		std::cin >> str;
		cont = cont.findSubSetByTitle(str);
		break;
	case 4://Publishing house
		std::cout << "Enter publishing house: ";
		std::cin >> str;
		cont = cont.findSubSetByPublishingHouse(str);
		break;
	case 5://Return date
		cont = cont.findSubSetByReturnDate(inputDate("Enter return date: "));
		break;
	case 0://Exit
		consoleOutput(cont);
		return cont;
	}

	return findBooks(cont, level + 1);
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
	std::string FName;
	std::vector<Book>::iterator itBook;
	std::vector<Subscriber>::iterator itSubscriber;

	subscriberContainer.fileInput(std::fstream("subs.txt", std::ios::in));
	bookContainer.fileInput(std::fstream("books.txt", std::ios::in));

	while (true) {
		printModeMenu();
		n = inputInt("Enter the command: ", 0, 2);
		switch (n) {
		case 1:
			printLibrarianMenu();
			n = inputInt("Enter the command: ", 0, 4);
			while (n != 0) {
				switch (n) {
				case 1://OUTPUT SUB
					printMenuConsoleFile();
					n = inputInt("Enter the command: ", 0, 2);
					switch (n) {
					case 1://To console
						consoleOutput(subscriberContainer);
						break;
					case 2://To file
						FName = output_file_name();
						subscriberContainer.fileOutput(std::fstream(FName, std::ios::out));
						break;
					case 0://Exit
						break;
					}
					break;
				case 2://OUTPUT BOOK
					printMenuConsoleFile();
					n = inputInt("Enter the command: ", 0, 2);
					switch (n) {
					case 1://To console
						consoleOutput(bookContainer);
						break;
					case 2://To file
						FName = output_file_name();
						bookContainer.fileOutput(std::fstream(FName, std::ios::out));
						break;
					case 0://Exit
						break;
					}
					break;
				case 3://EDIT SUBS
					printSubEdit();
					n = inputInt("Enter the command: ", 0, 3);
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
						case 2://subset
							subcontSubscriber = subscriberContainer;
							subcontSubscriber = findSubscribers(subcontSubscriber, 0);
							if (subcontSubscriber.size() == 0) {
								std::cout << "-------------------------------------" << std::endl;
								std::cout << "There are no such subscribers!" << std::endl;
							}
							else {
								if (subcontSubscriber.size() > 1) {
									subscriberContainer.find(subcontSubscriber[inputInt("Enter subscriber's position in the list(1.."
										+ std::to_string(subcontSubscriber.size()) + "): ", 1, subcontSubscriber.size()) - 1], itSubscriber);
								}
								else
									subscriberContainer.find(subcontSubscriber[0], itSubscriber);
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
							break;
						case 3:
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
						n = inputInt("Enter the command:", 0, 3);
					}
					break;
				case 4://Edit books
					printBookEdit();
					n = inputInt("Enter the command:", 0, 3);
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
						case 2://Find books
							subcontBook = bookContainer;
							subcontBook = findBooks(subcontBook, 0);
							if (subcontBook.size() == 0) {
								std::cout << "-------------------------------------" << std::endl;
								std::cout << "There are no such books!" << std::endl;
							}
							else {
								if (subcontBook.size() > 1) {
									bookContainer.find(subcontBook[inputInt("Enter book's position in the list(1.."
										+ std::to_string(subcontBook.size()) + "): ", 1, subcontBook.size()) - 1], itBook);
								}
								else
									bookContainer.find(subcontBook[0], itBook);
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
							break;
						case 3:
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
						n = inputInt("Enter the command:", 0, 3);
					}
				}
				printLibrarianMenu();
				n = inputInt("Enter the command: ", 0, 4);
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
						n = inputInt("Enter the command: ", 0, 5);
						while (n != 0) {
							switch (n) {
							case 1:								
								printMenuFindParamBook();
								n = inputInt("Enter the command: ", 0, 5);
								switch (n) {
								case 0:
									break;
								case 1://Library card
									found = bookContainer.findByLibraryCard(inputInt("Enter library card: "), itBook);
									break;
								case 2://Author
									std::cout << "Enter author: ";
									std::cin >> str;
									found = bookContainer.findByAuthor(str, itBook);
									break;
								case 3://Title
									std::cout << "Enter title: ";
									std::cin >> str;
									found = bookContainer.findByTitle(str, itBook);
									break;
								case 4://Publishing house
									std::cout << "Enter publishing house: ";
									std::cin >> str;
									found = bookContainer.findByPublishingHouse(str, itBook);
									break;
								case 5://Return date
									found = bookContainer.findByReturnDate(inputDate("Enter return date: "), itBook);
									break;
								}
								if (n != 0) {
									if (found) {
										printBookCaption();
										std::cout << *itBook;		
									}
									else
										std::cout << "Record not found \n";
								}
							break;
							case 2://Output my books
								subcontBook = bookContainer.findSubSetByLibraryCard(currentSubscriber);
								if (subcontBook.size() == 0)
									std::cout << "You don't have any books!" << std::endl;
								else {
									std::cout << "-------------------------------------" << std::endl;
									std::cout << "Your books:" << std::endl;
									consoleOutput(subcontBook);
								}
								break;
							case 3:
								subcontBook = bookContainer.findSubSetByLibraryCard(0);
								if (subcontBook.size() == 0)
									std::cout << "There are no available books! Please, come again later!" << std::endl;
								else {
									std::cout << "-------------------------------------" << std::endl;
									std::cout << "Available books:" << std::endl;
									consoleOutput(subcontBook);
								}
								break;
							case 4:
								subcontBook = bookContainer.findSubSetByLibraryCard(0);
								if (subcontBook.size() == 0)
									std::cout << "There are no available books! Please, come again later!" << std::endl;
								else {
									std::cout << "-------------------------------------" << std::endl;
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
							case 5:
								subcontBook = bookContainer.findSubSetByLibraryCard(currentSubscriber);
								if (subcontBook.size() == 0)
									std::cout << "You don't have any books!" << std::endl;
								else {
									std::cout << "-------------------------------------" << std::endl;
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
							n = inputInt("Enter the command: ", 0, 5);
						}
					}
				}

				catch (const char* str) {
					break;
				}
			}
			break;
		case 0:
			subscriberContainer.fileOutput(std::fstream("subs.txt", std::ios::out));
			bookContainer.fileOutput(std::fstream("books.txt", std::ios::out));
			return 0;
		}
	}
}