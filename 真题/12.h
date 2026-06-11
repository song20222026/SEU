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

//最大公约数
int gcd(int x, int y) {
	int a = max(x, y), b = min(x, y);
	if (a % b == 0)return b;
	else return gcd(b, a % b);
}
//最小公倍数
int lcm(int x, int y) {
	return x * y / gcd(x, y);
}

int f2_12() {
	int n;cin >> n;
	int t, num = 0;
	for (int i = 1; i <= n;i++) {
		cin >> t;
		num += t;
	}
	return num;
}


//去除标点符号
void mydelete(string &s) {
	if (ispunct(s[s.size() - 1]))s.erase(s.end() - 1);
}
void f3_13() {
	string s;
	unordered_map<string, int>mymap;
	ifstream in("English.txt");
	while (getline(in, s, ' ')) {
		mydelete(s);
		mymap[s]++;
	}
	cout << "单词" << "  |  " << "出现的次数" << endl;
	for (auto& e : mymap) {
		cout << e.first << " | " << e.second << endl;
		cout << "----------------------------------------------" << endl;
	}

}
