#include <iostream>

using namespace std;

enum Color{RED, BLACK};
struct Node{
    int data;
    Color color;
    Node *left, *right, *parent;
};

class RedBlackTree{
    private:
        Node *root;
    protected:
        void rotateLeft(Node *&node){
            if((node->right)==NULL)
                return;
            else{
                Node *x = node->right;
                if((x->left)!=NULL){
                    node->right = x->left;
                    x->left->parent = node;
                }
                else
                    node->right = NULL;
                if((node->parent)!=NULL)
                    x->parent = node->parent;
                if((node->parent)==NULL)
                    root = x;
                else{
                    if(node==(node->parent->left))
                        node->parent->left = x;
                    else
                        node->parent->right = x;
                }
                x->left = node;
                node->parent = x;
             }
        }
        void rotateRight(Node *&node){
            if((node->left)==NULL)
                return;
            else{
                Node *x = node->left;
                if((x->right)!=NULL){
                    node->left = x->right;
                    x->right->parent = node;
                }
                else
                    node->left = NULL;
                if((node->parent)!=NULL)
                    x->parent = node->parent;
                if((node->parent)==NULL)
                    root = x;
                else{
                    if(node==(node->parent->left))
                        node->parent->left = x;
                    else
                        node->parent->right = x;
                }
                x->right = node;
                node->parent = x;
            }
        }
    public:
        RedBlackTree(){
            root = NULL;
        }
        void insert(int);
        // fixes the Red Black Tree after insertion of new element
        void insertfixup(Node *&);
        void deleteNode(Node *&);
        // fixes the Red Black Tree after deletion of new element
        void deletefixup(Node *&);
        Node* predecessor(Node *&);
        Node* successor(Node *&);
        Node* getMinimum();
        Node* getMaximum();
        Node* search(int);
};

void RedBlackTree::insert(int element){
     Node *a, *b;
     // node that stores the element to be inserted
     Node *k;
     k = new Node;
     k->data = element;
     k->left = NULL;
     k->right = NULL;
     k->color = RED;
     a = root;
     b = NULL;
     if(root==NULL){
         root = k;
         k->parent = NULL;
     }
     else{
         while(a!=NULL){
              b = a;
              if((a->data)<(k->data))
                  a = a->right;
              else
                  a = a->left;
         }
         k->parent = b;
         if((b->data)<(k->data))
              b->right = k;
         else
              b->left = k;
     }
     insertfixup(k);
     cout << element << " has been inserted into the Tree." << endl;
}

void RedBlackTree::insertfixup(Node *&k){
     Node *z;
     if(root==k){
         k->color = BLACK;
         return;
     }
     while((((k->parent)!=NULL)&&(k->parent->color)==RED)){
        Node *w = k->parent->parent;
        if((w->left)==(k->parent)){
            if((w->right)!=NULL){
                  z = w->right;
                  if((z->color)==RED){
                       k->parent->color = BLACK;
                       z->color = BLACK;
                       w->color = RED;
                       k = w;
                  }
            }else{
                if((k->parent->right)==k){
                     k = k->parent;
                     rotateLeft(k);
                }
                k->parent->color = BLACK;
                w->color = RED;
                rotateRight(w);
            }
        }else{
            if((w->left)!=NULL){
                 z = w->left;
                 if((z->color)==RED){
                      k->parent->color = BLACK;
                      z->color = BLACK;
                      w->color = RED;
                      k = w;
                 }
            }else{
                if((k->parent->left)==k){
                       k = k->parent;
                       rotateRight(k);
                }
                k->parent->color = BLACK;
                w->color = RED;
                rotateLeft(w);
            }
        }
        root->color = BLACK;
     }
}

void RedBlackTree::deleteNode(Node *&k){
     if(root==NULL){
        cout << "The Tree is Empty! Can not perform delete operation!" << endl;
        return;
     }
     Node *x;
     x = root;
     Node *y = NULL;
     Node *z = NULL;
     int ispresent = 0;
     while((x!=NULL)&&(ispresent==0)){
            if(x->data == k->data)
                ispresent = 1;
            if(ispresent==0){
                if(x->data < k->data)
                    x = x->right;
                else
                    x = x->left;
            }
     }
     if(ispresent==0){
            cout << "The element has not been found!" << endl;
            return;
     }else{
        if(((x->left)==NULL)||((x->right)==NULL))
              y = x;
         else
              y = successor(x);
         if((y->left)!=NULL)
              z = y->left;
         else{
              if((y->right)!=NULL)
                   z = y->right;
              else
                   z = NULL;
         }
         if(z!=NULL)
              z->parent = y->parent;
         if((y->parent)==NULL)
              root = z;
         else{
             if(y == (y->parent->left))
                y->parent->left = z;
             else
                y->parent->right = z;
         }
         if(y!=x){
             x->color = y->color;
             x->data = y->data;
         }
         if((y->color)==BLACK)
             deletefixup(z);
     }
}

void RedBlackTree::deletefixup(Node *&k){
    Node *x;
    while((k!=root)&&((k->color) == BLACK)){
          if((k->parent->left)==k){
              x = k->parent->right;
              if((x->color)==RED){
                     x->color = BLACK;
                     k->parent->color = RED;
                     rotateLeft(k->parent);
                     x = k->parent->right;
              }
              if((x->right->color)==BLACK && (x->left->color)==BLACK){
                     x->color = RED;
                     k = k->parent;
              }
              else{
                  if((x->right->color)==BLACK){
                     x->left->color = BLACK;
                     x->color = RED;
                     rotateRight(x);
                     x = k->parent->right;
                  }
                  x->color = k->parent->color;
                  k->parent->color = BLACK;
                  x->right->color = BLACK;
                  rotateLeft(k->parent);
                  k = root;
              }
          }
          else{
              x = k->parent->left;
              if(x->color == RED){
                x->color = BLACK;
                k->parent->color = RED;
                rotateRight(k->parent);
                x = k->parent->left;
              }
              if(((x->left->color)==BLACK)&&((x->right->color)==BLACK)){
                    x->color = RED;
                    k = k->parent;
              }
              else{
                    if((x->left->color)==BLACK){
                          x->right->color = BLACK;
                          x->color = RED;
                          rotateLeft(x);
                          x = k->parent->left;
                    }
                    x->color = k->parent->color;
                    k->parent->color = BLACK;
                    x->left->color = BLACK;
                    rotateRight(k->parent);
                    k = root;
              }
          }
          k->color = BLACK;
          root->color = BLACK;
    }
}

Node* RedBlackTree::predecessor(Node *&k){
	Node *a = new Node;
	if(k->left){
        while(k->left->right)
            k->left = k->left->right;
		return k->left;
	}
	a = k->parent;
	while((a!=NULL)&&(k==(a->left))){
		k = a;
		a = a->parent;
	}
	return a;
}

Node* RedBlackTree::successor(Node *&k){
	Node *a = new Node;
	if(k->right){
        while(k->right->left)
            k->right = k->right->left;
        return k->right;
	}
	a = k->parent;
	while((a!=NULL)&&(k==(a->right))){
		k = a;
		a = a->parent;
	}
	return a;
}

Node* RedBlackTree::getMinimum(){
	Node *a;
	a = new Node;
    a = root;
	while(a->left)
		a = a->left;
	return a;
}

Node* RedBlackTree::getMaximum(){
	Node *a;
	a = new Node;
	a = root;
	while(a->right)
		a = a->right;
	return a;
}

Node* RedBlackTree::search(int element){
     if(root==NULL){
           cout << "The Tree is Empty! Couldn't find the element you searched for!" << endl;
           return  0;
     }
     Node *x = root;
     int ispresent = 0;
     while((x!=NULL)&&(ispresent==0)){
            if((x->data)==element) {
                ispresent = 1;
            }
            if(ispresent==0){
                 if((x->data)<element)
                    x = x->right;
                 else
                    x = x->left;
            }
     }
     if(ispresent==0){
          cout << "The element you are looking for has not been found!" << endl;
          return 0;
     }
     else
        return x;
}

// prints out the node or element along with its color
// in the Red Black Tree
void print(Node *node){
    cout << "Element of Tree: " << node->data << " Color" << ": ";
	if((node->color)==BLACK)
		cout << "BLACK" << endl;
	else
		cout << "RED" << endl;
}

int main(){
    RedBlackTree RBtree;
    // Inserting elements into the tree
    RBtree.insert(27);
    RBtree.insert(3);
    RBtree.insert(49);
    RBtree.insert(8);
    RBtree.insert(19);
    cout << endl;
    // find minimum element
	Node *minimum;
	minimum = RBtree.getMinimum();
	cout << "The minimum element of the tree is:" << endl;
	print(minimum);
	// find maximum element
	Node *maximum;
	maximum = RBtree.getMaximum();
	cout << "The maximum element of the tree is:" << endl;
	print(maximum);
	// Predecessor
    Node *pre;
    pre = RBtree.predecessor(maximum);
	cout << "Predecessor of the maximum element in the tree is:" << endl;
	print(pre);
    // Successor
	Node *after;
    after = RBtree.successor(minimum);
	cout << "Successor of the minimum element in the tree is:" << endl;
	print(after);
	cout << endl;
	// search for the minimum element
	cout << "Searching for the minimum element of the tree..." << endl;
	Node *z = RBtree.search(minimum->data);
	print(z);
    cout << "Element found! Search successful." << endl;
    cout << endl;
	// deleting Node minimum
	int temp = minimum->data;
	RBtree.deleteNode(minimum);
	cout << temp << " has been deleted from the Tree." << endl;
	cout << endl;
	cout << "Testing if delete function prints error message in an empty tree:" << endl;
	RedBlackTree E;
	Node *test;
	test = new Node;
	E.deleteNode(test);
	cout << "Test Successful!" << endl;
    return 0;
}
