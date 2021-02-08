#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
typedef pair<int, int> pii;


string inpu;
int w,s;
vector <pii> v;

int dp[100000];


int main(){
	int N = 0; int W=0;
	while(cin >> w && cin >> s){
		if (w==0 && s==0) break;
		N++; W += w;
		v.push_back({w, s});
	}
	
	
  	for (int i=W; i>=0; i--){
  		for (int j=0; j<N; j++){
      		if (v[j].second >= i+v[j].first)
          		dp[i] += dp[i+v[j].first] + 1;
          	else
          		dp[i] = dp[i+1];
      	}
    }

   //  int MMM=0;  	
   //  for(int i=0; i<W; ++i){
   //  	MMM = max(MMM, dp[i]);
   //  }

  	// cout << MMM << '\n';
  	cout << dp[0];

}