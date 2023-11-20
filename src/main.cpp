#include <iostream>
#include "../include/Book.hpp"
#include "../include/BookShelf.hpp"
#include "../include/Date.hpp"

int main() {
	std::cout << "Hello, World!" << std::endl;
	Date date {2023, Month(12), 30};
	std::cout << date << std::endl;
	date.add_day(5);
	std::cout << date << std::endl;
	return 0;
}
