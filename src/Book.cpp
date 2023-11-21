#include <utility>

#include "../include/Book.hpp"

Book::Book(std::string&& author_name, std::string&& author_surname, std::string&& title, std::string&& ISBN, const Date& date, State state) :
		author_name(author_name), author_surname(author_surname), title(title), ISBN(ISBN),  date(date), state(state) {
    		(ISBN.length()==13) ? ISBN : throw std::invalid_argument("Invalid ISBN");
}

void Book::set_ISBN(std::string&& new_ISBN) {
    this -> ISBN = new_ISBN;
}

void Book::set_title(std::string&& new_title) {
    this -> title = new_title;
}

void Book::set_author_name(std::string&& new_author_name) {
    this -> author_name = std::move(new_author_name);
}

void Book::set_author_surname(std::string&& new_author_surname) {
    this -> author_surname = new_author_surname;
}

void Book::set_date(const Date& new_date) {
    this -> date = new_date;
}

void Book::set_state(State new_state) {
    this -> state = new_state;
}

Book& Book::operator=(const Book& b) = default;

Book& Book::operator=(Book&& b) noexcept {
    ISBN = b.ISBN;
    title = b.title;
    author_name = b.author_name;
    author_surname = b.author_surname;
    date = b.date;
    state = b.state;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Book &b) {
    return os << b.get_ISBN() << " " << b.get_title();
}