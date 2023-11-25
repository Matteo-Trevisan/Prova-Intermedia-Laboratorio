#ifndef PROVA_INTERMEDIA_BOOKSHELF_H
#define PROVA_INTERMEDIA_BOOKSHELF_H

#include "iostream"
#include "../include/Book.h"

class BookShelf {

// membri classe BookShelf
private:
	static const int start_buff_capacity = 1;   // dimensione iniziale buffer
	int length;     // dimensione logica
	int buff_capacity;  // dimensione fisica
	Book *buff;     // puntatore all'array

public:

	// costruttori e distruttore
	BookShelf();    // costruttore di default
	explicit BookShelf(int size,
					   const Book &val = Book());    // costruttore di lunghezza length che contiene valori value
	BookShelf(std::initializer_list<Book> il);  // costruttore con initializer_list
	BookShelf(const BookShelf &arg);   // costruttore di copia
	BookShelf(BookShelf &&arg) noexcept;   // costruttori di spostamento
	~BookShelf();   // distruttore

	// overloading degli operatori
	BookShelf &operator=(const BookShelf &arg); // overloading assignment operator
	BookShelf &operator=(BookShelf &&arg) noexcept;     // overloading move assignment operator
	Book &operator[](int i);    // overloading []
	const Book &operator[](int i) const;    // overloading [] (const)

	Book &at(int i);    // restituisce il valore all'indice i con controlli
	const Book &at(int i) const;    // restituisce il valore all'indice i con controlli (const)

	void clear();   // svuota la BookShelf
	int size() const;   // restituisce la dimensione logica
	bool empty() const;     // controlla se la BookShelf è vuota
	int capacity() const;   // restituisce la dimensione fisica
	void push_back(Book &b);    // inserimento oggetto Book in BookShelf
	void pop_back();    // diminuzione dimensione logica
	void reserve(int n);       // ridimensionamento nella BookShelf senza cambiare la dimensione logica
	void resize(int size);     // ridimensionamento nella BookShelf cambiando la dimensione logica
	void shrink_to_fit();       // ridimensionamento della dimensione fisica

};

std::ostream &operator<<(std::ostream &os, const BookShelf &b); // overloading operatore <<

#endif //PROVA_INTERMEDIA_BOOKSHELF_H
