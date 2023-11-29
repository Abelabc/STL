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
    return 0;
}