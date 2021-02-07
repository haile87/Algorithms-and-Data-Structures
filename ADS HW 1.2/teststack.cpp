#include <iostream>
#include "stack.h"

using namespace std;

int main()
{
    Stack<int> s1;
    Stack<int> s3(7);
    int m;
    s1.push(2);
    s1.push(4);
    s1.push(6);
    s1.push(8);
    int z = s1.getNumEntries();
    cout << "There have been " << z << " entries for the stack s1 at this moment" << endl;
    s1.push(9);
    s1.push(11);
    s1.push(19);

    Stack<int> s2;
    s2 = s1;
    m = s1.Back();//returns top element of stack without altering the stack
    cout << m << " has been successfully retrieved from stack without changing it" << endl;
    int k = 0;
    s1.pop(k);
    int j = 0;
    s1.pop(j);
    return 0;
}
