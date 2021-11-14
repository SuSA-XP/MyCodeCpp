//�Լ�����ʹ��Vector����ʵ�ֶ����
//! ��vectorһ�����Կ���һСʱ��vector��û��ӹ�Ԫ��ʱ������ͨ�������±�ķ�ʽ����vectorԪ�أ�vector[0]������������


#include <vector>
#include <iostream>
using namespace std;

class BinaryHeap
{
public:
    vector<int> vec;
    BinaryHeap();
    BinaryHeap(vector<int> &array);
    int getsize();
    void add(int num);
    void siftup(int index);
    void remove();
    void siftdown(int index);
    void print();
};

BinaryHeap::BinaryHeap(){

}
BinaryHeap::BinaryHeap(vector<int> &array){
    this->vec = array;
}

int BinaryHeap::getsize(){
    return vec.size();
}

void BinaryHeap::add(int num){
    cout<<"start add"<<endl;
    vec.push_back(num);//vectorû��pushback����ʹ���±���ʣ��Ʋ���vector�����ݺ���д����pushback��
    int size = vec.size();
    cout<<size<<endl;
    int newNumIndex = size-1;//�����½���±�͸�����±�
    int fatherNumIndex = (size-1)/2;

    while (newNumIndex != 0)//ѭ���͸����Ƚϣ��˳�ѭ������������ ���޸������Ѿ�С�ڵ��ڸ����
    {
        if (vec[newNumIndex] > vec[fatherNumIndex])
        {
            int temp = vec[newNumIndex];
            vec[newNumIndex] = vec[fatherNumIndex];
            vec[fatherNumIndex] = temp;
        }else{
            break;
        }
        newNumIndex = fatherNumIndex;//�ı����±꣬Ϊ��һ�αȽ���׼��
        fatherNumIndex = (newNumIndex-1)/2;
    }
    cout<<"add success"<<endl;
    print();
    cout<<endl;
}

void BinaryHeap::siftup(int index){
    int size = vec.size();
    int numIndex = index;//�������±�͸�����±�
    int fatherNumIndex = (index-1)/2;
    while (numIndex != 0)//ѭ���͸����Ƚϣ��˳�ѭ������������ ���޸������Ѿ�С�ڵ��ڸ����
    {
        if (vec[numIndex] > vec[fatherNumIndex])
        {
            int temp = vec[numIndex];
            vec[numIndex] = vec[fatherNumIndex];
            vec[fatherNumIndex] = temp;
        }else{
            break;
        }
        numIndex = fatherNumIndex;//�ı����±꣬Ϊ��һ�αȽ���׼��
        fatherNumIndex = (numIndex-1)/2;
    }
    print();
    cout<<endl;
}

void BinaryHeap::siftdown(int index){
    int notLeaf = vec.size()/2;
    int num = vec[index];
    int maxChildIndex;
    int leftChildIndex;
    int rightChildIndex;
    while(index < notLeaf){
        leftChildIndex = index *2+1;
        rightChildIndex = index*2+2;
        if (rightChildIndex>vec.size()-1)
        {
            if (vec[index]<vec[leftChildIndex])
            {
                vec[index] = vec[leftChildIndex];
                index = leftChildIndex;
            }
        }
        if (vec[rightChildIndex]<vec[leftChildIndex])
        {
           vec[index] = vec[leftChildIndex];
           index = leftChildIndex;
        }
        if (vec[leftChildIndex]<vec[rightChildIndex])
        {
            /* code */
        }
        
        
        
    }
}
void BinaryHeap::print(){
    for (int i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
}

