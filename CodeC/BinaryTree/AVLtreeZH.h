//!二叉搜索树的添加删除，搜索操作的时间复杂度跟树的高度有关，为O（h）（相比线性表的O（n）搜索以及添加的话）
//! 满二叉树的高度基本是logn，所以满的二叉搜索树的时间复杂度也接近O（logn）
//! 但是如果二叉搜索树建立的顺序，输入是一个有序数组的话，比如1，2，3，4，5，。。。n这样建立的二叉搜索树高度就等于n
//! 也就是最坏时间复杂度等于O（n），被称为二叉搜索树退化为链表
//! 所以我们要尽力维持时间复杂度在O（h）而不是O（n）

//! 平衡的概念：二叉树结点数量固定，左右子树高度越接近就越平衡，完全二叉树和满二叉树是最平衡的

//! 所以如何改进我们的二叉搜索树？？
//! 1.改变添加删除的元素顺序，简介控制树的高度   2.改善添加元素后的二叉树，使之更平衡
//! 我们设计的二叉搜索树是给别人用的，所以添加删除的顺序，我们无法改变，所以我们只能从添加后的二叉树的平衡改进入手
//! 一颗达到适度平衡的二叉搜索树 ，我们称之为平衡二叉搜索树  比如：AVL树，红黑树
//! AVL树是以其发明者命名的，发明者是一个苏联科学家，AVL树是最早发明的自平衡二叉搜索树之—，搜索、添加、删除的时间复杂度是O(logn)O(logn)
//! 平衡因子：该结点平衡因子等于左子树高度减去右子树高度，绝对值小于等于1，即超过1或小于-1，即为失衡，就要自动调整
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
    //我这里把根节点写成public了，主要后面写一些函数可以方便点
    AVLNode *root = nullptr;
    void add(int element); //添加元素

    void afterAdd(AVLNode *node);         //! 添加后判断是否进行以及高度更新  //平衡步骤//什么时候更新结点高度
    bool isBalanced(AVLNode *node);       //! 判断一个结点是否平衡
    int balanceFactor(AVLNode *node);     //! 获取一个结点的平衡因子
    void balancing(AVLNode *node);        //! 如何判别平衡操作的类型（RR,LL,LR,RL）
    AVLNode *heigherChild(AVLNode *node); //!  返回左右子树中高度较高的那个子结点
    int getHeight(AVLNode *node);         //! 通过左右子树的height值，返回当前结点的高度
    void rotateRight(AVLNode *node1);     //! 以node1右旋
    void rotateLeft(AVLNode *node1);      //! 以node1左旋
};

void AVLtreeZH::afterAdd(AVLNode *node)
{
    while (node->parent != nullptr)
    {
        node = node->parent;
        if (isBalanced(node))
        {
            node->height = getHeight(node); //更新结点高度
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
    { //LL情况
    rotateRight(node1);
    }
    if (node2 == node1->left && node3 == node2->right)
    { //LR情况
    rotateLeft(node2);
    rotateRight(node1);
    }
    if (node2 == node1->right && node3 == node2->right)
    { //RR情况
    rotateLeft(node1);
    }
    if (node2 == node1->right && node3 == node2->left)
    { //RL情况
    rotateRight(node2);
    rotateLeft(node1);
    }
}

void AVLtreeZH::rotateRight(AVLNode *node1)
{
    AVLNode *node2 = heigherChild(node1);
    AVLNode *node3 = heigherChild(node2);
    AVLNode *noderoot = node1->parent;
    node1->left = node2->right; //核心就这两句
    node2->right = node1;

    node1->parent = node2; //维护父结点指针
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
    //以后再说
}

bool AVLtreeZH::isBalanced(AVLNode *node) //判断结点是否平衡，其实就是看平衡因子绝对值有没有大于等于2
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
