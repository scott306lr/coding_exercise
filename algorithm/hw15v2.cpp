#include<iostream>
#include<vector>
#include<stack>
#include<set>
using namespace std;
typedef pair<int,int> pii;


//int rootcnt[5001][5001];
int p[5001],Rank[5001];
int rec[5001][5001];
int n,m,q,u,v;

void link (int x, int y){
	if (Rank[x] > Rank[y]) {
		p[y] = x;
		Rank[x] += Rank[y];
		//cout<<"LINK "<<x<<", "<<y<<": "<<Rank[x]<<"+="<<Rank[y]<<'\n';
	}else{
		p[x] = y;
		if (x!=y) Rank[y] += Rank[x];
		//if (x!=y) cout<<"LINK "<<y<<", "<<x<<": "<<Rank[y]<<"+="<<Rank[x]<<'\n';
	}
	
}

void makeSet(int x){
	p[x] = x;
	Rank[x] = 1;
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

	stack <pii> cmdStack;
	stack <int> outStack;
	vector<pii> ss;

	cin>>n>>m>>q;

	for(int i=0; i<n; ++i) makeSet(i);

	for(int i=0; i<m; ++i){
		cin>>u>>v;
		int x,y; if(u>v) x=v,y=u; else x=u,y=v;
		rec[x][y]++;
		ss.push_back({x,y});
	}


	for(int i=0; i<q; ++i){
		cin>>u>>v;
		cmdStack.push({u,v});
		if(u>=0){
			int x,y; if(u>v) x=v,y=u; else x=u,y=v;
			rec[x][y]--;
		} 
	}

	for(auto a : ss){
		//if (a.second>0) cout<<"Union: "<<a.first.first<<", "<<a.first.second<<'\n';
		int x,y; if(a.first>a.second) x=a.second,y=a.first; else x=a.first,y=a.second;
		if (rec[x][y]>0) Union(x,y);	
	}

	while(!cmdStack.empty()){
		pii cmd = cmdStack.top();
		cmdStack.pop();

		if(cmd.first<0){ 
			outStack.push( findLen(cmd.second) );

		}else{
			int x,y; if(cmd.first>cmd.second) x=cmd.second,y=cmd.first; else x=cmd.first,y=cmd.second;
			rec[x][y]++ ;
			//if ( mm[{x,y}] <=0 ) cout<<"Union: "<<cmd.first<<", "<<cmd.second<<'\n';
			if (rec[x][y]>0) Union(x,y);
		}
	}

	while(!outStack.empty()){
		cout<< outStack.top() << '\n';
		outStack.pop();
	}
}