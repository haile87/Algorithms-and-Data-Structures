#include <iostream>
#include <string>

using namespace std;

// gets max value of string array
size_t stringmaxval(string* arr, int x){
    size_t max = arr[0].size();
    for(int i = 1;i<x;i++){
        if(arr[i].size()>max)
            max = arr[i].size();
    }
    return max;
}

void countingSort(string s[], int arrsize, size_t m){
    string *v = NULL;
    int *w = NULL;
    v = new string[arrsize];
    w = new int[257];
    for(int i = 0;i<257;i++){
        w[i] = 0;
    }
    for(int j = 0;j<arrsize;j++){
        w[m<s[j].size() ? (int)(unsigned char)s[j][m] + 1 : 0]++;
    }
    for (int r = 1;r<257;r++){
        w[r] += w[r - 1];
    }
    for(int y = arrsize - 1;y>=0;y--){
        v[w[m < s[y].size() ? (int)(unsigned char)s[y][m] + 1 : 0] - 1] = s[y];
        w[m < s[y].size() ? (int)(unsigned char)s[y][m] + 1 : 0]--;
    }
    for(int d = 0;d<arrsize;d++){
        s[d] = v[d];
    }
    delete [] v;
    delete [] w;
}

void radixSort(string s[], int x){
    size_t max = stringmaxval(s, x);
    for (size_t num = max;num>0;num--){
        countingSort(s, x, num - 1);
    }
}

int main(){
    string s[] = {"word", "category", "cat", "new", "news", "world", "bear", "at", "work", "time"};
    radixSort(s, 10);
    for(int i = 0;i<10;i++)
        cout << s[i] << " ";
    cout << endl;
    return 0;
}
