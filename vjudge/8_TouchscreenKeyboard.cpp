#include <bits/stdc++.h>
using namespace std;
typedef pair<int, string> pis;
typedef pair<int, int> pii;

string inpu, comp;

pii keypos(char c){
	if ( c == 'q' ){
		return { 0,0 };
	}else if ( c == 'w' ){
		return { 1,0 };
	}else if ( c == 'e' ){
		return { 2,0 };
	}else if ( c == 'r' ){
		return { 3,0 };
	}else if ( c == 't' ){
		return { 4,0 };
	}else if ( c == 'y' ){
		return { 5,0 };
	}else if ( c == 'u' ){
		return { 6,0 };
	}else if ( c == 'i' ){
		return { 7,0 };
	}else if ( c == 'o' ){
		return { 8,0 };
	}else if ( c == 'p' ){
		return { 9,0 };
	}else if ( c == 'a' ){
		return { 0,1 };
	}else if ( c == 's' ){
		return { 1,1 };
	}else if ( c == 'd' ){
		return { 2,1 };
	}else if ( c == 'f' ){
		return { 3,1 };
	}else if ( c == 'g' ){
		return { 4,1 };
	}else if ( c == 'h' ){
		return { 5,1 };
	}else if ( c == 'j' ){
		return { 6,1 };
	}else if ( c == 'k' ){
		return { 7,1 };
	}else if ( c == 'l' ){
		return { 8,1 };
	}else if ( c == 'z' ){
		return { 0,2 };
	}else if ( c == 'x' ){
		return { 1,2 };
	}else if ( c == 'c' ){
		return { 2,2 };
	}else if ( c == 'v' ){
		return { 3,2 };
	}else if ( c == 'b' ){
		return { 4,2 };
	}else if ( c == 'n' ){
		return { 5,2 };
	}else if ( c == 'm' ){
		return { 6,2 };
	}
	return {-1,-1};
}

int compare(string a, string b){
	int sum = 0;
	int ssize = a.size();
	for(int i=0; i<ssize; ++i){
		pii apos = keypos(a[i]);
		pii bpos = keypos(b[i]);
		sum += abs(apos.first  - bpos.first);
		sum += abs(apos.second - bpos.second);
	}
	return sum;
}

void solve(){
	priority_queue<pis, vector<pis>, greater<pis> > pq;
	int a;
	cin >> inpu;
	cin >> a;
	for(int i=0; i<a; ++i){
		cin >> comp;
		pq.push( {compare(inpu, comp), comp} );
	}

	while(!pq.empty()){
		pis out = pq.top();
		pq.pop();

		cout << out.second << " " << out.first << '\n'; 
	}
}

int main(){
	int t; 
	cin >> t;
	for(int i=0; i<t; ++i){
		solve();
	}
}