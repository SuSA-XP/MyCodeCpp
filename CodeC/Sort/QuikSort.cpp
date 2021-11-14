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
//快速排序：其实比较难想，整体概括就是begin和end双向奔赴互相给对面找位置，最后找到轴点位置的过程

//自己看完思路写的快速排序，其实大体上和老师写的差不多，就是都写到一个里了，但是排查bug排查了两个小时都没找出问题出在哪
void quikSort(vector<int> &array, int begin, int end)
{
    //没想到这个东西恶心了我两小时，end和begin分别代表数组头元素和尾元素下标
    //那么begin到end的元素数量就是end-begin+1而不是-1啊啊啊，这都能整错
    if ((end - begin + 1) < 2)
    {
        return;
    }
    int tempBegin = begin;//临时存储begin的值，因为后面begin会变，我们还需要它代表下一个递归左数组的起点呢
    int tempEnd = end;//同上
    int pivot = array[begin];//临时存储轴点值，因为后面轴点这个位置会被覆盖
    int beginOrEnd = 1;//记录上次循环是end--了还是begin++了
    while (begin != end)
    {
        if (beginOrEnd == 1)
        //如果上次循环动的是end--，或者第一次，那这次就从end开始
        //以end--为例子，end--有两种情况，一种array[end] > pivot不用动，接着比较，一种array[begin] > pivot，把当前end元素覆盖了，end--
        {
            if (array[end] < pivot)//第一次从end开始
            {
                array[begin] = array[end];
                begin++;
                beginOrEnd = 0;
            }
            else
            {
                end--;
                beginOrEnd = 1;
            }
        }
        else
        {
            if (array[begin] > pivot)
            {
                array[end] = array[begin];
                end--;
                beginOrEnd = 1;
            }
            else
            {
                begin++;
                beginOrEnd = 0;
            }
        }
    }
    array[begin] = pivot;//把轴点值放到合适位置
    vectorPrint(array);
    quikSort(array, tempBegin, end - 1);
    quikSort(array, end + 1, tempEnd);
}

int SearchAndSort(vector<int> &array, int begin, int end)
{
    int pivotNum = array[begin];
    //思路是end--直到发生覆盖，然后进行begin++直到发生覆盖，又回到end--如此反复
    //很多时候两个if嵌套都可以改进成while
    while (begin<end)
    {
        while(begin<end){
            if(array[end]>pivotNum){//右侧值大于轴点值，不需要改动位置（覆盖begin当前元素），end--
                end--;
            }else{//右侧值小于轴点值
                array[begin] = array[end];
                begin++;
                break;//break只会打破一层循环，此时发生了覆盖，要掉头了
            }
        }
        while (begin<end)
        {
            if(array[begin]<pivotNum){
                begin++;
            }else{
                array[end] = array[begin];
                end--;
                break;
            }
        }
    }
    array[end] = pivotNum;
    return end; //注意这里要返回end，因为判断元素是end-begin+1而begin有时存在-1的情况，会负负得正，而end即使是负的也不怕
}

void quikSort2nd(vector<int> &array,int begin,int end){
    if((end - begin +1)<2){
        return;
    }
    int pivotIndex = SearchAndSort(array,begin,end);//注意这里除了array都是值传递，不会影响主函数的begin和end值的，所以大可放心
    vectorPrint(array);
    quikSort2nd(array,begin,pivotIndex-1);
    quikSort2nd(array,pivotIndex+1,end);
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
    cout << "快速排序基础版" << endl;
    quikSort(array, 0, (array.size() - 1));
    cout << "算法用时：（微秒）";
    time1.printElapsed();
    cout << ' ' << endl;

    time1.start();
    vectorPrint(array2);
    cout << "快速排序改进版" << endl;
    quikSort2nd(array2, 0, (array.size() - 1));
    cout << "算法用时：（微秒）";
    time1.printElapsed();
    cout << ' ' << endl;

    return 0;
}