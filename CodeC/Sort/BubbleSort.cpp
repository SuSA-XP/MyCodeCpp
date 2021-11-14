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
    int compareTimes = 0; //��¼�Ƚϴ�����Ϊ�����������㷨������
    //������Ҫ����ע��ѭ������������
    //�ҵ��������ѭ��endֵ����ÿ��ѭ���ȽϵĴ�����
    //�����һ��ѭ���Ǵ��±�0��ʼ���һλ�Ƚϣ����±�[size -2]���±�[size -1]�Ƚϣ������ܹ��ǡ�size - 2 +1����
    for (int end = array.size() - 1; end > 1; end--) //��ѭ������ÿ�αȽϽ����ĵط�����Ϊ������ѭ��ð�ݳ����������оͲ����ٱȽ���
    {
        for (int i = 0; i < end; i++) //��ѭ�����ƽ�����������Ԫ�صıȽ�
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
    cout << "���Ƚ�" << compareTimes << "��" << endl;
}

void bubbleSort2nd(vector<int> &array) //ð������ĵ�һ���Ż����Ż�����ǰ����������������������������ʱ�������Ż�
{
    int compareTimes = 0;
    for (int end = array.size() - 1; end > 1; end--)
    {
        bool alreadyAscend = true; //������һ���ж��Ƿ�ʣ�µĶ����Ѿ����������
        for (int i = 0; i < end; i++)
        {
            compareTimes++;
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                alreadyAscend = false;
                //�����һ�ֱȽϣ�������һ�ε���λ�ã����п���ʹ���в���������һ�ε�����û����˵���Ѿ����������
            }
        }
        vectorPrint(array);
        if (alreadyAscend)
        {
            break;
        }
    }
    cout << "���Ƚ�" << compareTimes << "��" << endl;
}

void bubbleSort3rd(vector<int> array)
{
    int compareTimes = 0;
    //ð������ĵڶ����Ż����Ż����ظ��Ƚϵĵط��������˵ڶ����Ż�����ǰ���������
    //��ʱ���ܲ����������Ż����ģ�����1��2��4��3��5��6��ôһ������
    //��һ��ѭ����1��2��3��4��5��{6}������ʱ��Ȼ���һ�ε���������4��3֮�䣬����ʵ�����5��6�����Ƚ��Ѿ���ǰ������4���󣬶�������
    //���ԣ��ڶ���ѭ���Ϳ���ֱ����2��3�ıȽϴ������ˣ���Ϊ�����Ѿ���ǰ�����������
    //��lastTempLocation���Ǽ�¼���������λ�ã��ϴε�����λ�ã�
    for (int end = array.size() - 1; end > 0; 1)
    {
        int lastTempLocation = 0;
        //��¼��һ�αȽϵ�����Ԫ�ص���������ʱ�����Ԫ���Ѿ����������
        //Ĭ�ϳ�ʼֵΪ0�������������Ѿ���ȫ������һ��ѭ����end��Ϊ0����ֱ���˳�ѭ��
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
        //��Ȼ�������͵ڶ����Ż��Ǵ�ӡ������һ���ģ�����ʵ�������˺ܶ�ȽϵĹ���
    }
    cout << "���Ƚ�" << compareTimes << "��" << endl;
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
    cout << "ð�ݴ�ӡ������" << endl;
    vectorPrint(array);
    bubbleSort1th(array);
    cout << "�㷨��ʱ����΢�룩";
    time1.printElapsed();
    cout << ' ' << endl;

    time2.start();
    vectorPrint(array2);
    cout << "ð�ݴ�ӡ�Ż���" << endl;
    bubbleSort2nd(array2);
    cout << "�㷨��ʱ����΢�룩";
    time2.printElapsed();
    cout << ' ' << endl;

    time3.start();
    vectorPrint(array3);
    cout << "ð�ݴ�ӡ�ڶ����Ż���" << endl;
    bubbleSort3rd(array3);
    cout << "�㷨��ʱ����΢�룩";
    time3.printElapsed();

    return 0;
}