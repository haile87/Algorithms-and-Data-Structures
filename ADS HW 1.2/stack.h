#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;


template <class T>
class Stack {
    private:
        T* arr;
        int stacksize;
        T element;
        int top;
    public:
        Stack(){
            stacksize = 10;
            cout << "Initialized Stack To Default Size " << stacksize << endl;
            top = -1;
            arr = new T[stacksize];
        }
        Stack(int stacksizeentered){
            this->stacksize = stacksizeentered;
        }
        Stack(const Stack& source){
            stacksize = source.stacksize;
            int m = 0;
            for(m=0;m<stacksize;m++){
                 arr[m]= source.element;
            }
            top = m;
        }
        bool isFull(){
            return top + 2 > stacksize;
        }
        bool isEmpty(){
            return top < 0;
        }
        bool push(T element){
            if (isFull()) {
                return false;
                cout << "Stack is full. Can not add any more elements." << endl;
            }
            else {
                arr[++top] = element;
                cout << element << " has been pushed into stack" << endl;
                return true;
            }
        }
         bool pop(T& out){
            if(isEmpty()){
                return false;
                cout << "The stack is empty. Can not pop." << endl;
            }
            else {
                out = arr[top];
                top--;
                cout << out << " has been popped from stack." << endl;
                return true;
            }
        }
        T Back(void){
            return arr[top];
        }
        int getNumEntries(){
            return top + 1;
        }

        ~Stack(){
            delete [] arr;
            cout << "Destructor called. Stack has been destroyed!" << endl;
        }
};

#endif

