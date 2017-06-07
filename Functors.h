#pragma once

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