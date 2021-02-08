#include <bits/stdc++.h>
using namespace std;

int nugget[int(2e5+10)];
int noodles[int(2e5+10)];
bool alone[int(2e5+10)];

int n, inpu;
long long totalw = 0;
vector<int> v[int(2e5+10)];


int main(){
	cin >> n;
	for(int i=2; i<=n; ++i){
		cin >> inpu;
		if (i == inpu){
			noodles[inpu]++;
			alone[i] = true;
		}else{
			noodles[inpu]++;
			noodles[i]++;
			v[inpu].push_back(i);
		}
		
	}

	for(int i=1; i<=n; ++i){
		cin >> inpu;
		nugget[i] = inpu;
		totalw += inpu;
	}

	if (n % 2 == 0){
		cout << totalw << "\n";
		return 0;
	}

	int minN = 1e5; bool avail = false;
	for(int i=1; i<=n; ++i){
		if (noodles[i] % 2){
			minN = min(minN, nugget[i]);
			avail = true;
		}else if (alone[i]){
			for(auto a : v[i]){
				if (noodles[a] % 2 == 0){
					minN = min(minN, nugget[a] + nugget[i]); 
					avail = true;
				}
			}
		}
	}

	if (avail) 
		cout << totalw - minN << "\n";
	else
		cout << 0 << "\n";
}