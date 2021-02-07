#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

template <class T>
class List{
public:
    List(const T &e = T(), List *n = NULL, List *p = NULL) : element(e), next(n), previous(p) {}
    ~List(){
        cout << "Destructor called. Doubly linked list destroyed!" << endl;
    }
    T element;
    List *next;
    List *previous;

};

template <class T>
class Iterator {
private:
    List<T> *actualNode;
public:
    Iterator(List<T> *node = NULL) : actualNode(node) {}
    ~Iterator() {
        if (actualNode==NULL) {
            actualNode = NULL;
        }
    }
    List<T> *nextNode() {
        if (actualNode==NULL) {
            return NULL;
        }
        actualNode = actualNode->next;
        return actualNode;
    }
    List<T> *previousNode() {
        if (actualNode==NULL) {
            return NULL;
        }
        actualNode = actualNode->previous;
        return actualNode;
    }
};
template <class T>
class DoubleList {
private:
    List<T> *head;
    List<T> *tail;
    public:
    DoubleList() {
        head = new List<T>();
        tail = new List<T>();
    }
    ~DoubleList() {
        clear();
        delete head;
        delete tail;
    }
    bool isEmpty(){
        return (head->next == NULL);
    }
    void pushfront(T &e) {
        if (isEmpty()) {
            List<T> *newNode = new List<T>(e);
            head->next = newNode;
            tail->previous = newNode;
        }
        else {
            List<T> *actualFirst = head->next;
            List<T> *newNode = new List<T>(e, actualFirst);
            //List<T> *tempNode = newNode;
            actualFirst->previous = newNode;
            head->next = newNode;
        }
    }
    void pushback(T &e) {
        if (isEmpty()) {
            List<T> *newNode = new List<T>(e);
            head->next = newNode;
            tail->previous = newNode;
        }
        else {
            List<T> *actualLast = tail->previous;
            List<T> *newNode = new List<T>(e, NULL, actualLast);
            actualLast->next = newNode;
            tail->previous = newNode;
        }
    }
    bool remove(List<T> *r) {
        if (isEmpty()) {
            return false;;
        }
        List<T> *removeNode = tail->previous;
        while (removeNode!=NULL) {
            if (removeNode==r) {
                break;
            }
            removeNode = removeNode->previous;
        }
        if (removeNode==NULL) {
            return false;
        }
        else {
            List<T> *afterRemove = removeNode->next;
            List<T> *beforeRemove = removeNode->previous;
            if (afterRemove==NULL) {
                tail->previous = beforeRemove;
            }
            else {
                afterRemove->previous = beforeRemove;
            }
            if (beforeRemove==NULL) {
                head->next = afterRemove;
            }
            else {
                beforeRemove->next = afterRemove;
            }
            delete removeNode;
            return true;
        }
    }
    bool insertAfter(List<T> *ref, T &e) {
        if (isEmpty()) {
            return false;
        }
        List<T> *searchRef = head->next;
        while (searchRef!=NULL) {
            if (searchRef==ref) {
                break;
            }
            searchRef = searchRef->next;
        }
        if (searchRef==NULL) {
            return false;
        }
        else {
            List<T> *afterRef = searchRef->next;
            List<T> *newNode = new List<T>(e, afterRef, searchRef);
            if (afterRef==NULL) {
                tail->previous = newNode;
            }
            else {
                afterRef->previous = newNode;
            }
            searchRef->next = newNode;
            return true;
        }
    }
    /*List<T> lastelementwithremove(){
        return tail->element;
        cout << tail->element;
        cout << " is the last element of the list and has been removed and returned" << endl;
    }
    List<T> lastelementwithoutremove(){
        return tail->element;
        cout << tail->element;
        cout << " is the last element of the list and has been returned without removal" << endl;
    }
    List<T> firstelementwithremove(){
        return head->element;
        cout << head->element;
        cout << " is the first element of the list and has been removed and returned" << endl;
    }
    List<T> firstelementwithoutremove(){
        return head->element;
        cout << head->element;
        cout << " is the first element of the list and has been returned without removal" << endl;
    }*/
    int clear() {
        int counter = 0;
        while (tail->previous!=NULL) {
            List<T> *remove = tail->previous;
            tail->previous = remove->previous;
            delete remove;
            counter++;
        }
        return counter;
        std::cout << "Released " << counter << " nodes from memory" << std::endl;
    }
    Iterator<T> *getIteratorAtHead() {
        Iterator<T> *i = new Iterator<T>(head);
        return i;
    }
    Iterator<T> *getIteratorAtTail() {
        Iterator<T> *i = new Iterator<T>(tail);
        return i;
    }
    int numofelem(){
        int num = 6;
        return num;
    }
};

#endif // LINKEDLIST_H
