#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;


int* input(int size) {//size是高度
	int num = size * (size + 1) / 2;
	int* arr = new int[num];
	for (int i = 0;i < num;i++)cin >> arr[i];
	return arr;
}
int index(int r, int c) {
	return r * (r - 1) / 2 + c - 1;
}
int digui(int* arr, int size, int row, int col) {
	if (row == size)return arr[index(row, col)];
	return max(digui(arr, size, row + 1, col), digui(arr, size, row + 1, col + 1))
		+ arr[index(row, col)];
}
int ditui(int* arr, int size) {
	int num = size * (size + 1) / 2;
	int* res = new int[num]();
	for (int r = size, c = 1;c <= size;c++)
		res[index(r, c)] = arr[index(r, c)];

	for (int r = size - 1;r >= 1;r--)
		for (int c = 1;c <= r;c++)
			res[index(r, c)] =
			max(res[index(r + 1, c)], res[index(r + 1, c + 1)]) + arr[index(r, c)];

	int result = res[index(1,1)];
	delete[] res;
	return result;
}
void f1_23() {
	int size;cin >> size;
	int* arr = input(size);
	cout << ditui(arr, size) << endl;
	for (int i = 1;i <= size;i++) {
		for (int j = 1;j <= i;j++) 
			cout << digui(arr, size, i, j) << " ";
		cout << endl;
	}
	//cout << digui(arr, size, 1, 1) << endl;
	delete[] arr;
}

//拓展，01背包
void f2_23() {
	int v[4] = { 2,4,6,3 };//价值
	int w[4] = { 1,3,4,2 };//重量
	int capacity = 6;
	vector<vector<int>>dp(4, vector<int>(capacity + 1, 0));//4*7,注意列数比容量多1

	for (int j = 0;j < capacity + 1;j++) {
		if (j >= w[0])dp[0][j] = v[0];
		else dp[0][j] = 0;
	}

	for (int i = 1;i < 4;i++)
		for (int j = w[i];j < capacity + 1;j++)
			if (j >= w[i])//要判断能否装下，否则j-w为负数
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			else dp[i][j] = dp[i - 1][j];

	cout << dp[3][capacity];
}

