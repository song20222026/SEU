#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


//判断完数
bool is_wanshu(int x) {
	int num = 0;
	for (int i = 1;i <= x/2;++i)
		if (x % i == 0)num = num + i;
	if (num == x)return true;
	else return false;
}

//输出1000内的完数
void f1_18() {
	for (int i = 1;i <= 1000;i++)
		if (is_wanshu(i))cout << i << " ";
}


//随机生成十个10到100000的数，转成字符串并输出至文件
void f2_18() {
	srand((unsigned int)time(0));
	int a[10] = { 0 };
	ofstream out("18_t2.txt");
	for (int i = 0;i < 10;i++) {
		a[i] = 10 + rand() % 99991;
		stringstream oss;
		oss << a[i];
		string s = oss.str();
		out << s << " ";
	}
	out.close();
}

//求m*n矩阵的马鞍点：第i行中最小的元素，又是第j列中最大的元素
void f3_18() {
	int m, n;cin >> m >> n;
	vector<vector<int>>a(m, vector<int>(n, 0));
	for (int i = 0;i < m;i++)
		for (int j = 0;j < n;j++)
			cin >> a[i][j];

	for (int i = 0;i < m;i++) {
		int min_col = 0;//最小元素的列标
		int min_val = a[i][0];//记录i行最小值
		//确定min_col和min_val
		for (int j = 1;j < n;j++)
			if (a[i][j] < min_val) {
				min_val = a[i][j];
				min_col = j;
			}
		//min_val是j列最大才是鞍点，遍历所有行验证
		int flag = 1;
		for (int k = 0;k < m;k++)
			if (a[k][min_col] > min_val) {
				flag = 0;
				break;
			}
		if (flag == 1)cout << "(" << i << "," << min_col << ")" << min_val << endl;
	}
}

//读一行字符到字符数组
void f4_18(char* buf,int size) {
	int i = 0;
	char ch;
	while (i < size - 1) {
		ch = cin.get();
		if (ch == '\n')break;
		buf[i] = ch;
		i++;
	}
	buf[size - 1] = '\0';
	cout << buf << endl;
	//cout << buf + size << endl;
	
}


