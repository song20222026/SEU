#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


//×Ö·û´®·­×ª+×ª´óÐ´
void f2_25(char* p) {
	int r = (int)strlen(p) - 1;
	int l = 0;
	while (l < r) {
		swap(p[r], p[l]);
		l++;r--;
	}
	for (int i = 0;i < strlen(p);i++)
		p[i] = p[i] - 32;
	cout << p;
}
