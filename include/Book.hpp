#ifndef PROVA_INTERMEDIA_BOOK_HPP
#define PROVA_INTERMEDIA_BOOK_HPP

#include "iostream"
#include "Date.hpp"

enum State {
    available = 0, on_loan = 1
};

class Book {
public:
    explicit  Book(std::string&& author_name = "", std::string&& author_surname = "", std::string&& title = "", std::string&& ISBN = "*************",const Date& date = Date(), State state = State::available);
    Book& operator=(const Book& b);
    Book& operator=(Book&& b)  noexcept;

    void set_ISBN(std::string&& new_ISBN);
    void set_title(std::string&& new_title);
    void set_author_name(std::string&& new_author_name);
    void set_author_surname(std::string&& new_author_surname);
    void set_date(const Date& new_date);
    void set_state(State new_state);

    std::string get_ISBN() const { return ISBN; };
    std::string get_title() const { return title; };
    std::string get_author_name() const { return author_name; };
    std::string get_author_surname() const { return author_surname; };
    Date get_date() { return date; };
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

#endif //PROVA_INTERMEDIA_BOOK_HPP