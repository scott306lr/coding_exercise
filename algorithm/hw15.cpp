#include<iostream>
#include<vector>
using namespace std;

struct Vertex{
	vector<int> edg;

} vtx[5001];

int cnt;

void dfs(bool *rec, int ver){
	if(rec[ver]==true) return;
	
	rec[ver]=true; cnt++;

	int s = vtx[ver].edg.size();
	for(int i=0; i<s; ++i){
		dfs(rec,vtx[ver].edg[i]);
	}
}

void remove(int u, int v){
	int s = vtx[u].edg.size();
	for(int i=0; i<s; ++i){
		if (vtx[u].edg[i] == v){
			vtx[u].edg[i] = u;
			break;
		}
	}

	s = vtx[v].edg.size();
	for(int i=0; i<s; ++i){
		if (vtx[v].edg[i] == u){
			vtx[v].edg[i] = v;
			break;
		}
	}
}

int findsize(int v){
	bool rec[5001]={false};
	cnt=0;
	dfs(rec,v);
	return cnt;
}

void connect(int u, int v){
	vtx[u].edg.push_back(v);
	vtx[v].edg.push_back(u);
}

int main(){
	int n,m,q,u,v;
	cin.tie(0), cout.sync_with_stdio(0);
	cin>>n>>m>>q;
	for(int i=0; i<m; ++i){
		cin>>u>>v;
		connect(u,v);
	}

	for(int i=0; i<q; ++i){
		cin>>u>>v;
		if(u<0) cout<< findsize(v)<<'\n';
		else remove(u,v);
	}
}