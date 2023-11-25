#include <iostream>
#include "../include/Book.h"
#include "../include/BookShelf.h"

void printBookShelf(const BookShelf& shelf, const std::string& shelfName);
void get_shelfDetails(const BookShelf& shelf);

int main() {

    Date dateTest {1980, Month::November, 25};
    std::string name = "Umberto";
    std::string surname = "Eco";
    std::string title = "Il nome della rosa";
    std::string ISBN = "456-234-789-6";
    State state = State::on_loan;


    //Test costruttori
    Book book1 {name, surname, title, ISBN, dateTest, state};
    Book book2 {"Joanne", "Rowling", "Harry Potter and the chamber of secrets", "123-456-789-1", Date(2014, Month::January, 1), State::available};
    Book book3 {"Dante", "Alighieri", "Divina Commedia", "789-321-111-1", Date(1321, Month::March, 1), State::on_loan};
    Book book4 {"Dante", "Alighieri", "Divina Commedia", "789-321-111-1", Date(1321, Month::March, 1), State::on_loan};
    Book book5 {"Dante", "Alighieri", "Divina Commedia"};
    Book book6("David" , "Foster Wallace", "Una cosa divertente che non farò mai più", "887-521-837-4");

    //Test inserimento libri in una BookShelf
    BookShelf shelf1;
    shelf1.push_back(book1);
    shelf1.push_back(book2);
    std::cout << std::endl;
    printBookShelf(shelf1, "Shelf1");
    std::cout << std::endl;

    std::cout << "#############################   MODIFICHE VALORI LIBRI   #############################" << std::endl << std::endl;

    //Modifiche dei valori di ogni libro
    BookShelf shelf3;
    shelf3.push_back(book6);
    printBookShelf(shelf3, "Shelf3");
    book6.set_author_name("Andrea");
    book6.set_author_surname("Baiocco");
    book6.set_title("C'era una volta...");
    book6.set_ISBN("999-888-777-6");
    book6.set_copyright_date(Date(2023, Month::November, 25));
    book6.set_state(State::on_loan);
    shelf3.push_back(book6);
    printBookShelf(shelf3, "Shelf3");
    shelf3.at(0).set_title("Nuovo");
    printBookShelf(shelf3, "Shelf3");

    std::cout << "############################  UTILIZZO METODI GET  ##################################" << std::endl << std::endl;

    std::cout << "Book6 details:" << std::endl;
    std::cout << book6.get_author_name() << " " << book6.get_author_surname() << " " << book6.get_title() << " " << book6.get_ISBN() << " " << book6.get_copyright_date() << " " << book6.get_state() << std::endl << std::endl;


    std::cout << "########################     RIMOZIONE E SVUOTAMENTO    ##################################" << std::endl << std::endl;

    shelf3.clear();
    shelf3.empty()  ? std::cout << "SHELF EMPTY" << std::endl : std::cout << "SHELF NOT EMPTY" << std::endl << std::endl;
    printBookShelf(shelf3, "Shelf3");
    shelf3.push_back(book1);
    shelf3.push_back(book2);
    shelf3.push_back(book3);
    printBookShelf(shelf3, "Shelf3");
    shelf3.pop_back();
    printBookShelf(shelf3, "Shelf3");


    std::cout << "#############################   STAMPA CON CICLI   ###################################" << std::endl << std::endl;

    //Utilizzo costruttore di copie e stampa con accesso attraverso []
    BookShelf shelf4(shelf1);
    for(int i=0; i<shelf4.size(); i++){
        std::cout<<"\n"<<shelf1[i];
    }
    std::cout << std::endl;

    //Utilizzo costruttore con initializer list e stampa con accesso mediante at()
    BookShelf shelf5{book6, book1, book3};
    for(int i=0; i<shelf5.size(); i++){
        std::cout<<"\n"<<shelf5.at(i);
    }
    std::cout << std::endl;
    std::cout << std::endl;

    //Visualizzazione modifiche sulla memoria di una BookShelf
    get_shelfDetails(shelf4);
    std::cout << "resize(6): " << std::endl;
    shelf4.resize(6);
    get_shelfDetails(shelf4);
    std::cout << "reserve(10): " << std::endl;
    shelf4.reserve(10);
    get_shelfDetails(shelf4);
    std::cout << "shrink_to_fit(): " << std::endl;
    shelf4.shrink_to_fit();
    get_shelfDetails(shelf4);


	return 0;
}

void get_shelfDetails(const BookShelf& shelf){
    std::cout << " Size: " << shelf.size() << std::endl << "Capacity: " << shelf.capacity() << std::endl;
    std::cout << std::endl;
}

void printBookShelf(const BookShelf& shelf, const std::string& shelfName) {
	std::cout <<  shelfName << " (size: " << shelf.size() << ", Capacity: " << shelf.capacity() << ")"
			  << std::endl<< "Books: " << std::endl << shelf << std::endl;
}
