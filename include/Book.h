#ifndef PROVA_INTERMEDIA_BOOK_H
#define PROVA_INTERMEDIA_BOOK_H

#include <iostream>
#include "Date.h"

enum class State {
    available = 0, on_loan = 1
};

class Book {
public:
    explicit  Book(
		std::string   author_name = "Unknown",
		std::string  author_surname = "Unknown",
		std::string  title = "Unknown",
		const std::string& ISBN = "*************",
		const Date& date = Date(),
		const State& state = State::available
    );

	Book& operator=(const Book& b);

    void set_ISBN(const std::string& new_ISBN);
    void set_title(const std::string& new_title);
    void set_author_name(const std::string& new_author_name);
    void set_author_surname(const std::string& new_author_surname);
    void set_date(const Date& new_date);
    void set_state(const State& new_state);

    std::string get_ISBN() const { return ISBN; };
    std::string get_title() const { return title; };
    std::string get_author_name() const { return author_name; };
    std::string get_author_surname() const { return author_surname; };
    Date get_date() const { return date; };
    State get_state() const { return state; };


private:
    std::string ISBN;
    std::string title;
    std::string author_name;
    std::string author_surname;
    Date date;
    State state;
};

std::ostream &operator<<(std::ostream &os, const Book &b);

#endif //PROVA_INTERMEDIA_BOOK_H