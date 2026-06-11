#pragma once
#include <iostream>
#include <unordered_map>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;


double ex(int x) {
	double t = 1;
	double res = 0;
	for (int i = 1;t >= 1e-9;i++) {
		res = res + t;
		t = (t * x) / i;
	}
	cout << res;
	return res;
}

//递归找数组最小值
template<class T>
int find_min(T a[], int len) {
	if (len <= 1)return 0;
	int t = find_min(a, len - 1);
	if (a[t] > a[len - 1])return len - 1;
	else return t;
}

//二维数组类
class Array {
private:
	int row, col;
	int** p;//一般放在私有
public:
	Array(int row,int col):row(row),col(col) {
		p = new int* [row]();
		for (int i = 0;i < row;i++)
			p[i] = new int[col]();
	}
	Array(const Array& arr)
		:row(arr.row), col(arr.col) {
		p = new int* [row]();
		for (int i = 0;i < row;i++)
			p[i] = new int[col]();
		for (int i = 0;i < row;i++)
			for (int j = 0;j < col;j++)
				p[i][j] = arr.p[i][j];//深拷贝
	}

	~Array() {
		for (int i = 0;i < row;i++)
			delete[] p[i];
		delete[] p;
	}

	int& operator()(int r, int c) {
		return p[r][c];
	}

	void display() {
		for (int i = 0;i < row;i++) {
			for (int j = 0;j < col;j++)
				cout << p[i][j] << ' ';
			cout << endl;
		}

	}
};


class shape {
private:
	int* p;
public:
	shape(){
		p = new int[100]();
	}
	virtual ~shape() = 0;
	virtual double get_area() { return 0; }
};
shape::~shape() {
	delete[] p;
}

class circle :public shape {
private:
	int x, y, r;
public:
	circle(int x,int y,int r):x(x),y(y),r(r){}
	virtual double get_area() {
		return 3.14 * r * r;
	}
};

class tri :public shape {
private:
	int x1, x2, x3;
	int y1, y2, y3;
public:
	tri(int x1,int y1,int x2,int y2,int x3,int y3)
		:x1(x1),y1(y1),x2(x2),y2(y2),x3(x3),y3(y3){}
	virtual double get_area() {
		int l1 = (int)sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		int l2 = (int)sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
		int l3 = (int)sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
		int p = (l1 + l2 + l3) / 2;
		return sqrt(p * (p - l1) * (p - l2) * (p - l3));
	}
};

class rec :public shape {
private:
	int x1, x2;
	int y1, y2;
public:
	rec(int x1,int y1,int x2,int y2):x1(x1),y1(y1),x2(x2),y2(y2){}
	virtual double get_area() {
		return abs((x1 - x2) * (y1 - y2));
	}
};

void f6_11() {
	ifstream in("file.txt");

	string s, t;
	getline(in, s);
	in.close();

	istringstream raw_data(s);
	vector<shape*> shapes_ptr;

	while (getline(raw_data, t, ';')) {
		char tag = t[0];
		string t2 = t.substr(2);
		istringstream in_t2(t2);
		string num;
		vector<int> data;

		while (getline(in_t2, num, ',')) 
			data.push_back(stoi(num));

		switch (tag) {
		case 'C':
			shapes_ptr.push_back(new circle(data[0], data[1], data[2]));
			break;
		case 'R':
			shapes_ptr.push_back(new rec(data[0], data[1], data[2], data[3]));
			break;
		case 'T':
			shapes_ptr.push_back(new tri(data[0], data[1], data[2], data[3], data[4], data[5]));
			break;
		}//switch
	}//while

	for (auto p : shapes_ptr) 
		cout << p->get_area() << endl;

	for (auto p : shapes_ptr) 
		delete p;
	shapes_ptr.clear();
}
