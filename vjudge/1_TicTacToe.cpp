#include <iostream>
using namespace std;

string inpu;
char grid[3][3];

void testp(){
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
}

bool testend(char symbol){
	for(int i=0; i<3; ++i){
		if (grid[i][0] == symbol && grid[i][0] == grid[i][1] && grid[i][1] == grid[i][2]){
			return true;
		}
		if (grid[0][i] == symbol && grid[0][i] == grid[1][i] && grid[1][i] == grid[2][i]){
			return true;
		}
	}

	if(grid[0][0] == symbol && grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
		return true;
	}

	if(grid[2][0] == symbol && grid[2][0] == grid[1][1] && grid[1][1] == grid[0][2]){
		return true;
	}

	return false;
}

void solve(){
	
	int x=0, c=0;
	//bool fuck=0;

	for(int i=0; i<3; ++i){
		getline(cin, inpu);
		//if (inpu.size() != 3) fuck = 1;
		for(int j=0; j<3; ++j){
			grid[i][j] = inpu[j];
			if (inpu[j] == 'X'){
				x += 1;
			}else if (inpu[j] == 'O')
				c += 1;
		}
	}

	//testp();

	// if "O" too much or both have a line, then returns "no".
	bool xend = testend('X');
	bool oend = testend('O');
	if ( (x!=c && x!=c+1) || (xend && x==c) || (oend && x==c+1) || (xend && oend)){
		cout << "no" << '\n';
	}
	else cout << "yes" << '\n';	
}

int main(){
	cin.tie(0), cout.sync_with_stdio(0);
	int t;
	cin >> t;
	cin.ignore();
	for(int i=0; i<t; ++i){
		solve();
		if (i<t-1) getline(cin, inpu);	
	}
	return 0;
}

/*

5
...
...
...

X..
...
...

X.O
...
...

X.O
...
..X

X.O
.O.
..X
*/