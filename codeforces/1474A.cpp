// https://codeforces.com/contest/1474/problem/A

#include <iostream>
#include <string.h>
using namespace std;

int t,n;
string b;
int ans[100001];
bool a[100001];


void solve(){
	cin>>n;
	cin>>b;
	a[0]=1;

	if (b[0] == '1') 
		ans[0]=2;
	else 
		ans[0]=1;
	
	for(int i=1; i<n; ++i){
		if (b[i]=='1'){
			if (ans[i-1] != 2){
				a[i]=1;
				ans[i]=2;
			}else{
				a[i]=0;
				ans[i]=1;
			}
		}else{
			if (ans[i-1] != 1){
				a[i]=1;
				ans[i]=1;
			}else{
				a[i]=0;
				ans[i]=0;
			}
		}
	}
	for(int i=0; i<n; ++i)
		cout<<a[i];
	cout<<'\n';
}

int main(){
	cin>>t;
	for(int i=0; i<t; ++i){
		solve();
	}
}