//
// Created by flux_user on 2023/11/29.
//
#include <iostream>
using namespace std;
#ifndef UNTITLED_STK_H
#define UNTITLED_STK_H


class stk {
public:
    //构造函数
    stk(int size =0) : msize(size),mtop(0)
    {
        cout<<"stk(int)"<<endl;
        mpstack = new int[size];
    }
    //析构函数
    ~stk()
    {
        cout<<"~stk()"<<endl;
        delete []mpstack;
        mpstack=nullptr;
    }


    //拷贝构造
    stk(const stk &src):msize(src.msize), mtop(src.mtop)
    {
        cout << "Stack(const Stack&)" << endl;
        mpstack=new int[src.msize];
        for (int i = 0; i < mtop; ++i) {
            mpstack[i] = src.mpstack[i];
        }
    }
    //赋值重载
    stk& operator=(const stk &src)
    {
        cout<<"operator="<<endl;

        cout<<this<<" "<<&src<<endl;
        if(this==&src)
            return *this;
        delete []mpstack;

        msize=src.msize;
        mtop=src.mtop;
        mpstack=new int[msize];
        for(int i=0; i<msize; i++){
            mpstack[i]=src.mpstack[i];
        }
        return *this;
    }
    int getsize() const
    {
        return msize;
    }
    void push(int x){
        cout<<"push "<<x<<endl;
        mpstack[msize]=x;
        msize++;
        mtop=x;
    }
    void pop(){
        if (msize==0) {
            cout<<"error"<<endl;
            return;
        }
        cout<<"pop"<<msize<<endl;
        msize--;
        mtop=mpstack[msize];
    }
    [[nodiscard]] int top() const{
        return mtop;
    }

private:
    int *mpstack;//数组指针
    int mtop;//栈顶
    int msize;//尺寸
};


#endif //UNTITLED_STK_H
