// 栈--> 堆栈  --其限制是只允许在栈的一段进行插入和删除运算。这一端被称为栈顶，相对地，把另一端称为栈底。

// 栈的实现
// 1、利用数组手动实现，需要固定缓存大小，也就是数组的大小。
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

// 用 stack 表示存储栈的空间，top 表示当栈顶的指针位置，
// 方法 push( ) 压入一个数 x 到栈顶，方法 pop( ) 从栈顶弹出一个元素，方法 topval( ) 获取栈顶元素。

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

// 队列
/*
队列（queue）是一种线性的数据结构，和栈一样是一种运算受限制的线性表。
其限制只允许从表的前端（front）进行删除操作，而在表的后端（rear）进行插入操作。
一般允许进行插入的一端我们称为队尾，允许删除的一端称为队首。队列的插入操作又叫入队，队列的删除操作又叫出队。
可以把队列想像成购物时排队结账的时候的队伍，先排队的人会先结账，后排队的人会后结账，并且不允许有插队的行为，
只能在队伍的末尾进行排队。这就是队列的特点，具有先进先出（FIFO——First in First out）的性质。

              出队   <---    a1->a2->a3->...->an   <--- 入队
			                front             rear

							队列的主要操作包括：
+ 入队（push）
+ 出队（pop）
+ 判断队列是否为空（empty）
+ 统计队列元素的个数（size）
+ 访问队头元素（front）
+ 访问队尾元素（back）

*/

/*
队列的实现与使用
由于队列和栈都是线性表，所以队列也同样可以用数组模拟来手动实现。但是由于队列的出队和入队在不同的两端，所以要引入一个循环队列的概念。

如果单纯地用数组进行模拟，那么当有元素出队的时候，我们有两种方法处理剩余的元素：第一种是保持队首（front）位置不变，
其余所有的元素顺序往前移动一位；第二种是让队首（front）向后移动一位，其余每个元素的位置不变，也就是使现在的位置称为新的队首位置。

第一种方法需要移动队列的所有元素，时间效率非常低，第二种只需要移动队头则变得非常简单，
但第二种会导致之前队头所在的位置以后不会再被用到，造成空间的浪费。循环队列就解决了这个问题。

在实际使用队列中，为了使队列的空间能重复使用，一旦队列的头（front）或者尾（rear）超出了所分配的队列空间，
则让它指向队列的起始位置，从 MaxSize -1 增加 1 变成 0 。

*/
// 手动实现
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
			// 溢出
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

// 基本操作
/*
操作	        C++
入队	        push
出队	        pop
访问队首元素	front
大小	        size
是否为空	    empty
*/

#include <queue>
#include <iostream>
using namespace std;
int main() {
	queue<int> q; // 声明一个装 int 类型数据的队列
	q.push(1); // 入队
	q.push(2);
	q.push(3);
	cout << q.size() << endl; // 输出队列元素个数
	while (!q.empty()) { // 判断队列是否为空
		cout << q.front() << endl; // 访问队首元素
		q.pop(); // 出队
	}
	return 0;
}

// 优先队列
/*
一些问题不能按照传统模式先进先出，要优先访问级别高的元素，这时，就产生了对优先队列的思考。
在队列中，元素从队尾进入，从队首删除。相比队列，优先队列里的元素增加了优先级的属性，优先级高的元素先被删除。
*/
#include <queue>
#include <iostream>
using namespace std;
int main() {
	priority_queue<int> q; // 声明一个装 int 类型数据的优先队列
	q.push(1); // 入队
	q.push(2);
	q.push(3);
	while (!q.empty()) { // 判断队列是否为空
		cout << q.top() << endl; // 访问队列首元素
		q.pop(); // 出队
	}
	return 0;
}
/*
输出为
3
2
1
*/