#include<iostream>
#include<vector>
#include<algorithm>
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
int records[3][10010];

int n,m,u,v,w;


void bell(int start, int *weight, int *rec){
	weight[start] = 0;

	for(int i=0; i<n-1; ++i){
		for(int j=0; j<n; ++j){
			for(auto a : adj[j]){
				if (weight[a.des] > weight[j]+a.w)
					weight[a.des] = weight[j]+a.w;
			}
		}

		bool same=true;
		for(int j=0; j<n; ++j){	
			if(rec[j]!=weight[j]){
				same=false;
				rec[j]=weight[j];
			} 
		}
		if (same==true) return;
	}
}

int main(){	
	cin>>n>>m>>u>>v>>w;
	int from,to,k;
	for(int i=0; i<m; ++i){
		cin>>from>>to>>k;
		adj[from].push_back(W_edge(to,k));
	}

	for(int i=0; i<3; ++i){
		for(int j=0; j<n; ++j){
			wlist[i][j]=MAXW;
		}
	}

	bell(u,wlist[0],records[0]);
	bell(v,wlist[1],records[1]);
	bell(w,wlist[2],records[2]);

	int a=wlist[0][v]+wlist[1][w]+wlist[2][u];
	int b=wlist[0][w]+wlist[1][u]+wlist[2][v];
	if (a>MAXW || b>MAXW) cout<< -1 << '\n';
	else cout<< ((a<b) ? a : b) << '\n';
}


/*
	u -> v
	v -> w
*/