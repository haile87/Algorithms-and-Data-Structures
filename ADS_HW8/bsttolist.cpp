#include <iostream>
using namespace std;

struct linkedlist{
    int data;
    struct linkedlist *next;
};

struct linkedlist* pushback(struct linkedlist *mylist, int element){
    struct linkedlist *cursor, *newel;
    cursor = mylist;
    newel = new struct linkedlist();
    if(newel == NULL){
        return mylist;
    }
    newel->data = element;
    newel->next = NULL;
    if(mylist == NULL)
        return newel;
    while ((cursor->next)!=NULL)
        cursor = cursor->next;
    cursor->next = newel;
    return mylist;
}
void printlinkedlist(struct linkedlist *mylist){
    struct linkedlist *ptr;
    for(ptr=mylist;ptr;ptr = ptr->next){
        cout << ptr->data << " " ;
    }
    cout << endl;
}
// Binary search tree
class BSTree{
    private:
        typedef struct node{
            node *left;
            node *right;
            int data;
        }node;
    public:
        node *root;
        BSTree(){
            root = NULL;
        }
        node* createnode(int data){
            node *newnode = new node;
            newnode->data = data;
            newnode->left = NULL;
            newnode->right = NULL;
            return newnode;
        }
        bool isEmpty()const{
            return root==NULL;
        }
        int nodedepth(node *to, node *from){
            if (to == from)
                return 0;
            else if (to->data < from->data)
                return nodedepth(to, from->left) + 1;
            else
                return nodedepth(to, from->right) + 1;
        }
        void insertNode(int element){
            node* newnode = createnode(element);
            node* parent;
            parent = NULL;
            if(isEmpty())
                root = newnode;
            else {
                node* current;
                current = root;
                while(current){
                    parent = current;
                    if (newnode->data > current->data)
                        current = current->right;
                    else
                        current = current->left;
                }
                if((newnode->data)<(parent->data))
                    parent->left = newnode;
                else
                    parent->right = newnode;
            }
        }
        // the printTree function prints the BST by indicating the depth or level of the tree
        // the element is present on first and uses spaces to create the impression of a tree.
        void printTree(node *node){
            if(node == NULL)
                return;
            printTree(node->left);
            cout << "Level " << nodedepth(node, root) << " of BST: ";
            for(int i=0;i<nodedepth(node, root);i++)
                cout << "  ";
            cout << node->data << endl;
            printTree(node->right);
        }

        // converts BST to linked list
        struct linkedlist* converttolist(node *node, struct linkedlist *mylist){
            if(node == NULL)
                return mylist;
            mylist = converttolist(node->left, mylist);
            mylist = pushback(mylist, node->data);
            mylist = converttolist(node->right, mylist);
            return mylist;
        }
};

int main(){
    BSTree mytree;
    struct linkedlist *mylist = NULL;
    mytree.insertNode(6);
    mytree.insertNode(2);
    mytree.insertNode(12);
    mytree.insertNode(4);
    mytree.insertNode(73);
    mytree.insertNode(15);
    mytree.insertNode(3);
    mytree.insertNode(50);
    mytree.insertNode(21);
    cout << "Binary Search Tree:" << endl;
    mytree.printTree(mytree.root);
    mylist = mytree.converttolist(mytree.root, mylist);
    cout << endl;
    cout << "Sorted Linked List: " << endl;
    cout << endl;
    printlinkedlist(mylist);
    return 0;
}
