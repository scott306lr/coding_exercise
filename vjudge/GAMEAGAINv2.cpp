#include <iostream>
using namespace std;

int vertex, edge;
int a, b;
bool rec[51];


void solve(){
	cin >> vertex >> edge;
	int win_cnt = vertex;
	for(int i=0; i<edge; ++i){
		cin >> a >> b;	
		if (rec[a] && rec[b]){
			rec[a] = false;
			rec[b] = false;
			win_cnt -= 2;
		}
	}

	if( win_cnt > 0 )
		cout << "alice" << '\n';
	else
		cout << "bob" << '\n';
}

void reclear(){
	for(int i=1; i<=50; ++i){
		rec[i] = true;
	}
}

int main(){
	cin.tie(0); cout.sync_with_stdio(0);
	int t;
	cin >> t; 
	for(int i=0; i<t; ++i){
		reclear();
		solve();
	}

}