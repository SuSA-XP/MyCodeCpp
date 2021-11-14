#include <iostream>
#include <stack>
#include "MeasureAlgoTime.hpp"
using namespace std;

//绿色高亮注释
//!红色高亮注释
//?橙色高亮注释

int main()
{
    Tools::Time::AlgoTimeUs time;
    //调用栈类
    time.start();
    stack<char> stk;
    for (int i = 0; i < 10; i++)
    {
        stk.push(i);
    }
    for (int i = 0; i < 10; i++)
    {
        int j = stk.top();
        //?为什么不直接int j = stk.pop（）？
        //!因为C++的栈的pop函数没有返回值，java里的会自动返回被pop的栈顶元素
        stk.pop();
        cout << j << endl;
    }
    cout << "oh my 呵呵" << endl;
    time.printElapsed();
    system("pause");
    return 0;
}
