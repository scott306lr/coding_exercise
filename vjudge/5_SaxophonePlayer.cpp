#include <bits/stdc++.h>
using namespace std;

/*
	each letter adds up different numbers
	add
	add
	print
*/
string inpu;
int finger[11];//0
bool note[14][11] = {
	{0,0,1,1,1,0,0,1,1,1,1},
	{0,0,1,1,1,0,0,1,1,1,0},
	{0,0,1,1,1,0,0,1,1,0,0},
	{0,0,1,1,1,0,0,1,0,0,0},
	{0,0,1,1,1,0,0,0,0,0,0},
	{0,0,1,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,0,0,0,0},
	{0,1,1,1,1,0,0,1,1,1,0},
	{0,1,1,1,1,0,0,1,1,0,0},
	{0,1,1,1,1,0,0,1,0,0,0},
	{0,1,1,1,1,0,0,0,0,0,0},
	{0,1,1,1,0,0,0,0,0,0,0},
	{0,1,1,0,0,0,0,0,0,0,0}
};

void fingerprint(){
	for(int i=1; i<=10; ++i){
		cout<< finger[i] << " ";
	}
	cout<<'\n';
}

int notetoi(char note){
	if (note=='c'){
		return 0;
	}else if (note=='d'){
		return 1;
	}else if (note=='e'){
		return 2;
	}else if (note=='f'){
		return 3;
	}else if (note=='g'){
		return 4;
	}else if (note=='a'){
		return 5;
	}else if (note=='b'){
		return 6;
	}else if (note=='C'){
		return 7;
	}else if (note=='D'){
		return 8;
	}else if (note=='E'){
		return 9;
	}else if (note=='F'){
		return 10;
	}else if (note=='G'){
		return 11;
	}else if (note=='A'){
		return 12;
	}else if (note=='B'){
		return 13;
	}
	return -1;
}

void nextnote(int i){
	for(int j=1; j<=10; ++j){
		if(note[notetoi(inpu[i])][j] && !note[notetoi(inpu[i-1])][j]){
			finger[j]++;
		}	
	}	
}

void solve(){
	getline(cin, inpu);
	int ssize = inpu.size();
	for(int i=1; i<=10; ++i){
		finger[i]=0;
	}

	if( ssize != 0 ){
		for(int j=1; j<=10; ++j){
			if(note[notetoi(inpu[0])][j]){
				finger[j]++;
			}	
		}

		for(int i=1; i<ssize; ++i){
			nextnote(i);
		}
	}

	fingerprint();
}

int main(){
	int t;
	cin >> t;
	cin.ignore();
	for(int i=0; i<t; ++i){
		solve();
	}
}