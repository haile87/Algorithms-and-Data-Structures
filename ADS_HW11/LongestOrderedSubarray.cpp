#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void LongestOrderedSubarray(int arr[], int arrsize) {
     /*Now, we will create two other arrays, one array storing
       length of all ordered subarrays and another array that
       stores the positions of the elements that are in the
       ordered subarrays.*/
    int lengthsubarr[arrsize], subarrpos[arrsize];
    // We initialize each entry of lengthsubarr[] as 1, since at first
    // every element is an ordered subarray itself of length 1.
    for(int x=0;x<arrsize;x++)
        lengthsubarr[x] = 1;
    for(int i=1;i<arrsize;i++){
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]){
                lengthsubarr[i] = max(lengthsubarr[i], lengthsubarr[j]+1);
                if(lengthsubarr[i] == (lengthsubarr[j]+1))
                	subarrpos[i] = j;
            }
        }
    }
    int z, y = lengthsubarr[0];
    for(int t=0;t<arrsize;t++) {
        if(lengthsubarr[t]>y) {
            y = lengthsubarr[t];
            z = t;
        }
    }
    int longestsubarray[y];
    for(int h=y-1;h>=0;h--){
        longestsubarray[h] = z;
        z = subarrpos[z];
    }
    for(int j=0;j<y;j++)
        cout << arr[longestsubarray[j]] << " ";
    cout << endl;
}

int main(){
    string arrstr;
    getline(cin, arrstr);
    istringstream inpstrA(arrstr);
    int x = 0, counter = 0;
    while(inpstrA >> x){
        counter++;
    }
    istringstream inpstrB(arrstr);
	int arr[counter];
	for(int i=0;i<counter;i++){
        int element;
        inpstrB >> element;
        arr[i] = element;
    }
	LongestOrderedSubarray(arr, counter);
	return 0;
}
