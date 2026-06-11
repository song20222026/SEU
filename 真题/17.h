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

void f1_17() {
	ifstream in("17t1.txt");
	char ch[20];
	in >> ch;
	string Month[13] = { "","Jan","Feb","Mar","Apr","May","June",
	"July","Aug","Sept","Oct","Nov","Dec" };
	char* token = strtok(ch, "/");
	cout << Month[atoi(token)] << " ";
	token = strtok(NULL, "/");
	cout << token << ",";
	token = strtok(NULL, "/");
	cout << token;
}