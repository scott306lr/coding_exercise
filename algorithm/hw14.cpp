#include <iostream>
#include <set>
using namespace std;
typedef long long ll;

int main(){
	cin.tie(0), cout.sync_with_stdio(0);
	set<int> mset;
	set<int>::iterator ith;
	int n,inpu,max=-2147483647;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>inpu;
		if(max<=inpu){
			max=inpu;
			cout<<-1<<'\n';
			mset.erase(mset.begin(),mset.end());
		}else{
			ith=mset.upper_bound(inpu);
			cout<<*ith<<'\n';
			mset.erase(mset.begin(),ith);
		}
		mset.insert(inpu);
	}
	return 0;
}
