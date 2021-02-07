#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Bucket sort implementation
void bucketSort(double* arr, int x){
    int i = 0;
    vector<double> arrnew[x];
    for(i=0;i<x;i++){
       int index = x*arr[i];
       arrnew[index].push_back(arr[i]);
    }
    for(i=0;i<x;i++)
       sort(arrnew[i].begin(), arrnew[i].end());
    int pos = 0;
    for(i=0;i<x;i++){
        for(unsigned int j = 0;j<arrnew[i].size();j++){
          arr[pos++] = arrnew[i][j];
        }
    }
}

int main(){
    int arrsize = 7;
    double arr[arrsize] = {0.9,0.1,0.6,0.7,0.6,0.3,0.1};
    bucketSort(arr,arrsize);
    for(int i = 0;i<arrsize;i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
