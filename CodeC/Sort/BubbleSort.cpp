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

void bubbleSort1th(vector<int> &array)
{
    int compareTimes = 0; //记录比较次数，为了体现三个算法的区别
    //这里需要特殊注意循环结束的条件
    //我的理解是外循环end值控制每次循环比较的次数，
    //联想第一次循环是从下标0开始与后一位比较，到下标[size -2]与下标[size -1]比较，所以总共是【size - 2 +1】次
    for (int end = array.size() - 1; end > 1; end--) //外循环控制每次比较结束的地方，因为后面内循环冒泡出的有序序列就不用再比较了
    {
        for (int i = 0; i < end; i++) //内循环控制进行两个相邻元素的比较
        {
            compareTimes++;
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
            }
        }
        vectorPrint(array);
    }
    cout << "共比较" << compareTimes << "次" << endl;
}

void bubbleSort2nd(vector<int> &array) //冒泡排序的第一次优化，优化了提前有序的情况，但这种情况不多见，有时反倒负优化
{
    int compareTimes = 0;
    for (int end = array.size() - 1; end > 1; end--)
    {
        bool alreadyAscend = true; //增加了一个判断是否剩下的队列已经是升序队列
        for (int i = 0; i < end; i++)
        {
            compareTimes++;
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                alreadyAscend = false;
                //如果这一轮比较，但凡有一次调换位置，都有可能使队列不是有序，若一次调换都没有那说明已经是有序的了
            }
        }
        vectorPrint(array);
        if (alreadyAscend)
        {
            break;
        }
    }
    cout << "共比较" << compareTimes << "次" << endl;
}

void bubbleSort3rd(vector<int> array)
{
    int compareTimes = 0;
    //冒泡排序的第二次优化，优化了重复比较的地方（包括了第二次优化的提前有序情况）
    //有时可能不明白这里优化了哪，比如1，2，4，3，5，6这么一个数组
    //第一次循环后【1，2，3，4，5，{6}】，此时虽然最后一次调换发生在4与3之间，但其实后面的5，6经过比较已经比前面最大的4还大，而且有序
    //所以，第二次循环就可以直接在2和3的比较处结束了，因为后面已经比前面大且有序了
    //而lastTempLocation就是记录这里结束的位置（上次调换的位置）
    for (int end = array.size() - 1; end > 0; 1)
    {
        int lastTempLocation = 0;
        //记录上一次比较的最后的元素的索引，此时后面的元素已经是有序的了
        //默认初始值为0，这样若数组已经完全有序，下一轮循环的end就为0，会直接退出循环
        for (int i = 0; i < end; i++)
        {
            compareTimes++;
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                lastTempLocation = i;
            }
        }
        end = lastTempLocation;
        vectorPrint(array);
        //虽然最后输出和第二种优化是打印遍数是一样的，但是实际上少了很多比较的过程
    }
    cout << "共比较" << compareTimes << "次" << endl;
}

int main()
{
    Tools::Time::AlgoTimeUs time1;
    Tools::Time::AlgoTimeUs time2;
    Tools::Time::AlgoTimeUs time3;

    vector<int> array;
    array = {1, 2, 3, 4, 5, 8, 7, 6, 9, 10, 11, 15, 29};
    vector<int> array2 = array;
    vector<int> array3 = array;

    time1.start();
    vectorPrint(array);
    cout << "冒泡打印基础版" << endl;
    vectorPrint(array);
    bubbleSort1th(array);
    cout << "算法用时：（微秒）";
    time1.printElapsed();
    cout << ' ' << endl;

    time2.start();
    vectorPrint(array2);
    cout << "冒泡打印优化版" << endl;
    bubbleSort2nd(array2);
    cout << "算法用时：（微秒）";
    time2.printElapsed();
    cout << ' ' << endl;

    time3.start();
    vectorPrint(array3);
    cout << "冒泡打印第二次优化版" << endl;
    bubbleSort3rd(array3);
    cout << "算法用时：（微秒）";
    time3.printElapsed();

    return 0;
}