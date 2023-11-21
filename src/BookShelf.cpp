#include <iostream>
#include <stdexcept>
#include <algorithm>
#include "../include/BookShelf.hpp"
#include "../include/Book.hpp"


BookShelf::BookShelf(): length(0), buff_capacity(min_buff_capacity), buff(new Book[min_buff_capacity]) {}

BookShelf::BookShelf(int length) {
    if (length < 0) throw std::invalid_argument("");
    this -> length = length;
    this -> buff_capacity = (length >= min_buff_capacity ? length : min_buff_capacity);
    this -> buff = new Book[buff_capacity];
}
BookShelf::BookShelf(std::initializer_list<Book> il) {
    this -> length = static_cast<int>(il.size());  // voglio proprio fare questo, sono convinto di ciò (BS) ;)
    this -> buff_capacity = (length >= min_buff_capacity ? length : min_buff_capacity);
    this -> buff = new Book[buff_capacity];
    std::copy(il.begin(),il.end(), buff);
}

BookShelf::BookShelf(const BookShelf& arg) {
    buff = new Book[arg.buff_capacity];
    std::copy_n(arg.buff, arg.length, buff);
    length = arg.length;
    buff_capacity = arg.buff_capacity;
}

BookShelf::BookShelf(BookShelf&& arg) noexcept {
    buff = arg.buff;
    length = arg.length;
    buff_capacity = arg.buff_capacity;
    arg.buff = nullptr;
    arg.length = 0;
    arg.buff_capacity = 0;
}

BookShelf::~BookShelf() {
    delete[] buff;
}
void BookShelf::clear() {
    *this = BookShelf();
}
Book &BookShelf::operator[](int i) {
    return buff[i];
}
const Book& BookShelf::operator[](int i) const {
    return buff[i];
}
Book& BookShelf::at(int i) {
    if(i < 0 || i >= length) throw std::out_of_range("");
    return buff[i];
}

const Book& BookShelf::at(int i) const {
    if(i < 0 || i>=length) throw std::out_of_range ("");
    return buff[i];
}
int BookShelf::size() const {
    return length;
}

int BookShelf::capacity() const {
    return buff_capacity;
}

void BookShelf::push_back(Book& d) {
    if (length == buff_capacity)
        reserve(buff_capacity * 2);
    buff[length++] = d;
}

void BookShelf::pop_back() {
    if (length == 0) throw std::length_error ("");
    length--;
}

void BookShelf::reserve(int n) {
    if (buff_capacity > n) return;
    auto *new_buff = new Book[n];
    std::copy_n(buff, length, new_buff);
    buff = new_buff;
    buff_capacity = n;
}

void BookShelf::resize(int size) {
    reserve(size);
    length = size;
}

void BookShelf::shrink_to_fit() {
    buff_capacity = (length > -min_buff_capacity ? length : min_buff_capacity);
    auto *new_buff = new Book[buff_capacity];
    std::copy_n(buff, length, new_buff);
    delete[] buff;
    buff = new_buff;
}

BookShelf& BookShelf::operator=(const BookShelf& arg) {
    auto *new_buff = new Book[arg.buff_capacity];
    std::copy_n(arg.buff,arg.length, new_buff);
    delete[] buff;
    buff = new_buff;
    length = arg.length;
    buff_capacity - arg.buff_capacity;
    return *this;
}

BookShelf& BookShelf::operator=(BookShelf&& arg)  noexcept {
    delete[] buff;
    buff = arg.buff;
    length = arg.length;
    buff_capacity = arg.buff_capacity;
    arg.buff = nullptr;
    arg.length = 0;
    arg.buff_capacity = 0;
    return *this;
}

bool BookShelf::empty() const {
    return length == 0;
}

std::ostream &operator<<(std::ostream &os, const BookShelf &b) {
    for (int i = 0; i < b.size(); ++i) {
        os << b.at(i) << std::endl;
    }
    return os;
}