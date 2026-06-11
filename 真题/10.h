#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

//10转2
string convert2(int x) {
	int t = 0;
	string s;
	while (x) {
		t = x % 2;
		s = char(t + '0') + s;
		x = x / 2;
	}
	return s;
}
//输入n个十进制数转换成二进制写到文件，n是随机得到
void f1() {
	//srand((unsigned int)time(0));
	srand(0);
	int n = rand();
	int t = 0;
	ofstream out("10t1.txt");
	while (n--) {
		cin >> t;
		out << convert2(t) << endl;
	}
	out.close();
}

//插入排序法的迭代实现与递归实现
template<class T>
void f2_10(T a[], int len) {
	for (int i = 1;i < len;i++) {
		int temp = a[i];
		int j = i - 1;
		while (a[j] > temp && j >= 0) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp;
	}
}

//递归辅助函数,把第len个元素a[len-1]插入前面
template<class T>
void insert(T a,int len){
	int j = len - 2;
	int t = a[len - 1];
	while (j >= 0 && a[j] > t) {
		a[j + 1] = a[j];
		--j;
	}
	a[j + 1] = t;
}

//插入排序法的递归实现
template<class T>
void f3_10(T a[], int len) {
	if (len <= 1)return;
	f3_10(a, len - 1);
	insert(a, len);//把a[len]插入a中，前len-1已经有序
}

//解析字符串
void f4_10() {
	fstream in("10t3.txt", ios::in);
	string s;
	getline(in, s,'\n');
	cout << s.substr(1, 3) << "|" << s.substr(6, 11) << "|" << s.substr(19, 3) << "|" << s.substr(24, 6);
}

//多项式类
template<class T = double>
class Poly {
private:
	T* a;//系数
	int b;//最高次数
public:
	Poly(T* aa, int bb) :b(bb) {
		a = new T[bb + 1]();
		for (int i = 0;i <= bb;i++)
			this->a[i] = aa[i];
	}
	Poly(const Poly& other) {
		b = other.b;
		a = new T[b + 1]();
		for (int i = 0;i <= b;i++)
			a[i] = other.a[i];
	}
	~Poly() {
		delete[] a;
	}

	Poly& operator=(const Poly& other) {
		//这里返回值是原对象的引用
		b = other.b;
		delete[] a;
		a = new T[b + 1]();
		for (int i = 0;i <= b;i++)
			a[i] = other.a[i];
		return *this;
	}

	Poly operator+(const Poly& other) {
		if (this->b > other.b) {
			Poly t(*this);
			for (int i = 0;i <= other.b;i++)
				t.a[i] += other.a[i];
			return t;
		}
		else {
			Poly t(other);
			for (int i = 0;i <= this->b;i++)
				t.a[i] += this->a[i];
			return t;
		}
	}

	void show() const {
		cout << "最高次：" << b << endl;
		for (int i = 0;i <= b;i++)
			cout << a[i] << " ";
		cout << endl;
	}
};

//测试多项式类
void f5_10() {
	int a[] = { 1,2,4,0,3,0,5 };
	int b[] = { 0,3,4,5,1,0 };
	Poly<int> p1(a, sizeof(a) / sizeof(int) - 1);
	p1.show();
	Poly<int> p2(p1);
	p2.show();
	p1 = p1 + p2;
	p1.show();
	Poly<int> p3(b, sizeof(b) / sizeof(int) - 1);
	p3.show();
	p3 = p3 + p1;
	p3.show();
}

