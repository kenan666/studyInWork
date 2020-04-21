// pointer ָ��
/*

ָ����һ����������ֵΪ��һ�������ĵ�ַ�������ڴ�λ�õ�ֱ�ӵ�ַ��
������ʹ��ָ��洢����������ַ֮ǰ���������������

type *var-name;

example :
int    *ip;    // һ�����͵�ָ�� /
double *dp;    // һ�� double �͵�ָ�� /
float  *fp;    // һ�������͵�ָ�� //
char   *ch;    // һ���ַ��͵�ָ�� /

����ָ���ֵ��ʵ���������ͣ����������͡������͡��ַ��ͣ������������������ͣ�����һ���ģ�
����һ�������ڴ��ַ�ĳ���ʮ������������ͬ�������͵�ָ��֮��Ψһ�Ĳ�ͬ�ǣ�ָ����ָ��ı����������������Ͳ�ͬ��

*/
// use pointer
//����һ��ָ��������ѱ�����ַ��ֵ��ָ�롢����ָ������п��õ�ַ��ֵ��
//ͨ��ʹ��һԪ����� * ������λ�ڲ�������ָ����ַ�ı�����ֵ��

#include <iostream>

using namespace std;

int main()
{
	int  var = 20;   // ʵ�ʱ���������
	int  *ip;        // ָ�����������

	ip = &var;       // ��ָ������д洢 var �ĵ�ַ

	cout << "Value of var variable: ";
	cout << var << endl;

	// �����ָ������д洢�ĵ�ַ
	cout << "Address stored in ip variable: ";
	cout << ip << endl;

	// ����ָ���е�ַ��ֵ
	cout << "Value of *ip variable: ";
	cout << *ip << endl;

	return 0;
}
/*
output:
Value of var variable: 20
Address stored in ip variable: 0xbfc601ac
Value of *ip variable: 20
*/

// c++ NULL pointer
// �ڱ���������ʱ�����û��ȷ�еĵ�ַ���Ը�ֵ��Ϊָ�������һ�� NULL
// ��Ϊ NULL ֵ��ָ�뱻��Ϊ��ָ�롣��Ϊ NULL ֵ��ָ�뱻��Ϊ��ָ�롣
// example:
#include <iostream>

using namespace std;

int main()
{
	int  *ptr = NULL;

	cout << "ptr ��ֵ�� " << ptr;

	return 0;
}
// output : ptr ��ֵ�� 0
/*
tips:����������ʵ�ַΪ 0 ���ڴ�Ȼ�����ڴ��ַ 0 ���ر���Ҫ�����壬
��������ָ�벻ָ��һ���ɷ��ʵ��ڴ�λ�á�
���ָ�������ֵ����ֵ������ٶ�����ָ���κζ�����
*/
// example 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout << "NULL=" << NULL << endl;
	return 0;
}
// output : NULL = 0

// ָ�����������
//ָ����һ������ֵ��ʾ�ĵ�ַ�����Զ�ָ����������������㣺++��--��+��-�� 
//example : ptr++
/*
ptr ��ָ��λ�� 1004����Ϊ ptr ÿ����һ�Σ�������ָ����һ������λ�ã�
����ǰλ�������� 4 ���ֽڡ����������ڲ�Ӱ���ڴ�λ����ʵ��ֵ������£�
�ƶ�ָ�뵽��һ���ڴ�λ�á���� ptr ָ��һ����ַΪ 1000 ���ַ���
���������ᵼ��ָ��ָ��λ�� 1001����Ϊ��һ���ַ�λ������ 1001��
*/
// ����һ��ָ��
// ָ�����������飬����ָ����Ե������������鲻�ܣ�������һ������ָ��
#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
	int  var[MAX] = { 10, 100, 200 };
	int  *ptr;

	// ָ���е������ַ
	ptr = var;
	for (int i = 0; i < MAX; i++)
	{
		cout << "Address of var[" << i << "] = ";
		cout << ptr << endl;

		cout << "Value of var[" << i << "] = ";
		cout << *ptr << endl;

		// �ƶ�����һ��λ��
		ptr++;
	}
	return 0;
}
/*
output :
Address of var[0] = 0xbfa088b0
Value of var[0] = 10
Address of var[1] = 0xbfa088b4
Value of var[1] = 100
Address of var[2] = 0xbfa088b8
Value of var[2] = 200
*/
// �ݼ�ָ��
// example
#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
	int  var[MAX] = { 10, 100, 200 };
	int  *ptr;

	// ָ�������һ��Ԫ�صĵ�ַ
	ptr = &var[MAX - 1];
	for (int i = MAX; i > 0; i--)
	{
		cout << "Address of var[" << i << "] = ";
		cout << ptr << endl;

		cout << "Value of var[" << i << "] = ";
		cout << *ptr << endl;

		// �ƶ�����һ��λ��
		ptr--;
	}
	return 0;
}
/*
output :
Address of var[3] = 0xbfdb70f8
Value of var[3] = 200
Address of var[2] = 0xbfdb70f4
Value of var[2] = 100
Address of var[1] = 0xbfdb70f0
Value of var[1] = 10
*/
// ָ��Ƚ�
//ָ������ù�ϵ��������бȽϣ��� ==��< �� >��
//��� p1 �� p2 ָ��������صı�����ͬһ�������еĲ�ͬԪ�أ���ɶ� p1 �� p2 ���д�С�Ƚϡ�
// example
#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
	int  var[MAX] = { 10, 100, 200 };
	int  *ptr;

	// ָ���е�һ��Ԫ�صĵ�ַ
	ptr = var;
	int i = 0;
	while (ptr <= &var[MAX - 1])
	{
		cout << "Address of var[" << i << "] = ";
		cout << ptr << endl;

		cout << "Value of var[" << i << "] = ";
		cout << *ptr << endl;

		// ָ����һ��λ��
		ptr++;
		i++;
	}
	return 0;
}
/*
output:
Address of var[0] = 0xbfce42d0
Value of var[0] = 10
Address of var[1] = 0xbfce42d4
Value of var[1] = 100
Address of var[2] = 0xbfce42d8
Value of var[2] = 200
*/

// ָ��Ա�����
// ָ���������������صġ�ָ��������ںܶ�������ǿ��Ի����ġ�
//example
#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
	int  var[MAX] = { 10, 100, 200 };
	int  *ptr;

	// ָ���е������ַ
	ptr = var;
	for (int i = 0; i < MAX; i++)
	{
		cout << "var[" << i << "]���ڴ��ַΪ ";
		cout << ptr << endl;

		cout << "var[" << i << "] ��ֵΪ ";
		cout << *ptr << endl;

		// �ƶ�����һ��λ��
		ptr++;
	}
	return 0;
}
/*
output:
var[0]���ڴ��ַΪ 0x7fff59707adc
var[0] ��ֵΪ 10
var[1]���ڴ��ַΪ 0x7fff59707ae0
var[1] ��ֵΪ 100
var[2]���ڴ��ַΪ 0x7fff59707ae4
var[2] ��ֵΪ 200
*/
// ���ǣ�����ȫ��������������Ի���
// example
#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
	int  var[MAX] = { 10, 100, 200 };

	for (int i = 0; i < MAX; i++)
	{
		*var = i;    // ������ȷ���﷨
		var++;       // ���ǲ���ȷ��
	}
	return 0;
}
/*
��ָ������� * Ӧ�õ� var ������ȫ���Եģ����޸� var ��ֵ�ǷǷ��ġ�
��Ϊ var ��һ��ָ�����鿪ͷ�ĳ�����������Ϊ��ֵ��

����һ����������Ӧһ��ָ�볣����ֻҪ���ı������ֵ����Ȼ������ָ����ʽ�ı��ʽ��
*/

// ָ������
// example 
#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
	int  var[MAX] = { 10, 100, 200 };

	for (int i = 0; i < MAX; i++)
	{
		cout << "Value of var[" << i << "] = ";
		cout << var[i] << endl;
	}
	return 0;
}
/*
output:
Value of var[0] = 10
Value of var[1] = 100
Value of var[2] = 200
*/

// else:
// �� ptr ����Ϊһ�����飬�� MAX ������ָ�����,ptr �е�ÿ��Ԫ�أ�����һ��ָ�� int ֵ��ָ��
//example 
#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
	int  var[MAX] = { 10, 100, 200 };
	int *ptr[MAX];

	for (int i = 0; i < MAX; i++)
	{
		ptr[i] = &var[i]; // ��ֵΪ�����ĵ�ַ
	}
	for (int i = 0; i < MAX; i++)
	{
		cout << "Value of var[" << i << "] = ";
		cout << *ptr[i] << endl;
	}
	return 0;
}
/*
output:
Value of var[0] = 10
Value of var[1] = 100
Value of var[2] = 200
*/

// else:
// ����ָ���ַ���ָ���������洢һ���ַ����б�
#include <iostream>

using namespace std;
const int MAX = 4;

int main()
{
	const char *names[MAX] = {
					  "Zara Ali",
					  "Hina Ali",
					  "Nuha Ali",
	};

	for (int i = 0; i < MAX; i++)
	{
		cout << "Value of names[" << i << "] = ";
		cout << names[i] << endl;
	}
	return 0;
}
/*
output:
Value of names[0] = Zara Ali
Value of names[1] = Hina Ali
Value of names[2] = Nuha Ali
*/

// ָ��ָ���ָ�� --> �༶���Ѱַ
// ָ��ָ���ָ����һ�ֶ༶���Ѱַ����ʽ����һ��ָ����.
// һ��ָ�����һ�������ĵ�ַ�������Ƕ���һ��ָ��ָ���ָ��ʱ��
// ��һ��ָ������˵ڶ���ָ��ĵ�ַ���ڶ���ָ��ָ�����ʵ��ֵ��λ�á�
/*
pointer        pointer        variable
address   -->  address  -->   value
*/
// ��һ��Ŀ��ֵ��һ��ָ����ָ����һ��ָ��ʱ���������ֵ��Ҫʹ�������Ǻ������
#include <iostream>

using namespace std;

int main()
{
	int  var;
	int  *ptr;
	int  **pptr;

	var = 3000;

	// ��ȡ var �ĵ�ַ
	ptr = &var;

	// ʹ������� & ��ȡ ptr �ĵ�ַ
	pptr = &ptr;

	// ʹ�� pptr ��ȡֵ
	cout << "var ֵΪ :" << var << endl;
	cout << "*ptr ֵΪ:" << *ptr << endl;
	cout << "**pptr ֵΪ:" << **pptr << endl;

	return 0;
}
/*
output:
var ֵΪ :3000
*ptr ֵΪ:3000
**pptr ֵΪ:3000
*/

// example 2
#include <iostream>

using namespace std;

int main()
{
	int var;
	int *ptr;
	int **pptr;
	var = 3000;

	// ��ȡ var �ĵ�ַ
	ptr = &var;

	// ʹ������� & ��ȡ ptr �ĵ�ַ
	pptr = &ptr;

	// ʹ�� pptr ��ȡֵ
	cout << "var ֵΪ :" << var << endl;
	cout << "*ptr ֵΪ:" << *ptr << endl;
	cout << "**pptr ֵΪ:" << **pptr << endl;
	cout << "var ��ַΪ :" << &var << endl;
	cout << "ptr=&var ֵΪvar�ĵ�ַ:" << ptr << endl;
	cout << "ptr��ַΪ:" << &ptr << endl;
	cout << "*pptr=ptr=&var  ֵΪvar�ĵ�ַ:" << *pptr << endl;
	cout << "pptr ��ַΪ:" << &pptr << endl;
	return 0;
}
/*
output: �鿴 var��ptr��*pptr �ĵ�ַ,�ӽ�����Կ����� 3 ���ĵ�ַ����һ���ġ�
var ֵΪ :3000
*ptr ֵΪ:3000
**pptr ֵΪ:3000
var ��ַΪ :0x7ffeec7a65e8
ptr=&var ֵΪvar�ĵ�ַ:0x7ffeec7a65e8
ptr��ַΪ:0x7ffeec7a65e0
*pptr=ptr=&var  ֵΪvar�ĵ�ַ:0x7ffeec7a65e8
pptr ��ַΪ:0x7ffeec7a65d8
*/

// ָ�봫ֵ����
// C++ ������ָ���������ֻ��Ҫ�򵥵�������������Ϊָ�����ͼ��ɡ�

// example
#include <iostream>
#include <ctime>

using namespace std;
void getSeconds(unsigned long *par);

int main()
{
	unsigned long sec;


	getSeconds(&sec);

	// ���ʵ��ֵ
	cout << "Number of seconds :" << sec << endl;

	return 0;
}

void getSeconds(unsigned long *par)
{
	// ��ȡ��ǰ������
	*par = time(NULL);
	return;
}
// output : Number of seconds :1294450468

//�ܽ���ָ����Ϊ�����ĺ�����Ҳ�ܽ���������Ϊ������
// example
#include <iostream>
using namespace std;

// ��������
double getAverage(int *arr, int size);

int main()
{
	// ���� 5 ��Ԫ�ص���������
	int balance[5] = { 1000, 2, 3, 17, 50 };
	double avg;

	// ����һ��ָ�������ָ����Ϊ����
	avg = getAverage(balance, 5);

	// �������ֵ
	cout << "Average value is: " << avg << endl;

	return 0;
}

double getAverage(int *arr, int size)
{
	int    i, sum = 0;
	double avg;

	for (i = 0; i < size; ++i)
	{
		sum += arr[i];
	}

	avg = double(sum) / size;

	return avg;
}
// output : Average value is: 214.4

// ��������ָ�� 
// ��������ָ�� --> ������������ָ��ĺ���

// example:
int *myFunction()
{

}

// tips : C++ ��֧���ں����ⷵ�ؾֲ������ĵ�ַ�����Ƕ���ֲ�����Ϊ static ������
// example 
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Ҫ���ɺͷ���������ĺ���
int * getRandom()
{
	static int  r[10];

	// ��������
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		r[i] = rand();
		cout << r[i] << endl;
	}

	return r;
}

// Ҫ�������涨�庯����������
int main()
{
	// һ��ָ��������ָ��
	int *p;

	p = getRandom();
	for (int i = 0; i < 10; i++)
	{
		cout << "*(p + " << i << ") : ";
		cout << *(p + i) << endl;
	}

	return 0;
}
/*
output:
624723190
1468735695
807113585
976495677
613357504
1377296355
1530315259
1778906708
1820354158
667126415
*(p + 0) : 624723190
*(p + 1) : 1468735695
*(p + 2) : 807113585
*(p + 3) : 976495677
*(p + 4) : 613357504
*(p + 5) : 1377296355
*(p + 6) : 1530315259
*(p + 7) : 1778906708
*(p + 8) : 1820354158
*(p + 9) : 667126415
*/