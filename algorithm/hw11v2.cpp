//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
typedef pair<int,int> pii;

int n; 
string inpu; 
int dp[7001][7001];


int main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin >> n ;
	cin >> inpu;
	for(int i=0; i<n; ++i) dp[i][i]=1;
	
	for(int len=2; len<=n; ++len){ //try bottom-up
		for(int i=0; i+len-1<n; ++i){
			int j=i+len-1;
			
			if( inpu[i]==inpu[j] )	dp[i][j] = max(dp[i][j], dp[i+2][j-2]+2);

			dp[i][j] = max(dp[i][j],max( dp[i+1][j] , dp[i][j-1] ));
		}
	}
	//cout<< dp[0][n-1];

	// for (int i = 0; i < n; ++i)
	// {
	// 	for (int j = 0; j < n; ++j)
	// 	{
	// 		cout<<dp[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	cout<< dp[0][n-1];
}