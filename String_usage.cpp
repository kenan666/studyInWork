// string usage 
// string ����ͷ�ļ� <string>
#include <iostream>
#include <string>  //  string ͷ�ļ�

using namespace std;

int main() {
	string s1;
	string s2 = "c plus plus";
	string s3 = s2;
	string s4(5, 's');
	return 0;
}
// output -->
/*
���� s1 ֻ�Ƕ��嵫û�г�ʼ�����������ὫĬ��ֵ���� s1��Ĭ��ֵ��""��Ҳ�����ַ�����

���� s2 �ڶ����ͬʱ����ʼ��Ϊ"c plus plus"����C�����ַ�����ͬ��string �Ľ�βû�н�����־'\0'��

���� s3 �ڶ����ʱ��ֱ���� s2 ���г�ʼ������� s3 ������Ҳ��"c plus plus"��

���� s4 ����ʼ��Ϊ�� 5 ��'s'�ַ���ɵ��ַ�����Ҳ����"sssss"��

--->
string ��������ֱ��ͨ����ֵ������=���и�ֵ��
string ����Ҳ������C�����ַ������и�ֵ�����磬s2 ����һ���ַ����������г�ʼ���ģ��� s3 ����ͨ�� s2 �������г�ʼ���ġ�
*/

/*
length() ����---> �ַ�������

string s = "http://c.biancheng.net";
int len = s.length();
cout<<len<<endl;

-->
������Ϊ22������ string ��ĩβû��'\0'�ַ������� length() ���ص����ַ�������ʵ���ȣ������ǳ��� +1��

*/

/*
C++ �ṩ�� string �������C�����е��ַ�����������ʵ�ʱ���У���ʱ�����Ҫʹ��C�����ַ�����������ļ�ʱ��·������
string ��Ϊ�����ṩ��һ��ת������ c_str()���ú����ܹ��� string �ַ���ת��ΪC�����ַ����������ظ��ַ����� const ָ�루const char*��

-->
string path = "D:\\demo.txt";
FILE *fp = fopen(path.c_str(), "rt");

Ϊ��ʹ��C�����е� fopen() �������ļ������뽫 string �ַ���ת��ΪC�����ַ�����

*/

// input  output
#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string s;
	cin >> s;  //�����ַ���
	cout << s << endl;  //����ַ���
	return 0;
}
// tips: ����input:http://c.biancheng.net
// output --> http://c.biancheng.net

// �ַ�������
// string �ַ���Ҳ������C�����ַ���һ�������±����������е�ÿһ���ַ���string �ַ�������ʼ�±����Ǵ� 0 ��ʼ
#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string s = "1234567890";
	for (int i = 0, len = s.length(); i < len; i++) 
	{
		cout << s[i] << " ";
	}
	cout << endl;
	s[5] = '5';
	cout << s << endl;
	return 0;
}
// output --> 1 2 3 4 5 6 7 8 9 0
// output --> 1234567890
// tips:������һ�� string ���� s������ֵ "1234567890"��֮���� for ѭ���������ÿһ���ַ���
// �����±꣬�����ܹ�����ÿ���ַ���Ҳ�����޸�ÿ���ַ���s[5] = '5';�ͽ���6���ַ��޸�Ϊ '5'������ s ���Ϊ "1234557890"��

// �ַ���ƴ��
/*
���� string �࣬���ǿ���ʹ��+��+=�������ֱ��ƴ���ַ������ǳ����㣬��Ҳ����Ҫʹ��C�����е� strcat()��strcpy()��malloc() �Ⱥ�����ƴ���ַ����ˣ�
��Ҳ���õ��Ŀռ䲻��������ˡ�

��+��ƴ���ַ���ʱ������������߿��Զ��� string �ַ�����Ҳ������һ�� string �ַ�����һ��C�����ַ�������������һ�� string �ַ�����һ���ַ����飬
������һ�� string �ַ�����һ���������ַ���
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1 = "first ";
	string s2 = "second ";
	char *s3 = "third ";
	char s4[] = "fourth ";
	char ch = '@';
	string s5 = s1 + s2;
	string s6 = s1 + s3;
	string s7 = s1 + s4;
	string s8 = s1 + ch;

	cout << s5 << endl << s6 << endl << s7 << endl << s8 << endl;
	return 0;
}
// output --> first second
// output --> first third
// output --> first four 
// output --> first @

//��ɾ�Ĳ�

//�����ַ���  insert() ���������� string �ַ�����ָ����λ�ò�����һ���ַ�����

string& insert(size_t pos, const string& str);  // pos ��ʾ�±�  str ��ʾ��Ҫ������ַ���

#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string s1, s2, s3;
	s1 = s2 = "1234567890";
	s3 = "aaa";
	s1.insert(5, s3);
	cout << s1 << endl;
	s2.insert(5, "bbb");
	cout << s2 << endl;
	return 0;
}
// output --> 12345aaa67890
// output --> 12345bbb67890

// delete
// erase() ��������ɾ�� string �е�һ�����ַ���
string& erase(size_t pos = 0, size_t len = npos); // pos ��ʾҪɾ�������ַ�������ʼ�±꣬len ��ʾҪɾ�����ַ����ĳ��ȡ�
												//�����ָ�� len �Ļ�����ôֱ��ɾ���� pos ���ַ����������������ַ�����ʱ len = str.length - pos��

#include <iostream>
#include <string>
using namespace std;
int main() 
{
	string s1, s2, s3;
	s1 = s2 = s3 = "1234567890";
	s2.erase(5);
	s3.erase(5, 3);
	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	return 0;
}
// output --> 1234567890
// output --> 12345
// output --> 1234590

/*
tips:
�� pos ����û��Խ�������£� len ����Ҳ���ܻᵼ��Ҫɾ�������ַ���Խ�硣��ʵ��������������ᷢ����
erase() ���������������ֵ��ȡ����С��һ����Ϊ��ɾ�����ַ����ĳ��ȣ�
	len ��ֵ��
	�ַ������ȼ�ȥ pos ��ֵ��

Ҳ����˵-->��ɾ���ַ������ֻ��ɾ�����ַ�����β
*/

// ��ȡ�ַ���
//  substr() �������ڴ� string �ַ�������ȡ���ַ���
string substr(size_t pos = 0, size_t len = npos) const; // pos ΪҪ��ȡ�����ַ�������ʼ�±꣬len ΪҪ��ȡ�����ַ����ĳ��ȡ�

#include <iostream>
#include <string>
using namespace std;
int main() 
{
	string s1 = "first second third";
	string s2;
	s2 = s1.substr(6, 6);
	cout << s1 << endl;
	cout << s2 << endl;
	return 0;
}
// output --> first second third
// output --> second 
/*
tips:
ϵͳ�� substr() �����Ĵ���� erase() ���ƣ�
	��� pos Խ�磬���׳��쳣��
	��� len Խ�磬����ȡ�� pos ���ַ�����β���������ַ���
*/

// �ַ�������
// find() ���� 
size_t find(const string& str, size_t pos = 0) const;
size_t find(const char* s, size_t pos = 0) const;
// tips: ��һ������Ϊ�����ҵ����ַ������������� string �ַ�����Ҳ������C�����ַ������ڶ�������Ϊ��ʼ���ҵ�λ�ã��±꣩�������ָ������ӵ�0���ַ���ʼ���ҡ�

#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string s1 = "first second third";
	string s2 = "second";
	int index = s1.find(s2, 5);
	if (index < s1.length())
		cout << "Found at index : " << index << endl;
	else
		cout << "Not found" << endl;
	return 0;
}
// output --> Found at index : 6
// find() �������շ��ص������ַ�����һ�γ������ַ����е���ʼ�±ꡣ�������������±�6���ҵ��� s2 �ַ��������û�в��ҵ����ַ�������ô�᷵��һ������ֵ

// rfind() ����
// rfind() �� find() �����ƣ�ͬ�������ַ����в������ַ�������ͬ���� find() �����ӵڶ���������ʼ������ң�
//�� rfind() �����������ҵ��ڶ�����������������˵ڶ���������ָ�����±껹û���ҵ����ַ������򷵻�һ������ֵ

#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string s1 = "first second third";
	string s2 = "second";
	int index = s1.rfind(s2, 6);
	if (index < s1.length())
		cout << "Found at index : " << index << endl;
	else
		cout << "Not found" << endl;
	return 0;
}
// output --> Found at index :6

//find_first_of() ����
// find_first_of() �������ڲ������ַ������ַ�����ͬ���е��ַ����ַ������״γ��ֵ�λ�á�
#include <iostream>
#include <string>

using namespace std;

int main() 
{
	string s1 = "first second second third";
	string s2 = "asecond";
	int index = s1.find_first_of(s2);
	if (index < s1.length())
		cout << "Found at index : " << index << endl;
	else
		cout << "Not found" << endl;
	return 0;
}
// output --> Found at index : 3   tips: s1 �� s2 ��ͬ���е��ַ��� ��s�������ַ��� s1 ���״γ��ֵ��±���3���ʲ��ҽ������3��