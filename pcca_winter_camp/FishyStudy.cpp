#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

int n, res;
int sums[2][201];
map <int, int> imthemap;

void ask(int a, int b){
	cout << "?" << a-1 << " " << b-1 << endl; //flush

	cin >> res;
	sums[a][b] = res; 
} 

int main(){
	cin >> n;
	for (int j=1; j<=n; ++j){
		ask(1, j);
		imthemap[sums[1][j]] = j;
	}

	int k;
	for (int j=1; j<=n; ++j){
		ask(2, j);
		int loc = imthemap[sums[2][j]];
		if ( loc != 0 ){
			
			k = loc - j;
			break;
		}
	}

	if (k < 0)
		cout << "! " << n + k << '\n';
	else
		cout << "! " << k << '\n';
}

// 2 3 1 4
// 3 1 4 2