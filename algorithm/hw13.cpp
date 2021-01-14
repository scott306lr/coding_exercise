#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct inf{
	int w,v,p=0;
};

int n,W,V;
vector<inf> items;
int dp[501][501];


int main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin>>n>>W>>V;
	inf inpu;
	int maxW=0,maxV=0;
	int minW=W,minV=V;
	items.push_back(inpu);
	for(int i=1; i<=n; ++i){
		cin>>inpu.w>>inpu.v>>inpu.p;
		items.push_back(inpu);
		maxW+=inpu.w, maxV+=inpu.v;
		minW=min(minW,inpu.w), minV=min(minV,inpu.v);
	}
	W = min(W,maxW), V = min(V,maxV);

	for(int i=n; i>=0; --i){
		for(int weight=W; weight>=minW; --weight){
			int wd = weight-items[i].w;
			for(int volume=V; volume>=minV; --volume){
				int vd = volume-items[i].v;
				if( wd>=0 && vd>=0 ){ //item wv < restrict
					//dp[i][weight][volume] = max( dp[i-1][weight][volume], dp[i-1][wd][vd]+items[i].p ); 
					dp[weight][volume] = max( dp[weight][volume], dp[wd][vd]+items[i].p ); 
				}
			}
		}
	}

	cout<<dp[W][V];
}

