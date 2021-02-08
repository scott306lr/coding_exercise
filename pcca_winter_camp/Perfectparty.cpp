#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;


//int rootcnt[5001][5001];
int p[1001],Rank[1001];
int A[1001], B[1001];
bool rec[1001]; int recf[1001];
vector<pii> v[1001];

int dp[1001][1001];

void link (int x, int y){
	if (Rank[x] > Rank[y]) {
		p[x] = y;
		Rank[x] = Rank[y];
	}else{
		p[y] = x;
		Rank[y] = Rank[x];
	}
	
}

void makeSet(int x){
	p[x] = x;
	Rank[x] = x;
}

int findSet(int x){
	if (x!=p[x]) p[x] = findSet(p[x]);
	return p[x];
}

void Union(int x, int y){
	link(findSet(x),findSet(y));
}


int findLen(int x){
	int root = findSet(x);
	return Rank[root];
}

int main(){
	cin.tie(0), cout.sync_with_stdio(0);
	int n, m, k; int at, to;
	cin >> n >> m >> k;
	for(int i=0; i<m; ++i){
		cin >> A[i] >> B[i];
		makeSet(i);
	}

	for(int i=0; i<k; ++i){
		cin >> at >> to;
		Union(at-1, to-1);
	} 

	int field = 0;
	for(int i=0; i<m; ++i){
		int temp = findLen(i);
		if(!rec[temp]){
			rec[temp] = true;
			field++;
			recf[temp] = field;	
		}

		v[recf[temp]].push_back({A[i], B[i]});
	}
	
	for (int i=1; i<=field; ++i){
		for (int j=0; j<=n; ++j){
			dp[i][j] = -1;
		}
	}

	for (int i = 1; i <= field; i++)
	  	for (auto a : v[i])
	      	for (int j = n; j >= 0; j--)
	      		if (j >= a.first && dp[i-1][j-a.first] != -1)
	          		dp[i][j] = max(dp[i][j], dp[i-1][j-a.first] + a.second);

	if (dp[field][n] == -1 )
		cout << "trash problem" << '\n';
	else
		cout << dp[field][n] << '\n';
	
}	
