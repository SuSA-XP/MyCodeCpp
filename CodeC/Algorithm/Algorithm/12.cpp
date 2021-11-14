#include <iostream>
#define MAXSIZE 100
using namespace std;

typedef struct BiTNode
{
    char data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

typedef struct SNode
{
    BiTNode *t_s;
    int tag;
} SNode, *Stack;

BiTree CreateBitree(char *a, int *pi)
{
    if (a[*pi] == '#')
    {
        (*pi)++;
        return NULL;
    }
    BiTNode *root = (BiTNode *)malloc(sizeof(BiTNode));
    root->lchild = NULL;
    root->lchild = NULL;
    root->data = a[*pi];
    (*pi)++;
    root->lchild = CreateBitree(a, pi);
    root->rchild = CreateBitree(a, pi);
    return root;
}

typedef struct SqQueue
{
    BiTNode *data[MAXSIZE];
    int front, rear;
    int tag = 0;
} SqQueue;

bool Empty(SqQueue s)
{
    if (s.front == s.rear && s.tag == 0)
        return true;
    else
        return false;
}

void InitQueue(SqQueue &q)
{
    q.front = 0;
    q.rear = 0;
}

bool EnSqQueue(SqQueue &s, BiTNode *x)
{
    if (s.front == s.rear && s.tag == 1)
        return false;
    s.data[s.rear] = x;
    s.rear = (s.rear + 1) % MAXSIZE;
    s.tag = 1;
    return true;
}

bool DeQueue(SqQueue &s, BiTree &x)
{
    if (s.front == s.rear && s.tag == 0)
        return false;
    x = s.data[s.front];
    s.front = (s.front + 1) % MAXSIZE;
    s.tag = 0;
    return true;
}

void visit(BiTNode *t)
{
    cout << t->data << " ";
}

void LevelOrder(BiTree t)
{
    if (t == NULL)
        return;
    SqQueue q;
    InitQueue(q);
    BiTree p = NULL;
    EnSqQueue(q, t);
    while (!Empty(q))
    {
        DeQueue(q, p);
        visit(p);
        if (p->lchild != NULL)
            EnSqQueue(q, p->lchild);
        if (p->rchild != NULL)
            EnSqQueue(q, p->rchild);
    }
}

void Search(BiTree t, char x)
{
    SNode s[100];
    int top = 0;
    while (t != NULL || top > 0)
    {
        while (t != NULL && t->data != x)
        {
            s[++top].t_s = t;
            s[top].tag = 0;
            t = t->lchild;
            cout << "1";
        }
        cout << "5" << endl;
        if (t != NULL&&t->data == x)
        {
            cout << "4";
            for (int i = 1; i <= top; i++)
            {
                cout << s[i].t_s->data << " ";
            }
            exit(1);
        }
        cout << "6";
        while (top != 0 && s[top].tag == 1)
        {
            top--;
            cout << "2";
        }
        if (top != 0)
        {
            cout << "3";
            s[top].tag = 1;
            t = s[top].t_s->rchild;
        }
    }
}

int main()
{
    char a[20] = "ABD##E#H##CF##G##";
    int pi = 0;
    BiTNode *t = CreateBitree(a, &pi);
    LevelOrder(t);
    cout << endl;
    Search(t, 'H');
    system("pause");
    return 0;
}