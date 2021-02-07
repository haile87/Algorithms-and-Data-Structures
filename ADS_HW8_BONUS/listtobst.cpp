#include <iostream>
using namespace std;

// implemented as doubly linked list
class node{
    public:
        int data;
        node *next;
        node *prev;
};

void pushfront(node **mylist, int value){
    node *newnode = new node();
    newnode->data = value;
    newnode->prev = NULL;
    newnode->next = (*mylist);
    if((*mylist)!=NULL)
        (*mylist)->prev = newnode ;
    (*mylist) = newnode;
}
int nodecounter(node *mylist){
    int counter = 0;
    node *temp = mylist;
    while(temp){
        temp = temp->next;
        counter++;
    }
    return counter;
}
// converts linked list to BST recursively
node* listToTreeRecursion(node **mylist, int num){
    if(num<=0)
        return NULL;
    // creates left subtree
    node *left = listToTreeRecursion(mylist, num/2);
    // makes middle node root
    node *root = *mylist;
    root->prev = left;
    *mylist = (*mylist)->next;
    // creates right subtree
    root->next = listToTreeRecursion(mylist, (num/2)-1);
    return root;
}
node* listToTree(node *mylist){
    int num = nodecounter(mylist);
    return listToTreeRecursion(&mylist, num);
}
void printList(node *node){
    while(node!=NULL){
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}
void printTree(node* node){
    if (node==NULL)
        return;
    cout << node->data << " ";
    printTree(node->prev);
    printTree(node->next);
}

int main(){
    node *mylist = NULL;
    int i = 10;
    while(i>=1){
        pushfront(&mylist, (2*i));
        i--;
    }
    cout << "Sorted linked list: " << endl;
    printList(mylist);
    cout << endl;
    node *tree = listToTree(mylist);
    cout << "Binary search tree beginning from root to left subtree and then to the right subtree: " << endl;
    printTree(tree);
    cout << endl;
    return 0;
}
