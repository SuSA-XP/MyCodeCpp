#include <iostream>
#include <vector>
#include "MeasureAlgoTime.hpp"
using namespace std;

//ϣ��������ǲ��������һ���Ż���һ�仰������˼����ǣ�������ÿ���n��Ԫ������һ�飬����n�飬������в�������Ȼ������Сn��
//�����������Ϸ��鲢����Ĳ�����ֱ��n=1��������������Ϊһ����в�������

void vectorPrint(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

//�����������У�����ϣ�����˵����ɷ�ʽ��
void stepSequenceGenerator(vector<int> array, vector<int> &stepSequence)
{
    for (int i = 2; i < array.size(); i = i * 2)
    {
        stepSequence.push_back(array.size() / i);
    }
}

void insertionSort1th(vector<int> &array, int begin, int end) //���������������Ϊ�������һ��
{
    // chaosBeginIndex��δ�������е���ʼԪ���±�
    // insertEIndex����ȥ�����������е��Ǹ�Ԫ�ص��±꣬����δ�������е���ʼԪ�أ������Ž���λ�ã��±��ı�
    for (int chaosBeginIndex = begin + 1; chaosBeginIndex <= end; chaosBeginIndex++)
    //��ѭ�����ƴӵڶ���Ԫ�ؿ�ʼ���뵽���������ֱ�����һ��Ԫ��
    {
        for (int insertEIndex = chaosBeginIndex; insertEIndex > begin; insertEIndex--)
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

//���������д��
void sort2nd(vector<int> array, int stepSequence)
{
    //col����ǰ�ǵڼ��飨�У�
    for (int col = 0; col < stepSequence; col++)
    {
        //������ʵ������򵥵Ĳ�������Ĵ��룬ֻ�����Ƕ�ͬһ�飨�У����Ԫ�صĲ�������
        //������Ԫ��֮��ľ�����stepSequence�ˣ�����1�ˣ�������ĵ�һ��Ԫ��������col����0�ˣ���һ������Ԫ�ص�λ�þ���col+stepSequence��
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
        cout << "(ÿ������Ԫ�ؾ�ȡ��һ������һ��)(Ҳ������)����Ϊ" << stepSequence[i] << endl;
        sort(array, stepSequence[i]);
    }
}

void shellSort2nd(vector<int> &array)
{
    vector<int> stepSequence;
    stepSequenceGenerator(array, stepSequence);
    for (int i = 0; i < stepSequence.size(); i++)
    {
        cout << "(ÿ������Ԫ�ؾ�ȡ��һ������һ��)(Ҳ������)����Ϊ" << stepSequence[i] << endl;
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

    cout << "�������飺" << endl;
    vectorPrint(array);
    time1.start();
    cout << "ϣ����������ഺ��" << endl;
    shellSort(array);
    cout << "�㷨��ʱ����΢�룩";
    time1.printElapsed();

    cout << "�������飺" << endl;
    vectorPrint(array2);
    time1.start();
    cout << "ϣ������������" << endl;
    shellSort2nd(array2);
    cout << "�㷨��ʱ����΢�룩";
    time1.printElapsed();

    cout << ' ' << endl;
    return 0;
}