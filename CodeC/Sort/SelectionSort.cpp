#include <iostream>
#include <vector>
#include "MeasureAlgoTime.hpp"
using namespace std;

//! 选择排序：从未排序序列中，找出最大的那个元素，与未排序序列的末尾元素交换，
//! 不断执行上述步骤（n-1轮），末尾最大元素形成有序序列（挑最小的也可以，看需求是升序还是降序）
//! 相比冒泡排序，选择排序无法在内循环过程中，通过比较确定前面是否已经形成有序序列，因此我认为难以优化
//! 堆排序
//! 最好最坏平均时间复杂度：O（n2）   空间复杂度：O（1）  属于稳定排序

void vectorPrint(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

void selectionSort(vector<int> &array)
{                                                    //外循环控制未排序序列末尾指针，以及重置最大值索引，以及调换最大值与末尾元素
    for (int end = array.size() - 1; end > 0; end--) // end记录当前未排序序列的末尾
    {
        int maxNumIndex = 0;
        for (int i = 1; i <= end; i++)
        { //注意这里：选择排序：每次内循环取出最大值（初始值为数组第一个元素）与后面每一位元素比较，若找到更大的，则更新最大值所在索引
            if (array[maxNumIndex] <= array[i])
            {
                maxNumIndex = i;
            }
        } //内循环结束，记录当前未排序序列的最大值的索引
        cout << "找到最大值：" << array[maxNumIndex] << " "
             << "与" << array[end] << "交换" << endl;
             
        int temp = array[maxNumIndex]; //调换未排序序列的最大值元素与末尾元素位置
        array[maxNumIndex] = array[end];
        array[end] = temp;
        vectorPrint(array);
    }
}

int main()
{
    Tools::Time::AlgoTimeUs time1;
    Tools::Time::AlgoTimeUs time2;
    Tools::Time::AlgoTimeUs time3;

    vector<int> array;
    array = {6, 9, 3, 1, 2, 0, 8, 29, 15, 11, 10};
    vector<int> array2 = array;
    vector<int> array3 = array;

    time1.start();
    vectorPrint(array);
    cout << "选择排序基础版" << endl;
    selectionSort(array);
    cout << "算法用时：（微秒）";
    time1.printElapsed();
    cout << ' ' << endl;

    return 0;
}