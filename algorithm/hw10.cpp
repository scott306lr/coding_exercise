#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
unordered_map < ll,pii > sum; 
vector<int> v;
int main(){
	int n,s; ll inpu;
	
	cin>>n>>s;
	for(int i=0; i<n; ++i){
		cin>>inpu;
		v.push_back(inpu);
	}

	for (int i=n-2; i>=0; --i){
		for (int j=n-1; j>i; --j){
			sum[v[i]+v[j]] = make_pair(i,j);
		}
	}

	for (int i=0; i<n-1; ++i){
		for (int j=i+1; j<n; ++j){
			ll dsum = v[i]+v[j];
			if(sum.find( s-dsum ) != sum.end() ){
				pii p = sum[s-dsum];
				if (i == p.first || i == p.second || j == p.first || j == p.second) continue;

				int a[4] = {i,j,p.first,p.second};
				sort(a,a+4);
				printf("%d %d %d %d",a[0],a[1],a[2],a[3]);
				return 0;
			}
		}
	}
	cout<<"-1";
	return 0;


}