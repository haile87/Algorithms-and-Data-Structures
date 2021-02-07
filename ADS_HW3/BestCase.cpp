#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void selectionSort(int*, int);

int main()
{
    /*For the best case scenario or the case with the least swaps(Case B), an array was inputted to selectionSort algorithm
      after it was already sorted to simulate the best case scenario. The Random sequence generator function in C++ was
      used in coming up with the random input and this input was sorted then fed into the selectionSort algorithm.*/
    srand(time(NULL));
    int arr[100];
    int i = 0;
    int k = 0;
    for(k=0;k<100;k++){
        arr[k] = rand();
    }
    for(i=0;i<100;i++){
        if(arr[i]<arr[i+1]){
            int temp = arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
        }
    }
    selectionSort(arr,100);
    int j = 0;
    for(j=0;j<100;j++){
        cout << arr[j] << ' ';
    }
    cout << endl;
    return 0;
}

void selectionSort(int* arr, int num){
   int x = 0, y = 0, minval;
   for(x=0;x<num-1;x++){
      minval = x;
      for(y=x+1;y<num;y++)
         if(arr[y] < arr[minval])
            minval = y;
         int temp = arr[x];
         arr[x] = arr[minval];
         arr[minval] = temp;
   }
}
