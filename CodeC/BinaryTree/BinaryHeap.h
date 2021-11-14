//自己尝试使用Vector容器实现二叉堆
//! 被vector一个特性卡了一小时，vector里没添加过元素时，不能通过数组下标的方式访问vector元素（vector[0]），程序会崩溃


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
    vec.push_back(num);//vector没有pushback不能使用下标访问，推测是vector的扩容函数写在了pushback里
    int size = vec.size();
    cout<<size<<endl;
    int newNumIndex = size-1;//定义新结点下标和父结点下标
    int fatherNumIndex = (size-1)/2;

    while (newNumIndex != 0)//循环和父结点比较，退出循环有两个出口 ：无父结点或已经小于等于父结点
    {
        if (vec[newNumIndex] > vec[fatherNumIndex])
        {
            int temp = vec[newNumIndex];
            vec[newNumIndex] = vec[fatherNumIndex];
            vec[fatherNumIndex] = temp;
        }else{
            break;
        }
        newNumIndex = fatherNumIndex;//改变结点下标，为下一次比较做准备
        fatherNumIndex = (newNumIndex-1)/2;
    }
    cout<<"add success"<<endl;
    print();
    cout<<endl;
}

void BinaryHeap::siftup(int index){
    int size = vec.size();
    int numIndex = index;//定义结点下标和父结点下标
    int fatherNumIndex = (index-1)/2;
    while (numIndex != 0)//循环和父结点比较，退出循环有两个出口 ：无父结点或已经小于等于父结点
    {
        if (vec[numIndex] > vec[fatherNumIndex])
        {
            int temp = vec[numIndex];
            vec[numIndex] = vec[fatherNumIndex];
            vec[fatherNumIndex] = temp;
        }else{
            break;
        }
        numIndex = fatherNumIndex;//改变结点下标，为下一次比较做准备
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

