#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
#define MAX 2147483647

int u,v,inpu;
int n,m,k; // n: tools  m: products  k: requirements

//int graph[1010][1010];
int rgraph[1010][1010];
vector<int> path[1010];

int parent[1010];
bool rec[1010];
queue<int> q;

int max_flow = 0;
int total = 0;


bool bfs(){
  memset(rec, 0, sizeof(rec));

  rec[0] = true;
  parent[0] = -1;
  q.push(0);

  int u;
  while(!q.empty()){
    u = q.front();
    q.pop();

    for(int a : path[u]){
      if(rec[a] || rgraph[u][a]==0) continue;

      rec[a] = true;
      parent[a] = u;
      q.push(a);
    }
  }
  
  return rec[n+m+1]; //reach sink
}

int solve(){

  while(bfs()){
    int path_flow = MAX;

    for(int i = n+m+1; i > 0; i = parent[i]){
      path_flow = min(path_flow, rgraph[parent[i]][i] );
    }

    for(int i = n+m+1; i > 0; i = parent[i]){
      rgraph[parent[i]][i] -= path_flow;
      rgraph[i][parent[i]] += path_flow;  
    }

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
    rgraph[0][i+1] = inpu;
    path[0].push_back(i+1);
    path[i+1].push_back(0);
  }

  for(int i=0; i<m; ++i){
    cin >> inpu;
    rgraph[n+1+i][n+m+1] = inpu;
    path[n+1+i].push_back(n+m+1);
    path[n+m+1].push_back(n+1+i);
    total += inpu;
  }

  for(int i=0; i<k; ++i){
    cin >> u >> v;
    rgraph[u+1][v+n+1] = MAX;
    path[u+1].push_back(v+n+1);
    path[v+n+1].push_back(u+1);
  }

  cout << solve() << '\n';
  return 0;
}