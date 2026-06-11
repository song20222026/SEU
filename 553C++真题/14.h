#pragma once
#include <iostream>
#include <map>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;


int ack(int m, int n) {
	if (m == 0)return n + 1;
	if (n == 0)return m + 1;
	return ack(m - 1, n - 1);
}

string IntToStr(int a) {
	ostringstream out;
	out << a;
	return (out.str());
}

class Data {
private:
	int year, month, day;
public:
	Data():year(1900),month(1),day(1) {}
	Data(const Data& a) :year(a.year), month(a.month), day(a.day) { }
	void setData(int year,int month,int day) {
		this->year = year;
		this->month = month;
		this->day = day;
	}
	void display() {
		cout << year << "年" << month << "月" << day << "日" << endl;
	}
	int getyear() {
		return year;
	}
};


class Employee {
private:
	int employee_id;
	string name, id;
	Data birth_data, hired_data;
	int hired_time, salary;
public:
	Employee(int employee_id, string name, string id)
		:employee_id(employee_id), name(name), id(id) {
		birth_data = Data();
		hired_data = Data();
		hired_time = 0;
		salary = 0;
	}

	void set_birth(int year, int month, int day) {
		birth_data.setData(year, month, day);
	}
	
	void set_hired_data(int year, int month, int day) {
		hired_data.setData(year, month, day);
	}

	void set_hired_time(int n) {
		hired_time = n;
	}

	void set_salary(int n) {
		salary = n;
	}

	void xuping(int n) {
		if (hired_data.getyear() - birth_data.getyear() + hired_time + n > 60)
			cout << "no!" << endl;
		else hired_time += n;
	}

	void display();
};

void Employee::display() {
	cout << "工号：" << employee_id << endl;
	cout << "姓名：" << name << endl;
}