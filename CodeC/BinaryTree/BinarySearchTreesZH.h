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

//! �ݹ飺�ں������ӹ����ڲ���ֱ�ӻ��ӵص����Լ��������ں��������ڲ��������Լ��ĺ�������
//! �ݹ�˼�룺������ת����ͬ��Ĺ�ģ��С�������⣬�Ƚ�������⣬��ͨ����ͬ����ⲽ���𲽽�����߲�ε����⣬���յõ����ս�
//! ��ʽ��x0 -> ��x1 = f(x0)�� -> x2 = f(x1) -> x3 = f(x2) ...->xn = f��x��n-1����  xnΪ���ս�  �����ֱ��ó��󣬲��续ͼ����Ƶ��
//! ��Ϊ�����ǰѴ������𲽷ֽ�ΪС���⣬������СС���⿪ʼ�𲽻ص������⣬����������Ҫ��ס��������м�С���⣬��Ϊջ���м����ԣ��Ƚ�������ݹ����Ӧ����ϵͳջ
//! ջ�ڲ���{f(x(n-1)),f(x(n-2))....f(x1),f(x0)} �����f(x(n-1))��ʼ����push��ȥ��Ȼ�������β������pop

////��ʹ��һ���������飬�����ɾ��Ԫ�ص�ʱ�临�Ӷ�Ҳֻ������O��n��
//��ʹ�ö���������������ɾ�����������ʱ�临�ӶȾ����Ż���O(logn)

//������������һ�ö��������κν������ӽ��С�ڸýڵ㣬���ӽڵ���ڸýڵ�
//����������û������index���±꣩һ˵����Ϊ������Ԫ�صĴ�С��λ�ö��޹أ�û������

//ǰ�������Preorder Traversal��
//����˳�򣺸���㣬ǰ�������������ǰ�����������

//���������Inorder Traversal��
//����˳��������������������ڵ㣬������������������Һ���Ҳ���ԣ�ֻҪ���ڵ����м���ʣ��������������ͬ��ǰ�����
//�������������������������ʹԪ��������������

//���������Postorder Traversal��
//����˳�򣺺��������������������������������ڵ�

//���������Levelorder Traversal��
//����˳��һ��һ����ʽ��

//ͷ�ļ���Ķ�����������ֱ����ͷ�ļ���д��Ķ������

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
    //������Ѹ��ڵ�д��public�ˣ���Ҫ����дһЩ�������Է����
    Node *root = nullptr;
    void add(int element);                          //���Ԫ��
    Node *searchBST(int element, Node *root);       //����������
    bool isEmpty();                                 //�Ƿ�Ϊ��
    void clear();                                   //���
    void clear(Node *node);                         //�����nodeΪ����������
    void preorderTraversal(Node *root);             //ǰ������ݹ�
    void inorderTraversal(Node *root);              //��������ݹ�
    void postorderTraversal(Node *root);            //��������ݹ�
    void levelorderTraversal(Node *root);           //������������У�
    void preorderTraversalNoRecursion(Node *root);  //ǰ�����������ģ��ջ��
    void inorderTraversalNoRecursion(Node *root);   //�������������ģ��ջ��
    void postorderTraversalNoRecursion(Node *root); //�������������ģ��ջ��
    int height(Node *node);                         //�����߶ȵ���
    int heightNoRecursion(Node *node);              //�����߶ȵ��������������
    bool isCompleteTree(Node *node);                //��ȫ�Լ��飨���������
    Node *invertTreePreOrder(Node *node);           //��ת��������ǰ�������
    Node *invertTreeInOrder(Node *node);            //��ת�����������������
    Node *invertTreePostOrder(Node *node);          //��ת�����������������
    Node *invertTreeLeverOrder(Node *node);         //��ת�����������������
    Node *searchNode(int key, Node *node);          //���ҽ�㣨ǰ�������
    Node *predecessor(Node *node);                  //��ǰ�����
    Node *successor(Node *node);                    //�Һ�̽ڵ�
    void remove(Node *node);                        //ɾ���ڵ�
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
    Node *nextCompare = root;
    //������Ҫ���бȽϵĽ�㣬���������ƶ��������ҽ�㣬����С���ƶ����������㣬������һ�αȽ�
    Node *parent = root;
    //��¼�ƶ�ǰ��nextCompare����nextCompareѭ����nullʱ�����ĸ���㣬Ҳ�ǲ���λ�õĸ����
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
//��������������Ԫ��
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

//ǰ��������ݹ�汾�����������ĵݹ�д��˼�붼һ�£�Ψһ���������ʲôʱ����ʸ����
//����ͼ��ջ������⣬���ﲻ�����
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
//! �����ݹ�������������ѱ���������������������⣬ת��Ϊ�������ڵ������������
//! ��Ϊ����һ��ֻ���������Ķ������Ľ����ʽ��һ���ģ���������������ȷ������ӽڵ㣬���ڵ�����м���ʣ�Ȼ��������ӽ��
//! ���ݹ�ֻ�����ǰѷ����ӽ��������̱�����ȷ���һ��������ӽ��Ϊ�������������������Ĺ��̣�Ȼ��ѹ��̽�����أ��������ӽ��ķ��ʽ��
//! ����������ջ��˼�룬��ͼ

//����������ݹ�汾
void BinarySearchTreesZH::inorderTraversal(Node *node)
{
    if (node == nullptr)
    {
        return;
    }
    inorderTraversal(node->left);
    cout << node->element << " "; //! ���Ǹ��ڵ����м���ʣ��ȷ�����������Ȼ����ڵ㣬Ȼ�������������������ķ���Ҳ��һ�����м���ʸ��ڵ�
    inorderTraversal(node->right);
}

//����������ݹ�汾
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

//! �������������Ҫ���������ڶ��ڶ��е�Ӧ��
void BinarySearchTreesZH::levelorderTraversal(Node *node)
{
    queue<Node *> list; //�����ṹ��ָ����У���������Node*�����ǲ����������ָ��Ҳ����
    if (node == nullptr)
    {
        return;
    }
    else
    {
        list.push(node); //�Ѹ��ڵ�push��ȥ
    }
    while (list.size() != 0) //ֻҪ���в�Ϊ�վ�һֱ���ӽ���
    {
        cout << list.front()->element << " ";
        //������ǰѶ��׵�Ԫ�ص������ӽڵ���ӣ�Ȼ�󵯳�����Ԫ�أ��Ϳ��԰Ѷ����������нڵ�һ��һ��İ�������Ӻͳ���
        //���ǻ�ͼ�ȽϺ����
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

//! ǰ������ķǵݹ�汾������������ջģ��ݹ�Ĺ��̣���ʵ�ʽ�ջ��ջ˳����ݹ鲢��һ����
//! �Ƚϳ��󣬽��黭ͼ��⣬�Ƚ���Ҫ
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
        //! ע��ǰ������������ң���ջ˳����������ң���ջ��Ҫ���Һ���
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

//! ����������ǵݹ�棬����һ��ǰ������ķǵݹ��ȣ�˼·��ͬ������ʵ�ַ����͹�����ȫ��ͬ
//! �Ƚϳ�����Ȼ���黭ͼ���
//! ����ظı�����ջ˳��ʵ�����������
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
        //! ����˼·Ϊ�������ڵ㣬�ͱ�����������������ڵ㣬��ȫ����ջ��Ȼ�󰤸���ջ��
        //! ��ջ�м���Ƿ����ҽڵ㣬����������ҽڵ�Ϊ����㣬�ٴα���ȫ�����㣬ȫ����ջ��Ȼ�󰤸���ջ
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

//! ����������ǵݹ�棬����ͨ���ı�ǰ������ǵݹ�������ҽ�����ջ˳�򣬺ͷ�ת������뷨ʵ��
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
        { //! ����˼·��ǰ�������ͬ����ջ˳���Լ�����ǰ�������ң��ͺ��������У���������
            stk.push(top->left);
        }
        if (top->right != nullptr)
        {
            stk.push(top->right);
        }
    }
    reverse(s.begin(), s.end()); //reverse������ת�ַ���
    cout << s;
}

//! ��������ĸ߶�,�ݹ�汾
//! �ݹ�ľ�������ڣ��Ѵ�����ֽ�Ϊ��������ͬ��С����
//! ��Ȼ����Ҫ����ڵ�ĸ߶ȣ����ڵ�ĸ߶��ֵ������ӽڵ�����߶ȼ�һ
//! ��ô�����ת��Ϊ����ÿ���ڵ㼰���ӽڵ�ĸ߶ȣ�����С�������Ҷ�ڵ���ӽڵ�Ϊ�գ��߶�Ϊ0
int BinarySearchTreesZH::height(Node *node)
{
    int nodeHeight = 0;
    int leftSonHeight = 0;  //�������ӽڵ�߶�
    int rightSonHeight = 0; //�������ӽڵ�߶�
    if (node == nullptr)
    { //������˿ս�㣬����߶�Ϊ0
        nodeHeight = 0;
        return nodeHeight;
    }
    leftSonHeight = height(node->left);
    rightSonHeight = height(node->right);
    if (leftSonHeight >= rightSonHeight) //��ǰ���ĸ߶ȵ����������ӽڵ����߶�+1
    {
        nodeHeight = leftSonHeight + 1;
    }
    else
    {
        nodeHeight = rightSonHeight + 1;
    }
    return nodeHeight;
}

//! ��������ĸ߶ȣ������汾
//! ��ν�������ĸ߶Ⱦ��Ƕ������ж��ٲ㣬�����ڲ���������һ�����������Ϳ�����
//! ����������������������룬��ʵ�ڲ�������Ķ����У���һ��ȫ�����Ӻ���һ���ж���Ԫ�أ����Ƕ��е�size����
int BinarySearchTreesZH::heightNoRecursion(Node *node)
{
    queue<Node *> list; //�����ṹ��ָ����У���������Node*�����ǲ����������ָ��Ҳ����
    if (node == nullptr)
    {
        return 0;
    }
    else
    {
        list.push(node); //�Ѹ��ڵ�push��ȥ
    }
    int height = 0;
    int nextCengNum = 1;     //! ��һ��Ԫ����Ϊ1
    int j = 0;               //! ѭ����������ÿһ��ѭ��nextCengNum�ξͻ����㣬���߶�+1
    while (list.size() != 0) //ֻҪ���в�Ϊ�վ�һֱ���ӽ���
    {
        //������ǰѶ��׵�Ԫ�ص������ӽڵ���ӣ�Ȼ�󵯳�����Ԫ�أ��Ϳ��԰Ѷ����������нڵ�һ��һ��İ�������Ӻͳ���
        //���ǻ�ͼ�ȽϺ����
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

//! ����������Ƿ�Ϊ��ȫ������
//! �������ÿһ����㣬��������������������
bool BinarySearchTreesZH::isCompleteTree(Node *node)
{
    if (node == nullptr)
    {
        return false;
    }
    queue<Node *> list;
    list.push(node);
    while (list.size() != 0) //! �����
    {
        Node *front = list.front();
        if (front->left != nullptr && front->right != nullptr) //! ���ý��ͬʱӵ�������ӽ�㣬������������
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
        else if (front->left == nullptr && front->right != nullptr) //! ���ý��û����ֻ���ң�ֱ�ӷ���false
        {
            return false;
        }
        else //! ���ý��û�������ӽ�㣬��ֻ�����ӽ�㣬���ӽڵ���Ӻ󣬶��иý��������н�㶼��Ҷ��㣨û���ӽڵ㣩
        {
            if (front->left != nullptr)
            {
                list.push(front->left);
            }
            list.pop();              //�ѵ�ǰ���Ϲ���������pop��ȥ
            while (list.size() != 0) //���������ǲ��Ƕ���Ҷ��㣬������return false
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
    //ÿ�μ��鶼ͨ��������true
    return true;
}

//! �������ķ�ת�����ʾ��Ƕ������ı�����Ӧ��
//! ��������ʽ������������ÿһ����㣬����ÿһ������ͬʱ��������������
//! �����������ע��һ�µ�����Ĳ�������
Node *BinarySearchTreesZH::invertTreePreOrder(Node *node)
{
    if (node == nullptr)
    {
        return node;
    }
    Node *tmp = node->left;
    node->left = node->right;
    node->right = tmp;
    invertTreePreOrder(node->left);  //!�����������ҪĿ���Ǳ��������еĸ����á�����ת
    invertTreePreOrder(node->right); //! �������ﲻreturn��Ҫ������ñ������
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
    //! �������������㣺���ڵ������������������Եڶ����ݹ����Ӧ�������ڵ�����������ԭ����������
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

//! ����ĳ������ǰ�����̽�㣨Ҫ����Ҫ��parentָ�룩
//! ǰ����㶨�壺��������е�ǰһ����㣬�����Ƕ������ṹ�е���һ��ĸ���
Node *BinarySearchTreesZH::predecessor(Node *node)
{
    if (node == nullptr)
    {
        return node;
    }
    //! ǰ��������������е����ҽ��
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
        //! ��ʱ�����������ֿ���
        //! node->parent = nullptr(��û��ǰ�����) �� node->parent ->right = node����ǰ�������node->parent��
        //! �������� ֱ�ӷ���parent������
        return node->parent;
    }
}
//! ����ĳ�����ĺ�̽�㣨Ҫ����Ҫ��parentָ�룩
//! ��̽�㶨�壺��������еĺ�һ�����
Node *BinarySearchTreesZH::successor(Node *node)
{
    if (node == nullptr)
    {
        return node;
    }
    //! ǰ��������������е�������
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
        //! ��ʱ�����������ֿ���
        //! node->parent = nullptr(��û��ǰ�����) �� node->parent ->left = node����ǰ�������node->parent��
        //! �������� ֱ�ӷ���parent������
        return node->parent;
    }
}

//! ɾ�����
void BinarySearchTreesZH::remove(Node *node)
{
    if (node->left != nullptr && node->right != nullptr) //! ��ɾ����Ϊ2 �Ľ�������ת��Ϊɾ��
    {
        node->element = predecessor(node)->element;
        remove(predecessor(node));
    }
    else if (node->left == nullptr && node->right == nullptr) //! ɾ����Ϊ0�Ľ��
    {
        if (node->parent == nullptr) //! ������Ǹ����ֱ���ÿ�
        {
            node = nullptr;
        }
        if (node == node->parent->left) //!���ʱҶ���ʱ���ÿ�
        {
            node->parent->left = nullptr;
        }
        if (node == node->parent->right)
        {
            node->parent->right = nullptr;
        }
        //!�Ҿ�������ֱ��ȫ��node = nullptrӦ����һ����
    }
    else
    {
        //! ɾ����Ϊ1�Ľ��
        if (node->parent == nullptr) //!������Ǹ���㣬�����ӽ�������Ϊ�����
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
        { //! ����Ǹ��������ӽ������ӽ��ʱ���Ķ�˫��ָ�룬��˫������ɾ��������һ��
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
//!��ֵ����nodeΪ���ڵ�����в��ҽ��
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
    return searchNode(key, node->left);  //!�����������ҪĿ���Ǳ�����ͬʱ�ȽϽ��ֵ���������ҵ��Ľ��
    return searchNode(key, node->right); //! ��������Ҫ�ǵ�return�����ҵ��Ľ��return������Ҫ������ÿ��
    return nullptr;
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
    size = 0;
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
