#include <iostream>
#include <stack>
using namespace std;

//��ɫ����ע��
//!��ɫ����ע��
//?��ɫ����ע��

int main()
{
    //����ջ��
    stack<char> stk;
    for (int i = 0; i < 10; i++)
    {
        stk.push(i);
    }
    for (int i = 0; i < 10; i++)
    {
        int j = stk.top();
        //?Ϊʲô��ֱ��int j = stk.pop������
        //!��ΪC++��ջ��pop����û�з���ֵ��java��Ļ��Զ����ر�pop��ջ��Ԫ��
        stk.pop();
        cout << j << endl;
    }
    cout << "oh my �Ǻ�" << endl;
    system("pause");
    return 0;
}
