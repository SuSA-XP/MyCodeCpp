//! *指针变量，例如：int b = *p； *代表取值运算符，返回地址指向的值（不是地址本身，p是地址本身）
//! 做个比喻*p就是找到地址为p的箱子，然后*打开箱子取出里面的东西，然后把东西赋值给b
//! 定义指针变量，例如：int *p = &a; 中的int*p只是表明p是一个指针变量，变量类型为int*（int类型指针变量），不要和别的*p整混
//! &代表取地址符，&a就是拿到变量a的地址

//! **指针变量，也称二重指针，例如：int *p = a； int **q = &p；
//! 二重指针就是指指向一个指针类型变量的地址的指针，这里p存放a的地址，q存放的就是p的地址 此时 *q = p；
//! 同理int ***m = &q； 称为三重指针，就是存放二重指针q的地址的，此时 *m = q；
//! *p = a = **q = *（*q）= ***m = *（*（*m）） ；  知道了上面的原理这个不难推出来把

//! 结构体指针变量，例如：Node *node = new Node(10); 此时访问node的成员变量element有两种等同的方法：
//! (*node).element 或 node -> element ，所谓 ->运算符就是结构体指针访问其指向的结构体成员变量专用的，这样就不用*node了
//! node此时就是一个结构体指针变量，普通结构体访问成员变量只需要node.element就可以了，但此时node是指针，我们是new出来的

//即使是一个有序数组，插入和删除元素的时间复杂度也只能做到O（n）
//而使用二叉搜索树，插入删除和搜索的最坏时间复杂度均可优化至O(logn)

//二叉搜索树：一棵二叉树，任何结点的左子结点小于该节点，右子节点大于该节点
//二叉搜索树没有索引index（下标）一说，因为索引和元素的大小和位置都无关，没有意义
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
    Node *node = new Node(element); // 新new一个结点在堆区，存储输入的数值
    //! 要记得new传送回来的是对象在堆区的地址，一定要用指针变量来接收

    if (root == nullptr)
    { //如果树目前为空，则使之成为根结点
        root = node;
        size++;
        return;
    }

    //通过二叉搜索树的特性，查找需要插入的位置
    Node *nextCompare = root; //代表需要进行比较的结点，比它大则移动到它的右结点，比他小就移动到它的左结点，进行下一次比较
    Node *parent = root;      //记录移动前的nextCompare，即nextCompare循环到null时，它的父结点，也是插入位置的父结点
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
        else if (node->element = nextCompare->element) //若已有相同元素，直接return
        {
            return;
        }
    }
    if (node->element < parent->element) //与找到的父结点进行比较，并插入
    {
        parent->left = node;
    }
    else if (node->element > parent->element)
    {
        parent->right = node;
    }
    //这里不用delete nextCompare 和parent ，因为不是new出来的，随着成员函数执行完就自动销毁了
    size++;
    return;
}

//销毁整个二叉树
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

//销毁以某结点为根结点的子树
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
