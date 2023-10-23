#pragma once
#include<iostream>
using namespace std;

class Date {
public:
	Date(int year = 1900, int month = 1, int day = 1) {   //���캯�������ڳ�ʼ��
		_year = year;
		_month = month;
		_day = day;
	}

	void Print();   //��ӡ���ڣ����ڲ���
	int GetMonthDay(int year, int month);
	int ConverttoDay(int year, int month, int day);

	//���ܵľ���ʵ��
	bool operator==(const Date& d);  //�ж���date�Ƿ����
	bool operator!=(const Date& d);  

	bool operator>(const Date& d);    //date��Ƚϴ�С
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);

	Date operator+(int day);     //��(��)��������Ϧ�Ǻ���
	Date& operator+=(int day);
	Date operator-(int day);
	Date& operator-=(int day);

	Date& operator++();     //date������/�Լ�
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	int operator-(const Date& d);  //������date��������

private:
	int _year;
	int _month;
	int _day;
};
