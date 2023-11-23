#ifndef PROVA_INTERMEDIA_DATE_H
#define PROVA_INTERMEDIA_DATE_H

enum Month {
	January = 1, February, March, April, May, June, July, August, September, October, November, December
};

class Date {
public:
    Date();
	Date(int y, Month m, int d);			//check e inizializza
	Date(Date& d);
    Date(const Date& d);

	void add_day(int n);

	void set_day(int d);
	void set_month(Month m);
	void set_year(int y);

	int get_day() const { return day; }
	Month get_month() const { return month; }
	int get_year() const { return year; }

	bool is_leap_year() const;
	bool has_been_set() const { return set; };

private:
	int year, day;
	Month month;
	bool set;
	bool is_valid(int y, Month m, int d) const;
	int days_in_month();
};

Date& operator++(Date& d);
const Date operator++(Date& d, int);
Month& operator++(Month& m);
const Month operator++(Month& m, int);
std::ostream &operator<<(std::ostream &os, const Date &d);

#endif //PROVA_INTERMEDIA_DATE_H
