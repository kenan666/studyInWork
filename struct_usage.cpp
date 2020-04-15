// usage

/*
声明结构体的方式和声明类的方式大致相同，其区别如下：
	使用关键字 struct 而不是关键字 class。
	尽管结构体可以包含成员函数，但它们很少这样做。所以，通常情况下结构体声明只会声明成员变量。
	结构体声明通常不包括 public 或 private 的访问修饰符。
	类成员默认情况是私有的，而结构体的成员则默认为 public。程序员通常希望它们保持公开，只需使用默认值即可。

*/
// example
/*
以下是一个结构体声明的示例，该结构体将 5 个变量绑定在一起，保存了员工的工资单数据。这个特殊结构体的名称是 PayRoll。
它以大写字母开头，这和类名使用大写字母开头的约定一样。另外还要注意，与类声明一样，在结构体声明的大括号后面必须有一个分号。

struct PayRoll
{
	int empNumber;
	string name;
	double hours, payRate, grossPay;
};

定义 PayRoll 结构体的变量和定义其他任何变量的方式并无二致，首先列出数据类型，然后是变量名称。以下定义语句创建了 PayRoll 结构体的 3 个变量：
PayRoll deptHead, foreman, associate;

*/
// init struct
/*
init struct
声明
struct Date
{
	int day,month , year;
}

定义、初始化 Date的方式：先指定变量名，后接赋值运算符和初始化列表
Date birthday = {23,8,1983};
or
Date birthday = {23,8};

but 不允许跳过变量初始化，如：Date birthday = {23,1983};-->非法

or
//非法结构体声明
struct Date
{
	int day = 23,
	month = 8,
	year = 1983;
}；
*/

// 访问结构体成员
/*
结构体成员的访问方式与类的公共成员一样，都是使用点运算符。但是，类的数据成员通常是私有的，必须通过函数访问。
因为结构数据成员是公共的，所以它们可以被直接访问，并且可以像常规变量一样使用。以下语句即可为前面创建的每个 PayRoll 变量的 empNumber 成员赋值：

deptHead.empNumber = 475;
foreman.empNumber = 897;
associate.empNumber = 729;

output:
cout << deptHead.empNumber << endl;
cout << deptHead.name << endl;
cout << deptHead.hours << endl;
cout << deptHead.payRate << endl;
cout << deptHead.grossPay << endl;
*/
//example

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct PayRoll
{
	int    empNumber; // Employee number
	string name;    // Employee name
	double hours,    // Hours worked
		payRate; // Hourly pay rate
};
int main()
{
	PayRoll employee; // Employee is a PayRoll structure
	double grossPay; // Gross amount the employee earned this week
	cout << "Enter the employee1s number:";
	cin >> employee.empNumber;
	cout << "Enter the employee's name: ";
	cin.ignore();// Skip the '\n' character left in the input buffer
	getline(cin, employee.name);
	cout << "Hours worked this week: ";
	cin >> employee.hours;
	cout << "Employee's hourly pay rate: ";
	cin >> employee.payRate;

	// Calculate the employee's gross pay
	grossPay = employee.hours * employee.payRate;
	// Display the results
	cout << "\nHere is the employee1s payroll data:\n";
	cout << "Name:    " << employee.name << endl;
	cout << "Employee number: " << employee.empNumber << endl;
	cout << "Hours worked:    " << employee.hours << endl;
	cout << "Hourly pay rate: " << employee.payRate << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "Gross pay: $" << grossPay << endl;
	return 0;
}

// 嵌套结构体
/*
一个类的对象可以嵌套在另一个类中一样，一个结构体的实例也可以嵌套在另一个结构体中。例如，
struct Costs
{
	double wholesale;
	double retail;
};
struct Item
{
	string partNum;
	string description;
	Costs pricing;
};Costs 结构体有两个 double 类型成员，wholesale 和 retail。
Item 结构体有 3 个成员，前 2 个是 partNum 和 description，它们都是 string 对象。第 3 个是 pricing，它是一个嵌套的 Costs 结构体。
widget  
{
	partNum
	description
	pricing 
	{
		wholesale
		retail
	}
}

访问方式-->
widget.partNum
widget.description
* widget.pricing.wholesale
  widget.pricing.retail

wholesale 和 retail 不是 widget 的成员，pricing 才是。
要访问 wholesale 和 retail，必须首先访问 widget 的定价 pricing，然后由于它是一个 Costs 结构体，所以同样可以使用点运算符访问其 wholesale 和 retail 成员。

还要注意，对于所有结构体来说，访问成员时必须使用成员名称，而不是结构体名称。例如，以下语句不合法：
cout << widget.retail;    // 错误
cout << widget.Costs.wholesale;    // 错误

*/
// example
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct CostInfo
{
	double food, // Food costs
		medical, // Medical costs
		license, // License fee
		misc; // Miscellaneous costs
};
struct PetInfo
{
	string name; // Pet name
	string type; // Pet type
	int age; // Pet age
	CostInfo cost;

	PetInfo() // Default constructor
	{
		name = "unknown";
		type = "unknown";
		age = 0;
		cost.food = cost.medical = cost.license = cost.misc = 0.00;
	}
};
int main()
{
	PetInfo pet;
	pet.name = "Sassy";
	pet.type = "cat";
	pet.age = 5;
	pet.cost.food = 300.00;
	pet.cost.medical = 200.00;
	pet.cost.license = 7.00;
	cout << fixed << showpoint << setprecision(2);
	cout << "Annual costs for my " << pet.age << "—year—old " << pet.type << " " << pet.name << " are $" << (pet.cost.food + pet.cost.medical + pet.cost.license + pet.cost.misc) << endl;
	return 0;
}

// 结构体传值给函数
/*
与类对象一样，结构体变量也可以通过值、引用和常量引用传递给函数。默认情况下，它们通过值传递，这意味着需要生成整个原始结构的副本并传递给函数。
因为不希望浪费时间来复制整个结构体，所以，除非结构很小，否则一般会通过引用将结构体传递给函数。
但是，这样意味着函数可以访问原始结构的成员变量，从而可能更改它们。如果不想让函数更改任何成员变量值，那么可以考虑将结构体变量作为一个常量引用传递给函数。
*/
//example
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Invltem// Holds data for an inventory item
{
	int partNum; // Part number
	string description; // Item description
	int onHand; // Units on hand
	double price; // Unit price
};

// Function prototypes
void getltemData(InvItem &);

void showItem(const InvItem &);

void getItemData(InvItem & item)
{
	cout << "Enter the part number: ";
	cin >> item.partNum;
	cout << "Enter the part description: ";
	cin.get();
	getline(cin, item.description);
	cout << "Enter the quantity on hand: ";
	cin >> item.onHand;
	cout << "Enter the unit price: ";
	cin >> item.price;
}
void showItem(const InvItem &item)
{
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Part Number : " << item.partNum << endl;
	cout << "Description : " << item.description << endl;
	cout << "Units On Hand : " << item.onHand << endl;
	cout << "Price    : $" << item.price << endl;
}

int main()
{
	InvItem part; // Define an Invltem structure variable.
	getItemData(part);
	showItem(part);
	return 0;
}

// 函数返回结构体
/*
也可以从函数返回结构体变量。在这种情况下，函数的返回类型是结构体的名称。
可以改写程序 1 以允许 getItemData 函数创建 Invltem 结构体的局部实例，将数据值放入其成员变量中，然后将其传递回 main，而不是将其作为引用变量从 main 接收。
*/
//修改后的 getltemData 函数的样子：
void getItemData()
{
	InvItem item;
	cout << "Enter the part number:";
	cin >> item.partNum;
	cout << "Enter the part description: ";
	cin.get();
	getline(cin, item.description);
	cout << "Enter the quantity on hand: ";
	cin >> item.onHand;
	cout << "Enter the unit price: ";
	cin >> item.price;
	return item;
}

// main 函数调用
part = getItemData();

// ** C++ 只允许从函数返回单个值。然而，结构体提供了解决这一限制的方法。
//即使一个结构体可能有几个成员，它在技术上还是一个单一的对象。通过在结构体中打包多个值，可以从函数返回任意数量的值。 