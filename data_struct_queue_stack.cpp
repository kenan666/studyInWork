// ջ--> ��ջ  --��������ֻ������ջ��һ�ν��в����ɾ�����㡣��һ�˱���Ϊջ������Եأ�����һ�˳�Ϊջ�ס�

// ջ��ʵ��
// 1�����������ֶ�ʵ�֣���Ҫ�̶������С��Ҳ��������Ĵ�С��
int stack[maxsize], top = 0;
void push(int x) {
	stack[top++] = x;
}
void pop() {
	--top;
}
int topval() {
	return stack[top - 1];
}
int empty() {
	return top > 0;
}

// �� stack ��ʾ�洢ջ�Ŀռ䣬top ��ʾ��ջ����ָ��λ�ã�
// ���� push( ) ѹ��һ���� x ��ջ�������� pop( ) ��ջ������һ��Ԫ�أ����� topval( ) ��ȡջ��Ԫ�ء�

// example
#include <stack>
#include <iostream>
using namespace std;
stack<int> S;
int main() 
{
	S.push(1);
	S.push(10);
	S.push(7);
	while (!S.empty()) 
	{
		cout << S.top() << endl;
		S.pop();
	}
	return 0;
}

// ����
/*
���У�queue����һ�����Ե����ݽṹ����ջһ����һ�����������Ƶ����Ա�
������ֻ����ӱ��ǰ�ˣ�front������ɾ�����������ڱ�ĺ�ˣ�rear�����в��������
һ��������в����һ�����ǳ�Ϊ��β������ɾ����һ�˳�Ϊ���ס����еĲ�������ֽ���ӣ����е�ɾ�������ֽг��ӡ�
���԰Ѷ�������ɹ���ʱ�Ŷӽ��˵�ʱ��Ķ��飬���Ŷӵ��˻��Ƚ��ˣ����Ŷӵ��˻����ˣ����Ҳ������в�ӵ���Ϊ��
ֻ���ڶ����ĩβ�����Ŷӡ�����Ƕ��е��ص㣬�����Ƚ��ȳ���FIFO����First in First out�������ʡ�

              ����   <---    a1->a2->a3->...->an   <--- ���
			                front             rear

							���е���Ҫ����������
+ ��ӣ�push��
+ ���ӣ�pop��
+ �ж϶����Ƿ�Ϊ�գ�empty��
+ ͳ�ƶ���Ԫ�صĸ�����size��
+ ���ʶ�ͷԪ�أ�front��
+ ���ʶ�βԪ�أ�back��

*/

/*
���е�ʵ����ʹ��
���ڶ��к�ջ�������Ա����Զ���Ҳͬ������������ģ�����ֶ�ʵ�֡��������ڶ��еĳ��Ӻ�����ڲ�ͬ�����ˣ�����Ҫ����һ��ѭ�����еĸ��

������������������ģ�⣬��ô����Ԫ�س��ӵ�ʱ�����������ַ�������ʣ���Ԫ�أ���һ���Ǳ��ֶ��ף�front��λ�ò��䣬
�������е�Ԫ��˳����ǰ�ƶ�һλ���ڶ������ö��ף�front������ƶ�һλ������ÿ��Ԫ�ص�λ�ò��䣬Ҳ����ʹ���ڵ�λ�ó�Ϊ�µĶ���λ�á�

��һ�ַ�����Ҫ�ƶ����е�����Ԫ�أ�ʱ��Ч�ʷǳ��ͣ��ڶ���ֻ��Ҫ�ƶ���ͷ���÷ǳ��򵥣�
���ڶ��ֻᵼ��֮ǰ��ͷ���ڵ�λ���Ժ󲻻��ٱ��õ�����ɿռ���˷ѡ�ѭ�����оͽ����������⡣

��ʵ��ʹ�ö����У�Ϊ��ʹ���еĿռ����ظ�ʹ�ã�һ�����е�ͷ��front������β��rear��������������Ķ��пռ䣬
������ָ����е���ʼλ�ã��� MaxSize -1 ���� 1 ��� 0 ��

*/
// �ֶ�ʵ��
#define maxsize 10000
class queue 
{
	int q[maxsize];
	int front, rear, count;
	queue() 
	{
		front = 0;
		rear = 0;
		count = 0;
	}
	void push(int x) 
	{
		count++;
		if (count == maxsize) 
		{
			// ���
		}
		q[rear] = x;
		rear = (rear + 1) % maxsize;
	}
	int pop() 
	{
		count--;
		front = (front + 1) % maxsize;
		return q[front];
	}
	int front_val() 
	{
		return q[front];
	}
	bool empty() 
	{
		if (count == 0) 
		{
			return true;
		}
		return false;
	}
};

// ��������
/*
����	        C++
���	        push
����	        pop
���ʶ���Ԫ��	front
��С	        size
�Ƿ�Ϊ��	    empty
*/

#include <queue>
#include <iostream>
using namespace std;
int main() {
	queue<int> q; // ����һ��װ int �������ݵĶ���
	q.push(1); // ���
	q.push(2);
	q.push(3);
	cout << q.size() << endl; // �������Ԫ�ظ���
	while (!q.empty()) { // �ж϶����Ƿ�Ϊ��
		cout << q.front() << endl; // ���ʶ���Ԫ��
		q.pop(); // ����
	}
	return 0;
}

// ���ȶ���
/*
һЩ���ⲻ�ܰ��մ�ͳģʽ�Ƚ��ȳ���Ҫ���ȷ��ʼ���ߵ�Ԫ�أ���ʱ���Ͳ����˶����ȶ��е�˼����
�ڶ����У�Ԫ�شӶ�β���룬�Ӷ���ɾ������ȶ��У����ȶ������Ԫ�����������ȼ������ԣ����ȼ��ߵ�Ԫ���ȱ�ɾ����
*/
#include <queue>
#include <iostream>
using namespace std;
int main() {
	priority_queue<int> q; // ����һ��װ int �������ݵ����ȶ���
	q.push(1); // ���
	q.push(2);
	q.push(3);
	while (!q.empty()) { // �ж϶����Ƿ�Ϊ��
		cout << q.top() << endl; // ���ʶ�����Ԫ��
		q.pop(); // ����
	}
	return 0;
}
/*
���Ϊ
3
2
1
*/