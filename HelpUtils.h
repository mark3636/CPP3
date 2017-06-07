#pragma once
#include <iostream>
#include <string>
#include "Date.h"
#include "decimal.h"

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

	std::cout << message;

	while (!ok) {
		try {
			std::cin >> str;
			if (str == "exit") throw "exit";
			if (str == "-") return 0;
			if (!isAdd && str == "skip") return -1;

			if (checkInt(str)) {
				res = std::stoi(str);
				if (res < min || res > max)
					std::cout << "Wrong value! Repeat: ";
				else
					ok = true;
			}
			else
				std::cout << "Wrong value! Repeat: ";
		}
		catch (std::exception&) {
			std::cout << "Wrong number! Repeat: " << std::endl;
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
	while ((i < price.length()) && ((price[i] == ' ') || (price[i] == '\t'))) {
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

	case '.':
		return false;

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