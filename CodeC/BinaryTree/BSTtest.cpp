#include "BinarySearchTreesZH.h"//! 注意包含头文件用的是“  ”
using namespace std;

int main()
{
    system("cls");
    BinarySearchTreesZH *bst = new BinarySearchTreesZH;
    int x;
    cin>>x;
    int *num = new int[x]; //!动态创建数组
    for (int i = 0; i < x; i++)
    {
        cin>>num[i];
    }
    for (int i = 0; i < x; i++)
    {
        bst->add(num[i]);
    }
    bst->preorderTraversal(bst->root);
    cout<<endl;
    bst->inorderTraversal(bst->root);
    cout<<endl;
    bst->postorderTraversal(bst->root);
    cout<<endl;
    bst->levelorderTraversal(bst->root);
    cout<<endl;
    bst->preorderTraversalNoRecursion(bst->root);
    cout<<endl;
    bst->inorderTraversalNoRecursion(bst->root);
    cout<<endl;
    bst->postorderTraversalNoRecursion(bst->root);
    cout<<endl;
    cout<<bst->height(bst->root)<<endl;
    cout<<bst->heightNoRecursion(bst->root)<<endl;
    Node* node = bst->searchNode(2,bst->root);
    cout<<node->element<<endl;
    Node* node2 = bst->searchBST(2,bst->root);
    cout<<node2->element<<endl;
    return 0;
}