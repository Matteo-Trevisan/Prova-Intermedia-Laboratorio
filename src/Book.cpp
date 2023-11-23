#include <utility>

#include "../include/Book.h"

Book::Book(std::string  author_name, std::string  author_surname, std::string  title, const std::string& ISBN, const Date& date,const State& state) :
		author_name(std::move(author_name)),
		author_surname(std::move(author_surname)),
		title(std::move(title)),
		ISBN((ISBN.length()==13) ? ISBN : throw std::invalid_argument("Invalid ISBN, provide a 13 character long string")),
		date(date),
		state(state) {

}

void Book::set_ISBN(const std::string& new_ISBN) {
	(ISBN.length()==13) ? ISBN : throw std::invalid_argument("Invalid ISBN, provide a 13 character long string");
    this -> ISBN = new_ISBN;
}

void Book::set_title(const std::string& new_title) {
    this -> title = new_title;
}

void Book::set_author_name(const std::string& new_author_name) {
    this -> author_name = new_author_name;
}

void Book::set_author_surname(const std::string& new_author_surname) {
    this -> author_surname = new_author_surname;
}

void Book::set_date(const Date& new_date) {
    this -> date = new_date;
}

void Book::set_state(const State& new_state) {
    this -> state = new_state;
}

Book& Book::operator=(const Book& b) = default;


bool operator==(const Book& b1, const Book& b2) {
	return b1.get_ISBN() == b2.get_ISBN();
}

std::ostream &operator<<(std::ostream &os, const Book &b) {
	os << "Author: " << b.get_author_name() << " "  << b.get_author_surname()
	<< ", Title: \""  << b.get_title()
	<< "\", ISBN: " << b.get_ISBN() << ", Copyright: ";
	if (b.get_date().has_been_set()) {
		os << b.get_date();
	} else {
		os << "not set";
	}
	os << ", State: " << (b.get_state() == State::available ? "Available" : "On Loan");
    return os;
}