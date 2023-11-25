#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "../include/BookShelf.h"

// costruttore di default
BookShelf::BookShelf() : length(0), buff_capacity(start_buff_capacity), buff(new Book[start_buff_capacity]) {}

// costruttore di lunghezza length che contiene valori value
BookShelf::BookShelf(int length, const Book &val) {
	if (length < 0) throw std::invalid_argument("Bookshelf length not valid, provide a non-negative number");
	this->length = length;
	this->buff_capacity = (start_buff_capacity < length ? length : start_buff_capacity);
	this->buff = new Book[buff_capacity];
	std::fill_n(buff, length, val);
}

// costruttore con initializer_list
BookShelf::BookShelf(std::initializer_list<Book> il) {
	this->length = static_cast<int>(il.size());
	this->buff_capacity = length;
	this->buff = new Book[buff_capacity];
	std::copy(il.begin(), il.end(), buff);
}

// costruttore di copia
BookShelf::BookShelf(const BookShelf &arg) {
	buff = new Book[arg.buff_capacity];
	std::copy_n(arg.buff, arg.length, buff);
	length = arg.length;
	buff_capacity = arg.buff_capacity;
}

// costruttore di spostamento
BookShelf::BookShelf(BookShelf &&arg) noexcept {
	buff = arg.buff;
	length = arg.length;
	buff_capacity = arg.buff_capacity;
	arg.buff = nullptr;
	arg.length = 0;
	arg.buff_capacity = 0;
}

// distruttore
BookShelf::~BookShelf() {
	delete[] buff;
}

// svuota la BookShelf con costruttore di default
void BookShelf::clear() {
	*this = BookShelf();
}

// overloading degli operatori
std::ostream &operator<<(std::ostream &os, const BookShelf &b) {    // overloading operatore <<
	for (int i = 0; i < b.size(); ++i) {
		os << i + 1 << ":{" << b.at(i) << "}" << std::endl;
	}
	return os;
}

BookShelf &BookShelf::operator=(const BookShelf &arg) {     // overloading assignment operator
	if (this == &arg) {
		return *this;
	}
	auto *new_buff = new Book[arg.buff_capacity];
	std::copy_n(arg.buff, arg.length, new_buff);
	delete[] buff;
	buff = new_buff;
	length = arg.length;
	buff_capacity = arg.buff_capacity;
	return *this;
}

BookShelf &BookShelf::operator=(BookShelf &&arg) noexcept {     // overloading move assignment operator
	delete[] buff;
	buff = arg.buff;
	length = arg.length;
	buff_capacity = arg.buff_capacity;
	arg.buff = nullptr;
	arg.length = 0;
	arg.buff_capacity = 0;
	return *this;
}

Book &BookShelf::operator[](int i) {    // overloading operatore []
	return buff[i];
}

const Book &BookShelf::operator[](int i) const {    // overloading operatore [] (const)
	return buff[i];
}

Book &BookShelf::at(int i) {    // restituisce il valore all'indice i con controlli
	if (i < 0 || i >= length) throw std::out_of_range("requested index out of range");
	return buff[i];
}

const Book &BookShelf::at(int i) const {    // restituisce il valore all'indice i con controlli (const)
	if (i < 0 || i >= length) throw std::out_of_range("requested index out of range");
	return buff[i];
}

bool BookShelf::empty() const {     // controlla se la BookShelf è vuota
	return length == 0;
}

int BookShelf::size() const {   // restituisce la dimensione logica
	return length;
}

int BookShelf::capacity() const {   // restituisce la dimensione fisica
	return buff_capacity;
}

void BookShelf::push_back(Book &d) {    // inserimento oggetto Book in BookShelf
	if (length == buff_capacity)
		reserve(buff_capacity * 2);
	buff[length++] = d;
}

void BookShelf::pop_back() {    // diminuzione dimensione logica
	if (length == 0) throw std::length_error("Bookshelf already empty, no element to pop");
	length--;
}

void BookShelf::reserve(int n) {    // ridimensionamento nella BookShelf senza cambiare la dimensione logica
	if (buff_capacity > n) return;
	auto *new_buff = new Book[n];
	std::copy_n(buff, length, new_buff);
	buff = new_buff;
	buff_capacity = n;
}

void BookShelf::resize(int size) {  // ridimensionamento nella BookShelf cambiando la dimensione logica
	reserve(size);
	length = size;
}

void BookShelf::shrink_to_fit() {   // ridimensionamento della dimensione fisica
	buff_capacity = (length == 0 ? 1 : length);
	auto *new_buff = new Book[buff_capacity];
	std::copy_n(buff, buff_capacity, new_buff);
	delete[] buff;
	buff = new_buff;
}



