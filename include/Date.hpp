#ifndef PROVA_INTERMEDIA_DATE_HPP
#define PROVA_INTERMEDIA_DATE_HPP

enum Month {
	January = 1, february, March, April, May, June, July, August, September, October, November, December
};

class Date {
public:
	Date(int y, Month m, int d);			//check e inizializza
	Date(Date& d);

	void add_day(int n);

	void set_day(int d);
	void set_month(Month m);
	void set_year(int y);

	int get_day() const { return day; }
	Month get_month() const { return month; }
	int get_year() const { return year; }

	bool is_leap_year() const;

private:
	int year, day;
	Month month;
	bool is_valid(int y, Month m, int d) const;
	int days_in_month();
};

Date& operator++(Date& d);
const Date operator++(Date& d, int);
Month& operator++(Month& m);
const Month operator++(Month& m, int);
std::ostream &operator<<(std::ostream &os, Date &d);

#endif //PROVA_INTERMEDIA_DATE_HPP
