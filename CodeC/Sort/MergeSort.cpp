#include <iostream>
#include <vector>
#include "MeasureAlgoTime.hpp"
using namespace std;

//
void vectorPrint(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

//merge函数就是将两个有序数组合并成一个有序数组，由于归并排序中，这两个数组都在一个数组内，所以这里参数begin是左数组的第一位，end是右数组的最后一位
//这里的begin，mid，end都代表的是数组下标
//merge的整体思想是，两个有序数组，两个指针分别指向首位，指针指向的二者进行比较，小的先放入新数组，同时插入的元素对应数组指针++，另一个不变，接着比
//还是画图比较好理解，但这个也不难
//时间复杂度O（nlogn），这个时间复杂度的分析方法很重要一定要掌握
void merge(vector<int> &array, int begin, int end)
{
    vector<int> temp = {};//定义临时数组，用于暂时存放合并并排序的有序数组，最后再覆盖给array
    int mid = (begin + end) / 2;
    //求mid，mid是左数组的终端，mid+1是右数组的起点，这和mergeSort函数中上面两个递归调用的begin与mid和end是一样的
    int tempPointer = 0;
    int leftBeginPointer = begin;//不要想当然以为左数组起点下标一定是0，这要看你传进来的是从哪开始的数组
    int rightBeginPointer = mid + 1;
    //这里定义了三个指针，分别指向临时数组的下一个插入位置(vector就不需要了，就是个摆设)，左数组的下一个插入元素，右数组的下一个插入元素
    while (tempPointer != end + 1)//当临时数组长度已经等于右数组末尾长度（左右数组长度和），说明都插入了，结束循环
    {
        if (array[leftBeginPointer] <= array[rightBeginPointer])
        {
            temp.push_back(array[leftBeginPointer]);
            tempPointer++;
            leftBeginPointer++;
        }
        else if (array[rightBeginPointer] < array[leftBeginPointer])
        {
            temp.push_back(array[rightBeginPointer]);
            tempPointer++;
            rightBeginPointer++;
        }
        //若检测一个数组已经全部插入，则直接把另一个数组剩余元素全部插入退出即可
        if (leftBeginPointer == mid + 1)
        {
            while (rightBeginPointer != end + 1)
            {
                temp.push_back(array[rightBeginPointer]);
                tempPointer++;
                rightBeginPointer++;
            }
            break;
        }
        else if (rightBeginPointer == end + 1)
        {
            while (leftBeginPointer != mid + 1)
            {
                temp.push_back(array[leftBeginPointer]);
                tempPointer++;
                leftBeginPointer++;
            }
            break;
        }
    }
    //用临时数组覆盖array对应位置的数组
    for (int i = 0; i < end - begin + 1; i++)
    {
        array[begin + i] = temp[i];
    }
}

void merge2nd(vector<int> &array, int begin, int end)
{
    vector<int> temp = {};//定义临时数组，用于暂时存放合并并排序的有序数组，最后再覆盖给array
    int mid = (begin + end) / 2;
    //求mid，mid是左数组的终端，mid+1是右数组的起点，这和mergeSort函数中上面两个递归调用的begin与mid和end是一样的
    int tempPointer = 0;
    int leftBeginPointer = begin;//不要想当然以为左数组起点下标一定是0，这要看你传进来的是从哪开始的数组
    int rightBeginPointer = mid + 1;
    //这里定义了三个指针，分别指向临时数组的下一个插入位置，左数组的下一个插入元素，右数组的下一个插入元素
    
    while(leftBeginPointer<mid+1&&rightBeginPointer<end+1){
        if (array[leftBeginPointer] <= array[rightBeginPointer])
        {
            temp.push_back(array[leftBeginPointer]);
            tempPointer++;
            leftBeginPointer++;
        }
        else if (array[rightBeginPointer] < array[leftBeginPointer])
        {
            temp.push_back(array[rightBeginPointer]);
            tempPointer++;
            rightBeginPointer++;
        }
    }
    while(leftBeginPointer<mid+1){
        temp.push_back(array[leftBeginPointer]);
        tempPointer++;
        leftBeginPointer++;
    }
    while(rightBeginPointer<end+1){
        temp.push_back(array[rightBeginPointer]);
        tempPointer++;
        rightBeginPointer++;
    }
    //用临时数组覆盖array对应位置的数组
    for (int i = 0; i < end - begin + 1; i++)
    {
        array[begin + i] = temp[i];
    }
}

void mergeSort(vector<int> &array, int begin, int end)
{
    //有点类似树的递归访问，每次调用都把当前数组一分为二，直到不可再分就return，然后merge成一个有序数组，再不断merge
    if (end - begin + 1 < 2)
    {
        return;
    }
    int mid = (begin + end) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid+1, end);
    merge(array, begin, end);
    vectorPrint(array);
}

void mergeSort2nd(vector<int> &array, int begin, int end)
{
    if (end - begin + 1 < 2)
    {
        return;
    }
    int mid = (begin + end) / 2;
    mergeSort2nd(array, begin, mid);
    mergeSort2nd(array, mid+1, end);
    merge2nd(array, begin, end);
    vectorPrint(array);
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

    cout << "输入数组：" << endl;
    vectorPrint(array);
    time1.start();
    cout << "归并排序基础版" << endl;
    mergeSort(array, 0, array.size() - 1);
    cout << "算法用时：（微秒）";
    time1.printElapsed();

    cout << "输入数组：" << endl;
    vectorPrint(array2);
    time1.start();
    cout << "归并排序归并换个写法" << endl;
    mergeSort(array2, 0, array2.size() - 1);
    cout << "算法用时：（微秒）";
    time1.printElapsed();
    return 0;
}