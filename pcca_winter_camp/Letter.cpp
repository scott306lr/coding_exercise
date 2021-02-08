#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int rewrite(int start, int end);
int shrink(int start, int end);

string inpu;

int rewrite(int start, int end){
	int fbig=end, lsmall=start;

	for(int i=start; i<=end; ++i){
		if (inpu[i] <= 'Z'){
			fbig = i;
			break;
		}
	}

	for(int i=end; i>=start; --i){
		if (inpu[i] >= 'a'){
			lsmall = i;
			break;
		}
	}

	int b = fbig - start ;
	int s = end - lsmall ;
	if (b <= s) 
		return shrink(fbig, end) + b;
	else 
		return shrink(start, lsmall) + s;
}

int shrink(int start, int end){
	int fsmall=end, lbig=start;

	for(int i=start; i<=end; ++i){
		if (inpu[i] >= 'a'){
			fsmall = i;
			break;
		}
	}

	for(int i=end; i>=start; --i){
		if (inpu[i] <= 'Z'){
			lbig = i;
			break;
		}
	}

	if (lbig <= fsmall) return 0;
	
	return rewrite(fsmall, lbig);
}

int main(){
	getline(cin, inpu);
	cout << shrink(0, inpu.size()-1) << '\n';
}