#pragma once
#pragma warning(disable:4996)  // 关闭VS的strcpy不安全警告
#include <iostream>
#include <map>
#include <ctime>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

//求e^x
double f1_15(double x) {
    int i = 1;
    double sum = 1, temp = 1;
    while (fabs(temp) > 1e-7) {
        temp = temp * x / i;
        sum += temp;
        i++;
    }
    cout << sum << endl;
    return sum;
}

//处理字符串
void myreverse(const char* s) {
    if (*s=='\0')return;
    myreverse(s + 1);
    if (*s >= '1' && *s <= '9')cout << *s;
}

void f3_15() {
    srand((unsigned int)time(0));
    int B[7][7] = { 0 };
    for (int i = 0;i < 1000;i++) {
        int a = rand() % 6 + 1, b = rand() % 6 + 1;
        B[a][b]++;
    }
}


void FindRepStr(char str[], const char findStr[], const char replaceStr[]) {
    char* pos;// 存储找到的子串起始位置
    int findLen = (int)strlen(findStr);
    char temp[1000] = { 0 };//临时存储区
    pos = strstr(str, findStr);
    while (pos) {
        strncpy(temp, str, pos - str);//复制原字符串中目标子串之前的部分到临时缓冲区
        temp[pos - str] = '\0';//手动补0

        strcat(temp, replaceStr);//拼接替换字符串
        strcat(temp, pos + findLen);//拼接原字符串中目标子串之后的部分

        strcpy(str, temp);//将替换后的临时字符串复制回原字符串
        pos = strstr(str, findStr);
    }
    cout << str << endl;
}

class Teacher {
private:
    int id;
    string name, sex, birth, date;
public:
    Teacher(int id=1,string name="张三",string sex="male",
        string birth="1900-00-00",string date="2016-1") 
        :id(id),name(name),sex(sex),birth(birth),date(date){ }
    Teacher(const Teacher& a)
        :id(a.id), name(a.name), sex(a.sex), birth(a.birth), date(a.date){ }

    int getBirthYear() {
        return stoi(birth.substr(0, 4));
    }
    int getHireYear() {
        return stoi(date.substr(0, 4));
    }
    void isRetired();
    void isHired();

};


void Teacher::isRetired() {
    int age = 2016 - getBirthYear();
    if (sex == "male" && age >=55)cout << name << " " << id << endl;
    if (sex == "female" && age >= 60)cout << name << " " << id << endl;
}

void Teacher::isHired() {
    int hiredTime = 2016 - getHireYear();
    if (sex == "female" && hiredTime < 35)cout << name << " " << id << endl;
}