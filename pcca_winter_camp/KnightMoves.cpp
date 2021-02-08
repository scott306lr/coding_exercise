#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

int dx[8] = {1,2,2,1,-1,-2,-2,-1};
int dy[8] = {-2,-1,1,2,2,1,-1,-2};

int atx,aty,tox,toy;
int rec[10][10];
int steps[10][10];
string inpu;

void printchess(int step){
	cout << "To get from " << char(aty + 'a') << atx+1;
	cout << " to " << char(toy + 'a') << tox+1;
	cout << " takes " << step << " knight moves." << '\n';
}

int bfs(){
	if (aty==toy && atx==tox) return 0;
	queue<pip> fq, dq;
	fq.push({0, {aty, atx}});
	dq.push({0, {toy, tox}});
	rec[aty][atx] = 1; steps[aty][atx] = 0;
	rec[toy][tox] = 2; steps[toy][tox] = 0;

	while(true){
		if(!fq.empty()){
			pip a = fq.front(); fq.pop();
			for(int i=0; i<8; ++i){
				int newY = a.second.first  + dy[i];
				int newX = a.second.second + dx[i];
				if (newX<0 || newX>7 || newY<0 || newY>7 || rec[newY][newX] == 1) continue;
				
				int cursteps = a.first + 1;
				if (rec[newY][newX] == 2){
					return steps[newY][newX] + cursteps;
				}

				fq.push({cursteps,{newY, newX}});
				rec[newY][newX] = 1;
				steps[newY][newX] = cursteps;
			}
		}
		
		if(!dq.empty()){
			pip a = dq.front(); dq.pop();
			for(int i=0; i<8; ++i){
				int newY = a.second.first  + dy[i];
				int newX = a.second.second + dx[i];
				if (newX<0 || newX>7 || newY<0 || newY>7 || rec[newY][newX] == 2) continue;
				
				int cursteps = a.first + 1;
				if (rec[newY][newX] == 1){		
					return steps[newY][newX] + cursteps;
				}

				dq.push({cursteps,{newY, newX}});
				rec[newY][newX] = 2;
				steps[newY][newX] = cursteps;

			}
		}
	}
}

int main(){
	while(getline(cin, inpu)){
		aty = inpu[0]-'a';
		atx = inpu[1]-'1';

		toy = inpu[3]-'a';
		tox = inpu[4]-'1';

		for(int i=0; i<10; ++i)
			for(int j=0; j<10; ++j)
				rec[i][j] = 0;
		printchess(bfs());
	}
}
