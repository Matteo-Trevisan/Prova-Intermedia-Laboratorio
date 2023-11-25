#include "../include/Book.h"

// costruttore di default
Book::Book(const std::string &author_name, const std::string &author_surname, const std::string &title,
		   const std::string &ISBN, const Date &date, const State &state) :
		author_name(author_name),
		author_surname(author_surname),
		title(title),
		ISBN((ISBN.length() == 13) ? ISBN : throw std::invalid_argument(
				"Invalid ISBN, provide a 13 character long string")),
		copyright_date(date),
		state(state) {

}

//funzioni membro set

// set ISBN con controllo: la lunghezza di ISBN deve essere uguale a 13
void Book::set_ISBN(const std::string &new_ISBN) {
	(ISBN.length() == 13) ? ISBN : throw std::invalid_argument("Invalid ISBN, provide a 13 character long string");
	this->ISBN = new_ISBN;
}

void Book::set_title(const std::string &new_title) {
	this->title = new_title;
}

void Book::set_author_name(const std::string &new_author_name) {
	this->author_name = new_author_name;
}

void Book::set_author_surname(const std::string &new_author_surname) {
	this->author_surname = new_author_surname;
}

void Book::set_copyright_date(const Date &new_date) {
	this->copyright_date = new_date;
}

void Book::set_state(const State &new_state) {
	this->state = new_state;
}

// overloading dell'operatore =
Book &Book::operator=(const Book &b) = default;

// overloading dell'operatore == come helper function
bool operator==(const Book &b1, const Book &b2) {
	return b1.get_ISBN() == b2.get_ISBN();
}

// overloading dell'operatore == come helper function
std::ostream &operator<<(std::ostream &os, const Book &b) {
	os << "Author: " << b.get_author_name() << " " << b.get_author_surname()
	   << ", Title: \"" << b.get_title()
	   << "\", ISBN: " << b.get_ISBN() << ", Copyright: ";
	if (b.get_copyright_date().has_been_set()) {    // controllo copyright_date non impostata
		os << b.get_copyright_date();
	} else {
		os << "not set";
	}
	os << ", State: " << (b.get_state() == State::available ? "Available" : "On Loan");
	return os;
}