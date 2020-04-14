/*
auto��c++����������ԵĹؼ��֡������������

��1����������ʱ���ݳ�ʼ�����ʽ�Զ��ƶϸñ���������

��2����������ʱ��������ֵ��ռλ��

auto��������������ʱ���ݱ�����ʼֵ�������Զ�Ϊ�˱���ѡ��ƥ������͡�

����������ֵx=1���ȿ��������� int x=1 �� long x=1��Ҳ����ֱ������ auto x=1
*/

/*
usage:

auto f = 3.14;  //double
auto s("hello");  //const char*
auto z = new auto(9);  //int *
auto x1 = 5, x2 = 5.0, x3 = 'r';   //���󣬱����ǳ�ʼ��Ϊͬһ����
�������ּ򵥵��������ͣ�����ֱ��д����������ʹ��auto

auto�ؼ��ָ������������߳����ӡ�����ʹ�÷�Χרһʱ��ʹ����������׶����磺
std::vector<int> vect;
for(auto it = vect.begin(); it != vect.end(); ++it)
{  //it��������std::vector<int>::iterator
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

// ���Ա�����������ʱ���鷳���ұ�����������ʱ�Ĵ��󡣵���auto���ܽ�����еľ������⡣���磺
#include <iostream>  
using namespace std;
int main()
{
	unsigned int a = 4294967295;//����unsigned intֵ  
	unsigned int b = 1;
	auto c = a + b;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;
}
/*
��������У�����Աϣ��ͨ����������cΪauto���ܽ��a+b��������⡣
��ʵ��������a+b���ص���Ȼ��unsigned int��ֵ������c��������Ȼ���Ƶ�Ϊunsigned int��
auto�����ܰ���æ���������̬��������������hi�Զ�������չ�����Ի��ǲ�һ���ġ�
*/

// TIPS:
/*
��1��������valatile��pointer��*����reference��&����rvalue reference��&&�� ������auto

	auto k = 5;
	auto* pK = new auto(k);
	auto** ppK = new auto(&k);
	const auto n = 6;

��2����auto�����ı��������ʼ��

��3��auto���������������������

��4��������ģ��������ܱ�����Ϊauto

��5�������ڶ��ϵı�����ʹ����auto�ı��ʽ���뱻��ʼ��

	int* p = new auto(0); //fine
	int* pp = new auto(); // should be initialized
	auto x = new auto(); // Hmmm ... no intializer
	auto* y = new auto(9); // Fine. Here y is a int*
	auto z = new auto(9); //Fine. Here z is a int* (It is not just an int)


��6����Ϊauto��һ��ռλ����������һ�����Լ������ͣ���˲�����������ת��������һЩ��������sizeof��typeid

��7��������һ��auto���еı�������ʼ���Ƶ���ͬһ����

	auto x1 = 5, x2 = 5.0, x3='r';  /<span style="font-family: Arial, Helvetica, sans-serif;">/���󣬱����ǳ�ʼ��Ϊͬһ����</span>

��8��auto�����Զ��Ƶ���CV-qualifiers (constant & volatile qualifiers)

��9��auto���˻���ָ�������ָ�룬���Ǳ�����Ϊ����

*/