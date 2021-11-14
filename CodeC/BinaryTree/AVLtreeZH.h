//!���������������ɾ��������������ʱ�临�Ӷȸ����ĸ߶��йأ�ΪO��h����������Ա��O��n�������Լ���ӵĻ���
//! ���������ĸ߶Ȼ�����logn���������Ķ�����������ʱ�临�Ӷ�Ҳ�ӽ�O��logn��
//! �����������������������˳��������һ����������Ļ�������1��2��3��4��5��������n���������Ķ����������߶Ⱦ͵���n
//! Ҳ�����ʱ�临�Ӷȵ���O��n��������Ϊ�����������˻�Ϊ����
//! ��������Ҫ����ά��ʱ�临�Ӷ���O��h��������O��n��

//! ƽ��ĸ����������������̶������������߶�Խ�ӽ���Խƽ�⣬��ȫ��������������������ƽ���

//! ������θĽ����ǵĶ�������������
//! 1.�ı����ɾ����Ԫ��˳�򣬼��������ĸ߶�   2.�������Ԫ�غ�Ķ�������ʹ֮��ƽ��
//! ������ƵĶ����������Ǹ������õģ��������ɾ����˳�������޷��ı䣬��������ֻ�ܴ���Ӻ�Ķ�������ƽ��Ľ�����
//! һ�Ŵﵽ�ʶ�ƽ��Ķ��������� �����ǳ�֮Ϊƽ�����������  ���磺AVL���������
//! AVL�������䷢���������ģ���������һ��������ѧ�ң�AVL�������緢������ƽ�����������֮������������ӡ�ɾ����ʱ�临�Ӷ���O(logn)O(logn)
//! ƽ�����ӣ��ý��ƽ�����ӵ����������߶ȼ�ȥ�������߶ȣ�����ֵС�ڵ���1��������1��С��-1����Ϊʧ�⣬��Ҫ�Զ�����
#include <iostream>
#include "queue"
#include "stack"
#include <string>
#include <algorithm>
using namespace std;
class AVLNode
{
public:
    int element;
    int height;
    AVLNode *left;
    AVLNode *right;
    AVLNode *parent;
    AVLNode()
    {
        this->element = 0;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        this->height = 1;
    }
    AVLNode(int element)
    {
        this->element = element;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
        this->height = 0;
    }
};

class AVLtreeZH
{
private:
    int size;

public:
    //������Ѹ��ڵ�д��public�ˣ���Ҫ����дһЩ�������Է����
    AVLNode *root = nullptr;
    void add(int element); //���Ԫ��

    void afterAdd(AVLNode *node);         //! ��Ӻ��ж��Ƿ�����Լ��߶ȸ���  //ƽ�ⲽ��//ʲôʱ����½��߶�
    bool isBalanced(AVLNode *node);       //! �ж�һ������Ƿ�ƽ��
    int balanceFactor(AVLNode *node);     //! ��ȡһ������ƽ������
    void balancing(AVLNode *node);        //! ����б�ƽ����������ͣ�RR,LL,LR,RL��
    AVLNode *heigherChild(AVLNode *node); //!  �������������и߶Ƚϸߵ��Ǹ��ӽ��
    int getHeight(AVLNode *node);         //! ͨ������������heightֵ�����ص�ǰ���ĸ߶�
    void rotateRight(AVLNode *node1);     //! ��node1����
    void rotateLeft(AVLNode *node1);      //! ��node1����
};

void AVLtreeZH::afterAdd(AVLNode *node)
{
    while (node->parent != nullptr)
    {
        node = node->parent;
        if (isBalanced(node))
        {
            node->height = getHeight(node); //���½��߶�
            continue;
        }
        else
        {
            balancing(node);
            break;
        }
    }
}

void AVLtreeZH::balancing(AVLNode *node1)
{
    AVLNode *node2 = heigherChild(node1);
    AVLNode *node3 = heigherChild(node2);
    if (node2 == node1->left && node3 == node2->left)
    { //LL���
    rotateRight(node1);
    }
    if (node2 == node1->left && node3 == node2->right)
    { //LR���
    rotateLeft(node2);
    rotateRight(node1);
    }
    if (node2 == node1->right && node3 == node2->right)
    { //RR���
    rotateLeft(node1);
    }
    if (node2 == node1->right && node3 == node2->left)
    { //RL���
    rotateRight(node2);
    rotateLeft(node1);
    }
}

void AVLtreeZH::rotateRight(AVLNode *node1)
{
    AVLNode *node2 = heigherChild(node1);
    AVLNode *node3 = heigherChild(node2);
    AVLNode *noderoot = node1->parent;
    node1->left = node2->right; //���ľ�������
    node2->right = node1;

    node1->parent = node2; //ά�������ָ��
    node2->parent = noderoot;
    if (node1->left != nullptr)
    {
        node1->left->parent = node1;
    }
    if (noderoot == nullptr)
    {
    }
    else if (node1 == noderoot->left)
    {
        node2 = noderoot->left;
    }
    else if (node1 == noderoot->right)
    {
        node2 = noderoot->right;
    }

    node1->height = getHeight(node1);
    node2->height = getHeight(node2);
    node3->height = getHeight(node3);
    if (noderoot != nullptr)
    {
        noderoot->height = getHeight(noderoot);
    }
}
void AVLtreeZH::rotateLeft(AVLNode *node1)
{
    //�Ժ���˵
}

bool AVLtreeZH::isBalanced(AVLNode *node) //�жϽ���Ƿ�ƽ�⣬��ʵ���ǿ�ƽ�����Ӿ���ֵ��û�д��ڵ���2
{
    int i = balanceFactor(node);
    if (i < -1 || i > 1)
    {
        return false;
    }
    else if (-1 <= i <= 1)
    {
        return true;
    }
}

int AVLtreeZH::getHeight(AVLNode *node)
{
    if (node->left->height >= node->right->height)
    {
        return (node->left->height + 1);
    }
    else
    {
        return (node->right->height + 1);
    }
}

int AVLtreeZH::balanceFactor(AVLNode *node)
{
    return getHeight(node->left) - getHeight(node->right);
}

AVLNode *AVLtreeZH::heigherChild(AVLNode *node)
{
    int leftheight;
    int rightheight;
    if (node->left == nullptr)
    {
        leftheight = 0;
    }
    if (node->right == nullptr)
    {
        rightheight = 0;
    }
    if (leftheight == 0 && rightheight == 0)
    {
        return nullptr;
    }
    if (leftheight > rightheight)
    {
        return node->left;
    }
    else if (leftheight < rightheight)
    {
        return node->right;
    }
}
