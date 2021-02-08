// https://codeforces.com/contest/1474/problem/B

#include <iostream>
#include <string.h>
using namespace std;
#define MAX 100000000

int arr[MAX];
int d;

void printarr(){
	for(int i=0; i<100; ++i){
		cout<< arr[i]<<" ";
	}
	cout<<'\n';
}

void solve(){
	cin >> d;
	arr[0] = arr[1] = 1;
	int cnt=1;
	for(int i=0; i<3; i++){
		//acceptable
		for(int j=2; j<MAX; j++){
				if (arr[j]==0 && j%cnt!=0) arr[j]=1;
			}
		//unacceptable
		for(int a=1; a<d; ++a){
			int div = a+cnt;
			for(int j=2; j<MAX; j++){
				if (arr[j]==0 && j%div==0) arr[j]=1;
			}
		}
		cnt+=d;
	}

	cnt=1;
	while(true){
		if(arr[cnt]==0) break;
		cnt++;
	}

	cout<<cnt<<'\n';
}

int main(){
	cin.tie(0), cout.sync_with_stdio(0);

	int t; cin >> t;
	for(int i=0; i<t; ++i){
		for(int i=0; i<MAX; ++i){
			arr[i]=0;
		}
		solve();
	}
}