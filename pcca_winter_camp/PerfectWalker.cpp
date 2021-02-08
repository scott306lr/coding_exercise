#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> ppi;

vector <pii> adj[100010];
bool rec[100010];
long long pathw[100010];
long long n, a, b, w;
int longestp = 0;

void dfs(int s, long long curw){
	rec[s] = true;
	pathw[s] = curw;

	for (auto a : adj[s]){
		if (rec[a.first]) continue;
		dfs(a.first, curw + a.second);
	}
	return;
}

int main(){
	cin.tie(0); cout.sync_with_stdio(0);
	cin >> n;

	long long ans = 0;
	for (int i=0; i<n-1; ++i){
		cin >> a >> b >> w;
		adj[a-1].push_back({b-1, w});
		adj[b-1].push_back({a-1, w});
		ans += w*2;
	}

	dfs(0,0);

	long long maxw = -1; 
	for (int i=0; i<n; ++i){
		if( pathw[i] > maxw){
			maxw = pathw[i];
			longestp = i;
		}
	}

	for (int i=0; i<n; ++i)
		rec[i] = false, pathw[i] = 0;

	dfs(longestp, 0);

	maxw = -1;
	for (int i=0; i<n; ++i){
		if( pathw[i] > maxw){
			maxw = pathw[i];
		}
	}

	cout << (ans - maxw) << '\n';
    return 0;  
}