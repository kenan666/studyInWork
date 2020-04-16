// static
/*
ʹ�þ�̬��Ա������ʵ�ֶ�����������ݵ�Ŀ�ꡣ��̬��Ա������һ������ĳ�Ա�����������ؼ���static����
*/

class Student {
public:
	Student(char *name, int age, float score);
	void show();
public:
	static int m_total;  //��̬��Ա����
private:
	char *m_name;
	int m_age;
	float m_score;
};
/*
��̬��Ա���� m_total 
static ��Ա���������࣬������ĳ������Ķ��󣬼�ʹ�����������ҲֻΪ m_total ����һ���ڴ棬���ж���ʹ�õĶ�������ڴ��е����ݡ�
��ĳ�������޸��� m_total��Ҳ��Ӱ�쵽��������
*/

// static ��Ա�������������������ⲿ��ʼ��
type class::name = value;

// type �Ǳ��������ͣ�class ��������name �Ǳ�������value �ǳ�ʼֵ��

//������� m_total ��ʼ����
int Student::m_total = 0;

// ��̬��Ա�����ڳ�ʼ��ʱ�����ټ� static��������Ҫ���������͡��� private��protected��public ���εľ�̬��Ա���������������ַ�ʽ��ʼ����
// tips:ע�⣺static ��Ա�������ڴ�Ȳ�����������ʱ���䣬Ҳ�����ڴ�������ʱ���䣬�����ڣ����⣩��ʼ��ʱ���䡣������˵��û���������ʼ���� static ��Ա��������ʹ�á�

// static ��Ա�����ȿ���ͨ�����������ʣ�Ҳ����ͨ���������ʡ�
//ͨ��������� static ��Ա����
Student::m_total = 10;
//ͨ������������ static ��Ա����
Student stu("С��", 15, 92.5f);
stu.m_total = 20;
//ͨ������ָ�������� static ��Ա����
Student *pstu = new Student("�", 16, 96);
pstu->m_total = 20;

// tips :static ��Ա������ռ�ö�����ڴ棬���������ж���֮�⿪���ڴ棬��ʹ����������Ҳ���Է��ʡ�
//������˵��static ��Ա��������ͨ�� static �������ƣ������ڴ�����е�ȫ�������������ڴ棬

#include <iostream>

using namespace std;

class Student 
{
	public:
		Student(char *name, int age, float score);
		void show();
	private:
		static int m_total;  //��̬��Ա����
	private:
		char *m_name;
		int m_age;
		float m_score;
};
//��ʼ����̬��Ա����
int Student::m_total = 0;
Student::Student(char *name, int age, float score) : m_name(name), m_age(age), m_score(score) 
{
	m_total++;  //������̬��Ա����
}
void Student::show() 
{
	cout << m_name << "��������" << m_age << "���ɼ���" << m_score << "����ǰ����" << m_total << "��ѧ����" << endl;
}
int main() 
{
	//������������
	(new Student("С��", 15, 90))->show();
	(new Student("����", 16, 80))->show();
	(new Student("�Ż�", 16, 99))->show();
	(new Student("����", 14, 60))->show();
	return 0;
}