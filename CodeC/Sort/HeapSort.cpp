#include <iostream>
#include <vector>
#include "MeasureAlgoTime.hpp"
using namespace std;

//! 选择排序：从未排序序列中，找出最大的那个元素，与未排序序列的末尾元素交换，
//! 不断执行上述步骤（n-1轮），末尾最大元素形成有序序列（挑最小的也可以，看需求是升序还是降序）
//! 最好最坏平均时间复杂度：O（n2）   空间复杂度：O（1）  属于稳定排序
//! 相比冒泡排序，选择排序无法在内循环过程中，通过比较确定前面是否已经形成有序序列，因此我认为这里难以优化
//! 但实际上可以从另一个地方优化：即选取未排序序列最大值这个过程，如果用堆完成的话，时间复杂度只有O（logn）（主要是下滤），整体复杂度O（nlogn）
//! 因此，优化后的选择排序算法 即为 堆排序

void vectorPrint(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

//堆的下滤函数
void siftDown(vector<int> &array, int index, int end)
{
    //! 这里指对array的index元素进行下滤操作，这里的end指的是未排序的序列的末尾元素的index，因为vector容器的size是私有的不能改
    int biggerChildIndex = index * 2 + 1;
    while (biggerChildIndex <= end)
    {
        if (biggerChildIndex + 1 <= end && array[biggerChildIndex] < array[biggerChildIndex + 1])
        { // if确保若该结点存在右子结点，且右结点值大于左结点，则biggerChildIndex更新为右结点的index
            //若没有右子结点，该语句不会触发，且biggerChildIndex默认就是左子结点，妙啊
            biggerChildIndex++;
        }
        if (array[index] < array[biggerChildIndex])
        {
            int temp = array[index];
            array[index] = array[biggerChildIndex]; //发现子结点大于该结点，进行调换
            array[biggerChildIndex] = temp;

            index = biggerChildIndex;
            biggerChildIndex = index * 2 + 1; //若发生下滤，则更新index和childIndex，进行下一次下滤比较
        }
        else
        {
            break; //若子结点大于该结点，停止本次下滤
        }
    }
}

//利用已有的数组建立一个堆，实际上就是对数组里的元素进行排序（从下至上的下滤），使之符合堆的定义（每一个结点大于左右子结点）
void BuildHeap(vector<int> &array)
{
    int index = array.size() / 2 - 1; //这里是找到二叉堆的最后一个非叶子结点的位置，叶子结点不用下滤
    for (int i = index; i >= 0; i--)
    {
        siftDown(array, i, array.size()); //从最后一个非叶子结点开始向上下滤（是建堆的两种方法之一）
    }
}

void HeapSort(vector<int> &array)
{
    BuildHeap(array);
    //! 对数组进行建堆后，array【0】就是该数组的最大值
    for (int end = array.size() - 1; end > 0; end--)
    {
        vectorPrint(array);
        siftDown(array, 0, end);
        int temp = array[0];
        array[0] = array[end];
        array[end] = temp;
        //! 此时array【0】是原本队尾的小元素，对其进行下滤，使这个堆的array【0】依旧是最大
    }
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

    cout<<"输入数组："<<endl;
    time1.start();
    vectorPrint(array);
    cout << "堆排序基础版" << endl;
    HeapSort(array);
    cout << "算法用时：（微秒）";
    time1.printElapsed();
    cout<<"排序完成："<<endl;
    vectorPrint(array);

    return 0;
}