#ifndef PROVA_INTERMEDIA_BOOK_H
#define PROVA_INTERMEDIA_BOOK_H

#include <iostream>
#include "Date.h"

// enumeratore State per definire se il libro è disponibile o in prestito
enum State {
	available = 0, on_loan = 1
};

class Book {

// membri classe Book
private:
	std::string ISBN;   // codice ISBN
	std::string title;  // titolo libro
	std::string author_name;    // nome autore
	std::string author_surname; // congnome autore
	Date copyright_date;  // data di copyright
	State state;    // stato libro: disponibile o in prestito

public:

	// costruttore esplicito con parametri in ingresso (default in caso di non inserimento)
	explicit Book(
			const std::string &author_name = "Unknown",
			const std::string &author_surname = "Unknown",
			const std::string &title = "Unknown",
			const std::string &ISBN = "000-000-000-0",
			const Date &date = Date(),
			const State &state = State::available
	);

	// funzioni membro set
	void set_ISBN(const std::string &new_ISBN);

	void set_title(const std::string &new_title);

	void set_author_name(const std::string &new_author_name);

	void set_author_surname(const std::string &new_author_surname);

	void set_copyright_date(const Date &new_date);

	void set_state(const State &new_state);

	// funzioni membro get
	std::string get_ISBN() const { return ISBN; };

	std::string get_title() const { return title; };

	std::string get_author_name() const { return author_name; };

	std::string get_author_surname() const { return author_surname; };

	const Date &get_copyright_date() const { return copyright_date; };

	State get_state() const { return state; };

	// overloading dell'operatore =
	Book &operator=(const Book &b);

};

bool operator==(const Book &b1, const Book &b2);    // overloading dell'operatore == come helper function

std::ostream &operator<<(std::ostream &os, const Book &b);  // overloading dell'operatore << come helper function

#endif //PROVA_INTERMEDIA_BOOK_H