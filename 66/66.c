// need to think
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void reverseStack2(stack<int> s, int n)
{
    if(n == 2)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();
        s.push(b);
        s.push(a);
    }
    else
    {
        int topData = s.top();
        s.pop();
        reverseStack2(s, n - 1);
        
    }

}
void addToStackBottom(stack<int>& s, int top)
{
    if(s.empty())
    {
        s.push(top);
    }
    else
    {
        int tmp = s.top();
        s.pop();
        //´íÎó£ºaddToStackBottom(s,tmp);
        addToStackBottom(s, top);
        s.push(tmp);
    }
}



void reverseStack(stack<int>& s)
{
    if(!s.empty())
    {
        int top = s.top();
        s.pop();
        reverseStack(s);
        addToStackBottom(s,top);
    }
}
int main()
{
    stack<int> s;

    for(int i = 1; i <= 5; i++)
        s.push(i);

    cout<<"the stack top ";
     
        for(int i = 5; i >= 1; i--)
            cout<<i<<ends;
         
     
    cout<<" the stack tail"<<endl;

    reverseStack(s);

    cout<<"the stack top ";

    while(!s.empty())
    {
        int top=s.top();
        s.pop();
        cout<<top<<ends;
    }
    cout<<" the stack tail"<<endl;

}