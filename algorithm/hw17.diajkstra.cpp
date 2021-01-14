#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
#define MAXW 100000000

struct W_edge{
	W_edge(int a, int b){
		des=a;
		w=b;
	}	
	int des;
	int w;
};

vector <W_edge> adj[10010];
int wlist[3][10010];
int n,m,u,v,w;


void dik(int start, int *weight){
	weight[start] = 0;
	priority_queue <pii> pq;
	pq.push( {0, start} );
	while(!pq.empty()){
		pii m = pq.top();
		pq.pop();

		for(auto a : adj[m.second]){
			int newW = weight[m.second] + a.w;
			if( weight[ a.des ] > newW ){
				weight[ a.des ] = newW;
				pq.push( {-newW, a.des} );
			}	
		}
	}
}

int main(){	
	cin >> n >> m >> u >> v >> w;
	int from, to, k;
	for(int i = 0; i < m; ++i){
		cin >> from >> to >> k;
		adj[from].push_back(W_edge(to,k));
	}

	for(int i=0; i<3; ++i){
		for(int j=0; j<n; ++j){
			wlist[i][j] = MAXW;
		}
	}

	dik(u, wlist[0]);
	dik(v, wlist[1]);
	dik(w, wlist[2]);

	int a = wlist[0][v] + wlist[1][w] + wlist[2][u];
	int b = wlist[0][w] + wlist[1][u] + wlist[2][v];
	
	if (a > MAXW && b>MAXW) 
		cout << -1 << '\n';
	else 
		cout << ((a < b) ? a : b) << '\n';

	return 0;
}


/*
	u -> v
	v -> w
*/