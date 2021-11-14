#include <iostream>
#include <vector>
#include "MeasureAlgoTime.hpp"
using namespace std;

//���������� �� ����Ѱ�����������е�ĳ��Ԫ�ص�λ�� ��ƽ��ʱ�临�Ӷ�O��logn����ÿ�ο�һ�룩��û���ȶ���

void vectorPrint(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

//!��������������������д������Ҫ����������end�Ķ��壬�Լ��Ҳ���Ԫ�ؽ���������������begin��end��λ�ù�ϵ����
//! �������������end�Ķ����Ǳ�������һ���������Ԫ�ص�����
void binarySearch(vector<int> &array, int element)
{
    int begin = 0;//begin������ǣ����������еĵ�һ��Ԫ�ص���������ʼΪ0
    int end = array.size()-1;//end��ʱ������ǲ�����������һλԪ������
    while (begin <= end)//��begin��end���ʱ�����������в������κ�Ԫ�أ���������
    {
        int middle = (begin + end) / 2;
        if (array[middle] == element)
        {
            cout << "Search Success Index = " << middle << endl;
            return;
        }
        else if (element < array[middle])
        {
            end = middle -1;//����endָ�룬ָ���µ����������ĩβԪ�أ�������middle������Ҫ-1��
        }
        else if (element > array[middle])
        {
            begin = middle + 1;//����beginָ�룬ָ���µ������������Ԫ�أ�������middle������Ҫ+1��
        } 
    }
    cout<<"Element Not Find"<<endl;
    return;
}

//! ���������end�Ķ����Ǳ�������һ���������Ԫ�ص�����+1
void binarySearch1thRE(vector<int> &array, int element)
{
    int begin = 0;//begin������ǣ����������еĵ�һ��Ԫ�ص���������ʼΪ0
    int end = array.size();
    //!������Ҫע�⣬�������������end���������������������ǲ�����������һλ������+1����ʼֵ�������鳤�ȣ���Ϊ��ʲô��
    while (begin < end)//��begin��end���ʱ�����������в������κ�Ԫ�أ���������������ͼ��������
    {
        int middle = (begin + end) / 2;
        if (array[middle] == element)
        {
            cout << "Search Success Index = " << middle << endl;
            return;
        }
        else if (element < array[middle])
        {
            end = middle;//����endָ�룬ָ���µ����������ĩβԪ�صĺ�һλ������middle�����Բ���-1��
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

    cout << "�������飺" << endl;
    time1.start();
    vectorPrint(array);
    cout << "��������������" << endl;
    binarySearch(array,19);
    cout << "�㷨��ʱ����΢�룩";
    time1.printElapsed();
    cout << "�������"<< endl;

    cout << "�������飺" << endl;
    time2.start();
    vectorPrint(array2);
    cout << "��������������" << endl;
    binarySearch1thRE(array2,29);
    cout << "�㷨��ʱ����΢�룩";
    time1.printElapsed();
    cout << "�������"<< endl;



    return 0;
}