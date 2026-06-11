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

bool is_prime(int a) {
	int t = int(sqrt(a));
	bool flag = 1;
	for (int i = 2;i <= t;i++) 
		if (a % i == 0) {
			flag = 0;
			break;
		}
	return flag;
}

//输出1-20000的质数，满10个换行
void f1_13() {
	int t = 1;
	for (int i = 1;i <= 20000;i++) {
		if (is_prime(i)) {
			cout << i << " ";
			if (t % 10 == 0) 
				cout << endl;
			t++;
		}
	}
}

void encrypt(char* &s) {
	s = s + 1;
}
void decrypt(char* &s) {
	s = s - 1;
}

//桶排序,数据范围[1,100]
void bucket_sort(int a[],int len) {
	int bucket[101] = { 0 };
	for (int i = 0;i < len;i++)
		bucket[a[i]]++;
	for (int i = 1;i <= 100;i++) {
		while (bucket[i] > 0) {
			cout << i << " ";
			bucket[i]--;
		}
	}
}

string dec_to_oct(int num) {
	string s;
	while (num) {
		int b = num % 8;
		s = char(b + '0') + s;
		num = num / 8;
	}
	return s;
}

string dec_to_hex(int num) {
	string s;
	while (num) {
		int b = num % 16;
		if(b<10)s = char(b + '0') + s;
		else {
			b = b - 10;
			s = char(b + 'A') + s;
		}
		num = num / 16;
	}
	return s;
}

void f4_13() {
	ofstream out("ASCII.txt");
	out << "10进制表格开始" << endl;
	for (int i = 33;i <= 126;i++)
		out << i << "-----" << char(i) << endl;
	out << endl << "8进制表格开始" << endl;
	for (int i = 33;i <= 126;i++)
		out << dec_to_oct(i) << "-----" << char(i) << endl;
	out << endl << "16进制表格开始" << endl;
	for (int i = 33;i <= 126;i++)
		out << dec_to_hex(i) << "-----" << char(i) << endl;
}

//处理区号字符串
void f5_13(char* str) {
	char* token = strtok(str, "()"); // 跳过前缀
	cout << token << " ";
	token = strtok(NULL, "-");
	cout << token << " ";
	token = strtok(NULL, "-");
	cout << token;
}

class Name {
private:
	string first, middle, last;
public:
	Name(string first, string middle, string last):
		first(first),middle(middle),last(last){}
	void printName() {
		cout << first << middle << last << endl;
	}
};

class person {
private:
	Name name;
	string nationality, sex;
public:
	person(Name name, string nationality, string sex)
		:name(name), nationality(nationality), sex(sex) {}
	void printName() {
		name.printName();
	}
	void printNationnality() {
		cout << nationality << endl;
	}
};
