// ���ݽṹ

// ����ṹ struct
struct type_name {
	member_type1 member_name1;
	member_type2 member_name2;
	member_type3 member_name3;	
} object_names;

// type_name �ǽṹ�����͵����ƣ�member_type1 member_name1 �Ǳ�׼�ı������壬
// ���� int i; ���� float f; ����������Ч�ı������塣
// example
struct Books
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
} book;

// Ϊ�˷��ʽṹ�ĳ�Ա������ʹ�ó�Ա�����������.������Ա����������ǽṹ�������ƺ�Ҫ���ʵĽṹ��Ա֮���һ����š�

// example  ���ʽṹ��Ա
#include <iostream>
#include <cstring>

using namespace std;

// ����һ���ṹ������ Books 
struct Books
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
};

int main()
{
	Books Book1;        // ����ṹ������ Books �ı��� Book1
	Books Book2;        // ����ṹ������ Books �ı��� Book2

	// Book1 ����
	strcpy(Book1.title, "C++ �̳�");
	strcpy(Book1.author, "Runoob");
	strcpy(Book1.subject, "�������");
	Book1.book_id = 12345;

	// Book2 ����
	strcpy(Book2.title, "CSS �̳�");
	strcpy(Book2.author, "Runoob");
	strcpy(Book2.subject, "ǰ�˼���");
	Book2.book_id = 12346;

	// ��� Book1 ��Ϣ
	cout << "��һ������� : " << Book1.title << endl;
	cout << "��һ�������� : " << Book1.author << endl;
	cout << "��һ������Ŀ : " << Book1.subject << endl;
	cout << "��һ���� ID : " << Book1.book_id << endl;

	// ��� Book2 ��Ϣ
	cout << "�ڶ�������� : " << Book2.title << endl;
	cout << "�ڶ��������� : " << Book2.author << endl;
	cout << "�ڶ�������Ŀ : " << Book2.subject << endl;
	cout << "�ڶ����� ID : " << Book2.book_id << endl;

	return 0;
}
/*
output:
��һ������� : C++ �̳�
��һ�������� : Runoob
��һ������Ŀ : �������
��һ���� ID : 12345
�ڶ�������� : CSS �̳�
�ڶ��������� : Runoob
�ڶ�������Ŀ : ǰ�˼���
�ڶ����� ID : 12346
*/

// example �ṹ��Ϊ��������
#include <iostream>
#include <cstring>

using namespace std;

void printBook(struct Books book);

// ����һ���ṹ������ Books 
struct Books
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
};

int main()
{
	Books Book1;        // ����ṹ������ Books �ı��� Book1
	Books Book2;        // ����ṹ������ Books �ı��� Book2

	 // Book1 ����
	strcpy(Book1.title, "C++ �̳�");
	strcpy(Book1.author, "Runoob");
	strcpy(Book1.subject, "�������");
	Book1.book_id = 12345;

	// Book2 ����
	strcpy(Book2.title, "CSS �̳�");
	strcpy(Book2.author, "Runoob");
	strcpy(Book2.subject, "ǰ�˼���");
	Book2.book_id = 12346;

	// ��� Book1 ��Ϣ
	printBook(Book1);

	// ��� Book2 ��Ϣ
	printBook(Book2);

	return 0;
}
void printBook(struct Books book)
{
	cout << "����� : " << book.title << endl;
	cout << "������ : " << book.author << endl;
	cout << "����Ŀ : " << book.subject << endl;
	cout << "�� ID : " << book.book_id << endl;
}
/*
output:
����� : C++ �̳�
������ : Runoob
����Ŀ : �������
�� ID : 12345
����� : CSS �̳�
������ : Runoob
����Ŀ : ǰ�˼���
�� ID : 12346
*/

// ָ��ṹ��ָ��
/*
����ָ��ṹ��ָ�룬��ʽ�붨��ָ���������ͱ�����ָ������
struct Books *struct_pointer;

Ϊ�˲��ҽṹ������ַ�����Խ� & ���ڽṹ������ǰ��
struct_pointer = &Book1

Ϊ��ʹ��ָ��ýṹ��ָ����ʽṹ�ĳ�Ա������ʹ�� -> �����
struct_pointer -> title
*/

// example �ṹָ��
#include <iostream>
#include <cstring>

using namespace std;
void printBook(struct Books *book);

struct Books
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
};

int main()
{
	Books Book1;        // ����ṹ������ Books �ı��� Book1
	Books Book2;        // ����ṹ������ Books �ı��� Book2

	 // Book1 ����
	strcpy(Book1.title, "C++ �̳�");
	strcpy(Book1.author, "Runoob");
	strcpy(Book1.subject, "�������");
	Book1.book_id = 12345;

	// Book2 ����
	strcpy(Book2.title, "CSS �̳�");
	strcpy(Book2.author, "Runoob");
	strcpy(Book2.subject, "ǰ�˼���");
	Book2.book_id = 12346;

	// ͨ���� Book1 �ĵ�ַ����� Book1 ��Ϣ
	printBook(&Book1);

	// ͨ���� Book2 �ĵ�ַ����� Book2 ��Ϣ
	printBook(&Book2);

	return 0;
}
// �ú����Խṹָ����Ϊ����
void printBook(struct Books *book)
{
	cout << "�����  : " << book->title << endl;
	cout << "������ : " << book->author << endl;
	cout << "����Ŀ : " << book->subject << endl;
	cout << "�� ID : " << book->book_id << endl;
}
/*
output :
�����  : C++ �̳�
������ : Runoob
����Ŀ : �������
�� ID : 12345
�����  : CSS �̳�
������ : Runoob
����Ŀ : ǰ�˼���
�� ID : 12346
*/

// typedef  keywords
typedef struct Books
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
}Books;

// ����ֱ��ʹ�� Books ������ Books ���͵ı�����������Ҫʹ�� struct �ؼ��֡�
Books Book1, Book2;

// ����ʹ�� typedef �ؼ���������ǽṹ����
typedef long int *pint32;

pint32 x, y, z;  // x, y �� z ����ָ������ long int ��ָ�롣

// ���õ����ݽṹ
// 1����̬����
#include <vector>  // ��̬����
using namespace std;
int main() 
{
	return 0;
}

// �������� vector
vector <T> vec; //������һ����Ϊ vec �Ĵ��� T �������ݵĶ�̬���顣
				//���� T ������Ҫ������������ͣ������� int��float��double ���������Զ�����������͵ȵȡ�
				//��ʼ��ʱ�� vec �ǿյġ�

// push_back()  ��������Ԫ��
#include <vector>
using namespace std;
int main() 
{
	vector<int> vec;  // []
	vec.push_back(1); // [1]
	vec.push_back(2); // [1, 2]
	vec.push_back(3); // [1, 2, 3]
	return 0;
}

// size() ������ȡ����  []����ֱ�ӷ���vector�е�Ԫ��
#include <vector>
#include <stdio.h>
using namespace std;
int main() 
{
	vector<int> vec;  // []
	vec.push_back(1); // [1]
	vec.push_back(2); // [1, 2]
	vec.push_back(3); // [1, 2, 3]
	for (int i = 0; i < vec.size(); ++i) 
	{
		printf("%d\n", vec[i]);
	}
	return 0;
}

// �޸�Ԫ�� �޸� vector ��ĳ��Ԫ�أ�ֻ��Ҫ�� = ������ֵ�ͺ��ˣ����� vec[1]=3��
#include <vector>
#include <stdio.h>
using namespace std;
int main() 
{
	vector<int> vec;  // []
	vec.push_back(1); // [1]
	vec.push_back(2); // [1, 2]
	vec.push_back(3); // [1, 2, 3]
	vec[1] = 3; // [1, 3, 3]
	vec[2] = 2; // [1, 3, 2]
	for (int i = 0; i < vec.size(); ++i) 
	{
		printf("%d\n", vec[i]);
	}
	return 0;
}

// ��� C++����� clear( ) �����Ϳ������ vector ��
// C++�� vector �� clear() ֻ����� vector ����������տ����ڴ档
// ��һ�ַ���������� vector ���ڴ档�ȶ���һ���յ� vector x��Ȼ������Ҫ��յ� vector �� x ��������Ϊ x �Ǿֲ�������
// ���Իᱻϵͳ�����ڴ棨ע�⣺������һ������ȥ������
vector<int> v;
{
	vector<int> x;
	v.swap(x);
}

// conclusion
/*

����	         ����
push_back	��ĩβ����һ��Ԫ��
pop_back	��ĩβ����һ��Ԫ��
size	       ��ȡ����
clear	         ���
*/

// ����
/*
��������ѧ�е�һ���������ͨ�׵ؽ�����������һЩ���ظ���������ɵġ�
���� { 1 , 2 , 3 } ����һ����1��2��3�ļ��ϡ�C++�ı�׼���еļ���֧�ָ�Ч�Ĳ��롢ɾ���ϲ�ѯ������
������������ʱ�临�Ӷȶ��� O(lgn)������n�ǵ�ǰ������Ԫ�صĸ�������������飬��Ȼ�����ʱ�临�Ӷ��� O(1)��
����ɾ���ϲ�ѯ���� O(n)����ʱЧ��̫�͡���C++�����ǳ��õļ�����set��
*/

// ���ÿ�
#include <set>

// ����һ������
set <T> s; // ������һ����Ϊs�ġ�����T�������ݵļ��ϣ�����T�Ǽ���Ҫ������������͡���ʼ��ʱ��s�ǿռ��ϡ�

// ����Ԫ��
//insert() �����򼯺��в���һ���µ�Ԫ�ء�
// tips :����������Ѿ�������ĳ��Ԫ�أ��ٴβ��벻������κ�Ч�����������ǲ�������ظ�Ԫ�صġ�
#include <set>
#include <string>
using namespace std;
int main() 
{
	set<string> country;  // {}
	country.insert("China"); // {"China"}
	country.insert("America"); // {"China", "America"}
	country.insert("France"); // {"China", "America", "France"}
	return 0;
}

// delete  ͨ�� erase( ) ����ɾ�������е�һ��Ԫ�أ���������в��������Ԫ�أ��������κβ�����
#include <set>
#include <string>
using namespace std;
int main() {
	set<string> country;  // {}
	country.insert("China"); // {"China"}
	country.insert("America"); // {"China", "America"}
	country.insert("France"); // {"China", "America", "France"}
	country.erase("America"); // {"China", "France"}
	country.erase("England"); // {"China", "France"}
	return 0;
}

// ����Ԫ��
// �� count( ) ��������������д�������Ҫ���ҵ�Ԫ�أ����� 1 �����򷵻� 0 ��
#include <set>
#include <string>
#include <stdio.h>
using namespace std;
int main() 
{
	set<string> country;  // {}
	country.insert("China"); // {"China"}
	country.insert("America"); // {"China", "America"}
	country.insert("France"); // {"China", "America", "France"}
	if (country.count("China")) 
	{
		printf("China belong to country");
	}
	return 0;
}

// ����Ԫ��
// ͨ�����������Է��ʼ����е�ÿ��Ԫ��
#include <set>
#include <string>
#include <iostream>
using namespace std;
int main() 
{
	set<string> country;  // {}
	country.insert("China"); // {"China"}
	country.insert("America"); // {"China", "America"}
	country.insert("France"); // {"China", "America", "France"}
	for (set<string>::iterator it = country.begin(); it != country.end(); ++it) 
	{
		cout << (*it) << endl;
	}
	return 0;
}

// ��� --> ���� clear() ����

/*
conclusion:

����	����
insert	����һ��Ԫ��
erase	ɾ��һ��Ԫ��
count	�ж�Ԫ���Ƿ���set��
size	��ȡԪ�صĸ���
clear	���

*/

// ӳ�� map
// ���ÿ�

#include <map>

// ����ӳ��
map<T1, T2> m; //������һ����Ϊ m �Ĵ� T1 ���͵� T2 ���͵�ӳ�䡣��ʼ��ʱ�� m �ǿ�ӳ�䡣

// ����ӳ��
// ͨ�� insert( ) �����򼯺��в���һ���µ�ӳ�䣬������һ�� pair ���͵Ľṹ��������Ҫ�õ�����һ�� STL ģ�� ���� Ԫ��(pair)��
pair<int, char>(1, 'a');
/*
������һ������ 1 ���ַ� a �� pair����ӳ���м�������ӳ��Ե�ʱ�����ͨ������ pair ��ʵ�ֵġ�
�������� key ֮ǰ�Ѿ����� value�������ò�����µ� value ���ԭ���� value��Ҳ���Ǵ˴β�������Ч�ġ�
*/
#include <map>
#include <string>
using namespace std;
int main() 
{
	map<string, int> dict;  // {}
	dict.insert(pair<string, int>("Tom", 1)); // {"Tom"->1}
	dict.insert(pair<string, int>("Jone", 2)); // {"Tom"->1, "Jone"->2}
	dict.insert(pair<string, int>("Mary", 1)); // {"Tom"->1, "Jone"->2, "Mary"->1}
	dict.insert(pair<string, int>("Tom", 2)); // {"Tom"->1, "Jone"->2, "Mary"->1}
	return 0;
}

// ����
/*

�� C++ �з���ӳ�������һ����ֱ���� [] ���ܷ��ʡ����� dict[��Tom��] �Ϳ��Ի�ȡ ��Tom�� �İ༶�ˡ�
���û�ж� ��Tom�� ����ӳ��Ļ�����ʱ����� dict[��Tom��] ��ϵͳ�����Զ�Ϊ ��Tom�� ����һ��ӳ�䣬�� value Ϊ��Ӧ���͵�Ĭ��ֵ��
�������ǿ���֮���ٸ�ӳ�丳���µ�ֵ������ dict[��Tom��] = 3 ������Ϊ�����ṩ����һ�ַ���Ĳ����ֶΡ�
��ϣ��ϵͳ�Զ�Ϊ��������ӳ�䣬��Ҫ��� ��Tom�� �Ƿ��Ѿ���ӳ���ˣ�����Ѿ���ӳ���ټ������ʡ���ʱ�����Ҫ�� count( ) ���������жϡ�

*/
#include <map>
#include <string>
#include <stdio.h>
using namespace std;
int main() 
{
	map<string, int> dict;  // {}
	dict["Tom"] = 1; // {"Tom"->1}
	dict["Jone"] = 2; // {"Tom"->1, "Jone"->2}
	dict["Mary"] = 1; // {"Tom"->1, "Jone"->2, "Mary"->1}
	printf("Mary is in class %d\n", dict["Mary"]);
	printf("Tom is in class %d\n", dict["Tom"]);
	return 0;
}

// ���ҹؼ���
//ĳ���ؼ����Ƿ�ӳ����������ֱ���� count( ) �����������ӳ��������� 1 �����򷵻� 0 ��
#include <map>
#include <string>
#include <stdio.h>
using namespace std;
int main() 
{
	map<string, int> dict;  // {}
	dict["Tom"] = 1; // {"Tom"->1}
	dict["Jone"] = 2; // {"Tom"->1, "Jone"->2}
	dict["Mary"] = 1; // {"Tom"->1, "Jone"->2, "Mary"->1}
	if (dict.count("Mary")) 
	{
		printf("Mary is in class %d\n", dict["Mary"]);
	}
	else
	{
		printf("Mary has no class");
	}
	return 0;
}

// ����ӳ��
// ͨ�����������Է���ӳ���е�ÿ��ӳ�䣬ÿ���������� first ֵ��Ӧ key��second ֵ��Ӧ value��
#include <map>
#include <string>
#include <iostream>
using namespace std;
int main() 
{
	map<string, int> dict;  // {}
	dict["Tom"] = 1; // {"Tom"->1}
	dict["Jone"] = 2; // {"Tom"->1, "Jone"->2}
	dict["Mary"] = 1; // {"Tom"->1, "Jone"->2, "Mary"->1}
	for (map<string, int>::iterator it = dict.begin(); it != dict.end(); ++it) 
	{
		cout << it->first << " is in class " << it->second << endl;
	}
	return 0;
}

// ���  --> ���� clear() ����

// conclusion
/*

����	����
insert	����һ��ӳ��
count	���ҹؼ���
erase	ɾ���ؼ���
size	��ȡӳ��Ը���
clear	���

*/