#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001];

int sa, sb;
string A, B;

int main(){
	cin >> sa >> sb;
	cin >> A >> B;

	for(int j=1; j<sa; ++j)
		dp[j][0] = 0;

	for(int j=1; j<sb; ++j)
		dp[0][j] = 0;


	for(int i=1; i<=sa; ++i){
		for(int j=1; j<=sb; ++j){
			if( A[i-1] == B[j-1])
				dp[i][j] = dp[i-1][j-1] + 1;
			else
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}

	//cout << dp[sa][sb] << '\n';

	int lcs = 0; 
	int x=0,y=0;
	for(int i=1; i<=sa; ++i){
		for(int j=1; j<=sb; ++j){
			if( dp[i][j] > prevlcs && (i-x + j-y) <= 4){
				lcs = dp[x][y];
			}
			ans = max(ans, 4*dp[i][j] - i - j);
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	cout << ans;
}
/*
abbbbbbbbbbbbba
accccccccccccca
*/


