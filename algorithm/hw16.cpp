#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;

struct Enemy{
	Enemy(int dir, pii loc){
		this->dir=dir;
		this->loc=loc;
	}	
	int dir;
	pii loc;
};

/*
	top:   [0][-1]
	right: [+1][0]
	down:  [0][+1]
	left:  [-1][0]
*/
int dy[5]={ 0,1,0,-1,0};
int dx[5]={-1,0,1, 0,0};

int maze[101][101];
bool enemy_pos[1002][101][101];
bool my_pos[1002][101][101];

queue <pip> q;
int n,m,t,inpu;
pii startp;
vector <Enemy> v;


void printMaze(){
	cout<< "Map: "<<'\n';
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cout<< maze[i][j] << " ";
		}
		cout<<'\n';
	}
}

void printE(int t){
	cout<< "Second "<<t<<":"<<'\n';
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(maze[i][j]==0) cout << "X" << " ";
			else if(enemy_pos[t][i][j]) cout << "e" << " ";
			else if(my_pos[t][i][j]) cout << "o" << " "; 
			else cout<<"."<< " ";
		}
		cout<<'\n';
	}
}

int bfs(int sx, int sy, int maxt){
	my_pos[0][sx][sy] = 1;
	q.push( { 0 , {sx,sy} } );

	while(!q.empty()){
		pip data=q.front();
		q.pop();

		int time = data.first;
		int x = data.second.first;
		int y = data.second.second;
 		
 		for(int i=0; i<5; ++i){
 			int newT=time+1;
 			int newX=x+dx[i];
 			int newY=y+dy[i];
 			if ( newT>maxt || my_pos[newT][newX][newY] ||
 				 newX<0 || newX>=n || newY<0 || newY>=m || maze[newX][newY]==0 ||
 				 enemy_pos[time][newX][newY] || enemy_pos[newT][newX][newY] ) continue;
 			
 			my_pos[newT][newX][newY] = 1;
 			if (maze[newX][newY]==3) return newT;
 			q.push( { newT , {newX,newY} } );
 		} 
	}
	return -1;
}

// int idfs(int time, int x, int y, int maxt){
// 	if ( x<0 || x>=n || y<0 || y>=m || maze[x][y]==0 || time>maxt || enemy_pos[time][x][y]==1 || enemy_pos[time+1][x][y]==1 ) return -1;
// 	if (maze[x][y]==3) return time+1;
// 	for(int i=0; i<5; ++i){
// 		int val = idfs( time+1, x+dx[i], y+dy[i], maxt);
// 		if(val != -1) return val;
// 	}
// 	return -1;
// }

void e_move(Enemy &e, int i){
	int x = e.loc.first  + dx[e.dir];
	int y = e.loc.second + dy[e.dir];
	if( x<0 || x>=n || y<0 || y>=m || maze[x][y]==0){
		e.dir = (e.dir+1)%4;
		enemy_pos[i][e.loc.first][e.loc.second]=1;
		return;	
	}
	e.loc = {x,y};
	enemy_pos[i][x][y]=1;
}

int main(){
	cin.tie(0), cout.sync_with_stdio(0);
	
	cin>>n>>m>>t;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cin>>inpu;
			switch(inpu){
				case 0: case 1: case 3:
					maze[i][j] = inpu;
					break;

				case 2:
					maze[i][j] = inpu;
					startp = {i,j};
					break;

				case 4: case 5: case 6: case 7:
					maze[i][j] = 1;
					enemy_pos[0][i][j]=1;
					Enemy enemy(inpu-4,{i,j});
					v.push_back(enemy);
					break;
			}
		}
	}

	//int best;
	int s=v.size();
	for(int i=1; i<t+1; ++i){
		for(int j=0; j<s; ++j){
			e_move(v[j],i);
		}
		// best = idfs(0,startp.first,startp.second,i-1);
		// if (best!=-1) cout<<best;
	}
	// if (best==-1) cout<<-1;

	cout<<bfs(startp.first,startp.second,t)<<'\n';

	// printMaze();
	// cout<<'\n';
	// for(int i=0; i<t+1; ++i){
	// 	printE(i);
	// 	cout<<'\n';
	// }
}

/*

9 4 12
3 0 1 1
6 0 1 6
1 0 0 0
1 0 5 1
1 0 0 1
1 1 0 1
2 0 0 1
1 0 1 1
1 0 1 3

*/

/*

8 4 10
0 0 0 0
1 2 1 0
0 1 1 0
0 4 4 0
0 1 1 0
0 1 3 0
0 1 5 0
0 0 0 0


8 8 22
0 0 0 0 0 0 0 0
0 2 5 1 1 1 1 0
0 0 0 0 0 0 0 0
0 1 1 1 1 1 1 0
0 1 1 1 1 1 1 0
0 1 7 1 1 1 1 0
0 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0

9 9 22
0 0 0 0 0 0 0 0 0
0 1 1 2 1 1 1 1 0
0 0 0 0 1 0 0 0 0
0 5 1 1 1 1 1 7 0
0 0 0 0 1 0 0 0 0
0 5 1 1 1 1 1 7 0
0 0 0 0 1 0 0 0 0
0 5 1 1 1 1 1 7 0
0 0 0 0 3 0 0 0 0


7 7 22
1 1 2 1 1 1 1
0 0 0 1 0 0 0
5 1 1 1 1 1 7
0 0 0 1 0 0 0
5 1 1 1 1 1 7
0 0 0 1 0 0 0
5 1 1 3 1 1 7
*/