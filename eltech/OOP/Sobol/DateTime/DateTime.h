#ifndef DATETIME_H
#define DATETIME_H

#include <windows.h>
#include <QString>

#include <QObject>

#include <iostream>
using namespace std;

const int sec_in_day = 86400;
const int start_year = 1970;

class DateTime: public QObject //за ноль примем 00:00:00 1 янв 1970
{
	Q_OBJECT
public:	
	DateTime();
	DateTime(__int64 sec);
	DateTime(int h, float min); //cекунды задаются в виде долей минут - в противном случае возникает конфликт между этой функцией и следующей (обе принимали бы три инта)
	DateTime(int year, int month, int day);
	DateTime(int year, int month, int day, int h, int m, int sec);

	~DateTime();

	__int64 to_seconds() const;

	int year() const;
	int month() const;
	int day() const;
	int hour() const;
	int minute() const;
	int second() const;	

	DateTime operator+(const __int64& seconds) const;
	void operator+=(const __int64& seconds);
	DateTime operator++();
	DateTime operator++( int );

	__int64 operator-(const DateTime& other) const;

	static QString month_name(int month);
	QString to_string() const;
	QString to_string_Just_time() const;

	bool operator>(const DateTime& other) const;
	bool operator<(const DateTime& other) const;
	bool operator==(const DateTime& other) const;
	bool operator>=(const DateTime& other) const;
	bool operator<=(const DateTime& other) const;
	bool operator!=(const DateTime& other) const;

private:
	__int64 data;
	static int days_in_month(int year, int month);
	static int days_in_year(int year);
	static int sec_from_mid(int hour, int min, int sec);
	static int sec_from_NY( int year, int month, int day, int hour, int min, int sec);

	void evaluate_data(int year, int month, int day, int hour, int minute, int second);

public slots:
	void second_increment();
};

ostream& operator<<(ostream& out, DateTime date_time);

#endif // DATETIME_H
