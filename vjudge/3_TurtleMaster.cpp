#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

string inpu;
char grid[8][8];

pii cur = {7,0};
int dir = 1; // up = 0, right = 1, down = 2, left = 3

void tprint(){
	for(int i=0; i<8; ++i){
		for(int j=0; j<8; ++j){
			if(cur.first == i && cur.second == j)
				cout << "T" << " ";
			else
				cout << grid[i][j] << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

int lazer(){
	int y = cur.first, x = cur.second;
	int newy = y + dy[dir];
	int newx = x + dx[dir];
	if(newx<0 || newx>7 || newy<0 || newy>7) return -1;
	//if(grid[newy][newx] == '.' || grid[newy][newx] == 'C' ) return -1;
	if(grid[newy][newx] == 'I'){
		grid[newy][newx] = '.';
		return 0;
	}else{
		return -1;
	}
	
}

void turnR(){
	dir++;
	if (dir == 4) dir=0;
}

void turnL(){
	dir--;
	if (dir == -1) dir=3;
}

int move(){
	int y = cur.first, x = cur.second;
	int newy = y+dy[dir];
	int newx = x+dx[dir];

	if(newx<0 || newx>7 || newy<0 || newy>7) return -1;
	if(grid[newy][newx] == 'I' || grid[newy][newx] == 'C') return -1;

	cur = {newy, newx};
	return 0;
}

int main(){
	for(int i=0; i<8; ++i){
		cin >> inpu;
		for(int j=0; j<8; ++j){
			if (inpu[j] == 'T'){
				grid[i][j] = '.';
			}else{
				grid[i][j] = inpu[j];
			}
			
		}
	}
	cin >> inpu;
	int ssize = inpu.size();
	for(int step=0; step<ssize; ++step){
		//tprint();
		if (inpu[step] == 'F'){
			if (move() == -1){
				cout << "Bug!" << '\n';
				return 0;
			}

		}else if(inpu[step] == 'R'){
			turnR();

		}else if(inpu[step] == 'L'){
			turnL();

		}else if(inpu[step] == 'X'){
			if (lazer() == -1){
				cout << "Bug!" << '\n';
				return 0;
			}

		}
	}	

	if(grid[cur.first][cur.second] == 'D') 
		cout << "Diamond!" << '\n';
	else 
		cout << "Bug!" << '\n';

	return 0;
}