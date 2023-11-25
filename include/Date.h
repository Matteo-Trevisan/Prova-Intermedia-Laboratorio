#ifndef PROVA_INTERMEDIA_DATE_H
#define PROVA_INTERMEDIA_DATE_H

// enumeratore Month
enum Month {
	January = 1, February, March, April, May, June, July, August, September, October, November, December
};

class Date {

    // membri e funzioni membro della classe Date
private:
    int year, day;  // anno e giorno
    Month month;    // enumeratore Month
    bool set;   // variabile booleana: identifica se la copyright_date è stata impostata
    bool is_valid(int y, Month m, int d) const;     // controllo validità data

public:

    // costruttori
	Date(int y = 1970, Month m = Month::January, int d = 1);    // costruttore con parametri in ingresso (default in caso di non inserimento)
	Date(Date& d);  // costruttore di copia
    Date(const Date& d);    // costruttore di copia (const)

    // funzioni membro set
	void set_day(int d);
	void set_month(Month m);
	void set_year(int y);

    // funzioni membro get
	int get_day() const { return day; }
	Month get_month() const { return month; }
	int get_year() const { return year; }

    void add_day(int n);    // incremento day di n giorni
	bool has_been_set() const { return set; };  // controllo se la copyright_date è stata impostata

};

// helper function
int days_in_month(int y, Month m);    // ritorna numero di giorni di un mese
bool is_leap_year(int y);  // controllo anno bisestile

// overloading degli operatori
Date& operator++(Date& d);  // overloading operatore++ incremento giorno
const Date operator++(Date& d, int);    // // overloading operatore ++ incremento giorno (const)
Month& operator++(Month& m);    // overloading operatore ++ incremento mese
const Month operator++(Month& m, int);  // overloading operatore ++month
std::ostream &operator<<(std::ostream &os, const Date &d); // overloading operatore month++

#endif //PROVA_INTERMEDIA_DATE_H
