#include <iostream>
#include <bits/stdc++.h>
#include <deque>
#include <algorithm>

using namespace std;

// define maximum size of the triangle globally
// makes max number of lines in triangle 100
int triangle[100][100];

void trianglesum(int trianglearr[100][100], int x){
    int copytriangle[100][100];
    // copytriangle[100][100] will be used to contain a copy of the original triangle
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            copytriangle[i][j] = trianglearr[i][j];
        }
    }
    if(x>1){
        copytriangle[1][1] = copytriangle[1][1] + copytriangle[0][0];
        copytriangle[1][0] = copytriangle[1][0] + copytriangle[0][0];
    }
    for(int j=2;j<x;j++){
        copytriangle[j][0] = copytriangle[j][0] + copytriangle[j-1][0];
        copytriangle[j][j] = copytriangle[j][j] + copytriangle[j-1][j-1];
        for(int k=1;k<j;k++){
            if(copytriangle[j-1][k-1] >= copytriangle[j-1][k]){
                copytriangle[j][k] = copytriangle[j][k] + copytriangle[j-1][k-1];
            }else{
                copytriangle[j][k] = copytriangle[j][k]+copytriangle[j-1][k];
            }
        }
    }
    // find the maximum among the sums
    int maximum = copytriangle[x-1][0];
    int maxindex;
    for(int i=1;i<x;i++){
        if(maximum < copytriangle[x-1][i]){
            maximum = copytriangle[x-1][i];
            maxindex = i;
        }
    }
    cout << maximum << endl;
    // find the path forming the maximum sum
    deque<int> dtriangle;
    for(int i=x-1;i>=0;i--){
        if(maxindex==0){
            for(int j=i;j>=0;j--)
                dtriangle.push_front(triangle[j][0]);
            break;
        }else if(maxindex==i) {
            for(int k=i;k>=0;k--)
                dtriangle.push_front(triangle[k][k]);
            break;
        }else{
            dtriangle.push_front(triangle[i][maxindex]);
            if(copytriangle[i-1][maxindex-1] >= copytriangle[i-1][maxindex]){
                maxindex--;
            }
        }
    }
    // print the path forming the maximum sum
    for(unsigned int y=0;y<dtriangle.size();y++){
        cout << dtriangle[y];
        if(y!=(dtriangle.size()-1))
            cout << " ";
    }
}

int main(){
    int h = 0;
    while(1) {
        label:;
        string tristr;
        getline(cin, tristr);
        if(tristr=="")
            break;
        for(int r=0;tristr[r];r++){
            if(!isdigit(tristr[r]) && (tristr[r]!=' ')){
                cout << "The data entered is invalid!" << endl;
                goto label;
            }
        }
        int countspace=0, countnum=0;
        for(int x=0;tristr[x];x++){
            if(tristr[x] == ' ')
                countspace++;
        }
        istringstream inpstrA(tristr);
        int val;
        // the values should not be larger than 10,000
        while(inpstrA >> val){
            if((val>10000)&&(val<0)){
                cout << "The number you entered is out of range!" << endl;
                goto label;
            }
            countnum++;
        }
        if((countnum == (countspace+1)) && (countspace == h)){
            istringstream inpstrB(tristr);
            for(int s=0;s<=h;s++) {
                int element;
                inpstrB >> element;
                triangle[h][s] = element;
            }
            h++;
        }else{
            cout << "The data entered is invalid!" << endl;
        }
    }
    trianglesum(triangle, h);

    return 0;
}
// Reference: http://himangi774.blogspot.com/2013/05/find-maximum-sum-in-triangle-from-top.html
// Used the info on this site to get an idea on how to implement the solution
