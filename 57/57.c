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

//插入元素
template <typename T> void CStack<T>::push(const T& element)
{
    if(queue1.size()>0)//如果queue1不为空则往queue1中插入元素
        queue1.push(element);
    else if(queue2.size()>0)//如果queue2不为空则往queue2中插入元素
        queue2.push(element);
    else//如果两个队列都为空，则往queue1中插入元素
        queue1.push(element);
        
}

//删除元素
template <typename T> T CStack<T>::pop()
{
    //如果queue1为空
    if(queue1.size()==0)
    {
        //保证queue2中有一个元素，将其余元素保存到queue1中
        while(queue2.size()>1)
        {
            queue1.push(queue2.front());
            queue2.pop();
        }
        T& data=queue2.front();
        queue2.pop();
        return data;
    }
    //如果queue2为空
    else
    {
        //保证queue2中有一个元素，将其余元素保存到queue1中
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

//构造函数
template <typename T> CQueue<T>::CQueue(void)
{
}

//析构函数
template <typename T> CQueue<T>::~CQueue(void)
{
}

//插入元素
template <typename T> void CQueue<T>::appendtail(const T& node)
{
    stack1.push(node);
}

//删除元素并返回
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
