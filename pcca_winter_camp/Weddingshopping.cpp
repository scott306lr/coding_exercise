#include <sstream>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int M,C;
string inpu;
vector<int> v[21];

int dp[21][201];

void solve(){
	cin >> M >> C; cin.ignore();
	for (int i=1; i<=C; ++i){
		getline(cin, inpu);
		stringstream ss(inpu);

		while( ss.good() ){
			int num; ss >> num;
			v[i].push_back(num);
		}
	}

	for (int j=0; j<=M; ++j)
		dp[0][j] = 0;
	
	for (int i=1; i<=C; ++i)
		for (int j=0; j<=M; ++j)
			dp[i][j] = -1;


	for (int i=1; i<=C; i++)
	  	//for (auto a : v[i])
	  	for (int k=0; k<v[i].size(); ++k){
	  		int a = v[i][k];
	      	for (int j=M; j>=0; j--)
	      		if (j >= a && dp[i-1][j-a] != -1)
	          		dp[i][j] = max(dp[i][j], dp[i-1][j-a] + a);
	  	}

	if (dp[C][M] == -1 )
		cout << "no solution" << '\n';
	else
		cout << dp[C][M] << '\n';
	// for (int i=1; i<=C; i++){
 //      	for (int j=0; j<=M; j++){
 //      		cout << dp[i][j] << " ";
 //      	}   
 //      	cout << '\n';
 //    }       
}		

int main(){
	cin.tie(0); cout.sync_with_stdio(0);
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		solve();
	}
}