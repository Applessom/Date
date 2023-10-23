#pragma once
#include<iostream>
using namespace std;

class Date {
public:
	Date(int year = 1900, int month = 1, int day = 1) {   //构造函数：用于初始化
		_year = year;
		_month = month;
		_day = day;
	}

	void Print();   //打印日期，便于测试
	int GetMonthDay(int year, int month);
	int ConverttoDay(int year, int month, int day);

	//功能的具体实现
	bool operator==(const Date& d);  //判断俩date是否相等
	bool operator!=(const Date& d);  

	bool operator>(const Date& d);    //date间比较大小
	bool operator>=(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);

	Date operator+(int day);     //加(减)天数，今夕是何年
	Date& operator+=(int day);
	Date operator-(int day);
	Date& operator-=(int day);

	Date& operator++();     //date的自增/自减
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	int operator-(const Date& d);  //算两个date间差多少天

private:
	int _year;
	int _month;
	int _day;
};
