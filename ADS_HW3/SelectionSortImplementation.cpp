#include <iostream>

using namespace std;

void selectionSort(int* arr, int num);
int main()
{
    cout << "Selection sort test or demo : " << endl;
    int num = 5;
    int arr[num] = {4,2,8,6,1};
    selectionSort(arr,num);
    cout << "After sorting using Selection Sort : " << endl;
    for(int j=0;j<num;j++){
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
