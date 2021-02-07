#include <iostream>

using namespace std;

void heapsort(int* arr, int arrsize);
void maxheapify(int* arr, int arrsize, int x);
void buildmaxheap(int* arr, int arrsize);
void heapsortvariant(int* arr, int arrsize);

int main(){
    int arrsize = 10;
    int arr[arrsize] = {5,9,3,12,23,6,1,8,4,56};
    cout << "Original Heap sort algorithm we learned in class: " << endl;
    heapsort(arr,arrsize);
    for(int j=0;j<arrsize;j++){
        cout << arr[j] << " ";
    }
    cout << endl;
    int arrvar[7] = {4,7,3,9,2,5,1};
    cout << "A variant of heap sort: " << endl;
    heapsortvariant(arrvar,7);
    for(int m=0;m<7;m++){
        cout << arrvar[m] << " ";
    }
    cout << endl;
    return 0;
}
void heapsort(int* arr, int arrsize){
    int sizeofheap = arrsize;
    int i = 0;
    int temp = 0;
    buildmaxheap(arr,arrsize);
    for(i=arrsize;i>=1;i--){
        temp = arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        sizeofheap = sizeofheap - 1;
        maxheapify(arr,sizeofheap,0);
    }
}
void buildmaxheap(int* arr, int arrsize){
    for(int k = arrsize/2;k>=0;k--)
        maxheapify(arr,arrsize,k);
}
void maxheapify(int* arr, int arrsize, int x){
    int largestelem = x, tempvar = 0;
    int a = 2*x + 1;
    int b = 2*x + 2;
    if(a<=arrsize && arr[a]>arr[x])
        largestelem = a;
    else
        largestelem = x;
    if(b<=arrsize && arr[b]>arr[largestelem])
        largestelem = b;
    if(largestelem!=x){
        tempvar = arr[x];
        arr[x] = arr[largestelem];
        arr[largestelem]=tempvar;
        maxheapify(arr,arrsize,largestelem);
    }
}

/* heap sort variant for question b involving
   floating the root to leaf level instead of calling max-heapify*/
void heapsortvariant(int* arr, int arrsize){
    int i = arrsize - 1;
    int temp = 0;
    buildmaxheap(arr,arrsize);
    temp = arr[0];
    arr[0]=arr[i];
    arr[i]=temp;
    if(arr[0]<arr[i]){
        temp = arr[i];
        arr[i]=arr[0];
        arr[0]=temp;
    }
    for(int x = 0;x<arrsize;x++){
        if(arr[x]>arr[x+1]){
            int temp2 = arr[x];
            arr[x] = arr[x+1];
            arr[x+1] = temp2;
        }
    }
}
