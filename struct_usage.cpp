// usage

/*
�����ṹ��ķ�ʽ��������ķ�ʽ������ͬ�����������£�
	ʹ�ùؼ��� struct �����ǹؼ��� class��
	���ܽṹ����԰�����Ա�����������Ǻ��������������ԣ�ͨ������½ṹ������ֻ��������Ա������
	�ṹ������ͨ�������� public �� private �ķ������η���
	���ԱĬ�������˽�еģ����ṹ��ĳ�Ա��Ĭ��Ϊ public������Աͨ��ϣ�����Ǳ��ֹ�����ֻ��ʹ��Ĭ��ֵ���ɡ�

*/
// example
/*
������һ���ṹ��������ʾ�����ýṹ�彫 5 ����������һ�𣬱�����Ա���Ĺ��ʵ����ݡ��������ṹ��������� PayRoll��
���Դ�д��ĸ��ͷ���������ʹ�ô�д��ĸ��ͷ��Լ��һ�������⻹Ҫע�⣬��������һ�����ڽṹ�������Ĵ����ź��������һ���ֺš�

struct PayRoll
{
	int empNumber;
	string name;
	double hours, payRate, grossPay;
};

���� PayRoll �ṹ��ı����Ͷ��������κα����ķ�ʽ���޶��£������г��������ͣ�Ȼ���Ǳ������ơ����¶�����䴴���� PayRoll �ṹ��� 3 ��������
PayRoll deptHead, foreman, associate;

*/
// init struct
/*
init struct
����
struct Date
{
	int day,month , year;
}

���塢��ʼ�� Date�ķ�ʽ����ָ������������Ӹ�ֵ������ͳ�ʼ���б�
Date birthday = {23,8,1983};
or
Date birthday = {23,8};

but ����������������ʼ�����磺Date birthday = {23,1983};-->�Ƿ�

or
//�Ƿ��ṹ������
struct Date
{
	int day = 23,
	month = 8,
	year = 1983;
}��
*/

// ���ʽṹ���Ա
/*
�ṹ���Ա�ķ��ʷ�ʽ����Ĺ�����Աһ��������ʹ�õ�����������ǣ�������ݳ�Աͨ����˽�еģ�����ͨ���������ʡ�
��Ϊ�ṹ���ݳ�Ա�ǹ����ģ��������ǿ��Ա�ֱ�ӷ��ʣ����ҿ����񳣹����һ��ʹ�á�������伴��Ϊǰ�洴����ÿ�� PayRoll ������ empNumber ��Ա��ֵ��

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

// Ƕ�׽ṹ��
/*
һ����Ķ������Ƕ������һ������һ����һ���ṹ���ʵ��Ҳ����Ƕ������һ���ṹ���С����磬
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
};Costs �ṹ�������� double ���ͳ�Ա��wholesale �� retail��
Item �ṹ���� 3 ����Ա��ǰ 2 ���� partNum �� description�����Ƕ��� string ���󡣵� 3 ���� pricing������һ��Ƕ�׵� Costs �ṹ�塣
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

���ʷ�ʽ-->
widget.partNum
widget.description
* widget.pricing.wholesale
  widget.pricing.retail

wholesale �� retail ���� widget �ĳ�Ա��pricing ���ǡ�
Ҫ���� wholesale �� retail���������ȷ��� widget �Ķ��� pricing��Ȼ����������һ�� Costs �ṹ�壬����ͬ������ʹ�õ������������ wholesale �� retail ��Ա��

��Ҫע�⣬�������нṹ����˵�����ʳ�Աʱ����ʹ�ó�Ա���ƣ������ǽṹ�����ơ����磬������䲻�Ϸ���
cout << widget.retail;    // ����
cout << widget.Costs.wholesale;    // ����

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
	cout << "Annual costs for my " << pet.age << "��year��old " << pet.type << " " << pet.name << " are $" << (pet.cost.food + pet.cost.medical + pet.cost.license + pet.cost.misc) << endl;
	return 0;
}

// �ṹ�崫ֵ������
/*
�������һ�����ṹ�����Ҳ����ͨ��ֵ�����úͳ������ô��ݸ�������Ĭ������£�����ͨ��ֵ���ݣ�����ζ����Ҫ��������ԭʼ�ṹ�ĸ��������ݸ�������
��Ϊ��ϣ���˷�ʱ�������������ṹ�壬���ԣ����ǽṹ��С������һ���ͨ�����ý��ṹ�崫�ݸ�������
���ǣ�������ζ�ź������Է���ԭʼ�ṹ�ĳ�Ա�������Ӷ����ܸ������ǡ���������ú��������κγ�Ա����ֵ����ô���Կ��ǽ��ṹ�������Ϊһ���������ô��ݸ�������
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

// �������ؽṹ��
/*
Ҳ���ԴӺ������ؽṹ�����������������£������ķ��������ǽṹ������ơ�
���Ը�д���� 1 ������ getItemData �������� Invltem �ṹ��ľֲ�ʵ����������ֵ�������Ա�����У�Ȼ���䴫�ݻ� main�������ǽ�����Ϊ���ñ����� main ���ա�
*/
//�޸ĺ�� getltemData ���������ӣ�
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

// main ��������
part = getItemData();

// ** C++ ֻ����Ӻ������ص���ֵ��Ȼ�����ṹ���ṩ�˽����һ���Ƶķ�����
//��ʹһ���ṹ������м�����Ա�����ڼ����ϻ���һ����һ�Ķ���ͨ���ڽṹ���д�����ֵ�����ԴӺ�����������������ֵ�� 