#include <iostream>
#include <bits/stdc++.h>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

const int INF = 1000000000;
int nitrogen[1000], oxygen[1000], weight[1000];
int cylinderstoequip[1000][21][79];

int minimumtotalweight(int x, int oxy, int nitro){
	if(cylinderstoequip[x][oxy][nitro] != -1){
		return cylinderstoequip[x][oxy][nitro];
	}
	if(oxy==0 && nitro==0){
		cylinderstoequip[x][oxy][nitro] = 0;
	}
	// if we still have not reached a solution after taking all cylinders,
	// return INF to eliminate the recursive paths that lead to this scenario
	else if(x==0){
		cylinderstoequip[x][oxy][nitro] = INF;
    }else{
        // comparing
		cylinderstoequip[x][oxy][nitro] = min(minimumtotalweight(x-1,oxy,nitro),
            minimumtotalweight(x-1,max(oxy-oxygen[x-1],0),max(nitro-nitrogen[x-1],0))+weight[x-1]);
	}
	return cylinderstoequip[x][oxy][nitro];
}

list<int> cylinderlist;
void scubadivercylinders(int x, int oxy, int nitro){
    int a = x, b = oxy, c = nitro, d = cylinderstoequip[x][oxy][nitro];
    for(;d>0 && a>0;a--){
        if(cylinderstoequip[a][b][c] != cylinderstoequip[a-1][b][c]){
            d = d - weight[a-1];
            if(b <= oxygen[a-1])
                b = 0;
            else
                b = b - oxygen[a-1];
            if(c <= nitrogen[a-1])
                c = 0;
            else
                c = c - nitrogen[a-1];
            cylinderlist.push_front(a);
        }
    }
}

int main(){
    int num = 0;
	cin >> num;
	int o = 0, n = 0, cyl = 0;
    // o = oxygen volume, n = nitrogen volume, cyl = number of accessible cylinders
	while(num--){
	 	cin >> o >> n >> cyl;
		for(int i=0;i<=cyl;i++)
			for(int j=0;j<=o;j++)
				for(int k=0;k<=n;k++)
					cylinderstoequip[i][j][k] = -1;
		for(int y = 0;y<cyl;y++)
            cin >> oxygen[y] >> nitrogen[y] >> weight[y];
        // print the minimum total weight and indexes of the cylinders respectively
		cout << minimumtotalweight(cyl, o, n) << endl;
		scubadivercylinders(cyl, o, n);
		list<int>::iterator liter;
		for(liter = cylinderlist.begin();liter!=cylinderlist.end();liter++)
            cout << *liter << " ";
	}
	return 0;
}
// Reference: https://codinghangover.wordpress.com/2015/03/11/spojscubadiv-scuba-diver/
