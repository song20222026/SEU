#pragma once

#include <iostream>
#include <map>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

//输入英文单词，统计
void f1_16() {
	string s, t;
	getline(cin, s);
	istringstream strin(s);
	vector<string>a;
	vector<int>b;
	while (getline(strin, t, ' ')) {
		a.push_back(t);
		b.push_back(static_cast<int>(t.size()));
	}
	for (size_t i = 0;i < a.size();++i) 
		cout << a[i] << " " << b[i] << endl;
}

//判断回文
bool f2_16(const char* s) {
	int i = 0, j = (int)strlen(s) - 1;
	bool flag = true;
	while (i < j) {
		if (s[i] != s[j])return false;
		else {
			i++;j--;
		}
	}
	return true;
}