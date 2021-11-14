#include"BinaryHeap.h"
using namespace std;

int main(){
    system("cls");
    BinaryHeap *h = new BinaryHeap;
    cout<<h->getsize()<<endl;
    h->add(12);
    for (int i = 0; i < 10; i++)
    {
        h->add(i);
    }
    cout<<h->getsize()<<endl;
    h->print();
    return 0;
}