#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void radixSort(vector<int>&x);
void radixSort(vector<int>&x, int exponent);
void radixSort(vector<int>&x, int exponent, int y);
int num(int k, int v);
int maximum(vector<int>&x);

int num(int x, int e){
	int y = ((x/e) % 10);
	return y;
}
int maximum(vector<int>&arr){
	int m = arr[0];
	for(int i = 1; i<(int)arr.size();i++)
		if(arr[i]>m)
			m = arr[i];
	return m;
}

void radixSort(vector<int>&arr, int exponent, int x){
    int i = 0;
	if(exponent == 0)
		return;
	int z = arr.size();
	vector<vector<int>>v(10);
	for(i=0;i<10;i++)
		v.push_back(vector<int>());
	for(i=0;i<z;i++)
		v[num(arr[i],exponent)].push_back(arr[i]);
	for(i=0;i<10;i++){
		if(v[i].size() >= 1)
			radixSort(v[i], exponent/10, 3);
	}
	int index = 0;
	for(int j = 0;j<10;j++){
		if(v[j].size() >= 1){
			for(int i = 0; i < (int)v[j].size();i++)
				arr[index++] = v[j][i];
		}
	}
}

void radixSort(vector<int>&arr, int exponent){
	if(exponent == 0)
		return;
	int x = arr.size();
	vector<vector<int>>m(10);
	for(int i = 0;i<10;i++)
		m.push_back(vector<int>());
	for(int i = 0; i < x; i++)
		m[num(arr[i],exponent)].push_back(arr[i]);
	for (int i = 0;i<10;i++){
		if (m[i].size() >= 1)
			radixSort(m[i], exponent/10, 7);
	}
	int index = 0;
	for(int j = 0; j < 10; j++){
		if(m[j].size() >= 1){
			for(int i = 0; i < (int)m[j].size();i++)
				arr[index++] = m[j][i];
		}
	}
}
void radixSort(vector<int>&arr){
	int m = maximum(arr);
	int i = -1;
	for(int x = 1;(m/x)>0;x = x*10)
		i++;
	radixSort(arr, static_cast<int>(pow(10,i)));
}

int main(){
	vector<int>test = {749, 61, 52, 4, 20, 378, 178, 856, 245, 10};
	radixSort(test);
	for(int i = 0;i<10;i++)
		cout << test[i] << " ";
	cout << endl;
	return 0;
}
