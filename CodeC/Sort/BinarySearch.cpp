#include <iostream>
#include <vector>
#include "MeasureAlgoTime.hpp"
using namespace std;

//二分搜索法 ： 用于寻找有序数组中的某个元素的位置 ，平均时间复杂度O（logn）（每次砍一半），没有稳定性

void vectorPrint(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

//!二分搜索法可以有两种写法，主要区别体现在end的定义，以及找不到元素结束搜索的条件（begin与end的位置关系）上
//! 比如下面这个，end的定义是被搜索那一块数组最后元素的索引
void binarySearch(vector<int> &array, int element)
{
    int begin = 0;//begin代表的是，查找数组中的第一个元素的索引，初始为0
    int end = array.size()-1;//end此时代表的是查找数组的最后一位元素索引
    while (begin <= end)//当begin与end错过时，查找数组中不再有任何元素，搜索结束
    {
        int middle = (begin + end) / 2;
        if (array[middle] == element)
        {
            cout << "Search Success Index = " << middle << endl;
            return;
        }
        else if (element < array[middle])
        {
            end = middle -1;//更新end指针，指向新的搜索数组的末尾元素（不包括middle，所以要-1）
        }
        else if (element > array[middle])
        {
            begin = middle + 1;//更新begin指针，指向新的搜索数组的首元素（不包括middle，所以要+1）
        } 
    }
    cout<<"Element Not Find"<<endl;
    return;
}

//! 下面这个，end的定义是被搜索那一块数组最后元素的索引+1
void binarySearch1thRE(vector<int> &array, int element)
{
    int begin = 0;//begin代表的是，查找数组中的第一个元素的索引，初始为0
    int end = array.size();
    //!这里需要注意，二分搜索法里的end不是数组最后的索引啦，是查找数组的最后一位的索引+1，初始值等于数组长度，是为了什么？
    while (begin < end)//当begin与end相等时，查找数组中不再有任何元素，搜索结束，画个图就明白了
    {
        int middle = (begin + end) / 2;
        if (array[middle] == element)
        {
            cout << "Search Success Index = " << middle << endl;
            return;
        }
        else if (element < array[middle])
        {
            end = middle;//更新end指针，指向新的搜索数组的末尾元素的后一位（就是middle，所以不用-1）
        }
        else if (element > array[middle])
        {
            begin = middle + 1;
        } 
    }
    cout<<"Element Not Find"<<endl;
    return;
}


int main()
{
    Tools::Time::AlgoTimeUs time1;
    Tools::Time::AlgoTimeUs time2;
    Tools::Time::AlgoTimeUs time3;

    vector<int> array;
    array = {1,4,6,8,11,15,29,31};
    vector<int> array2 = array;
    vector<int> array3 = array;

    cout << "输入数组：" << endl;
    time1.start();
    vectorPrint(array);
    cout << "二分搜索基础版" << endl;
    binarySearch(array,19);
    cout << "算法用时：（微秒）";
    time1.printElapsed();
    cout << "搜索完成"<< endl;

    cout << "输入数组：" << endl;
    time2.start();
    vectorPrint(array2);
    cout << "二分搜索基础版" << endl;
    binarySearch1thRE(array2,29);
    cout << "算法用时：（微秒）";
    time1.printElapsed();
    cout << "搜索完成"<< endl;



    return 0;
}