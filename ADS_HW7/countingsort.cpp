#include <iostream>

using namespace std;

void countingSort(int arr[], int x, int k){
    int arroutput[x];
    int auxarr[k+1], i = 0;
    for(i=0;i<=k;i++)
        auxarr[i] = 0;
    for(i=0;i<x;i++)
        auxarr[arr[i]] = auxarr[arr[i]] + 1;
    for(i=1;i<=k;i++)
        auxarr[i] = auxarr[i] + auxarr[i-1];
    for(i=x-1;i>=0;i--){
        arroutput[auxarr[arr[i]]-1] = arr[i];
        auxarr[arr[i]] = auxarr[arr[i]] - 1;
    }
    for(i=0;i<x;i++)
        arr[i] = arroutput[i];
}

int main(){
    // Counting sort algorithm implementation
    int arrsize = 7, k = 9;
    int arr[arrsize] = {9,1,6,7,6,2,1};
    countingSort(arr,arrsize,k);
    for(int j = 0;j<arrsize;j++){
        cout << arr[j] << " ";
    }
    cout << endl;
    return 0;
}
