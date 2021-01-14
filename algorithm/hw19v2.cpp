#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long ll;
#define MAX 2147483647

struct Path{
	Path (int rec, int des){
		this->rec = rec;
		this->des = des;
	}
	bool rec=0;
	int des=0;
}


int u,v,inpu;
int n,m,k; // n: tools  m: products  k: requirements

vector<int> tools,prods;
vector<Path> way[501];
bool used[501];

pair<int, int> apath;

ll max_flow=0;
ll total = 0;

bool bfs(){
	bool end = false;

	for(int i=0; i<n; ++i){
		for(auto a : way[i]){ 
			//cout<< "way[i],a : " << i<<", "<<a<< endl;
			if (prods[a] <= 0) continue;
			
			apath = {i,a};
			end = true;
			break;
		}
	}

	return end;
}

int solve(){
	while(bfs()){

		int path_flow = MAX;
		int s = apath.first, e = apath.second;
		
		path_flow = min(tools[s], prods[e]);
		
		tools[s] -= path_flow;
		prods[e] -= path_flow;

		max_flow += path_flow;
	}

	int sum = total - max_flow;

	return sum;
}

int main(){
	cin.tie(0); cout.sync_with_stdio(0);

	cin>>n>>m>>k;

	for(int i=0; i<n; ++i){
		cin >> inpu;
		tools.push_back(inpu);
	}

	for(int i=0; i<m; ++i){
		cin >> inpu;
		prods.push_back(inpu);
		total += inpu;
	}

	for(int i=0; i<k; ++i){
		cin >> u >> v;
		way[u].push_back(Path(0,v));
		way[v].push_back(Path(0,u));
	}

	cout << solve() << '\n';
}