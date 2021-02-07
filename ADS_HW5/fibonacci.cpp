#include <iostream>
#include <time.h>
#include <bits/stdc++.h>
#include <chrono>
#include <algorithm>

using namespace std;
using namespace std::chrono;


//Recursive Fibonacci function
int Fibonacci(int x){
    if(x==0||x==1)
        return x;
    else{
        return (Fibonacci(x-1)+Fibonacci(x-2));
    }
}

//closed form implementation
int closedformfib(int x){
    int fibon = 0;
	int fibseq[6] = {0,1,1,2,3,5};
	if(x<6)
        return fibseq[x];
    int y = 5;
    fibon = 5;
    while(y<x){
        fibon = round(fibon * (1.6180339));
        y++;
    }
	return fibon;
}

void matrixmultiply(int m[2][2], int q[2][2])
{
    int matrixarr[2][2];
    for(int i = 0;i<2;i++)
        for(int j = 0;j<2;j++){
            matrixarr[i][j] = 0;
            for(int k = 0;k<2;k++)
                matrixarr[i][j] += m[i][k]*q[k][j];
            }
    for(int g =0; g<2; g++)
        for(int h=0; h<2; h++)
            m[g][h] = matrixarr[g][h];
}

int matrixpow(int arr[2][2], int n){
    int matr[2][2] = {{1,1}, {1,0}};
    if (n==1)
        return arr[0][0] + arr[0][1];
    matrixpow(arr, n/2);
    matrixmultiply(arr, arr);

    if (n%2!=0)
        matrixmultiply(arr, matr);
    return arr[0][0] + arr[0][1];
}

int findtermn(int n){

    int arr[2][2] = {{1,1}, {1,0}};
    if(n==0)
        return 0;
    if(n==1 || n==2)
        return 1;
    return matrixpow(arr, n-2);
}

int main(){
    int m = 1;
    while(m<15){
        cout << "The Fibonacci sequences: " << endl;
        if(m<4)
            m = m+1;
        else
            m = 2*m;
        int i = 0, j =0, sum = 0;
        //naive recursive Fibonacci function implementation
        cout << "Naive Recursive Fibonacci sequence Implementation" << endl;
        auto starttime1 = chrono::high_resolution_clock::now();
        for(i = 0;i<m;i++)
            cout << Fibonacci(i) << " ";
        auto endtime1 = chrono::high_resolution_clock::now();
        cout << endl;
        auto time1 = duration_cast<chrono::microseconds>(endtime1 - starttime1);
        cout << "Computation time is " << time1.count() << " microseconds." << endl;
        //bottom up approach
        cout << "Bottom up approach Fibonacci sequence Implementation" << endl;
        int fibpreprev = 0, fibprev = 1;
        auto starttime2 = chrono::high_resolution_clock::now();
        cout << 0 << " " << 1 << " ";
        for(j=0;j<m-2;j++){
            sum = fibprev + fibpreprev;
            cout << sum << " ";
            fibpreprev = fibprev;
            fibprev = sum;
        }
        auto endtime2 = chrono::high_resolution_clock::now();
        cout << endl;
        auto time2 = duration_cast<chrono::microseconds>(endtime2 - starttime2);
        cout << "Computation time is " << time2.count() << " microseconds." << endl;
        //closed form implementation
        cout << "Closed form Fibonacci sequence Implementation" << endl;
        auto starttime3 = chrono::high_resolution_clock::now();
        for(int k = 0;k<m;k++)
            cout << closedformfib(k) << " ";
        auto endtime3 = chrono::high_resolution_clock::now();
        cout << endl;
        auto time3 = duration_cast<chrono::microseconds>(endtime3 - starttime3);
        cout << "Computation time is " << time3.count() << " microseconds." << endl;
        //matrix form
        cout << "Matrix form Fibonacci sequence Implementation" << endl;
        auto starttime4 = chrono::high_resolution_clock::now();
        for(int r = 0;r<m;r++)
            cout << findtermn(r) << " ";
        auto endtime4 = chrono::high_resolution_clock::now();
        cout << endl;
        auto time4 = duration_cast<chrono::microseconds>(endtime4 - starttime4);
        cout << "Computation time is " << time4.count() << " microseconds." << endl;
    }
    return 0;
}
