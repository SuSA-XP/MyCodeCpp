//! *ָ����������磺int b = *p�� *����ȡֵ����������ص�ַָ���ֵ�����ǵ�ַ����p�ǵ�ַ����
//! ��������*p�����ҵ���ַΪp�����ӣ�Ȼ��*������ȡ������Ķ�����Ȼ��Ѷ�����ֵ��b
//! ����ָ����������磺int *p = &a; �е�int*pֻ�Ǳ���p��һ��ָ���������������Ϊint*��int����ָ�����������Ҫ�ͱ��*p����
//! &����ȡ��ַ����&a�����õ�����a�ĵ�ַ

//! **ָ�������Ҳ�ƶ���ָ�룬���磺int *p = a�� int **q = &p��
//! ����ָ�����ָָ��һ��ָ�����ͱ����ĵ�ַ��ָ�룬����p���a�ĵ�ַ��q��ŵľ���p�ĵ�ַ ��ʱ *q = p��
//! ͬ��int ***m = &q�� ��Ϊ����ָ�룬���Ǵ�Ŷ���ָ��q�ĵ�ַ�ģ���ʱ *m = q��
//! *p = a = **q = *��*q��= ***m = *��*��*m���� ��  ֪���������ԭ����������Ƴ�����

//! �ṹ��ָ����������磺Node *node = new Node(10); ��ʱ����node�ĳ�Ա����element�����ֵ�ͬ�ķ�����
//! (*node).element �� node -> element ����ν ->��������ǽṹ��ָ�������ָ��Ľṹ���Ա����ר�õģ������Ͳ���*node��
//! node��ʱ����һ���ṹ��ָ���������ͨ�ṹ����ʳ�Ա����ֻ��Ҫnode.element�Ϳ����ˣ�����ʱnode��ָ�룬������new������

//��ʹ��һ���������飬�����ɾ��Ԫ�ص�ʱ�临�Ӷ�Ҳֻ������O��n��
//��ʹ�ö���������������ɾ�����������ʱ�临�ӶȾ����Ż���O(logn)

//������������һ�ö��������κν������ӽ��С�ڸýڵ㣬���ӽڵ���ڸýڵ�
//����������û������index���±꣩һ˵����Ϊ������Ԫ�صĴ�С��λ�ö��޹أ�û������
#include <iostream>
using namespace std;

class Node
{
public:
    int element;
    Node *left;
    Node *right;
    Node *parent;
    Node()
    {
        this->element = 0;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
    Node(int element)
    {
        this->element = element;
        this->left = nullptr;
        this->right = nullptr;
        this->parent = nullptr;
    }
};

class BinarySearchTreesZH
{
private:
    int size;

public:
    Node *root = nullptr;
    void add(int element);
    bool isEmpty();
    void clear();
    void clear(Node *node);
    void remove(int element);
};

bool BinarySearchTreesZH::isEmpty()
{
    if (size == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void BinarySearchTreesZH::add(int element)
{
    Node *node = new Node(element); // ��newһ������ڶ������洢�������ֵ
    //! Ҫ�ǵ�new���ͻ������Ƕ����ڶ����ĵ�ַ��һ��Ҫ��ָ�����������

    if (root == nullptr)
    { //�����ĿǰΪ�գ���ʹ֮��Ϊ�����
        root = node;
        size++;
        return;
    }

    //ͨ�����������������ԣ�������Ҫ�����λ��
    Node *nextCompare = root; //������Ҫ���бȽϵĽ�㣬���������ƶ��������ҽ�㣬����С���ƶ����������㣬������һ�αȽ�
    Node *parent = root;      //��¼�ƶ�ǰ��nextCompare����nextCompareѭ����nullʱ�����ĸ���㣬Ҳ�ǲ���λ�õĸ����
    while (nextCompare != nullptr)
    {
        parent = nextCompare;
        if (node->element < nextCompare->element)
        {
            nextCompare = nextCompare->left;
        }
        else if (node->element > nextCompare->element)
        {
            nextCompare = nextCompare->right;
        }
        else if (node->element = nextCompare->element) //��������ͬԪ�أ�ֱ��return
        {
            return;
        }
    }
    if (node->element < parent->element) //���ҵ��ĸ������бȽϣ�������
    {
        parent->left = node;
    }
    else if (node->element > parent->element)
    {
        parent->right = node;
    }
    //���ﲻ��delete nextCompare ��parent ����Ϊ����new�����ģ����ų�Ա����ִ������Զ�������
    size++;
    return;
}

//��������������
void BinarySearchTreesZH::clear()
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left != nullptr)
    {
        return clear(root->left);
    }
    if (root->right != nullptr)
    {
        return clear(root->right);
    }
    delete this;
}

//������ĳ���Ϊ����������
void BinarySearchTreesZH::clear(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->left != nullptr)
    {
        return clear(root->left);
    }
    if (root->right != nullptr)
    {
        return clear(root->right);
    }
    delete root;
}

int main()
{
    BinarySearchTreesZH *bst = new BinarySearchTreesZH;
    bst->add(10);
    bst->add(20);
    system("pause");
    return 0;
}
