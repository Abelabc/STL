#include <iostream>
using namespace std;
#include <vector>
#include "stk.h"


stk GetStack(stk &stack)
{
    stk tmp(stack.getsize());
    return tmp;
}

int main()
{
    stk s;
    s = GetStack(s);
    stk ns=stk(s);
    for(int i=0; i<5; i++)
    s.push(i);
    cout<<s.top()<<endl;
    for(int i=0; i<6; i++)
    s.pop();
    return 0;
}