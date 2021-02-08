#include <bits/stdc++.h>
using namespace std;
typedef pair<int, char> pii;

string inpu;
int arr[150];


int main(){
	cin.tie(0); cout.sync_with_stdio(0);
	int n;
	cin >> n;
	cin >> inpu;

	for(int i=0; i<n; ++i){
		arr[inpu[i]]++;
	}

	int smax=0;
	int smin=10000;
	for(int i='a'; i<='e'; ++i){
		smax = smax<arr[i] ? arr[i] : smax;
		smin = smin>arr[i] ? arr[i] : smin;
	}
	cout << smin << " " << smax;
}