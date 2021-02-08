#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
/*
 	7:6 in the 1st/2nd game
 	8:6 in the 3rd game
 	else should have a 2-gap & one shall >= 6 (ex 7:5)

 	federer can't lose any set

 	ends when one wins two sets => one loses two sets
*/

string nA,nB, inpu;

int check(int a, int b, int set){
	if (set <= 2){
		if (a==7 && b==6) return 1;
		if (a==6 && b==7) return 2;
		if (a>=6 && b>=6) return -1;
	}
	if ( !((a>=6 || b>=6) && (a-b>=2 || b-a>=2)) ){
		return -1;
	}
	if (a>b) return 1;
	if (b>a) return 2;

	return -1; // won't happen
}

void solve(){
	int loseA=0, loseB=0; //lose count
	int set=0;

	getline(cin, inpu); 	//cout<<"got line: "<< inpu <<'\n';
	stringstream ss(inpu);
	while( ss.good() ){
		if (loseA == 2 || loseB == 2){
			cout << "ne" << '\n';
			return;
		}

	    string oneset;
	    getline( ss, oneset, ' ' );
	    stringstream sss(oneset);

	    string sa,sb;
	    getline( sss, sa, ':' );
	    getline( sss, sb, ':' );
	    int a = stoi(sa);
	    int b = stoi(sb);
	    //cout<<a<<":"<<b<<"\n";
	    set += 1;

	    int val = check(a,b,set);
		if (val == 1){
			if (nB == "federer"){
				cout << "ne" << '\n';
				return;
			}
			loseB += 1;

		}else if (val == 2){
			if (nA == "federer"){
				cout << "ne" << '\n';
				return;
			}
			loseA += 1;

		}else{
			cout << "ne" << '\n';
			return;
		}
	}

	if (loseA < 2 && loseB < 2)
		cout<< "ne" << '\n';
	else
		cout<< "da" << '\n';
}


int main(){
	//getline(cin, nA, ' ');
	//getline(cin, nB);
	cin >> nA;
	cin >> nB;
	int t;
	cin >> t;
	cin.ignore();
	for(int i=0; i<t; ++i){
		solve();
	}
}