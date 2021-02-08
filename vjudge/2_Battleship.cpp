#include <bits/stdc++.h>
using namespace std;

bool grid[2][31][31];
string inpu;
int w,h,n;
int x,y;

void solve(){
	cin >> w >> h >> n;

	int ships[2]={0,0};
	for(int a=0; a<2; ++a){
		for(int i=0; i<h; ++i){
			cin >> inpu;
			for(int j=0; j<w; ++j){
				if (inpu[j] == '#'){
					grid[a][j][i] = 1;
					ships[a] += 1;
				}else{
					grid[a][j][i] = 0;
				}
			}
		}
	}

	bool turn = 1;
	bool winning = 0;
	int winner = 0;
	for(int i=0; i<n; ++i){
		cin >> x >> y;
		
		if(grid[turn][x][h-y-1]){
			//cout<< "HIT!" << '\n';
			grid[turn][x][h-y-1] = 0;
			ships[turn] -= 1;

			if(ships[turn]==0){
				if(turn == 1 && !winning)
					winning = 1;

				else
					if(turn == 0 && !winning && winner == 0){
						winner = 2;

					}else if(turn == 0 && winning && winner == 0){
						winner = 3;

					}
				turn = !turn;
			}
		}else{
			//cout<< "MISS!" << '\n';
			//cout<< "SWITCH!" << '\n';
			if(winning && winner == 0){
				winner = 1;
			}
			turn = !turn;
		}
	}

	if (winner==1)
		cout << "player one wins" << '\n';

	else if (winner==2)
		cout << "player two wins" << '\n';

	else
		cout << "draw" << '\n';
	
	return;
}

int main(){
	int t;
	cin >> t;
	for(int i=0; i<t; ++i){
		solve();
	}
	return 0;
}
