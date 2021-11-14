#include <iostream>
#include <vector>
#include "MeasureAlgoTime.hpp"
using namespace std;

void vectorPrint(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

//想象插入排序就是两只手，一只手里的牌是有序的，一只是无序的，每次把无序的手里的牌的第一张，与有序的比较，插入有序牌堆的合适位置
//插入排序的时间复杂度： 与数组中的逆序对有关 ，逆序对：比如想要递增的数组【0，8，9，1】这里【8，1】【9，1】都是逆序对
//最坏时间复杂度：O（n2）（输入数组完全逆序），最好时间复杂度O（n）（输入数组已经有序），平均时间复杂度O（n2），空间复杂度O（1）,原地稳定排序算法
//排序算法在逆序对特别少的数组中效率很高，甚至可能比O（nlogn）级别的堆排序和快速排序还快

void insertionSort1th(vector<int> &array) //这里以数组左侧作为有序的那一边
{
    // chaosBeginIndex：未排序序列的起始元素下标
    // insertEIndex：拿去插入有序序列的那个元素的下标，就是未排序序列的起始元素，但随着交换位置，下标会改变
    for (int chaosBeginIndex = 1; chaosBeginIndex < array.size(); chaosBeginIndex++)
    //外循环控制从第二个元素开始插入到有序序列里，直到最后一个元素
    {
        for (int insertEIndex = chaosBeginIndex; insertEIndex > 0; insertEIndex--)
        //内循环控制从未排序序列的首元素开始，逐渐与有序序列元素比较和交换位置，找到有序序列中的合适位置
        {
            if (array[insertEIndex] < array[insertEIndex - 1])
            {
                int temp = array[insertEIndex];
                array[insertEIndex] = array[insertEIndex - 1];
                array[insertEIndex - 1] = temp;
            }
            else
            {
                break;
            }
        }
        vectorPrint(array);
    }
}

void insertionSort1thRe(vector<int> &array) //这里以数组右侧作为有序的那一边
{
    for (int chaosBeginIndex = array.size() - 1 - 1; chaosBeginIndex >= 0; chaosBeginIndex--)
    {
        for (int insertEIndex = chaosBeginIndex; insertEIndex < array.size() - 1; insertEIndex++)
        {
            if (array[insertEIndex] > array[insertEIndex + 1])
            {
                int temp = array[insertEIndex];
                array[insertEIndex] = array[insertEIndex + 1];
                array[insertEIndex + 1] = temp;
            }
            else
            {
                break;
            }
        }
        vectorPrint(array);
    }
}

//插入排序的第一次优化，就是把不断的交换位置，改成了找到位置后插入数组，数组元素后移覆盖
//就是把左边比我大的元素都要跟我交换，换成了左边比我大的元素都要往右移
void insertionSort2nd(vector<int> &array) //这里以数组左侧作为有序的那一边
{
    for (int chaosBeginIndex = 1; chaosBeginIndex < array.size(); chaosBeginIndex++)
    {
        int insertENum = array[chaosBeginIndex]; //记录插入元素的元素内容，因为后面原本位置会被覆盖
        int rightEIndex = chaosBeginIndex;       //记录正确的插入位置，初始值就是被插入元素的原本位置（未排序序列的第一个元素位置）

        while (rightEIndex > 0) //不断比较插入元素与有序队列元素，找到合适插入位置，用rightEIndex记录
        {
            if (insertENum < array[rightEIndex - 1])
            {
                array[rightEIndex] = array[rightEIndex - 1]; //妙啊，找合适位置的同时就顺便把元素后移了
                rightEIndex = rightEIndex - 1;
            }
            else
            {
                break;
            }
        }

        array[rightEIndex] = insertENum; //插入到空出来的合适位置中

        vectorPrint(array);
    }
}

//整体思想是利用二分搜索的框架，修改结束条件，从找到或找不到某元素，变为寻找数组中第一个大于插入元素的元素
//具体修改: 插入元素小于mid，更新搜寻范围向左，插入元素大于等于mid，更新搜寻范围向右，直到begin=end说明找到插入位置
int binarySearchInsertionIndex(vector<int> array, int chaosBeginIndex)
{
    int begin = 0;
    int end = chaosBeginIndex;
    //!我们知道二分搜索法end的定义可以有两种，但是如果优化插入排序算法的话，我们这里的end只能定义为搜索数组的末尾元素的后一位
    while (begin != end)
    { //写begin<end也可，begin=end时已经找到插入位置
        int mid = (begin + end) / 2;
        if (array[chaosBeginIndex] < array[mid])
        {
            end = mid;
        }
        else if (array[chaosBeginIndex] >= array[mid])
        {
            begin = mid + 1;
        }
    }
    return begin;
    //如果前面end定义是数组末尾元素索引，会导致begin和end错过时才能确定插入位置，而且我们不知道begin和end哪个是正确的插入位
}

void insertionSort_BSEdition(vector<int> &array) //这里以数组左侧作为有序的那一边
{
    // chaosBeginIndex：未排序序列的起始元素下标
    for (int chaosBeginIndex = 1; chaosBeginIndex < array.size(); chaosBeginIndex++)
    //外循环控制从第二个元素开始插入到有序序列里，直到最后一个元素
    {
        int rightEIndex = binarySearchInsertionIndex(array, chaosBeginIndex); //二分搜索找到正确插入位置O（logn）
        int insertENum = array[chaosBeginIndex];                              //保留插入元素内容，因为后面要后移覆盖腾出插入的位置

        for (int i = chaosBeginIndex; i > rightEIndex; i--)
        {
            array[i] = array[i - 1];
        }

        array[rightEIndex] = insertENum;
        vectorPrint(array);
    }
}

int main()
{
    Tools::Time::AlgoTimeUs time1;
    Tools::Time::AlgoTimeUs time2;
    Tools::Time::AlgoTimeUs time3;
    Tools::Time::AlgoTimeUs time5;

    vector<int> array;
    array = {6, 9, 3, 1, 2, 0, 8, 29, 15, 11, 10};
    vector<int> array2 = array;
    vector<int> array3 = array;
    vector<int> array5 = array;

    cout << "输入数组：" << endl;
    vectorPrint(array);
    time1.start();
    cout << "插入排序基础版" << endl;
    insertionSort1th(array);
    cout << "算法用时：（微秒）";
    time1.printElapsed();

    cout << "输入数组：" << endl;
    vectorPrint(array2);
    time2.start();
    cout << "插入排序基础版（换一个方向）" << endl;
    insertionSort1thRe(array2);
    cout << "算法用时：（微秒）";
    time2.printElapsed();

    cout << "输入数组：" << endl;
    vectorPrint(array3);
    time3.start();
    cout << "插入排序第一次优化版" << endl;
    insertionSort2nd(array3);
    cout << "算法用时：（微秒）";
    time3.printElapsed();

    cout << "输入数组：" << endl;
    vectorPrint(array5);
    time5.start();
    cout << "插入排序二分搜索优化版" << endl;
    insertionSort_BSEdition(array5);
    cout << "算法用时：（微秒）";
    time5.printElapsed();

    cout << ' ' << endl;
    return 0;
}