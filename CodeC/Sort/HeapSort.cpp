#include <iostream>
#include <vector>
#include "MeasureAlgoTime.hpp"
using namespace std;

//! ѡ�����򣺴�δ���������У��ҳ������Ǹ�Ԫ�أ���δ�������е�ĩβԪ�ؽ�����
//! ����ִ���������裨n-1�֣���ĩβ���Ԫ���γ��������У�����С��Ҳ���ԣ��������������ǽ���
//! ����ƽ��ʱ�临�Ӷȣ�O��n2��   �ռ临�Ӷȣ�O��1��  �����ȶ�����
//! ���ð������ѡ�������޷�����ѭ�������У�ͨ���Ƚ�ȷ��ǰ���Ƿ��Ѿ��γ��������У��������Ϊ���������Ż�
//! ��ʵ���Ͽ��Դ���һ���ط��Ż�����ѡȡδ�����������ֵ������̣�����ö���ɵĻ���ʱ�临�Ӷ�ֻ��O��logn������Ҫ�����ˣ������帴�Ӷ�O��nlogn��
//! ��ˣ��Ż����ѡ�������㷨 ��Ϊ ������

void vectorPrint(vector<int> &array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << ' ';
    }
    cout << endl;
}

//�ѵ����˺���
void siftDown(vector<int> &array, int index, int end)
{
    //! ����ָ��array��indexԪ�ؽ������˲����������endָ����δ��������е�ĩβԪ�ص�index����Ϊvector������size��˽�еĲ��ܸ�
    int biggerChildIndex = index * 2 + 1;
    while (biggerChildIndex <= end)
    {
        if (biggerChildIndex + 1 <= end && array[biggerChildIndex] < array[biggerChildIndex + 1])
        { // ifȷ�����ý��������ӽ�㣬���ҽ��ֵ�������㣬��biggerChildIndex����Ϊ�ҽ���index
            //��û�����ӽ�㣬����䲻�ᴥ������biggerChildIndexĬ�Ͼ������ӽ�㣬�
            biggerChildIndex++;
        }
        if (array[index] < array[biggerChildIndex])
        {
            int temp = array[index];
            array[index] = array[biggerChildIndex]; //�����ӽ����ڸý�㣬���е���
            array[biggerChildIndex] = temp;

            index = biggerChildIndex;
            biggerChildIndex = index * 2 + 1; //���������ˣ������index��childIndex��������һ�����˱Ƚ�
        }
        else
        {
            break; //���ӽ����ڸý�㣬ֹͣ��������
        }
    }
}

//�������е����齨��һ���ѣ�ʵ���Ͼ��Ƕ��������Ԫ�ؽ������򣨴������ϵ����ˣ���ʹ֮���϶ѵĶ��壨ÿһ�������������ӽ�㣩
void BuildHeap(vector<int> &array)
{
    int index = array.size() / 2 - 1; //�������ҵ�����ѵ����һ����Ҷ�ӽ���λ�ã�Ҷ�ӽ�㲻������
    for (int i = index; i >= 0; i--)
    {
        siftDown(array, i, array.size()); //�����һ����Ҷ�ӽ�㿪ʼ�������ˣ��ǽ��ѵ����ַ���֮һ��
    }
}

void HeapSort(vector<int> &array)
{
    BuildHeap(array);
    //! ��������н��Ѻ�array��0�����Ǹ���������ֵ
    for (int end = array.size() - 1; end > 0; end--)
    {
        vectorPrint(array);
        siftDown(array, 0, end);
        int temp = array[0];
        array[0] = array[end];
        array[end] = temp;
        //! ��ʱarray��0����ԭ����β��СԪ�أ�����������ˣ�ʹ����ѵ�array��0�����������
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

    cout<<"�������飺"<<endl;
    time1.start();
    vectorPrint(array);
    cout << "�����������" << endl;
    HeapSort(array);
    cout << "�㷨��ʱ����΢�룩";
    time1.printElapsed();
    cout<<"������ɣ�"<<endl;
    vectorPrint(array);

    return 0;
}