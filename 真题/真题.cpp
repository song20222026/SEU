#define _CRT_SECURE_NO_WARNINGS
#include "10.h"
#include "23.h"
#include <iostream>
#include <sstream>
#include "19.h"
#include "18.h"
#include "17.h"
#include "15.h"
#include "16.h"
#include "14.h"
#include "13.h"
#include "12.h"
#include "11.h"
#include "25.h"
#include "银行账户.h"
using namespace std;

int sort_Array[] = { 4,7,2,98,34,1,12,37,34 };

//int a = 9;




int main()
{
	Account A("asd");

	//10
	{
		//f1();
		//f2_10(sort_Array, sizeof(sort_Array) / sizeof(int));for (int a : sort_Array) { cout << a << " "; }
		//f3_10(sort_Array, sizeof(sort_Array) / sizeof(int));for (int a : sort_Array) { cout << a << " "; }
		//f4_10();
		//f5_10();
	}

	//f1_23();
	//f2_23();
	//19
	{
		//for (int i = 0;i <= 10000;i++) 
		//	if (f1_19(i))cout << i << " ";

		//f2_19();
	}

	//18
	{
		//f1_18();
		//f2_18();
		//f3_18();
		//char buf[20] = "helloworld12345678";
		//f4_18(buf,10);//最多输9个
	}

	//f1_17();

	//15
	{
		//f1_15(-2);
		//myreverse("1 x 3 t 6 7 2 e f s 4");
		//f3_15();
		//char a[] = "hello,hello,world";	FindRepStr(a, "hello", "hi");
		//以下是f5_15的测试
		/*{
			vector<Teacher>teacher;
			Teacher a(1, "王二", "male", "1987 - 11 - 02", "2012 - 03 - 01");
			Teacher b(2, "李红", "female", "1960-05-10", "1985-09-01");
			Teacher c(3, "张军", "male", "1955-12-20", "1980-07-15");
			Teacher d(4, "刘芳", "female", "1965-08-05", "1990-04-01");
			Teacher e(5, "赵刚", "male", "1950-03-18", "1975-08-20");
			Teacher f(6, "孙丽", "female", "1958-11-30", "1988-01-10");
			teacher.push_back(a);
			teacher.push_back(b);
			teacher.push_back(c);
			teacher.push_back(d);
			teacher.push_back(e);
			teacher.push_back(f);
			for (auto a : teacher) {
				a.isRetired();
				a.isHired();
			}
		}*/
	}
	
	//f1_16();

	//14
	{
		//cout << ack(20, 10) << endl;
		//cout << IntToStr(520) << endl;
		//Data today;
		//today.setData(1, 2, 3);
		//today.display();
	}
	
	//13
	{
		//f1_13();

		/*{//f2_13
			char a[] = "hello world";
			char*p = a;
			encrypt(p);
			cout << p << endl;
			decrypt(p);
			cout << p << endl;
		}*/

		//bucket_sort(sort_Array, sizeof(sort_Array) / sizeof(int));

		//f4_13();

		/*{
			char str[] = "(025)87234865-987";
			f5_13(str);
		}*/

		//{//第6题
		//	Name n1("孙", "悟", "空");
		//	n1.printName();
		//	person p1(n1, "China", "male");
		//	p1.printName();
		//	p1.printNationnality();
		//}
	}

	//12
	{
		//cout << gcd(8, 12) << endl;
		//cout << f2_12() << endl;
		//f3_13();
	}

	//11
	{
		//ex(1);//求e^x
		//下面是Array类测试
		//Array chess(3, 4);
		//chess(1,2) = 3;
		//Array other(chess);
		//other.display();
		//cout << chess(1, 2) << endl;
		//chess.display();

		//f6_11();
	}

	//25
	{
		//char p[] = "helloworld";
		//f2_25(p);
	}

}



