#include <iostream>
#include "../include/Book.hpp"
#include "../include/BookShelf.hpp"
#include "../include/Date.hpp"

void printBookShelf(const BookShelf& shelf) {
	std::cout << "Shelf: (size: " << shelf.size() << ", Capacity: " << shelf.capacity() << ")"
			  << std::endl<< "Books: " << std::endl << shelf;
}

int main() {

    Date date1 {2023, March, 30};
    Date date2 {1943, December, 23};
    Date date3 {2020, April, 13};

	Book b1 {"Fabio", "Rossi", "La storia infinita", "456-789-234-6", Date(2012,Month::August, 13), State::on_loan};
	Book b2 {"Daniele", "Bianchi", "Dati e Algoritmi", "345-678-990-9", date1};
	Book mybook("David", "Foster Wallace", "Una cosa divertente che	non farò mai più", "887-521-837-4");
	
	BookShelf shelf(10);
	shelf.push_back(b1);
	shelf.push_back(b2);
	BookShelf shelf2 {mybook};
	BookShelf shelf3 {shelf};
	Book b4{b2};

	printBookShelf(shelf);

	shelf.shrink_to_fit();

	std::cout << std::endl;
	printBookShelf(shelf);


	std::cout << std::endl;
	printBookShelf(shelf2);

	shelf2.resize(5);

	std::cout << std::endl;
	printBookShelf(shelf2);


	return 0;
}
