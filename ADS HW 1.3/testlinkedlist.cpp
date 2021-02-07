#include <iostream>
#include "linkedlist.h"

using namespace std;

int main()
{
    DoubleList<int> *listOfInts = new DoubleList<int>();
    int v = 0;
    for(int y = 0; y<5;y++){
        v = y;
        if (listOfInts->isEmpty()) {
            listOfInts->pushback(v);//Insert element at end of function
        }
        else {
            Iterator<int> *i = listOfInts->getIteratorAtTail();
            List<int> *search;
            while ((search=i->previousNode())!=NULL) {
                int s = search->element;
                if (s>v) {
                    break;
                }
            }
            if (search==NULL) {
                listOfInts->pushfront(v);//Inserts element at front of function
            }
            else {
                listOfInts->insertAfter(search, v);
            }
            delete i;
        }
    }
        cout << "In descending order " << endl;
        Iterator<int> *i = listOfInts->getIteratorAtHead();
        List<int> *list;
        while ((list=i->nextNode())!=NULL) {
            cout << list->element << endl;
        }
        delete i;
    return 0;
}
