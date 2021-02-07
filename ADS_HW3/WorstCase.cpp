#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

void selectionSort(int* arr, int num);
int main()
{
    /*For the worst case scenario or the case with the most swaps(Case A), a random number generator in C++ was used to generate
        randomized input and fed into the selectionSort algorithm.*/
    srand(time(NULL));
    int arr[100];
    int k = 0;
    for(k=0;k<100;k++){
        arr[k] = rand();
    }
    selectionSort(arr,100);
    int j = 0;
    for(j=0;j<100;j++){
        cout << arr[j] << ' ';
    }
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
