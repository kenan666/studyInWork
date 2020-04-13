// ���Ա�ʵ��ջ
#include<iostream>  
#include<cstdio>  

using namespace std;

typedef struct Stacknode//������ʽջ�Ľṹ��  
{
	int data;//������  
	Stacknode *next;//��һ�ڵ��ָ����  
}Stacknode, *Stack;

//��ʼ��һ����ʽջ������һ����ʽջ��ͷ�ڵ㣩  
Stack InitStack()
{
	Stack stack = (Stack)malloc(sizeof(Stacknode));
	stack->next = NULL;
	return stack;
}

//��ջ  
void Push(Stack stack, int newData)
{
	//�ж��Ƿ�Ϊ��  
	if (stack == NULL)
	{
		printf("ջδ��ʼ�������ʼ���Ժ���ʹ��\n");
		return;
	}
	//�ҵ����һ���ڵ�  
	Stacknode *lastnode = stack;
	while (lastnode->next)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = (Stacknode*)malloc(sizeof(Stacknode*));
	lastnode->next->data = newData;
	lastnode->next->next = NULL;
	printf("��ջ�ɹ���\n");	
}

//��ջ  
int Pop(Stack stack)
{
	//�ж�ջ�Ƿ�Ϊ��  
	if (!stack->next)
	{
		printf("ջΪ�գ��޷���ջ\n");		
		return -1;//-1ֻ��һ���Զ���Ĵ������  
	}
	//�ҵ����һ���ڵ��Ǯһ���ڵ�  
	//tempNode:���һ���ڵ��ǰһ���ڵ�  
	Stacknode *tempNode = stack;
	while (tempNode->next->next)
	{
		tempNode = tempNode->next;
	}
	int data = tempNode->next->data;
	free(tempNode->next);
	tempNode->next = NULL;
	return data;
}

int main()
{
	Stack stack = InitStack();
	Push(stack, 3);//3��ջ  
	Push(stack, 4);//4��ջ  
	Push(stack, 5);//5��ջ  
	printf("%d\n", Pop(stack));
	printf("%d\n", Pop(stack));
	printf("%d\n", Pop(stack));
	printf("%d\n", Pop(stack));//��4�γ�ջ��Ӧ�ó���  
	return 0;
}
