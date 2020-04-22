// C ���Ժ���ָ��ʹ��
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
	pfun1 = fun1; //��һ�ָ�ֵ����
	a = pfun1();  //��һ�ֵ��÷������Ƽ���
	printf("%d\n", a);

	b = (*pfun1)();//�ڶ��ֵ��÷���
	printf("%d\n", b);

	pfun2 = &fun2;//�ڶ��ָ�ֵ�������Ƽ�����Ϊ����������ָ�븳ֵ����һ�£�
	pfun2(1, 'a');
	(*pfun2)(2, 'b');

	return 0;
}

// c++����ָ��ʹ��
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
	// ��ľ�̬��Ա����ָ���c��ָ����÷���ͬ
	double(*pstatic)(char buf[]) = NULL;//����Ҫ������
	pstatic = test::fun3; //���Բ���ȡ��ַ����
	pstatic("myclaa");
	pstatic = &test::fun3;
	(*pstatic)("xyz");

	//��ͨ��Ա����
	int (test::*pfun)(int, char) = NULL; //һ��Ҫ������
	pfun = &test::fun1; //һ��Ҫ��ȡ��ַ����
	test mytest;
	(mytest.*pfun)(1, 'a'); //������һ��Ҫ����Ķ�������*����

	//const ������������ͨ��Ա������ͬ��
	void (test::*pconst)(double)const = NULL; //һ��Ҫ��const
	pconst = &test::fun2;
	test mytest2;
	(mytest2.*pconst)(3.33);

	//    //���캯����������������ָ�룬ò�Ʋ����ԣ���֪��c++��׼��û�й涨������ָ�������ߵĺ���ָ��
	//    (test::*pcon)() = NULL;
	//    pcon = &test.test;
	//    test mytest3;
	//    (mytest3.*pcon)();

	return 0;
}

// ����ָ����Ϊ��������  --c�汾
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

// ����ָ����Ϊ��������ֵ��

// c ��ʽ
#include <stdio.h>
#include <stdlib.h>

void fun(int k, char c)
{
	printf("this is fun2 call:%d %c\n", k, c);
}

//fun1 �����Ĳ���Ϊdouble������ֵΪ����ָ��void(*)(int, char)
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

//c++ ��ʽ
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
	// test2 �ĳ�Ա����fun1,������double��
	//����ֵ��test�ĳ�Ա����ָ��int(test::*)(int, char)
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

// ����ָ�����飺

#include <stdio.h>
#include <stdlib.h>

float add(float a, float b) { return a + b; }
float minu(float a, float b) { return a - b; }

int main()
{
	//����һ������ָ�����飬��СΪ2
	//������float (*)(float, float)���͵�ָ��
	float(*pfunArry[2])(float, float) = { &add, &minu };
	double k = pfunArry[0](3.33, 2.22);// ����
	printf("%f\n", k);
	k = pfunArry[1](3.33, 2.22);
	printf("%f\n", k);
	return 0;
}

// typedef �򻯺���ָ�����ͣ�

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

//��pfunType ����ʾfloat(*)(float, float)
typedef float(*pfunType)(float, float);

int main()
{
	pfunType p = &add;//���庯��ָ�����
	p(3.33, 2.22);
	pfunType parry[2] = { &add, &minu };//���庯��ָ������
	parry[1](3.33, 2.22);
	//����ָ����Ϊ�������Զ���Ϊ��void fun(pfunType p)
	//����ָ����Ϊ����ֵ���Զ���Ϊ��pfunType fun();

	return 0;
}
//c++ �����