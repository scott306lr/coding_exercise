//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef pair<int,int> pii;

int n; 
string inpu; 
int range[7001][7001];

int solve(int s, int e){
	if (s>e)    return 0;
	if (range[s][e]!=0) return range[s][e];
	int maxnum=1;
	for (int i=e; i>1; --i){
		if ( (i-s) <= maxnum*2-1 ) break;

		for (int j=0; j<i-1; ++j){
			if ( (i-j) <= maxnum*2-1 ) break;
			if (range[j][i]!=0){	
				maxnum = max(range[j][i] , maxnum);
			}
			else if (inpu[i]==inpu[j]){
				int val = max(solve(j+2,i-2)+2 , maxnum);
				maxnum = max(val , maxnum);
			}
		}
	}

	range[s][e]=maxnum;
	return maxnum;
}

int main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> n ;
	cin >> inpu;
	cout<< solve(0,n-1);
	
}