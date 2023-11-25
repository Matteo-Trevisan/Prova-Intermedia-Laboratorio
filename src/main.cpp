#include <iostream>
#include "../include/Book.h"
#include "../include/BookShelf.h"

void printBookShelf(const BookShelf& shelf);

int main() {

    Date date1 {2023, Month::March, 30};
    Date date2 {1943, Month::December, 23};
    Date date3 {2020, Month::April, 13};
	std::string nome = "Fabio";

	Book b1 {nome, "Rossi", "La storia infinita", "456-789-234-6", Date(2012,Month::August, 13), State::on_loan};
	Book b2 {"Daniele", "Bianchi", "Dati e Algoritmi", "345-678-990-9", date1};
	Book mybook("David", "Foster Wallace", "Una cosa divertente che	non farò mai più", "887-521-837-4");


	BookShelf shelf;
	std::cout << shelf << std::endl;
	mybook.set_state(State::available);
	shelf.push_back(b1);
	shelf.push_back(b2);
	BookShelf shelf2 {mybook};
	BookShelf shelf3 {shelf};

	printBookShelf(shelf);

	shelf.reserve(5);

	std::cout << std::endl;
	printBookShelf(shelf);

	shelf.push_back(b1);
	std::cout << std::endl;
	printBookShelf(shelf);


	std::cout << std::endl;
	printBookShelf(shelf2);

	shelf2.resize(5);
	shelf2.pop_back();

	std::cout << std::endl;
	printBookShelf(shelf2);

	return 0;
}

void printBookShelf(const BookShelf& shelf) {
	std::cout << "BookShelf (size: " << shelf.size() << ", Capacity: " << shelf.capacity() << ")"
			  << std::endl<< "Books: " << std::endl << shelf;
}
