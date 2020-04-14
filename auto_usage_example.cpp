/*
auto是c++程序设计语言的关键字。用于两种情况

（1）声明变量时根据初始化表达式自动推断该变量的类型

（2）声明函数时函数返回值的占位符

auto可以在声明变量时根据变量初始值的类型自动为此变量选择匹配的类型。

举例：对于值x=1；既可以声明： int x=1 或 long x=1，也可以直接声明 auto x=1
*/

/*
usage:

auto f = 3.14;  //double
auto s("hello");  //const char*
auto z = new auto(9);  //int *
auto x1 = 5, x2 = 5.0, x3 = 'r';   //错误，必须是初始化为同一类型
上述这种简单的数据类型，建议直接写出，不建议使用auto

auto关键字更适用于类型冗长复杂、变量使用范围专一时，使程序更清晰易读。如：
std::vector<int> vect;
for(auto it = vect.begin(); it != vect.end(); ++it)
{  //it的类型是std::vector<int>::iterator
	std::cin >> *it;
}

*/

// advantage,such as:

#include <string>  
#include <vector>  
void loopover(std::vector<std::string>&vs)
{
	std::vector<std::string>::iterator i = vs.begin();
	for (; i < vs.end(); i++)
	{

	}
}

//--->
#include <string>  
#include <vector>  
void loopover(std::vector<std::string>&vs)
{
	for (auto i = vs.begin();; i < vs.end(); i++)
	{

	}
}

// 可以避免类型声明时的麻烦而且避免类型声明时的错误。但是auto不能解决所有的精度问题。比如：
#include <iostream>  
using namespace std;
int main()
{
	unsigned int a = 4294967295;//最大的unsigned int值  
	unsigned int b = 1;
	auto c = a + b;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
/*
上面代码中，程序员希望通过声明变量c为auto就能解决a+b溢出的问题。
而实际上由于a+b返回的依然是unsigned int的值，姑且c的类型依然被推导为unsigned int，
auto并不能帮上忙。这个跟动态类型语言中数据hi自动进行拓展的特性还是不一样的。
*/

// TIPS:
/*
（1）可以用valatile，pointer（*），reference（&），rvalue reference（&&） 来修饰auto

	auto k = 5;
	auto* pK = new auto(k);
	auto** ppK = new auto(&k);
	const auto n = 6;

（2）用auto声明的变量必须初始化

（3）auto不能与其他类型组合连用

（4）函数和模板参数不能被声明为auto

（5）定义在堆上的变量，使用了auto的表达式必须被初始化

	int* p = new auto(0); //fine
	int* pp = new auto(); // should be initialized
	auto x = new auto(); // Hmmm ... no intializer
	auto* y = new auto(9); // Fine. Here y is a int*
	auto z = new auto(9); //Fine. Here z is a int* (It is not just an int)


（6）以为auto是一个占位符，并不是一个他自己的类型，因此不能用于类型转换或其他一些操作，如sizeof和typeid

（7）定义在一个auto序列的变量必须始终推导成同一类型

	auto x1 = 5, x2 = 5.0, x3='r';  /<span style="font-family: Arial, Helvetica, sans-serif;">/错误，必须是初始化为同一类型</span>

（8）auto不能自动推导成CV-qualifiers (constant & volatile qualifiers)

（9）auto会退化成指向数组的指针，除非被声明为引用

*/