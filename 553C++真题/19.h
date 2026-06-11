#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


bool f1_19(int x) {
	string s1 = to_string(x);
	int y = x * x;
	string s2 = to_string(y);
	if (s2.find(s1)!=string::npos)return true;
	else 
		return false;
}

//找数组最小值
template<class T>
T minimum(T a[], int n) {
	if (n == 1)return a[0];
	return min(minimum(a, n - 1), a[n - 1]);
}

void f2_19() {
	int a[] = { 6,234,7,3,7,2,8,89,456 };
	cout << minimum(a, 9);
}


class mystring {
private:
	char* p;
	int len;
public:
	mystring(const char* filename):p(nullptr),len(0) {
		ifstream in(filename);
		// 获取文件大小
		in.seekg(0, ios::end);
		len = int(in.tellg());
		in.seekg(0, ios::beg);

		p = new char[len + 1];
		p[len] = '\0';
		in.read(p, len);
		in.close();
	}
	~mystring() {
		delete[] p;
	}
	friend void func(const mystring& s1, const mystring& s2);

};


void func(const mystring& s1, const mystring& s2) {
	int max_len = 0;
	char* p1 = s1.p;
	char* p2 = s2.p;
	while (*p1 != '\0' && *p2 != '\0') {
		if (*p1 == *p2 && *p1 != ' ')max_len++;
		//太难，不会
	}

}