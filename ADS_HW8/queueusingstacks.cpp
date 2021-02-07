#include <iostream>

using namespace std;

template <class T>
class Stack{
    private:
        struct StackNode { // linked list
            T data;
            StackNode *next;
        };
        StackNode *top; // top of stack
        int defaultsize; // -1 if not set, value otherwise
        int current_size; // unused if size = -1
    public:
        void push(T elem){ // if size set, check for overflow
            if(current_size >= defaultsize){
                cout << "Stack overflow!" << endl;
            }else{
                struct StackNode *pos = new StackNode;
                pos->data = elem;
                pos->next = top;
                top = pos;
                current_size++;
            }
        }
        T pop(){ // return element if not in underflow
            if(isEmpty()){
                return 0;
            }else{
                T element = top->data;
                top = top->next;
                current_size--;
                return element;
            }
        }
        bool isEmpty(){ // true if empty, false otherwise
            return (top == NULL);
        }
        Stack(int new_size){
            defaultsize = new_size;
            current_size = 0;
            top = NULL;
        }
        Stack(){
            defaultsize = -1;
            current_size = 0;
            top = NULL;
        }
        // returns the element at the top of the stack
        T gettopelem(){
            return top->data;
        }
};

template <class T>
class Queue{
    private:
        Stack<T> *a, *b;
        int sizeofqueue;
        int counter;
    public:
        Queue(){
            sizeofqueue = 2;
            counter = 0;
            a = new Stack<T>(sizeofqueue);
            b = new Stack<T>(sizeofqueue);
        }
        Queue(int new_size){
            sizeofqueue = new_size;
            counter = 0;
            a = new Stack<T>(sizeofqueue);
            b = new Stack<T>(sizeofqueue);
        }
        // enqueue enters the new element at the top of a.
        void enqueue(T elem){
            if(counter >= sizeofqueue){
                cout << "Queue is full. Queue overflow!" << endl;
            }else{
                // pushes element "elem" into first stack
                a->push(elem);
                cout << elem << " has been pushed into Queue." << endl;
                counter++;
            }
        }
        // dequeue moves all elements to b if b is empty and returns the element at the top of b.
        T dequeue(){
            // while both stacks are empty
            if(a->isEmpty() && b->isEmpty()){
                cout << "Queue is empty. Queue underflow!" << endl;
                return 0;
            }
            // while second stack is empty, move elements from first stack into the second stack
            if(b->isEmpty()){
                while (!a->isEmpty()){
                    b->push(a->gettopelem());
                    a->pop();
                }
            }
            // remove and return the top element in second stack b
            T value = b->gettopelem();
            b->pop();
            counter--;
            return value;
        }
};

int main(){
    Queue<int> x(8);
    x.enqueue(53);
    x.enqueue(2);
    x.enqueue(47);
    x.enqueue(6);
    x.enqueue(9);
    x.enqueue(4);
    x.enqueue(100);
    x.enqueue(65);
    x.enqueue(11);
    cout << endl;
    int val = 0, i = 0;
    for(i=0;i<8;i++){
        val = x.dequeue();
        cout << val << " has been popped from Queue." << endl;
    }
    x.dequeue();
    return 0;
}
