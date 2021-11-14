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

//merge�������ǽ�������������ϲ���һ���������飬���ڹ鲢�����У����������鶼��һ�������ڣ������������begin��������ĵ�һλ��end������������һλ
//�����begin��mid��end��������������±�
//merge������˼���ǣ������������飬����ָ��ֱ�ָ����λ��ָ��ָ��Ķ��߽��бȽϣ�С���ȷ��������飬ͬʱ�����Ԫ�ض�Ӧ����ָ��++����һ�����䣬���ű�
//���ǻ�ͼ�ȽϺ���⣬�����Ҳ����
//ʱ�临�Ӷ�O��nlogn�������ʱ�临�Ӷȵķ�����������Ҫһ��Ҫ����
void merge(vector<int> &array, int begin, int end)
{
    vector<int> temp = {};//������ʱ���飬������ʱ��źϲ���������������飬����ٸ��Ǹ�array
    int mid = (begin + end) / 2;
    //��mid��mid����������նˣ�mid+1�����������㣬���mergeSort���������������ݹ���õ�begin��mid��end��һ����
    int tempPointer = 0;
    int leftBeginPointer = begin;//��Ҫ�뵱Ȼ��Ϊ����������±�һ����0����Ҫ���㴫�������Ǵ��Ŀ�ʼ������
    int rightBeginPointer = mid + 1;
    //���ﶨ��������ָ�룬�ֱ�ָ����ʱ�������һ������λ��(vector�Ͳ���Ҫ�ˣ����Ǹ�����)�����������һ������Ԫ�أ����������һ������Ԫ��
    while (tempPointer != end + 1)//����ʱ���鳤���Ѿ�����������ĩβ���ȣ��������鳤�Ⱥͣ���˵���������ˣ�����ѭ��
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
        //�����һ�������Ѿ�ȫ�����룬��ֱ�Ӱ���һ������ʣ��Ԫ��ȫ�������˳�����
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
    //����ʱ���鸲��array��Ӧλ�õ�����
    for (int i = 0; i < end - begin + 1; i++)
    {
        array[begin + i] = temp[i];
    }
}

void merge2nd(vector<int> &array, int begin, int end)
{
    vector<int> temp = {};//������ʱ���飬������ʱ��źϲ���������������飬����ٸ��Ǹ�array
    int mid = (begin + end) / 2;
    //��mid��mid����������նˣ�mid+1�����������㣬���mergeSort���������������ݹ���õ�begin��mid��end��һ����
    int tempPointer = 0;
    int leftBeginPointer = begin;//��Ҫ�뵱Ȼ��Ϊ����������±�һ����0����Ҫ���㴫�������Ǵ��Ŀ�ʼ������
    int rightBeginPointer = mid + 1;
    //���ﶨ��������ָ�룬�ֱ�ָ����ʱ�������һ������λ�ã����������һ������Ԫ�أ����������һ������Ԫ��
    
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
    //����ʱ���鸲��array��Ӧλ�õ�����
    for (int i = 0; i < end - begin + 1; i++)
    {
        array[begin + i] = temp[i];
    }
}

void mergeSort(vector<int> &array, int begin, int end)
{
    //�е��������ĵݹ���ʣ�ÿ�ε��ö��ѵ�ǰ����һ��Ϊ����ֱ�������ٷ־�return��Ȼ��merge��һ���������飬�ٲ���merge
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

    cout << "�������飺" << endl;
    vectorPrint(array);
    time1.start();
    cout << "�鲢���������" << endl;
    mergeSort(array, 0, array.size() - 1);
    cout << "�㷨��ʱ����΢�룩";
    time1.printElapsed();

    cout << "�������飺" << endl;
    vectorPrint(array2);
    time1.start();
    cout << "�鲢����鲢����д��" << endl;
    mergeSort(array2, 0, array2.size() - 1);
    cout << "�㷨��ʱ����΢�룩";
    time1.printElapsed();
    return 0;
}