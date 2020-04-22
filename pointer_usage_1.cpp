// C 语言函数指针使用
#include <stdio.h>
#include <stdlib.h>

int fun1()
{
	printf("this is fun1 call\n");
	return 1;
}

void fun2(int k, char c)
{
	printf("this is fun2 call:%d %c\n", k, c);
}

int main()
{
	int(*pfun1)() = NULL;
	void(*pfun2)(int, char) = NULL;
	int a, b;
	pfun1 = fun1; //第一种赋值方法
	a = pfun1();  //第一种调用方法（推荐）
	printf("%d\n", a);

	b = (*pfun1)();//第二种调用方法
	printf("%d\n", b);

	pfun2 = &fun2;//第二种赋值方法（推荐，因为和其他数据指针赋值方法一致）
	pfun2(1, 'a');
	(*pfun2)(2, 'b');

	return 0;
}

// c++函数指针使用
#include <iostream>
`
using namespace std;

class test
{
public:
	test()
	{
		cout << "constructor" << endl;
	}
	int fun1(int a, char c)
	{
		cout << "this is fun1 call:" << a << " " << c << endl;
		return a;
	}
	void fun2(double d)const
	{
		cout << "this is fun2 call:" << d << endl;
	}
	static double fun3(char buf[])
	{
		cout << "this is fun3 call:" << buf << endl;
		return 3.14;
	}
};

int main()
{
	// 类的静态成员函数指针和c的指针的用法相同
	double(*pstatic)(char buf[]) = NULL;//不需要加类名
	pstatic = test::fun3; //可以不加取地址符号
	pstatic("myclaa");
	pstatic = &test::fun3;
	(*pstatic)("xyz");

	//普通成员函数
	int (test::*pfun)(int, char) = NULL; //一定要加类名
	pfun = &test::fun1; //一定要加取地址符号
	test mytest;
	(mytest.*pfun)(1, 'a'); //调用是一定要加类的对象名和*符号

	//const 函数（基本普通成员函数相同）
	void (test::*pconst)(double)const = NULL; //一定要加const
	pconst = &test::fun2;
	test mytest2;
	(mytest2.*pconst)(3.33);

	//    //构造函数或者析构函数的指针，貌似不可以，不知道c++标准有没有规定不能有指向这两者的函数指针
	//    (test::*pcon)() = NULL;
	//    pcon = &test.test;
	//    test mytest3;
	//    (mytest3.*pcon)();

	return 0;
}

// 函数指针作为函数参数  --c版本
#include <stdio.h>
#include <stdlib.h>

void fun(int k, char c)
{
	printf("this is fun2 call:%d %c\n", k, c);
}

void fun1(void(*pfun)(int, char), int a, char c)
{
	pfun(a, c);
}

int main()
{
	fun1(fun, 1, 'a');
	return 0;
}

// 函数指针作为函数返回值：

// c 形式
#include <stdio.h>
#include <stdlib.h>

void fun(int k, char c)
{
	printf("this is fun2 call:%d %c\n", k, c);
}

//fun1 函数的参数为double，返回值为函数指针void(*)(int, char)
void(*fun1(double d))(int, char)
{
	printf("%f\n", d);
	return fun;
}

int main()
{
	void(*p)(int, char) = fun1(3.33);
	p(1, 'a');
	return 0;
}

//c++ 形式
#include <iostream>
using namespace std;

class test
{
public:
	int fun(int a, char c)
	{
		cout << "this is fun call:" << a << " " << c << endl;
		return a;
	}
};

class test2
{
public:
	// test2 的成员函数fun1,参数是double，
	//返回值是test的成员函数指针int(test::*)(int, char)
	int (test::*fun1(double d))(int, char)
	{
		cout << d << endl;
		return &test::fun;
	}
};

int main()
{
	test mytest;
	test2 mytest2;
	int (test::*p)(int, char) = mytest2.fun1(3.33);
	(mytest.*p)(1, 'a');
	return 0;
}

// 函数指针数组：

#include <stdio.h>
#include <stdlib.h>

float add(float a, float b) { return a + b; }
float minu(float a, float b) { return a - b; }

int main()
{
	//定义一个函数指针数组，大小为2
	//里面存放float (*)(float, float)类型的指针
	float(*pfunArry[2])(float, float) = { &add, &minu };
	double k = pfunArry[0](3.33, 2.22);// 调用
	printf("%f\n", k);
	k = pfunArry[1](3.33, 2.22);
	printf("%f\n", k);
	return 0;
}

// typedef 简化函数指针类型：

#include <stdio.h>
#include <stdlib.h>

float add(float a, float b)
{
	printf("%f\n", a + b);
	return a + b;
}
float minu(float a, float b)
{
	printf("%f\n", a - b);
	return a - b;
}

//用pfunType 来表示float(*)(float, float)
typedef float(*pfunType)(float, float);

int main()
{
	pfunType p = &add;//定义函数指针变量
	p(3.33, 2.22);
	pfunType parry[2] = { &add, &minu };//定义函数指针数组
	parry[1](3.33, 2.22);
	//函数指针作为参数可以定义为：void fun(pfunType p)
	//函数指针作为返回值可以定义为：pfunType fun();

	return 0;
}
//c++ 可类比