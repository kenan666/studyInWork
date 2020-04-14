//运算符
/*
+		把两个操作数相加						A + B 将得到 30
-		从第一个操作数中减去第二个操作数		A - B 将得到 -10
*		把两个操作数相乘						A * B 将得到 200
/		分子除以分母							B / A 将得到 2
%		取模运算符，整除后的余数				B % A 将得到 0
++		自增运算符，整数值增加 1				A++ 将得到 11
--		自减运算符，整数值减少 1				A-- 将得到 9
*/

// example1
#include <iostream>
using namespace std;

int main()
{
	int a = 21;
	int b = 10;
	int c;

	c = a + b;
	cout << "Line 1 - c 的值是 " << c << endl;
	c = a - b;
	cout << "Line 2 - c 的值是 " << c << endl;
	c = a * b;
	cout << "Line 3 - c 的值是 " << c << endl;
	c = a / b;
	cout << "Line 4 - c 的值是 " << c << endl;
	c = a % b;
	cout << "Line 5 - c 的值是 " << c << endl;

	int d = 10;   //  测试自增、自减
	c = d++;
	cout << "Line 6 - c 的值是 " << c << endl;

	d = 10;    // 重新赋值
	c = d--;
	cout << "Line 7 - c 的值是 " << c << endl;
	return 0;
}

//关系运算符
/*
==		检查两个操作数的值是否相等，如果相等则条件为真。				(A == B) 不为真。
!=		检查两个操作数的值是否相等，如果不相等则条件为真。				(A != B) 为真。
>		检查左操作数的值是否大于右操作数的值，如果是则条件为真。		(A > B) 不为真。
<		检查左操作数的值是否小于右操作数的值，如果是则条件为真。		(A < B) 为真。
>=		检查左操作数的值是否大于或等于右操作数的值，如果是则条件为真。	(A >= B) 不为真。
<=		检查左操作数的值是否小于或等于右操作数的值，如果是则条件为真。	(A <= B) 为真。
*/

//example
#include <iostream>
using namespace std;

int main()
{
	int a = 21;
	int b = 10;
	int c;

	if (a == b)
	{
		cout << "Line 1 - a 等于 b" << endl;
	}
	else
	{
		cout << "Line 1 - a 不等于 b" << endl;
	}
	if (a < b)
	{
		cout << "Line 2 - a 小于 b" << endl;
	}
	else
	{
		cout << "Line 2 - a 不小于 b" << endl;
	}
	if (a > b)
	{
		cout << "Line 3 - a 大于 b" << endl;
	}
	else
	{
		cout << "Line 3 - a 不大于 b" << endl;
	}
	/* 改变 a 和 b 的值 */
	a = 5;
	b = 20;
	if (a <= b)
	{
		cout << "Line 4 - a 小于或等于 b" << endl;
	}
	if (b >= a)
	{
		cout << "Line 5 - b 大于或等于 a" << endl;
	}
	return 0;
}

//逻辑运算符

/*
&&		称为逻辑与运算符。如果两个操作数都非零，则条件为真。								(A && B) 为假。
||		称为逻辑或运算符。如果两个操作数中有任意一个非零，则条件为真。						(A || B) 为真。
!		称为逻辑非运算符。用来逆转操作数的逻辑状态。如果条件为真则逻辑非运算符将使其为假。	!(A && B) 为真。
*/
#include <iostream>
using namespace std;

int main()
{
	int a = 5;
	int b = 20;
	int c;

	if (a && b)
	{
		cout << "Line 1 - 条件为真" << endl;
	}
	if (a || b)
	{
		cout << "Line 2 - 条件为真" << endl;
	}
	/* 改变 a 和 b 的值 */
	a = 0;
	b = 10;
	if (a && b)
	{
		cout << "Line 3 - 条件为真" << endl;
	}
	else
	{
		cout << "Line 4 - 条件不为真" << endl;
	}
	if (!(a && b))
	{
		cout << "Line 5 - 条件为真" << endl;
	}
	return 0;
}

// 其他运算符
/*
sizeof				sizeof 运算符返回变量的大小。例如，sizeof(a) 将返回 4，其中 a 是整数。
Condition ? X : Y	条件运算符。如果 Condition 为真 ? 则值为 X : 否则值为 Y。
,					逗号运算符会顺序执行一系列运算。整个逗号表达式的值是以逗号分隔的列表中的最后一个表达式的值。
.					（点）和 ->（箭头）	成员运算符用于引用类、结构和共用体的成员。
Cast				强制转换运算符把一种数据类型转换为另一种数据类型。例如，int(2.2000) 将返回 2。
&					指针运算符 & 返回变量的地址。例如 &a; 将给出变量的实际地址。
*					指针运算符 * 指向一个变量。例如，*var; 将指向变量 var。
*/

// 优先级

/*
后缀 				() [] -> . ++ - -  					从左到右 
一元 				+ - ! ~ ++ - - (type)* & sizeof 	从右到左 
乘除 				* / % 								从左到右 
加减 				+ - 								从左到右 
移位 				<< >> 								从左到右 
关系 				< <= > >= 							从左到右 
相等 				== != 								从左到右 
位与 AND 			& 									从左到右 
位异或 XOR 			^ 									从左到右 
位或 OR 			| 									从左到右 
逻辑与 AND			&& 									从左到右 
逻辑或 OR 			|| 									从左到右 
条件 				?: 									从右到左 
赋值 			= += -= *= /= %=>>= <<= &= ^= |= 		从右到左 
逗号 				, 									从左到右 
*/	
#include <iostream>
using namespace std;

int main()
{
	int a = 20;
	int b = 10;
	int c = 15;
	int d = 5;
	int e;

	e = (a + b) * c / d;      // ( 30 * 15 ) / 5
	cout << "(a + b) * c / d 的值是 " << e << endl;

	e = ((a + b) * c) / d;    // (30 * 15 ) / 5
	cout << "((a + b) * c) / d 的值是 " << e << endl;

	e = (a + b) * (c / d);   // (30) * (15/5)
	cout << "(a + b) * (c / d) 的值是 " << e << endl;

	e = a + (b * c) / d;     //  20 + (150/5)
	cout << "a + (b * c) / d 的值是 " << e << endl;

	return 0;
}