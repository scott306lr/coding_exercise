#include <iostream>
#include <vector>
using namespace std;

int vertex, edge;
int from, to;
bool rec[51];
vector<int> adj[51];

/*
	這步不是你的回合, 
			下步有一步會贏 -> win
			下步皆會輸 -> lose

	這步是你的回合,
			下步皆會贏 -> win
			下步有一步會輸 -> lose
*/

void printstep(int v, bool turn){
	if(turn){
		cout << "alice ";
	}else{
		cout << "bob ";
	}
	cout << "goes: " << v << '\n';
}

bool a_win_here(int v, bool turn){
	//printstep(v,turn);

	for(int i=0; i<adj[v].size(); ++i){
		int a = adj[v][i];
	//for(auto a : adj[v]){
		if (rec[a]) continue;

		rec[a] = true;
		bool win = a_win_here(a, !turn);
		rec[a] = false;

		if (!turn && win) return true;
		if (turn && !win) return false;	
	}
	return turn;
}
void solve(){
	cin >> vertex >> edge;
	for(int i=0; i<edge; ++i){
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	for(int i=1; i<=vertex; ++i){
		rec[i] = true;
		if( a_win_here(i,true) ){
			cout << "alice" << '\n';
			return;
		}
		rec[i] = false;
	}
	cout << "bob" << '\n';
}

void vclear(){
	for(int i=1; i<=50; ++i){
		adj[i].clear();
		rec[i] = false;
	}
}

int main(){
	cin.tie(0); cout.sync_with_stdio(0);
	int t;
	cin >> t; 
	for(int i=0; i<t; ++i){
		vclear();
		solve();
	}

}