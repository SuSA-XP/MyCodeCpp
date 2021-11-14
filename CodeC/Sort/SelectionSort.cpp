#include <iostream>
#include <vector>
#include "MeasureAlgoTime.hpp"
using namespace std;

//! ѡ�����򣺴�δ���������У��ҳ������Ǹ�Ԫ�أ���δ�������е�ĩβԪ�ؽ�����
//! ����ִ���������裨n-1�֣���ĩβ���Ԫ���γ��������У�����С��Ҳ���ԣ��������������ǽ���
//! ���ð������ѡ�������޷�����ѭ�������У�ͨ���Ƚ�ȷ��ǰ���Ƿ��Ѿ��γ��������У��������Ϊ�����Ż�
//! ������
//! ����ƽ��ʱ�临�Ӷȣ�O��n2��   �ռ临�Ӷȣ�O��1��  �����ȶ�����

void vectorPrint(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

void selectionSort(vector<int> &array)
{                                                    //��ѭ������δ��������ĩβָ�룬�Լ��������ֵ�������Լ��������ֵ��ĩβԪ��
    for (int end = array.size() - 1; end > 0; end--) // end��¼��ǰδ�������е�ĩβ
    {
        int maxNumIndex = 0;
        for (int i = 1; i <= end; i++)
        { //ע�����ѡ������ÿ����ѭ��ȡ�����ֵ����ʼֵΪ�����һ��Ԫ�أ������ÿһλԪ�رȽϣ����ҵ�����ģ���������ֵ��������
            if (array[maxNumIndex] <= array[i])
            {
                maxNumIndex = i;
            }
        } //��ѭ����������¼��ǰδ�������е����ֵ������
        cout << "�ҵ����ֵ��" << array[maxNumIndex] << " "
             << "��" << array[end] << "����" << endl;
             
        int temp = array[maxNumIndex]; //����δ�������е����ֵԪ����ĩβԪ��λ��
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
    cout << "ѡ�����������" << endl;
    selectionSort(array);
    cout << "�㷨��ʱ����΢�룩";
    time1.printElapsed();
    cout << ' ' << endl;

    return 0;
}