// 数据结构

// 定义结构 struct
struct type_name {
	member_type1 member_name1;
	member_type2 member_name2;
	member_type3 member_name3;	
} object_names;

// type_name 是结构体类型的名称，member_type1 member_name1 是标准的变量定义，
// 比如 int i; 或者 float f; 或者其他有效的变量定义。
// example
struct Books
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
} book;

// 为了访问结构的成员，我们使用成员访问运算符（.）。成员访问运算符是结构变量名称和要访问的结构成员之间的一个句号。

// example  访问结构成员
#include <iostream>
#include <cstring>

using namespace std;

// 声明一个结构体类型 Books 
struct Books
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
};

int main()
{
	Books Book1;        // 定义结构体类型 Books 的变量 Book1
	Books Book2;        // 定义结构体类型 Books 的变量 Book2

	// Book1 详述
	strcpy(Book1.title, "C++ 教程");
	strcpy(Book1.author, "Runoob");
	strcpy(Book1.subject, "编程语言");
	Book1.book_id = 12345;

	// Book2 详述
	strcpy(Book2.title, "CSS 教程");
	strcpy(Book2.author, "Runoob");
	strcpy(Book2.subject, "前端技术");
	Book2.book_id = 12346;

	// 输出 Book1 信息
	cout << "第一本书标题 : " << Book1.title << endl;
	cout << "第一本书作者 : " << Book1.author << endl;
	cout << "第一本书类目 : " << Book1.subject << endl;
	cout << "第一本书 ID : " << Book1.book_id << endl;

	// 输出 Book2 信息
	cout << "第二本书标题 : " << Book2.title << endl;
	cout << "第二本书作者 : " << Book2.author << endl;
	cout << "第二本书类目 : " << Book2.subject << endl;
	cout << "第二本书 ID : " << Book2.book_id << endl;

	return 0;
}
/*
output:
第一本书标题 : C++ 教程
第一本书作者 : Runoob
第一本书类目 : 编程语言
第一本书 ID : 12345
第二本书标题 : CSS 教程
第二本书作者 : Runoob
第二本书类目 : 前端技术
第二本书 ID : 12346
*/

// example 结构作为函数参数
#include <iostream>
#include <cstring>

using namespace std;

void printBook(struct Books book);

// 声明一个结构体类型 Books 
struct Books
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
};

int main()
{
	Books Book1;        // 定义结构体类型 Books 的变量 Book1
	Books Book2;        // 定义结构体类型 Books 的变量 Book2

	 // Book1 详述
	strcpy(Book1.title, "C++ 教程");
	strcpy(Book1.author, "Runoob");
	strcpy(Book1.subject, "编程语言");
	Book1.book_id = 12345;

	// Book2 详述
	strcpy(Book2.title, "CSS 教程");
	strcpy(Book2.author, "Runoob");
	strcpy(Book2.subject, "前端技术");
	Book2.book_id = 12346;

	// 输出 Book1 信息
	printBook(Book1);

	// 输出 Book2 信息
	printBook(Book2);

	return 0;
}
void printBook(struct Books book)
{
	cout << "书标题 : " << book.title << endl;
	cout << "书作者 : " << book.author << endl;
	cout << "书类目 : " << book.subject << endl;
	cout << "书 ID : " << book.book_id << endl;
}
/*
output:
书标题 : C++ 教程
书作者 : Runoob
书类目 : 编程语言
书 ID : 12345
书标题 : CSS 教程
书作者 : Runoob
书类目 : 前端技术
书 ID : 12346
*/

// 指向结构的指针
/*
定义指向结构的指针，方式与定义指向其他类型变量的指针类似
struct Books *struct_pointer;

为了查找结构变量地址，可以将 & 放在结构体名称前面
struct_pointer = &Book1

为了使用指向该结构的指针访问结构的成员，必须使用 -> 运算符
struct_pointer -> title
*/

// example 结构指针
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
	Books Book1;        // 定义结构体类型 Books 的变量 Book1
	Books Book2;        // 定义结构体类型 Books 的变量 Book2

	 // Book1 详述
	strcpy(Book1.title, "C++ 教程");
	strcpy(Book1.author, "Runoob");
	strcpy(Book1.subject, "编程语言");
	Book1.book_id = 12345;

	// Book2 详述
	strcpy(Book2.title, "CSS 教程");
	strcpy(Book2.author, "Runoob");
	strcpy(Book2.subject, "前端技术");
	Book2.book_id = 12346;

	// 通过传 Book1 的地址来输出 Book1 信息
	printBook(&Book1);

	// 通过传 Book2 的地址来输出 Book2 信息
	printBook(&Book2);

	return 0;
}
// 该函数以结构指针作为参数
void printBook(struct Books *book)
{
	cout << "书标题  : " << book->title << endl;
	cout << "书作者 : " << book->author << endl;
	cout << "书类目 : " << book->subject << endl;
	cout << "书 ID : " << book->book_id << endl;
}
/*
output :
书标题  : C++ 教程
书作者 : Runoob
书类目 : 编程语言
书 ID : 12345
书标题  : CSS 教程
书作者 : Runoob
书类目 : 前端技术
书 ID : 12346
*/

// typedef  keywords
typedef struct Books
{
	char  title[50];
	char  author[50];
	char  subject[100];
	int   book_id;
}Books;

// 可以直接使用 Books 来定义 Books 类型的变量，而不需要使用 struct 关键字。
Books Book1, Book2;

// 可以使用 typedef 关键字来定义非结构类型
typedef long int *pint32;

pint32 x, y, z;  // x, y 和 z 都是指向长整型 long int 的指针。

// 常用的数据结构
// 1、动态数组
#include <vector>  // 动态数组
using namespace std;
int main() 
{
	return 0;
}

// 构造数组 vector
vector <T> vec; //定义了一个名为 vec 的储存 T 类型数据的动态数组。
				//其中 T 是我们要储存的数据类型，可以是 int、float、double 或者其他自定义的数据类型等等。
				//初始的时候 vec 是空的。

// push_back()  最后面插入元素
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

// size() 方法获取长度  []可以直接访问vector中的元素
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

// 修改元素 修改 vector 中某个元素，只需要用 = 给它赋值就好了，比如 vec[1]=3。
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

// 清空 C++需调用 clear( ) 方法就可以清空 vector 。
// C++中 vector 的 clear() 只是清空 vector ，并不会清空开的内存。
// 用一种方法可以清空 vector 的内存。先定义一个空的 vector x，然后用需要清空的 vector 和 x 交换，因为 x 是局部变量，
// 所以会被系统回收内存（注意：大括号一定不能去掉）。
vector<int> v;
{
	vector<int> x;
	v.swap(x);
}

// conclusion
/*

方法	         功能
push_back	在末尾加入一个元素
pop_back	在末尾弹出一个元素
size	       获取长度
clear	         清空
*/

// 集合
/*
集合是数学中的一个基本概念，通俗地讲，集合是由一些不重复的数据组成的。
比如 { 1 , 2 , 3 } 就是一个有1，2，3的集合。C++的标准库中的集合支持高效的插入、删除合查询操作，
这三个操作的时间复杂度都是 O(lgn)，其中n是当前集合中元素的个数。如果用数组，虽然插入的时间复杂度是 O(1)，
但是删除合查询都是 O(n)，此时效率太低。在C++中我们常用的集合是set。
*/

// 引用库
#include <set>

// 构造一个集合
set <T> s; // 定义了一个名为s的、储存T类型数据的集合，其中T是集合要储存的数据类型。初始的时候s是空集合。

// 插入元素
//insert() 方法向集合中插入一个新的元素。
// tips :如果集合中已经存在了某个元素，再次插入不会产生任何效果，集合中是不会出现重复元素的。
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

// delete  通过 erase( ) 方法删除集合中的一个元素，如果集合中不存在这个元素，不进行任何操作。
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

// 查找元素
// 用 count( ) 方法。如果集合中存在我们要查找的元素，返回 1 ，否则返回 0 。
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

// 遍历元素
// 通过迭代器可以访问集合中的每个元素
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

// 清空 --> 调用 clear() 方法

/*
conclusion:

方法	功能
insert	插入一个元素
erase	删除一个元素
count	判断元素是否在set中
size	获取元素的个数
clear	清空

*/

// 映射 map
// 引用库

#include <map>

// 构造映射
map<T1, T2> m; //定义了一个名为 m 的从 T1 类型到 T2 类型的映射。初始的时候 m 是空映射。

// 插入映射
// 通过 insert( ) 方法向集合中插入一个新的映射，参数是一个 pair 类型的结构。这里需要用到另外一个 STL 模板 —— 元组(pair)。
pair<int, char>(1, 'a');
/*
定义了一个整数 1 合字符 a 的 pair。向映射中加入了新映射对的时候就是通过加入 pair 来实现的。
如果插入的 key 之前已经有了 value，不会用插入的新的 value 替代原来的 value，也就是此次插入是无效的。
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

// 访问
/*

在 C++ 中访问映射合数组一样，直接用 [] 就能访问。比如 dict[“Tom”] 就可以获取 “Tom” 的班级了。
如果没有对 “Tom” 做过映射的话，此时你访问 dict[“Tom”] ，系统将会自动为 “Tom” 生成一个映射，其 value 为对应类型的默认值。
并且我们可以之后再给映射赋予新的值，比如 dict[“Tom”] = 3 ，这样为我们提供了另一种方便的插入手段。
不希望系统自动为我们生成映射，需要检测 “Tom” 是否已经有映射了，如果已经有映射再继续访问。这时候就需要用 count( ) 函数进行判断。

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

// 查找关键字
//某个关键字是否被映射过，你可以直接用 count( ) 方法。如果被映射过，返回 1 ，否则返回 0 。
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

// 遍历映射
// 通过迭代器可以访问映射中的每个映射，每个迭代器的 first 值对应 key，second 值对应 value。
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

// 清空  --> 调用 clear() 函数

// conclusion
/*

方法	功能
insert	插入一对映射
count	查找关键字
erase	删除关键字
size	获取映射对个数
clear	清空

*/