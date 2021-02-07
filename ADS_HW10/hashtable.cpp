#include <iostream>

using namespace std;

class Node{
    public:
        int key;
        int value;
        Node(int key, int value){
            this->value = value;
            this->key = key;
        }
};

class HashTable{
    private:
        Node **arr;
        int maxSize;
        int currentSize;
    public:
        HashTable(){
            /* The maximum size is chosen based on the amount
             of input data, here 5 is chosen as the maximum size
             as there will be 4 elements in my hash table. This
             will create a hash table that holds all the values entered and will
             also demonstrate that some places in the hash table can be empty
             too.*/
            maxSize = 5;
            currentSize = 0;
            arr = new Node*[maxSize];
            for(int i = 0;i<maxSize;i++){
                arr[i] = NULL;
            }
        };
        /* This hash code is the basic hash function h that is used to form a hash
         table using linear probing. The value of m has been selected here in such a way
         that it gives different remainders when divided by
         the input data to avoid collisions. A power of two or an even non
         prime number would result in collisions. So, since a good m value
         would be an odd prime number and not a power of two, this hash function is
         well suited for the data as the m value used here that is 5 satisfies
         these conditions.*/
        int hashCode(int key){
            return key%maxSize;
        }
        void insertNode(int key, int value){
            if(maxSize>currentSize){
                Node *temp = new Node(key, value);
                // index i
                int i = hashCode(key);
                while((arr[i]!=NULL)&&(arr[i]->key!=key)){
                    i++;
                    i %= maxSize;
                }
                if(arr[i]==NULL)
                    currentSize++;
                arr[i] = temp;
            }else
                return;
        }
        int get(int key){
            int i = hashCode(key);
            while(arr[i]!=NULL){
                int counter = 0;
                if(counter++ > maxSize)
                    return 0;
                if((arr[i]->key)==key)
                    return arr[i]->value;
                i++;
                i %= maxSize;
            }
            return 0;
        }
        bool isEmpty(){
            return (currentSize==0);
        }
        void hashtable_print(){
            int i = 0;
            for(i=0;i<maxSize;i++){
                if(arr[i]!=NULL) {
                    cout << "Index " << i << ": Key: " << arr[i]->key << " Value: ";
                    cout << arr[i]->value << endl;
                    cout << "*********" << endl;
                }
                if(arr[i]==NULL){
                    cout << "Index " << i << " : " << "-" << endl;
                    cout << "This place in the hash table is empty" << endl;
                    cout << "*********" << endl;
                }
            }
        }
};

int main(){
    HashTable *hashtable;
    hashtable = new HashTable;
    hashtable->insertNode(9,8);
    hashtable->insertNode(6,62);
    hashtable->insertNode(22,5);
    hashtable->insertNode(18,34);
    hashtable->hashtable_print();
    cout << endl;
    cout << "The value of key 22 is ";
    cout << hashtable->get(22) << endl;
    return 0;
}
