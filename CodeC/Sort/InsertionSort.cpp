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

//����������������ֻ�֣�һֻ�������������ģ�һֻ������ģ�ÿ�ΰ������������Ƶĵ�һ�ţ�������ıȽϣ����������ƶѵĺ���λ��
//���������ʱ�临�Ӷȣ� �������е�������й� ������ԣ�������Ҫ���������顾0��8��9��1�����8��1����9��1�����������
//�ʱ�临�Ӷȣ�O��n2��������������ȫ���򣩣����ʱ�临�Ӷ�O��n�������������Ѿ����򣩣�ƽ��ʱ�临�Ӷ�O��n2�����ռ临�Ӷ�O��1��,ԭ���ȶ������㷨
//�����㷨��������ر��ٵ�������Ч�ʺܸߣ��������ܱ�O��nlogn������Ķ�����Ϳ������򻹿�

void insertionSort1th(vector<int> &array) //���������������Ϊ�������һ��
{
    // chaosBeginIndex��δ�������е���ʼԪ���±�
    // insertEIndex����ȥ�����������е��Ǹ�Ԫ�ص��±꣬����δ�������е���ʼԪ�أ������Ž���λ�ã��±��ı�
    for (int chaosBeginIndex = 1; chaosBeginIndex < array.size(); chaosBeginIndex++)
    //��ѭ�����ƴӵڶ���Ԫ�ؿ�ʼ���뵽���������ֱ�����һ��Ԫ��
    {
        for (int insertEIndex = chaosBeginIndex; insertEIndex > 0; insertEIndex--)
        //��ѭ�����ƴ�δ�������е���Ԫ�ؿ�ʼ��������������Ԫ�رȽϺͽ���λ�ã��ҵ����������еĺ���λ��
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

void insertionSort1thRe(vector<int> &array) //�����������Ҳ���Ϊ�������һ��
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

//��������ĵ�һ���Ż������ǰѲ��ϵĽ���λ�ã��ĳ����ҵ�λ�ú�������飬����Ԫ�غ��Ƹ���
//���ǰ���߱��Ҵ��Ԫ�ض�Ҫ���ҽ�������������߱��Ҵ��Ԫ�ض�Ҫ������
void insertionSort2nd(vector<int> &array) //���������������Ϊ�������һ��
{
    for (int chaosBeginIndex = 1; chaosBeginIndex < array.size(); chaosBeginIndex++)
    {
        int insertENum = array[chaosBeginIndex]; //��¼����Ԫ�ص�Ԫ�����ݣ���Ϊ����ԭ��λ�ûᱻ����
        int rightEIndex = chaosBeginIndex;       //��¼��ȷ�Ĳ���λ�ã���ʼֵ���Ǳ�����Ԫ�ص�ԭ��λ�ã�δ�������еĵ�һ��Ԫ��λ�ã�

        while (rightEIndex > 0) //���ϱȽϲ���Ԫ�����������Ԫ�أ��ҵ����ʲ���λ�ã���rightEIndex��¼
        {
            if (insertENum < array[rightEIndex - 1])
            {
                array[rightEIndex] = array[rightEIndex - 1]; //����Һ���λ�õ�ͬʱ��˳���Ԫ�غ�����
                rightEIndex = rightEIndex - 1;
            }
            else
            {
                break;
            }
        }

        array[rightEIndex] = insertENum; //���뵽�ճ����ĺ���λ����

        vectorPrint(array);
    }
}

//����˼�������ö��������Ŀ�ܣ��޸Ľ������������ҵ����Ҳ���ĳԪ�أ���ΪѰ�������е�һ�����ڲ���Ԫ�ص�Ԫ��
//�����޸�: ����Ԫ��С��mid��������Ѱ��Χ���󣬲���Ԫ�ش��ڵ���mid��������Ѱ��Χ���ң�ֱ��begin=end˵���ҵ�����λ��
int binarySearchInsertionIndex(vector<int> array, int chaosBeginIndex)
{
    int begin = 0;
    int end = chaosBeginIndex;
    //!����֪������������end�Ķ�����������֣���������Ż����������㷨�Ļ������������endֻ�ܶ���Ϊ���������ĩβԪ�صĺ�һλ
    while (begin != end)
    { //дbegin<endҲ�ɣ�begin=endʱ�Ѿ��ҵ�����λ��
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
    //���ǰ��end����������ĩβԪ���������ᵼ��begin��end���ʱ����ȷ������λ�ã��������ǲ�֪��begin��end�ĸ�����ȷ�Ĳ���λ
}

void insertionSort_BSEdition(vector<int> &array) //���������������Ϊ�������һ��
{
    // chaosBeginIndex��δ�������е���ʼԪ���±�
    for (int chaosBeginIndex = 1; chaosBeginIndex < array.size(); chaosBeginIndex++)
    //��ѭ�����ƴӵڶ���Ԫ�ؿ�ʼ���뵽���������ֱ�����һ��Ԫ��
    {
        int rightEIndex = binarySearchInsertionIndex(array, chaosBeginIndex); //���������ҵ���ȷ����λ��O��logn��
        int insertENum = array[chaosBeginIndex];                              //��������Ԫ�����ݣ���Ϊ����Ҫ���Ƹ����ڳ������λ��

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

    cout << "�������飺" << endl;
    vectorPrint(array);
    time1.start();
    cout << "�������������" << endl;
    insertionSort1th(array);
    cout << "�㷨��ʱ����΢�룩";
    time1.printElapsed();

    cout << "�������飺" << endl;
    vectorPrint(array2);
    time2.start();
    cout << "������������棨��һ������" << endl;
    insertionSort1thRe(array2);
    cout << "�㷨��ʱ����΢�룩";
    time2.printElapsed();

    cout << "�������飺" << endl;
    vectorPrint(array3);
    time3.start();
    cout << "���������һ���Ż���" << endl;
    insertionSort2nd(array3);
    cout << "�㷨��ʱ����΢�룩";
    time3.printElapsed();

    cout << "�������飺" << endl;
    vectorPrint(array5);
    time5.start();
    cout << "����������������Ż���" << endl;
    insertionSort_BSEdition(array5);
    cout << "�㷨��ʱ����΢�룩";
    time5.printElapsed();

    cout << ' ' << endl;
    return 0;
}