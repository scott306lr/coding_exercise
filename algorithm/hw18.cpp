#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;


vector<int> adj[int(1e5+10)], adjT[int(1e5+10)];

bool rec[int(1e5+10)];
int fin[int(1e5+10)];
int top=0;

int dfsCnt(int u){
	rec[u]=true;
	int Largest=0;
	for(auto a: adjT[u]){
		if(!rec[a]) Largest += dfsCnt(a);
	}
	return Largest+1;
}

void dfsTime(int u){
	rec[u]=true;
	for(auto a: adj[u]){
		if(!rec[a]) dfsTime(a);
	}
	fin[top++] = u;
}


int main(){
	int n,m,a,b;
	cin>>n>>m;
	for(int i=0; i<m; ++i){
		cin>>a>>b;
		adj[a].push_back(b);
		adjT[b].push_back(a);
	}
	// first DFS
	for(int i=0; i<n; ++i){
		if(!rec[i]) dfsTime(i);
	}

	// rec reset
	for(int i=0; i<n; ++i) rec[i]=false;

	// find second largest
	int M=0, ans=0, num=0;
	for(int i=top-1; i>=0; --i){
		if (!rec[fin[i]]) num = dfsCnt(fin[i]);
		else num = 0;

		if (num>M){
			ans=M; M=num;
		}
		else if (num>ans){
			ans=num;
		}
	}
	cout<<ans;
}



	// for(int i=0; i<n; ++i){
	// 	cout<<fin[i].first<<" ";
	// }
	// cout<<"\n";
	// for(int i=0; i<n; ++i){
	// 	cout<<fin[i].second<<" ";
	// }
	// cout<<"\n";