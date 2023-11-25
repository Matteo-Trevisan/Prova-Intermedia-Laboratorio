#include <stdexcept>
#include <iostream>
#include "../include/Date.h"

// costruttori
Date::Date(int y, Month m, int d) { // costruttore con parametri in ingresso (default in caso di non inserimento)
	if (!is_valid(y, m, d)) {
		throw std::invalid_argument("Invalid copyright_date");
	}
	year = y;
	month = m;
	day = d;
	set = true;
}

Date::Date(Date &d) = default;  // costruttore di copia
Date::Date(const Date &d) = default;    // costruttore di copia (const)

// funzioni membro set
void Date::set_day(int new_day) {
	if (!is_valid(year, month, new_day)) {
		throw std::invalid_argument("Invalid copyright_date");
	}
	day = new_day;
	set = true;
}

void Date::set_month(Month m) {
	if (!is_valid(year, m, day)) {
		throw std::invalid_argument("Invalid copyright_date");
	}
	month = m;
	set = true;
}

void Date::set_year(int y) {
	if (!is_valid(y, month, day)) {
		throw std::invalid_argument("Invalid copyright_date");
	}
	year = y;
	set = true;
}

// funzione che controlla se la data fornita è valida
bool Date::is_valid(int y, Month m, int d) const {
	if (y < 0 || d < 1 || d >= days_in_month(y, m) || m < Month::January || m > Month::December) {
		return false;
	}
	return true;
}

// incremento date di n giorni
void Date::add_day(int n) {
	set = true;
	if (n < 0) {    // controllo numero gioni negativi
		throw std::invalid_argument("Number of days should be positive");
	}

	int daysInMonth = days_in_month(year, month);

	while (n > 0) {
		int daysToAdd = std::min(n, daysInMonth - day + 1);
		day += daysToAdd;
		n -= daysToAdd;

		if (n > 0) {
			day = 1;
			if (month == Month::December) {
				month = Month::January;
				year++;
			} else {
				++month;
			}
			daysInMonth = days_in_month(year, month);
		}
	}
}

// numero di giorni in un mese con controllo anno bisestile
int days_in_month(int y, Month m) {
	int month_days;
	switch (m) {
		case Month::February:
			month_days = is_leap_year(y) ? 29 : 28;
			break;
		case Month::April:
		case Month::June:
		case Month::September:
		case Month::November:
			month_days = 30;
			break;
		default:
			month_days = 31;
			break;
	}
	return month_days;
}

// controllo se è un anno bisestile
bool is_leap_year(int y) {
	return ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0);
}

// overloading operatore ++copyright_date

Date &operator++(Date &d) {
	d.add_day(1);
	return d;
}

// overloading operatore copyright_date++

const Date operator++(Date &d, int) {
	Date d_copy(d);
	++d;
	return d_copy;
}

// overloading operatore ++month

Month &operator++(Month &m) {
	m = (m == Month::December) ? Month::January : Month(int(m) + 1);
	return m;
}

// overloading operatore month++

const Month operator++(Month &m, int) {
	Month m_copy(m);
	++m;
	return m_copy;
}

// overloading operatore <<

std::ostream &operator<<(std::ostream &os, const Date &d) {
	return os << d.get_year() << "/" << d.get_month() << "/" << d.get_day();
}