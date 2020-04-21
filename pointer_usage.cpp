// pointer 指针
/*

指针是一个变量，其值为另一个变量的地址，即，内存位置的直接地址。
必须在使用指针存储其他变量地址之前，对其进行声明。

type *var-name;

example :
int    *ip;    // 一个整型的指针 /
double *dp;    // 一个 double 型的指针 /
float  *fp;    // 一个浮点型的指针 //
char   *ch;    // 一个字符型的指针 /

所有指针的值的实际数据类型，不管是整型、浮点型、字符型，还是其他的数据类型，都是一样的，
都是一个代表内存地址的长的十六进制数。不同数据类型的指针之间唯一的不同是，指针所指向的变量或常量的数据类型不同。

*/
// use pointer
//定义一个指针变量、把变量地址赋值给指针、访问指针变量中可用地址的值。
//通过使用一元运算符 * 来返回位于操作数所指定地址的变量的值。

#include <iostream>

using namespace std;

int main()
{
	int  var = 20;   // 实际变量的声明
	int  *ip;        // 指针变量的声明

	ip = &var;       // 在指针变量中存储 var 的地址

	cout << "Value of var variable: ";
	cout << var << endl;

	// 输出在指针变量中存储的地址
	cout << "Address stored in ip variable: ";
	cout << ip << endl;

	// 访问指针中地址的值
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
// 在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL
// 赋为 NULL 值的指针被称为空指针。赋为 NULL 值的指针被称为空指针。
// example:
#include <iostream>

using namespace std;

int main()
{
	int  *ptr = NULL;

	cout << "ptr 的值是 " << ptr;

	return 0;
}
// output : ptr 的值是 0
/*
tips:程序不允许访问地址为 0 的内存然而，内存地址 0 有特别重要的意义，
它表明该指针不指向一个可访问的内存位置。
如果指针包含空值（零值），则假定它不指向任何东西。
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

// 指针的算术运算
//指针是一个用数值表示的地址。可以对指针进行四种算术运算：++、--、+、-。 
//example : ptr++
/*
ptr 将指向位置 1004，因为 ptr 每增加一次，它都将指向下一个整数位置，
即当前位置往后移 4 个字节。这个运算会在不影响内存位置中实际值的情况下，
移动指针到下一个内存位置。如果 ptr 指向一个地址为 1000 的字符，
上面的运算会导致指针指向位置 1001，因为下一个字符位置是在 1001。
*/
// 递增一个指针
// 指针可以替代数组，变量指针可以递增，但是数组不能，数组是一个变量指针
#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
	int  var[MAX] = { 10, 100, 200 };
	int  *ptr;

	// 指针中的数组地址
	ptr = var;
	for (int i = 0; i < MAX; i++)
	{
		cout << "Address of var[" << i << "] = ";
		cout << ptr << endl;

		cout << "Value of var[" << i << "] = ";
		cout << *ptr << endl;

		// 移动到下一个位置
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
// 递减指针
// example
#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
	int  var[MAX] = { 10, 100, 200 };
	int  *ptr;

	// 指针中最后一个元素的地址
	ptr = &var[MAX - 1];
	for (int i = MAX; i > 0; i--)
	{
		cout << "Address of var[" << i << "] = ";
		cout << ptr << endl;

		cout << "Value of var[" << i << "] = ";
		cout << *ptr << endl;

		// 移动到下一个位置
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
// 指针比较
//指针可以用关系运算符进行比较，如 ==、< 、 >。
//如果 p1 和 p2 指向两个相关的变量，同一个数组中的不同元素，则可对 p1 和 p2 进行大小比较。
// example
#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
	int  var[MAX] = { 10, 100, 200 };
	int  *ptr;

	// 指针中第一个元素的地址
	ptr = var;
	int i = 0;
	while (ptr <= &var[MAX - 1])
	{
		cout << "Address of var[" << i << "] = ";
		cout << ptr << endl;

		cout << "Value of var[" << i << "] = ";
		cout << *ptr << endl;

		// 指向上一个位置
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

// 指针对比数组
// 指针和数组是密切相关的。指针和数组在很多情况下是可以互换的。
//example
#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
	int  var[MAX] = { 10, 100, 200 };
	int  *ptr;

	// 指针中的数组地址
	ptr = var;
	for (int i = 0; i < MAX; i++)
	{
		cout << "var[" << i << "]的内存地址为 ";
		cout << ptr << endl;

		cout << "var[" << i << "] 的值为 ";
		cout << *ptr << endl;

		// 移动到下一个位置
		ptr++;
	}
	return 0;
}
/*
output:
var[0]的内存地址为 0x7fff59707adc
var[0] 的值为 10
var[1]的内存地址为 0x7fff59707ae0
var[1] 的值为 100
var[2]的内存地址为 0x7fff59707ae4
var[2] 的值为 200
*/
// 但是，不完全是所有情况都可以互换
// example
#include <iostream>

using namespace std;
const int MAX = 3;

int main()
{
	int  var[MAX] = { 10, 100, 200 };

	for (int i = 0; i < MAX; i++)
	{
		*var = i;    // 这是正确的语法
		var++;       // 这是不正确的
	}
	return 0;
}
/*
把指针运算符 * 应用到 var 上是完全可以的，但修改 var 的值是非法的。
因为 var 是一个指向数组开头的常量，不能作为左值。

由于一个数组名对应一个指针常量，只要不改变数组的值，仍然可以用指针形式的表达式。
*/

// 指针数组
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
// 把 ptr 声明为一个数组，由 MAX 个整数指针组成,ptr 中的每个元素，都是一个指向 int 值的指针
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
		ptr[i] = &var[i]; // 赋值为整数的地址
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
// 利用指向字符的指针数组来存储一个字符串列表：
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

// 指向指针的指针 --> 多级间接寻址
// 指向指针的指针是一种多级间接寻址的形式，是一个指针链.
// 一个指针包含一个变量的地址。当我们定义一个指向指针的指针时，
// 第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的位置。
/*
pointer        pointer        variable
address   -->  address  -->   value
*/
// 当一个目标值被一个指针间接指向到另一个指针时，访问这个值需要使用两个星号运算符
#include <iostream>

using namespace std;

int main()
{
	int  var;
	int  *ptr;
	int  **pptr;

	var = 3000;

	// 获取 var 的地址
	ptr = &var;

	// 使用运算符 & 获取 ptr 的地址
	pptr = &ptr;

	// 使用 pptr 获取值
	cout << "var 值为 :" << var << endl;
	cout << "*ptr 值为:" << *ptr << endl;
	cout << "**pptr 值为:" << **pptr << endl;

	return 0;
}
/*
output:
var 值为 :3000
*ptr 值为:3000
**pptr 值为:3000
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

	// 获取 var 的地址
	ptr = &var;

	// 使用运算符 & 获取 ptr 的地址
	pptr = &ptr;

	// 使用 pptr 获取值
	cout << "var 值为 :" << var << endl;
	cout << "*ptr 值为:" << *ptr << endl;
	cout << "**pptr 值为:" << **pptr << endl;
	cout << "var 地址为 :" << &var << endl;
	cout << "ptr=&var 值为var的地址:" << ptr << endl;
	cout << "ptr地址为:" << &ptr << endl;
	cout << "*pptr=ptr=&var  值为var的地址:" << *pptr << endl;
	cout << "pptr 地址为:" << &pptr << endl;
	return 0;
}
/*
output: 查看 var，ptr，*pptr 的地址,从结果可以看出这 3 个的地址都是一样的。
var 值为 :3000
*ptr 值为:3000
**pptr 值为:3000
var 地址为 :0x7ffeec7a65e8
ptr=&var 值为var的地址:0x7ffeec7a65e8
ptr地址为:0x7ffeec7a65e0
*pptr=ptr=&var  值为var的地址:0x7ffeec7a65e8
pptr 地址为:0x7ffeec7a65d8
*/

// 指针传值函数
// C++ 允许传递指针给函数，只需要简单地声明函数参数为指针类型即可。

// example
#include <iostream>
#include <ctime>

using namespace std;
void getSeconds(unsigned long *par);

int main()
{
	unsigned long sec;


	getSeconds(&sec);

	// 输出实际值
	cout << "Number of seconds :" << sec << endl;

	return 0;
}

void getSeconds(unsigned long *par)
{
	// 获取当前的秒数
	*par = time(NULL);
	return;
}
// output : Number of seconds :1294450468

//能接受指针作为参数的函数，也能接受数组作为参数，
// example
#include <iostream>
using namespace std;

// 函数声明
double getAverage(int *arr, int size);

int main()
{
	// 带有 5 个元素的整型数组
	int balance[5] = { 1000, 2, 3, 17, 50 };
	double avg;

	// 传递一个指向数组的指针作为参数
	avg = getAverage(balance, 5);

	// 输出返回值
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

// 函数返回指针 
// 函数返回指针 --> 必须声明返回指针的函数

// example:
int *myFunction()
{

}

// tips : C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
// example 
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// 要生成和返回随机数的函数
int * getRandom()
{
	static int  r[10];

	// 设置种子
	srand((unsigned)time(NULL));
	for (int i = 0; i < 10; ++i)
	{
		r[i] = rand();
		cout << r[i] << endl;
	}

	return r;
}

// 要调用上面定义函数的主函数
int main()
{
	// 一个指向整数的指针
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