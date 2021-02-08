#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> pii;
#define MAX 21474836472147483647

int n,m,a,b,c;
vector <pii> v[100001];
int pi[100001];
long long w[100001];


void dfsp(int at){
	if (pi[at] == at) return;
	dfsp(pi[at]);
	cout << at << " ";
}

void printpath(){
	if (pi[n] == n){
		cout << -1 << '\n';
		return;
	}

	cout << 1 << " ";
	dfsp(n);
}

void dik(){
	priority_queue<pii> pq;

	w[1] = 0; 
	pq.push({0,1});

	while(!pq.empty()){
		pii p = pq.top(); int at = p.second;
		pq.pop();

		for ( auto a : v[at] ){
			long long newW = w[at] + a.second;
			if ( w[a.first] > newW ){
				w[a.first] = newW;
				pi[a.first] = at;
				pq.push({-newW, a.first});
			}
		}
	}
}

int main(){
	cin >> n >> m;
	for(int i=1; i<=m; ++i){
		cin >> a >> b >> c;
		v[a].push_back({b, c});
		v[b].push_back({a, c});
	}

	for(int i=1; i<=n; ++i)
		pi[i] = i, w[i] = MAX;

	dik();
	printpath();
}