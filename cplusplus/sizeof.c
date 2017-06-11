#include <iostream>
using namespace std;

struct st{
//    int a;

    st(){};
    ~st(){};
};

int main()
{
    cout << "the sizeof of the empty struct sizeof is:" << sizeof(st) <<endl;
}


