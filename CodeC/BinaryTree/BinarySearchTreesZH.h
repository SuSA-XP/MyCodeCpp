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

//! 递归：在函数和子过程内部，直接或间接地调用自己（比如在函数定义内部出现了自己的函数名）
//! 递归思想：把问题转化成同类的规模更小的子问题，先解决子问题，再通过相同的求解步骤逐步解决更高层次的问题，最终得到最终解
//! 公式表达：x0 -> （x1 = f(x0)） -> x2 = f(x1) -> x3 = f(x2) ...->xn = f（x（n-1））  xn为最终解  （文字表达好抽象，不如画图看视频）
//! 因为我们是把大问题逐步分解为小问题，再由最小小问题开始逐步回到大问题，所以我们需要记住大问题和中间小问题，因为栈具有记忆性，先进后出，递归就是应用了系统栈
//! 栈内部：{f(x(n-1)),f(x(n-2))....f(x1),f(x0)} 问题从f(x(n-1))开始依次push进去，然后从数组尾部依次pop

////即使是一个有序数组，插入和删除元素的时间复杂度也只能做到O（n）
//而使用二叉搜索树，插入删除和搜索的最坏时间复杂度均可优化至O(logn)

//二叉搜索树：一棵二叉树，任何结点的左子结点小于该节点，右子节点大于该节点
//二叉搜索树没有索引index（下标）一说，因为索引和元素的大小和位置都无关，没有意义

//前序遍历（Preorder Traversal）
//访问顺序：根结点，前序遍历左子树，前序遍历右子树

//中序遍历（Inorder Traversal）
//访问顺序：中序遍历左子树，根节点，中序遍历右子树（先右后左也可以，只要根节点在中间访问，都叫中序遍历，同理前序后序）
//二叉搜索树进行中序遍历，会使元素以升序或降序呈现

//后序遍历（Postorder Traversal）
//访问顺序：后序遍历左子树，后序遍历右子树，根节点

//层序遍历（Levelorder Traversal）
//访问顺序：一层一层访问结点

//头文件版的二叉搜索树，直接在头文件里写类的定义就行

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
    //我这里把根节点写成public了，主要后面写一些函数可以方便点
    Node *root = nullptr;
    void add(int element);                          //添加元素
    Node *searchBST(int element, Node *root);       //二叉树搜索
    bool isEmpty();                                 //是否为空
    void clear();                                   //清空
    void clear(Node *node);                         //清空以node为根结点的子树
    void preorderTraversal(Node *root);             //前序遍历递归
    void inorderTraversal(Node *root);              //中序遍历递归
    void postorderTraversal(Node *root);            //后序遍历递归
    void levelorderTraversal(Node *root);           //层序遍历（队列）
    void preorderTraversalNoRecursion(Node *root);  //前序遍历迭代（模拟栈）
    void inorderTraversalNoRecursion(Node *root);   //中序遍历迭代（模拟栈）
    void postorderTraversalNoRecursion(Node *root); //后序遍历迭代（模拟栈）
    int height(Node *node);                         //求树高度迭代
    int heightNoRecursion(Node *node);              //求树高度迭代（层序遍历）
    bool isCompleteTree(Node *node);                //完全性检验（层序遍历）
    Node *invertTreePreOrder(Node *node);           //翻转二叉树（前序遍历）
    Node *invertTreeInOrder(Node *node);            //翻转二叉树（中序遍历）
    Node *invertTreePostOrder(Node *node);          //翻转二叉树（后序遍历）
    Node *invertTreeLeverOrder(Node *node);         //翻转二叉树（层序遍历）
    Node *searchNode(int key, Node *node);          //查找结点（前序遍历）
    Node *predecessor(Node *node);                  //找前驱结点
    Node *successor(Node *node);                    //找后继节点
    void remove(Node *node);                        //删除节点
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
    Node *nextCompare = root;
    //代表需要进行比较的结点，比它大则移动到它的右结点，比他小就移动到它的左结点，进行下一次比较
    Node *parent = root;
    //记录移动前的nextCompare，即nextCompare循环到null时，它的父结点，也是插入位置的父结点
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
//二叉搜索树搜索元素
Node *BinarySearchTreesZH::searchBST(int element, Node *root)
{
    if (root == nullptr)
    {
        return nullptr;
    }
    Node *node = root;
    while (node != nullptr)
    {
        if (element == node->element)
        {
            return node;
        }
        if (element < node->element)
        {
            node = node->left;
        }
        if (element > node->element)
        {
            node = node->right;
        }
    }
    cout<<"Not Found"<<endl;
    return nullptr;
}

//前序遍历，递归版本，三个遍历的递归写法思想都一致，唯一区别就是在什么时候访问根结点
//画个图和栈更好理解，这里不多解释
void BinarySearchTreesZH::preorderTraversal(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    cout << node->element << " ";
    preorderTraversal(node->left);
    preorderTraversal(node->right);
}
//! 简单理解递归遍历二叉树，把遍历整个二叉树这个大问题，转化为遍历根节点的无数个子树
//! 因为遍历一个只有三个结点的二叉树的解决方式是一样的，比如中序遍历，先访问左子节点，根节点就在中间访问，然后访问右子结点
//! 而递归只不过是把访问子结点这个过程变成了先访问一颗以这个子结点为根结点的三个结点的子树的过程，然后把过程结果返回，当作该子结点的访问结果
//! 深入理解就是栈的思想，画图

//中序遍历，递归版本
void BinarySearchTreesZH::inorderTraversal(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    inorderTraversal(node->left);
    cout << node->element << " "; //! 就是根节点在中间访问，先访问左子树，然后根节点，然后右子树，对于子树的访问也是一样在中间访问根节点
    inorderTraversal(node->right);
}

//后序遍历，递归版本
void BinarySearchTreesZH::postorderTraversal(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->element << " ";
}

//! 层序遍历，很重要，精髓在于对于队列的应用
void BinarySearchTreesZH::levelorderTraversal(Node *node)
{
    queue<Node *> list; //创建结构体指针队列，数据类型Node*，但是层序遍历不用指针也可以
    if (node == nullptr)
    {
        return;
    }
    else
    {
        list.push(node); //把根节点push进去
    }
    while (list.size() != 0) //只要队列不为空就一直出队进队
    {
        cout << list.front()->element << " ";
        //这里就是把队首的元素的左右子节点进队，然后弹出队首元素，就可以把二叉树中所有节点一层一层的按次序进队和出队
        //还是画图比较好理解
        if (list.front()->left != nullptr)
        {
            list.push(list.front()->left);
        }
        if (list.front()->right != nullptr)
        {
            list.push(list.front()->right);
        }
        list.pop();
    }
}

//! 前序遍历的非递归版本，精髓在于用栈模拟递归的过程，但实际进栈出栈顺序与递归并不一样，
//! 比较抽象，建议画图理解，比较重要
void BinarySearchTreesZH::preorderTraversalNoRecursion(Node *node)
{
    stack<Node *> stk;
    if (node == nullptr)
    {
        return;
    }
    stk.push(node);
    while (stk.size() != 0)
    {
        Node *top = stk.top();
        cout << stk.top()->element << " ";
        stk.pop();
        //! 注意前序遍历是中左右，出栈顺序是先左后右，进栈就要先右后左
        if (top->right != nullptr)
        {
            stk.push(top->right);
        }
        if (top->left != nullptr)
        {
            stk.push(top->left);
        }
    }
}

//! 中序遍历，非递归版，跟上一个前序遍历的非递归版比，思路相同，但是实现方法和过程完全不同
//! 比较抽象，依然建议画图理解
//! 巧妙地改变了入栈顺序实现了中序遍历
void BinarySearchTreesZH::inorderTraversalNoRecursion(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    stack<Node *> stk;
    stk.push(node);
    while (stk.size() != 0)
    {
        while (node->left != nullptr)
        {
            stk.push(node->left);
            node = node->left;
        }
        //! 整体思路为遇到根节点，就遍历左子树的所有左节点，并全部入栈，然后挨个出栈，
        //! 出栈中检测是否有右节点，如果有则以右节点为根结点，再次遍历全部左结点，全部入栈，然后挨个出栈
        Node *top = stk.top();
        cout << top->element << " ";
        stk.pop();
        if (top->right != nullptr)
        {
            node = top->right;
            stk.push(top->right);
        }
    }
}

//! 后序遍历，非递归版，可以通过改变前序遍历非递归版中左右结点的入栈顺序，和翻转数组的想法实现
void BinarySearchTreesZH::postorderTraversalNoRecursion(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    string s = " ";
    stack<Node *> stk;
    stk.push(node);
    Node *top = stk.top();
    while (stk.size() != 0)
    {
        top = stk.top();
        stk.pop();
        s = s + to_string(top->element) + " ";
        if (top->left != nullptr)
        { //! 整体思路和前序遍历相同，入栈顺序自己想想前序中左右，和后序左右中，就明白了
            stk.push(top->left);
        }
        if (top->right != nullptr)
        {
            stk.push(top->right);
        }
    }
    reverse(s.begin(), s.end()); //reverse函数反转字符串
    cout << s;
}

//! 求二叉树的高度,递归版本
//! 递归的精髓就在于，把大问题分解为解答过程相同的小问题
//! 既然我们要求根节点的高度，根节点的高度又等于其子节点的最大高度加一
//! 那么问题就转化为了求每个节点及其子节点的高度，而最小问题就是叶节点的子节点为空，高度为0
int BinarySearchTreesZH::height(Node *node)
{
    int nodeHeight = 0;
    int leftSonHeight = 0;  //代表左子节点高度
    int rightSonHeight = 0; //代表右子节点高度
    if (node == nullptr)
    { //如果到了空结点，则其高度为0
        nodeHeight = 0;
        return nodeHeight;
    }
    leftSonHeight = height(node->left);
    rightSonHeight = height(node->right);
    if (leftSonHeight >= rightSonHeight) //当前结点的高度等于其左右子节点最大高度+1
    {
        nodeHeight = leftSonHeight + 1;
    }
    else
    {
        nodeHeight = rightSonHeight + 1;
    }
    return nodeHeight;
}

//! 求二叉树的高度，迭代版本
//! 所谓二叉树的高度就是二叉树有多少层，所以在层序遍历里加一个层数计数就可以了
//! 但这个层数计数反倒是难想，其实在层序遍历的队列中，上一层全部出队后，下一层有多少元素，就是队列的size（）
int BinarySearchTreesZH::heightNoRecursion(Node *node)
{
    queue<Node *> list; //创建结构体指针队列，数据类型Node*，但是层序遍历不用指针也可以
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        list.push(node); //把根节点push进去
    }
    int height = 0;
    int nextCengNum = 1;     //! 第一层元素数为1
    int j = 0;               //! 循环计数器，每一层循环nextCengNum次就会清零，并高度+1
    while (list.size() != 0) //只要队列不为空就一直出队进队
    {
        //这里就是把队首的元素的左右子节点进队，然后弹出队首元素，就可以把二叉树中所有节点一层一层的按次序进队和出队
        //还是画图比较好理解
        if (list.front()->left != nullptr)
        {
            list.push(list.front()->left);
        }
        if (list.front()->right != nullptr)
        {
            list.push(list.front()->right);
        }
        list.pop();
        j++;
        if (j == nextCengNum)
        {
            height++;
            nextCengNum = list.size();
            j = 0;
        }
    }
    return height;
}

//! 检验二叉树是否为完全二叉树
//! 层序遍历每一个结点，有三种情况，分情况讨论
bool BinarySearchTreesZH::isCompleteTree(Node *node)
{
    if (node == nullptr)
    {
        return false;
    }
    queue<Node *> list;
    list.push(node);
    while (list.size() != 0) //! 大遍历
    {
        Node *front = list.front();
        if (front->left != nullptr && front->right != nullptr) //! 若该结点同时拥有左右子结点，则继续出队入队
        {
            list.pop();
            if (front->left != nullptr)
            {
                list.push(front->left);
            }
            if (front->right != nullptr)
            {
                list.push(front->right);
            }
        }
        else if (front->left == nullptr && front->right != nullptr) //! 若该结点没有左只有右，直接返回false
        {
            return false;
        }
        else //! 若该结点没有左右子结点，或只有左子结点，则子节点入队后，队列该结点后面所有结点都是叶结点（没有子节点）
        {
            if (front->left != nullptr)
            {
                list.push(front->left);
            }
            list.pop();              //把当前符合规则的这个先pop出去
            while (list.size() != 0) //检验后面的是不是都是叶结点，若不是return false
            {
                front = list.front();
                if (front->left != nullptr || front->right != nullptr)
                {
                    return false;
                }
                list.pop();
            }
        }
    }
    //每次检验都通过，返回true
    return true;
}

//! 二叉树的翻转：本质就是二叉树的遍历的应用
//! 以任意形式遍历二叉树的每一个结点，访问每一个结点的同时调换其左右子树
//! 中序遍历额外注意一下调换后的参数问题
Node *BinarySearchTreesZH::invertTreePreOrder(Node *node)
{
    if (node == nullptr)
    {
        return node;
    }
    Node *tmp = node->left;
    node->left = node->right;
    node->right = tmp;
    invertTreePreOrder(node->left);  //!这里遍历的主要目的是遍历过程中的副作用。即翻转
    invertTreePreOrder(node->right); //! 所以这里不return，要灵活运用遍历框架
    return node;
}
Node *BinarySearchTreesZH::invertTreeInOrder(Node *node)
{
    if (node == nullptr)
    {
        return node;
    }
    invertTreeInOrder(node->left);
    Node *tmp = node->left;
    node->left = node->right;
    node->right = tmp;
    //! 中序遍历的特殊点：由于调换了左右子树，所以第二个递归参数应该是现在的左子树才是原来的右子树
    invertTreeInOrder(node->left);
    return node;
}
Node *BinarySearchTreesZH::invertTreePostOrder(Node *node)
{
    if (node == nullptr)
    {
        return node;
    }
    invertTreePostOrder(node->left);
    invertTreePostOrder(node->right);
    Node *tmp = node->left;
    node->left = node->right;
    node->right = tmp;
    return node;
}
Node *BinarySearchTreesZH::invertTreeLeverOrder(Node *node)
{
    if (node == nullptr)
    {
        return node;
    }
    queue<Node *> list;
    list.push(node);
    while (list.size() != 0)
    {
        Node *front = list.front();
        list.pop();
        Node *tmp = front->left;
        front->left = front->right;
        front->right = tmp;
        if (front->left != nullptr)
        {
            list.push(front->left);
        }
        if (front->right != nullptr)
        {
            list.push(front->right);
        }
    }
    return node;
}

//! 查找某个结点的前驱或后继结点（要求结点要有parent指针）
//! 前驱结点定义：中序遍历中的前一个结点，而不是二叉树结构中的上一个母结点
Node *BinarySearchTreesZH::predecessor(Node *node)
{
    if (node == nullptr)
    {
        return node;
    }
    //! 前驱结点是左子树中的最右结点
    if (node->left != nullptr)
    {
        node = node->left;
        while (node->right != nullptr)
        {
            node = node->right;
        }
        return node;
    }
    else
    {
        while (node->parent != nullptr && node->parent->right != node)
        {
            node = node->parent;
        }
        //! 此时到这里有两种可能
        //! node->parent = nullptr(即没有前驱结点) 或 node->parent ->right = node（即前驱结点是node->parent）
        //! 无论哪种 直接返回parent都可以
        return node->parent;
    }
}
//! 查找某个结点的后继结点（要求结点要有parent指针）
//! 后继结点定义：中序遍历中的后一个结点
Node *BinarySearchTreesZH::successor(Node *node)
{
    if (node == nullptr)
    {
        return node;
    }
    //! 前驱结点是右子树中的最左结点
    if (node->right != nullptr)
    {
        node = node->right;
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }
    else
    {
        while (node->parent != nullptr && node->parent->left != node)
        {
            node = node->left;
        }
        //! 此时到这里有两种可能
        //! node->parent = nullptr(即没有前驱结点) 或 node->parent ->left = node（即前驱结点是node->parent）
        //! 无论哪种 直接返回parent都可以
        return node->parent;
    }
}

//! 删除结点
void BinarySearchTreesZH::remove(Node *node)
{
    if (node->left != nullptr && node->right != nullptr) //! 把删除度为2 的结点的问题转化为删除
    {
        node->element = predecessor(node)->element;
        remove(predecessor(node));
    }
    else if (node->left == nullptr && node->right == nullptr) //! 删除度为0的结点
    {
        if (node->parent == nullptr) //! 若结点是根结点直接置空
        {
            node = nullptr;
        }
        if (node == node->parent->left) //!结点时叶结点时的置空
        {
            node->parent->left = nullptr;
        }
        if (node == node->parent->right)
        {
            node->parent->right = nullptr;
        }
        //!我觉得这里直接全都node = nullptr应该是一样的
    }
    else
    {
        //! 删除度为1的结点
        if (node->parent == nullptr) //!若结点是根结点，用其子结点替代成为根结点
        {
            if (node->left != nullptr)
            {
                root = node->left;
            }
            else if (node->right != nullptr)
            {
                root = node->right;
            }
        }
        else if (node == node->parent->left)
        { //! 结点是父结点的左子结点或右子结点时，改动双向指针，和双向链表删除结点操作一样
            if (node->left != nullptr)
            {
                node->parent->left = node->left;
                node->left->parent = node->parent;
            }
            else if (node->right != nullptr)
            {
                node->parent->left = node->left;
                node->left->parent = node->parent;
            }
        }
        else if (node == node->parent->right)
        {
            if (node->left != nullptr)
            {
                node->parent->right = node->left;
                node->left->parent = node->parent;
            }
            else if (node->right != nullptr)
            {
                node->parent->right = node->left;
                node->left->parent = node->parent;
            }
        }
    }
}
//!用值在以node为根节点的树中查找结点
Node *BinarySearchTreesZH::searchNode(int key, Node *node)
{
    if (node == nullptr)
    {
        return node;
    }
    if (node->element == key)
    {
        cout << "find finished" << endl;
        return node;
    }
    return searchNode(key, node->left);  //!这里遍历的主要目的是遍历的同时比较结点值，并返回找到的结点
    return searchNode(key, node->right); //! 所以这里要记得return，把找到的结点return出来，要灵活运用框架
    return nullptr;
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
    size = 0;
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
