#include <stdexcept>
#include <iostream>
#include "../include/Date.hpp"

Date::Date(int y, Month m, int d) {
	if (!is_valid(y, m, d)) {
		throw std::invalid_argument("invalid_argument");
	}
	year = y;
	month = m;
	day = d;
}

Date::Date(Date &d) = default;

void Date::set_day(int new_day) {
	if (!is_valid(year, month, new_day)) {
		throw std::invalid_argument("invalid_argument");
	}
	day = new_day;
}

void Date::set_month(Month m) {
	if (!is_valid(year, m, day)) {
		throw std::invalid_argument("invalid_argument");
	}
	month = m;
}

void Date::set_year(int y) {
	if (!is_valid(y, month, day)) {
		throw std::invalid_argument("invalid_argument");
	}
	year = y;
}

bool Date::is_leap_year() const {                                                // controlla se l'anno è bisestile
	return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

bool Date::is_valid(int y, Month m, int d) const {
	if (y < 0 || d < 1 || d > 31 || m < 1 || m > 12) {        // controllo day, month e year
		return false;
	}

	if (m == 2) {                    // controllo giorno nel month february
		if (is_leap_year()) {
			return d <= 29;
		} else {
			return d <= 28;
		}
	}

	if (m == 4 || m == 6 || m == 9 || m == 11) {
		return d <= 30;
	}

	return true;
}

void Date::add_day(int n) {
	if (n < 0) {
		throw std::invalid_argument("Number of days should be positive");
	}

	int daysInMonth = days_in_month();

	while (n > 0) {
		int daysToAdd = std::min(n, daysInMonth - day + 1);
		day += daysToAdd;
		n -= daysToAdd;

		if (n > 0) {
			day = 1;
			if (month == 12) {
				month = Month::January;
				year++;
			} else {
				++month;
			}
			daysInMonth = days_in_month();
		}
	}
}

int Date::days_in_month() {
	int month_days;
	switch (month) {
		case 2:
			month_days = is_leap_year() ? 29 : 28;
			break;
		case 4: case 6: case 9:
		case 11:
			month_days = 30;
			break;
		default:
			month_days = 31;
			break;
	}
	return month_days;
}

Date& operator++(Date& d) {
	d.add_day(1);
	return d;
}

const Date operator++(Date& d, int) {
	Date d_copy (d);
	++d;
	return d_copy;
}

Month& operator++(Month& m) {
	m = (m == Month::December) ? Month::January : Month(int(m) + 1);
	return m;
}

const Month operator++(Month& m, int) {
	Month m_copy (m);
	++m;
	return m_copy;
}

std::ostream &operator<<(std::ostream &os, Date &d) {
	return os << d.get_year() << "/" << d.get_month() << "/" << d.get_day();
}