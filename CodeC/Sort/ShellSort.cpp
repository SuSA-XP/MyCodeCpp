#include <iostream>
#include <vector>
#include "MeasureAlgoTime.hpp"
using namespace std;

//希尔排序就是插入排序的一种优化，一句话概括其思想就是，把索引每相差n的元素视作一组，共有n组，对其进行插入排序，然后逐渐缩小n，
//反复进行如上分组并排序的操作，直至n=1，代表整个数组为一组进行插入排序

void vectorPrint(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

//产生步长序列（按照希尔本人的生成方式）
void stepSequenceGenerator(vector<int> array, vector<int> &stepSequence)
{
    for (int i = 2; i < array.size(); i = i * 2)
    {
        stepSequence.push_back(array.size() / i);
    }
}

void insertionSort1th(vector<int> &array, int begin, int end) //这里以数组左侧作为有序的那一边
{
    // chaosBeginIndex：未排序序列的起始元素下标
    // insertEIndex：拿去插入有序序列的那个元素的下标，就是未排序序列的起始元素，但随着交换位置，下标会改变
    for (int chaosBeginIndex = begin + 1; chaosBeginIndex <= end; chaosBeginIndex++)
    //外循环控制从第二个元素开始插入到有序序列里，直到最后一个元素
    {
        for (int insertEIndex = chaosBeginIndex; insertEIndex > begin; insertEIndex--)
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
    }
}

void sort(vector<int> &array, int stepSequence)
{
    vector<int> temp;
    for (int j = 0; j < stepSequence; j++)
    {
        int i = 0;
        for (int index = j; index < array.size(); index = index + stepSequence)
        {
            temp.push_back(array[index]);
            i = i + 1;
        }
        insertionSort1th(temp, temp.size() - i, temp.size() - 1);
        vectorPrint(temp);
    }
    array = temp;
}

//这个是正常写法
void sort2nd(vector<int> array, int stepSequence)
{
    //col：当前是第几组（列）
    for (int col = 0; col < stepSequence; col++)
    {
        //下面其实就是最简单的插入排序的代码，只不过是对同一组（列）里的元素的插入排序
        //请想象元素之间的距离变成stepSequence了，不是1了，而且组的第一个元素索引是col不是0了，第一个无序元素的位置就是col+stepSequence了
        for (int chaosBeginIndex = col + stepSequence; chaosBeginIndex < array.size(); chaosBeginIndex = chaosBeginIndex + stepSequence)
        {
            for (int insertEIndex = chaosBeginIndex; insertEIndex > col; insertEIndex = insertEIndex - stepSequence)
            {
                if (array[insertEIndex] < array[insertEIndex - stepSequence])
                {
                    int temp = array[insertEIndex];
                    array[insertEIndex] = array[insertEIndex - stepSequence];
                    array[insertEIndex - stepSequence] = temp;
                }
            }
        }
        vectorPrint(array);
    }
}

void shellSort(vector<int> &array)
{
    vector<int> stepSequence;
    stepSequenceGenerator(array, stepSequence);
    for (int i = 0; i < stepSequence.size(); i++)
    {
        cout << "(每隔几个元素就取出一个看作一组)(也就是列)步长为" << stepSequence[i] << endl;
        sort(array, stepSequence[i]);
    }
}

void shellSort2nd(vector<int> &array)
{
    vector<int> stepSequence;
    stepSequenceGenerator(array, stepSequence);
    for (int i = 0; i < stepSequence.size(); i++)
    {
        cout << "(每隔几个元素就取出一个看作一组)(也就是列)步长为" << stepSequence[i] << endl;
        sort2nd(array, stepSequence[i]);
    }
}

int main()
{
    Tools::Time::AlgoTimeUs time1;
    Tools::Time::AlgoTimeUs time2;
    Tools::Time::AlgoTimeUs time3;
    Tools::Time::AlgoTimeUs time5;

    vector<int> array;
    vector<int> gaps = {4, 2, 1};
    array = {29,15,12,10,9,8,7,6,5,3,2,1};
    vector<int> array2 = array;
    vector<int> array3 = array;

    cout << "输入数组：" << endl;
    vectorPrint(array);
    time1.start();
    cout << "希尔排序个人青春版" << endl;
    shellSort(array);
    cout << "算法用时：（微秒）";
    time1.printElapsed();

    cout << "输入数组：" << endl;
    vectorPrint(array2);
    time1.start();
    cout << "希尔排序正常版" << endl;
    shellSort2nd(array2);
    cout << "算法用时：（微秒）";
    time1.printElapsed();

    cout << ' ' << endl;
    return 0;
}