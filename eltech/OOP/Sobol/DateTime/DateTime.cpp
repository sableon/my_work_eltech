#include "DateTime.h"

DateTime::DateTime():
QObject()
{
	SYSTEMTIME st;
	GetSystemTime(&st);

	int year = static_cast<int>(st.wYear);
	int month = static_cast<int>(st.wMonth);
	int day = static_cast<int>(st.wDay);
	int hour = static_cast<int>(st.wHour);
	int minute = static_cast<int>(st.wMinute);
	int second = static_cast<int>(st.wSecond);

	evaluate_data(year,month,day,hour,minute,second);
}

DateTime::DateTime( __int64 sec ):
QObject()
{
	data = sec;
}

DateTime::DateTime( int h, float min ):
QObject()
{
	SYSTEMTIME st;
	GetSystemTime(&st);

	int year = static_cast<int>(st.wYear);
	int month = static_cast<int>(st.wMonth);
	int day = static_cast<int>(st.wDay);

	int m = (int)min;
	int sec = (int)( ( min - ( (int)min ) ) * 60 );
	
	evaluate_data(year,month,day,h,m,sec);
}

DateTime::DateTime( int year, int month, int day ):
QObject()
{
	SYSTEMTIME st;
	GetSystemTime(&st);

	int hour = static_cast<int>(st.wHour);
	int minute = static_cast<int>(st.wMinute);
	int second = static_cast<int>(st.wSecond);

	evaluate_data(year,month,day,hour,minute,second);
}

DateTime::DateTime( int year, int month, int day, int h, int m, int sec ):
QObject()
{
	evaluate_data(year,month,day,h,m,sec);
}


DateTime::~DateTime()
{

}

int DateTime::days_in_month( int year, int month )
{
	if(month < 1 || month > 12)
		return 0;
	if(month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	if(month == 2)
	{
		if(year % 4 == 0)
			return 29;
		return 28;
	}
	return 31;
}

int DateTime::sec_from_mid( int hour, int min, int sec )
{
	return (hour * 60 + min) * 60 + sec;
}

int DateTime::days_in_year( int year )
{
	if(year % 4 == 0)
		return 366;
	return 365;
}

int DateTime::sec_from_NY( int year, int month, int day, int hour, int min, int sec )
{
	int res = 0;
	for(int i = 1; i < month; ++i)
		res += days_in_month(year,i) * sec_in_day;
	res += (day - 1) * sec_in_day + sec_from_mid(hour,min,sec);
	return res;
}

void DateTime::evaluate_data( int year, int month, int day, int hour, int minute, int second )
{
	data = 0;
	if( year < start_year )
	{
		int t_year = year;
		while(t_year + 1 < start_year)
		{
			data -= days_in_year(t_year) * sec_in_day;
			++t_year;
		}
		data -= days_in_year(year) * sec_in_day - sec_from_NY(year,month,day,hour,minute,second);
	}
	else
	{
		int t_year = year;
		while(t_year > start_year)
		{
			data += days_in_year(t_year - 1) * sec_in_day;
			--t_year;
		}
		data += sec_from_NY(year,month,day,hour,minute,second);
	}
}

__int64 DateTime::to_seconds() const
{
	return data;
}

DateTime DateTime::operator+( const __int64& seconds ) const
{
	return DateTime(this->data + seconds);
}

void DateTime::operator+=(const __int64& seconds )
{
	this->data += seconds;
}

DateTime DateTime::operator++()
{
	return DateTime( ++data );
}

DateTime DateTime::operator++( int )
{
	return DateTime( data++ );
}

__int64 DateTime::operator-( const DateTime& other ) const
{
	return data - other.to_seconds();
}

int DateTime::year()  const
{
	if(data > 0)
	{
		int Y = start_year;
		__int64 t_data = data;
		while(t_data > days_in_year(Y) * sec_in_day)
		{
			++Y;
			t_data -= days_in_year(Y) * sec_in_day;
		}
		return Y;
	}
	int Y = start_year - 1;
	__int64 t_data = -data;
	while(t_data > days_in_year(Y) * sec_in_day)
	{
		--Y;
		t_data -= days_in_year(Y) * sec_in_day;
	}
	return Y;
}

int DateTime::month() const
{
	int cur_year = year();
	DateTime temp(cur_year,1,1,0,0,0);
	int t_sec_from_NY = data - temp.to_seconds();
	int M = 1;
	while(t_sec_from_NY > days_in_month(cur_year,M) * sec_in_day)
	{
		++M;
		t_sec_from_NY -= days_in_month(cur_year,M) * sec_in_day;
	}
	return M;
}

int DateTime::day() const
{
	int cur_year = year();
	int cur_month = month();
	DateTime temp(cur_year,cur_month,1,0,0,0);
	int t_sec_from_first = data - temp.to_seconds();
	return t_sec_from_first / sec_in_day + 1;
}

int DateTime::hour() const
{
	int cur_year = year();
	int cur_month = month();
	int cur_day = day();
	DateTime temp(cur_year,cur_month,cur_day,0,0,0);
	int t_sec_from_mid = data - temp.to_seconds();
	return t_sec_from_mid / 3600;
}

int DateTime::minute() const
{
	int cur_year = year();
	int cur_month = month();
	int cur_day = day();
	int cur_hour = hour();
	DateTime temp(cur_year,cur_month,cur_day,cur_hour,0,0);
	int t_min_from_zero = data - temp.to_seconds();
	return t_min_from_zero / 60;
}

int DateTime::second() const
{
	int cur_year = year();
	int cur_month = month();
	int cur_day = day();
	int cur_hour = hour();
	int cur_min = minute();
	DateTime temp(cur_year,cur_month,cur_day,cur_hour,cur_min,0);
	int t_sec_from_zero = data - temp.to_seconds();
	return t_sec_from_zero;
}

QString DateTime::month_name( int month )
{
	switch(month)
	{
		case 1: return "Jan";
		case 2: return "Feb";
		case 3: return "Mar";
		case 4: return "Apr";
		case 5: return "May";
		case 6: return "Jun";
		case 7: return "Jul";
		case 8: return "Aug";
		case 9: return "Sep";
		case 10: return "Oct";
		case 11: return "Nov";
		case 12: return "Dec";
		default: return "ERROR";
	}
}

QString DateTime::to_string() const
{
	QString hs, ms, ss;
	hs = QString::number(hour(),10);
	ms = QString::number(minute(),10);
	ss = QString::number(second(),10);
	if(hs.length() < 2)
		hs.prepend('0');
	if(ms.length() < 2)
		ms.prepend('0');
	if(ss.length() < 2)
		ss.prepend('0');
	QString res = hs + QString(":") + ms + QString(":") + ss + QString(",  ") +
		QString::number(day(),10) + QString(" ") + DateTime::month_name(month()) + QString(" ") +
		QString::number(year(),10);
	return res;
}
QString DateTime::to_string_Just_time() const
{
	QString hs, ms, ss;
	hs = QString::number(hour(),10);
	ms = QString::number(minute(),10);
	ss = QString::number(second(),10);
	if(hs.length() < 2)
		hs.prepend('0');
	if(ms.length() < 2)
		ms.prepend('0');
	if(ss.length() < 2)
		ss.prepend('0');
	QString res = hs + QString(":") + ms + QString(":") + ss;
	return res;
}

bool DateTime::operator>( const DateTime& other ) const
{
	return data > other.to_seconds();
}

bool DateTime::operator<( const DateTime& other ) const
{
	return data < other.to_seconds();
}

bool DateTime::operator==( const DateTime& other ) const
{
	return data == other.to_seconds();
}

bool DateTime::operator>=( const DateTime& other ) const
{	
	return data >= other.to_seconds();
}

bool DateTime::operator<=( const DateTime& other ) const
{
	return data <= other.to_seconds();
}

bool DateTime::operator!=( const DateTime& other ) const
{
	return data != other.to_seconds();
}
void DateTime::second_increment()
{
	++data;
}
ostream& operator<<( ostream& out, const DateTime& date_time )
{
	out << (date_time.to_string().toAscii().data());
	return out;
}
