#include <bits/stdc++.h>
using namespace std;

void solve(){
	float a,b,c;
	cin >> a >> b >> c;
	
	int i=1;
	while(true){
		float interest = b*a/100;
		cout << interest ;
		interest = ( int((interest + 0.05)*10) > int(interest*10) ) ? int((interest+0.1)*10)/10.0 : int(interest*10)/10.0;
		cout << " " << interest << '\n';
		b += interest;
		//b = ( int((b + 0.05)*10) > int(b*10) ) ? int(b*10)/10.0 + 0.1 : int(b*10)/10.0;
		b -= c;
		if(b <= 0) break;

		i++;
		if (i > 1200){
			cout << "impossible" << '\n';
			return;
		}
	}
	cout << i << '\n';
}

int main(){
	int t;
	cin >> t;
	for(int i=0; i<t; ++i){
		solve();
	}
}