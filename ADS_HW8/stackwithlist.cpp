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
                cout << elem << " has been pushed into Stack." << endl;
            }
        }
        T pop(){ // return element if not in underflow
            if(isEmpty()){
                cout << "Stack is empty. Stack underflow!" << endl;
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
            cout << new_size << " has been set as stack size." << endl;
        }
        Stack(){
            defaultsize = -1;
            current_size = 0;
            top = NULL;
        }
};

// Analyzing running time, each specific operation in the Stack implementation has constant time complexity of O(n)
// because only a constant number of operations are always performed no matter how large the input size is. Here n doesn't
// represent linear time but is a constant number that varies across operations(since there are different
// amounts of sub-operations within each operation for example: pop operation and the sub-operations within it).

int main(){
    // using default constructor results in stack overflow because -1 would
    // be the value of defaultsize since it has not been set which we will test in the next line
    cout << "First test Stack using default constructor: " << endl;
    Stack<float> m;
    m.push(2.4);
    cout << endl;
    // using parametric constructor
    cout << "Second test Stack using parametric constructor: " << endl;
    Stack<int> a(7);
    a.push(8);
    a.push(10);
    a.push(13);
    a.push(24);
    a.push(15);
    a.push(3);
    a.push(45);
    // now since the stack is full, any more adding of elements will cause overflow which we will test in the next line
    a.push(1);
    int i = 0, val = 0;
    for(i=0;i<7;i++){
        val = a.pop();
        cout << val << " has been popped from Stack." << endl;
    }
    // since stack is empty, test for underflow
    val = a.pop();
    return 0;
}
