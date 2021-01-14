#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

vector<ll> v;
int n,k,inpu;

bool check(ll num){
	int spare = num;
	int cnt = k;
	for(int i=0; i<n-1; ++i){
		ll gap = v[i+1]-v[i];
		spare -= gap;
		if(spare<0){
			spare = num;
			cnt--;
		}
		if(cnt==0) return false;
	}
	return true;
}

int findmax(ll l, ll r){
	//cout<< "finding between "<<l<<", "<<r<<endl;
	ll mid = l+(r-l)/2;
	if (mid==l) return r;
	if (check(mid)){
		return findmax(l,mid);
	}else{
		return findmax(mid,r);
	}
}

int main(){
	cin.tie(0), cout.sync_with_stdio(0);
	cin>>n>>k;
	for(int i=0; i<n; ++i){
		cin>>inpu;
		v.push_back(inpu);
	}
	sort(v.begin(),v.end());
	cout<< findmax(-1,v[n-1]-v[0]);
}