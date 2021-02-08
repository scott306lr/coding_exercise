#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

bool par = false;
int n;
string inpu;
int a=0,b=0;

int main(){
	cin.tie(0);
	cin >> n; cin.ignore();
	getline(cin, inpu);

	int cnt = 0;
	for(int i=0; i<n; ++i){
		if (inpu[i] == '('){
			par = true;
			a = max(a, cnt);
			cnt = 0;

		}else if (inpu[i] == ')'){
			par = false;
			if (cnt!=0) b++;
			cnt = 0;

		}else if (inpu[i] == '_'){
			if ( par == false ){
				a = max(a, cnt);
			}else{
				if (cnt!=0){
					b++;
				} 
			}
			cnt = 0;
		}else{
			cnt++;
		}
	}
	a = max(a, cnt);

	cout << a << " " << b << '\n';
}