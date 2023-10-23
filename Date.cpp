#include"Date.h"
void Date::Print() {
	printf("%d-%d-%d\n", _year, _month, _day);
}

bool Date::operator==(const Date& d) {
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator!=(const Date& d) {
	return !(*this == d);
}

bool Date::operator>(const Date& d) {
	if (_year > d._year
		|| _year == d._year && _month > d._month
		|| _year == d._year && _month == d._month && _day > d._day) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::operator>=(const Date& d) {
	return *this > d || *this == d;
}

bool Date::operator<(const Date& d) {
	return !(*this >= d);
}

bool Date::operator<=(const Date& d) {
	return !(*this > d);
}

int Date::GetMonthDay(int year, int month) {
	int days[13]={ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int ret = days[month];

	//���������2����29������
	//���꣬Ҫô�ܱ�4����&&���ܱ�100~��Ҫô�ܱ�400����

	if (month == 2
		&& (year % 4 == 0 && year % 100 != 0
			|| year % 400 == 0)) {
		ret += 1;
	}

	return ret;
}

Date Date::operator+(int day) {
	Date ret = *this;
	ret += day;
	return ret;
}

Date& Date::operator+=(int day) {
	_day += day;
	int MaxDay = GetMonthDay(_year, _month);

	while (_day > MaxDay) {
		_day -= MaxDay;
		_month++;

		//��ֹmonth���
		if (_month == 13) {
			_month = 1;
			_year++;
		}

		MaxDay = GetMonthDay(_year, _month);
	}

	return *this;
}

Date Date::operator-(int day) {
	Date ret = *this;
	ret -= day;
	return ret;
}

Date& Date::operator-=(int day) {
	_day -= day;

	while (_day <= 0) {
		_month--;

		if (_month == 0) {
			_month = 12;
			_year--;
		}
		int BorrowDay = GetMonthDay(_year, _month);
		_day += BorrowDay;
	}

	return *this;
}
Date& Date::operator++() {
	return *this += 1;
}
Date Date::operator++(int) {
	Date ret = *this;
	*this += 1;
	return ret;
}
Date& Date::operator--() {
	return *this -= 1;
}
Date Date::operator--(int) {
	Date ret = *this;
	*this -= 1;
	return ret;
}

//int Date::operator-(const Date& d) {
//	Date More = *this;  //�Ȱ�date�����С
//	Date Less = d;
//
//	if (Less > More) {
//		More=d;
//      Less=*this;
//	}
//
//	int count = 0;    //�ü��������ֵ
//	while (Less<More) {
//		Less++;
//		count++;
//	}
//
//	int flag = 1;
//	if (More == d) {
//		flag = -1;  //*this-d�����*this��С���ǽ��ӦΪ��ֵ
//	}
//
//	return count*flag;
//}

int Date::ConverttoDay(int year, int month, int day) {
	int MonthtoDay = 0;
	month -= 1;

	while (month) {
		MonthtoDay += GetMonthDay(year, month);
		month--;
	}

	int ret = MonthtoDay + day;
	return ret;
}

int Date::operator-(const Date& d) {
	//���ж����ڵĴ�С
	Date BigDate = *this;
	Date SmallDate = d;

	if (BigDate < SmallDate) {
		Date tmp = SmallDate;
		SmallDate = BigDate;
		BigDate = tmp;
	}

	//���¡��ն�ת������
	int BigDay = ConverttoDay(BigDate._year, BigDate._month, BigDate. _day);
	int SmallDay = ConverttoDay(SmallDate._year, SmallDate._month, SmallDate._day);


	int RetofDay = BigDay - SmallDay;  //��֮�����������-С��
	
	int BigYear = BigDate._year;
	int SmallYear = SmallDate._year;

	//����-С��
	int CountDay = 0;

	while (SmallYear < BigYear) {
		CountDay += 365;

		if (SmallYear % 4 == 0 && SmallYear % 100 != 0  //��������
			|| SmallYear % 400 == 0) {
			CountDay += 1;
		}

		SmallYear++;
	}

	//�����ߵ�������һ
	int ret = RetofDay + CountDay;

	int flag = 1;
	if (*this == BigDate) {
		flag = -1;
	}

	return flag * ret;
}