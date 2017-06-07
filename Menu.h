#pragma once
#include <string>
#include <iostream>
#include <fstream>

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
	std::cout << " 2)Output my books" << std::endl;
	std::cout << " 3)Output available books" << std::endl;
	std::cout << " 4)Take book" << std::endl;
	std::cout << " 5)Return book" << std::endl;
	std::cout << " 0)Exit" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

void printLibrarianMenu() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)Output subscribers" << std::endl;
	std::cout << " 2)Output books" << std::endl;
	std::cout << " 3)Edit subscribers" << std::endl;
	std::cout << " 4)Edit books" << std::endl;
	std::cout << " 0)Exit" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

void printSubEdit() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)Add subscriber" << std::endl;
	std::cout << " 2)Find subscribers" << std::endl;
	std::cout << " 3)Sort subscribers" << std::endl;
	std::cout << " 0)Exit" << std::endl;
	std::cout << "-------------------------------------" << std::endl;
}

void printBookEdit() {
	std::cout << "-------------------------------------" << std::endl;
	std::cout << " 1)Add book" << std::endl;
	std::cout << " 2)Find books" << std::endl;
	std::cout << " 3)Sort books" << std::endl;
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
	std::cout << "-------------------------------------" << std::endl;
	std::cout << "LC\tIssue Date\tReturn Date\tAuthor\t\tTitle\tPYear\tPHouse\tPrice" << std::endl;
}

void printSubscriberCaption() {
	std::cout << "-------------------------------------" << std::endl;
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