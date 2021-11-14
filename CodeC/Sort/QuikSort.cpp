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
//����������ʵ�Ƚ����룬�����������begin��end˫�򱼸������������λ�ã�����ҵ����λ�õĹ���

//�Լ�����˼·д�Ŀ���������ʵ�����Ϻ���ʦд�Ĳ�࣬���Ƕ�д��һ�����ˣ������Ų�bug�Ų�������Сʱ��û�ҳ����������
void quikSort(vector<int> &array, int begin, int end)
{
    //û�뵽�����������������Сʱ��end��begin�ֱ��������ͷԪ�غ�βԪ���±�
    //��ôbegin��end��Ԫ����������end-begin+1������-1���������ⶼ������
    if ((end - begin + 1) < 2)
    {
        return;
    }
    int tempBegin = begin;//��ʱ�洢begin��ֵ����Ϊ����begin��䣬���ǻ���Ҫ��������һ���ݹ�������������
    int tempEnd = end;//ͬ��
    int pivot = array[begin];//��ʱ�洢���ֵ����Ϊ����������λ�ûᱻ����
    int beginOrEnd = 1;//��¼�ϴ�ѭ����end--�˻���begin++��
    while (begin != end)
    {
        if (beginOrEnd == 1)
        //����ϴ�ѭ��������end--�����ߵ�һ�Σ�����ξʹ�end��ʼ
        //��end--Ϊ���ӣ�end--�����������һ��array[end] > pivot���ö������űȽϣ�һ��array[begin] > pivot���ѵ�ǰendԪ�ظ����ˣ�end--
        {
            if (array[end] < pivot)//��һ�δ�end��ʼ
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
    array[begin] = pivot;//�����ֵ�ŵ�����λ��
    vectorPrint(array);
    quikSort(array, tempBegin, end - 1);
    quikSort(array, end + 1, tempEnd);
}

int SearchAndSort(vector<int> &array, int begin, int end)
{
    int pivotNum = array[begin];
    //˼·��end--ֱ���������ǣ�Ȼ�����begin++ֱ���������ǣ��ֻص�end--��˷���
    //�ܶ�ʱ������ifǶ�׶����ԸĽ���while
    while (begin<end)
    {
        while(begin<end){
            if(array[end]>pivotNum){//�Ҳ�ֵ�������ֵ������Ҫ�Ķ�λ�ã�����begin��ǰԪ�أ���end--
                end--;
            }else{//�Ҳ�ֵС�����ֵ
                array[begin] = array[end];
                begin++;
                break;//breakֻ�����һ��ѭ������ʱ�����˸��ǣ�Ҫ��ͷ��
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
    return end; //ע������Ҫ����end����Ϊ�ж�Ԫ����end-begin+1��begin��ʱ����-1��������Ḻ����������end��ʹ�Ǹ���Ҳ����
}

void quikSort2nd(vector<int> &array,int begin,int end){
    if((end - begin +1)<2){
        return;
    }
    int pivotIndex = SearchAndSort(array,begin,end);//ע���������array����ֵ���ݣ�����Ӱ����������begin��endֵ�ģ����Դ�ɷ���
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
    cout << "�������������" << endl;
    quikSort(array, 0, (array.size() - 1));
    cout << "�㷨��ʱ����΢�룩";
    time1.printElapsed();
    cout << ' ' << endl;

    time1.start();
    vectorPrint(array2);
    cout << "��������Ľ���" << endl;
    quikSort2nd(array2, 0, (array.size() - 1));
    cout << "�㷨��ʱ����΢�룩";
    time1.printElapsed();
    cout << ' ' << endl;

    return 0;
}