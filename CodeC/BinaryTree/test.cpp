#include <iostream>
#include <stack>
#include<vector>
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

    vector<int> vec;
    vector<int> vec2;
    cout<<vec.size();

    for (int i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }
    vec[3] = 0;
    for (int i = 0; i < 10; i++)
    {
        cout<<vec[i]<<endl;
    }
    
     
    system("pause");
    return 0;
}