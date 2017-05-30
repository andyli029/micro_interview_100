#if 0
#include<iostream>
#include<stdlib.h>
#include<stack>
#include<queue>
using namespace std;

template <typename T>class CStack
{
public:
    CStack(void){};
    ~CStack(void){};
    void push(const T& node);
    T pop();
private:
    queue<T> queue1;
    queue<T> queue2;
    
};

//����Ԫ��
template <typename T> void CStack<T>::push(const T& element)
{
    if(queue1.size()>0)//���queue1��Ϊ������queue1�в���Ԫ��
        queue1.push(element);
    else if(queue2.size()>0)//���queue2��Ϊ������queue2�в���Ԫ��
        queue2.push(element);
    else//����������ж�Ϊ�գ�����queue1�в���Ԫ��
        queue1.push(element);
        
}

//ɾ��Ԫ��
template <typename T> T CStack<T>::pop()
{
    //���queue1Ϊ��
    if(queue1.size()==0)
    {
        //��֤queue2����һ��Ԫ�أ�������Ԫ�ر��浽queue1��
        while(queue2.size()>1)
        {
            queue1.push(queue2.front());
            queue2.pop();
        }
        T& data=queue2.front();
        queue2.pop();
        return data;
    }
    //���queue2Ϊ��
    else
    {
        //��֤queue2����һ��Ԫ�أ�������Ԫ�ر��浽queue1��
        while(queue1.size()>1)
        {
            queue2.push(queue1.front());
            queue1.pop();
        }
        T& data=queue1.front();
        queue1.pop();
        return data;
    }

}


int main()
{
    CStack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);

    int len=4;

    while(len > 0)
    {
        cout<<stack.pop()<<" ";
        --len;
    }

    return 0;
    //system("pause");
}
#endif

#include<iostream>
#include<stdlib.h>
#include<stack>
#include <stdexcept>
#include <exception>  
#include <string>

using namespace std;

template <typename T>class CQueue
{
public:
    CQueue(void);
    ~CQueue(void);
    void appendtail(const T& node);
    T deleteHead();
private:
    stack<T> stack1;
    stack<T> stack2;

};

//���캯��
template <typename T> CQueue<T>::CQueue(void)
{
}

//��������
template <typename T> CQueue<T>::~CQueue(void)
{
}

//����Ԫ��
template <typename T> void CQueue<T>::appendtail(const T& node)
{
    stack1.push(node);
}

//ɾ��Ԫ�ز�����
template <typename T> T CQueue<T>::deleteHead()
{
    if(stack2.size()<=0)
    {
        while(stack1.size()>0)
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
    }

    if(stack2.size() == 0)
        //return 
        throw std::exception();//throw new exception("the queue is empty.");

    T head = stack2.top();
    stack2.pop();

    return head;
}

int main()
{
    CQueue<int> queue;
    queue.appendtail(1);
    queue.appendtail(2);
    queue.appendtail(3);
    queue.appendtail(4);
    int len=4;
    while(len>0)
    {
        try {
            cout<<queue.deleteHead()<<endl;
            --len;
        }
        catch (const std::exception& e) {
            e.what();
        }
    }

    return 0;
    //system("pause");
}
