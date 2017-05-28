
#include<iostream>
#include<stack>
#include<string>
#include<assert.h>
using namespace std;

template<class T>
class Stack
{
    public:
    	void Push(const T& x);
    	void Pop();
    	T& Min();
    	void PrintS();
    private:
    	stack<T> Sk;//���ջ������Ԫ�ص�
    	stack<T> MinSk;//���ջ����СԪ�ص�
};

template<class T>
void Stack<T>::Push(const T& x)
{
	Sk.push(x);
	//��MinSkΪ��ʱ���ȴ��һ��Ԫ�أ����Ƚ���ջԪ��С��ջ��Ԫ��ʱ����ջ
	if (MinSk.empty() || x < MinSk.top())
	{
		MinSk.push(x);
	}
}

template<class T>
void Stack<T>::Pop()
{
	if (Sk.empty())
	{
		cout << "stack is empty!" << endl;
		return;
	}
	//�����ջԪ�ص���MinSk��ջ��Ԫ�أ���MinSk��pop()��Ԫ�أ�ʹMinSkջ��ʼ�մ��Skջ����СԪ��
	if (Sk.top() == MinSk.top())
	{
		MinSk.pop();
	}
	Sk.pop();
}

template<class T>
T& Stack<T>::Min()
{
	assert(!MinSk.empty());
	return MinSk.top();
}

template<class T>
void Stack<T>::PrintS()
{
	if (Sk.empty())
	{
		cout << "stack is empty!" << endl;
		return;
	}

	stack<T> tmp = Sk;
	stack<T> mintmp = MinSk;
	cout << "stack: ";

	while (!tmp.empty())
	{
		cout << tmp.top() << " ";
		tmp.pop();
	}
	cout << "\nminstack: ";

	while (!mintmp.empty())
	{
		cout << mintmp.top() << " ";
		mintmp.pop();
	}
	cout << endl;
}

//��������
int main()
{
#if 1
	Stack<int> s1;
	s1.Push(9);
	s1.Push(5);
	s1.Push(7);
	s1.Push(3);
	s1.Push(8);
/*
	s1.Pop();
	s1.Pop();
	s1.Pop();
	s1.Pop();
*/
#endif
#if 0
	Stack<string> s1;
	s1.Push("sssss");
	s1.Push("syikl");
	s1.Push("yyyyy");
	s1.Push("fffff");
	s1.Push("lllll");
#endif
	s1.PrintS();
	cout << s1.Min() << endl;

    return 0;
}

