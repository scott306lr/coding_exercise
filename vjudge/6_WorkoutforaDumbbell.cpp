#include <bits/stdc++.h>
using namespace std;

/*
	oc = his exercise + recovery time

	if (t > took time)
		then no wait ( took time += my oc )
		gap = t - took time
		t += my exercise time - gap
	else
		if ( ((took time - t) % oc) > his exercise time )
			then no wait
			gap = ( oc - ((took time - t) % oc) )  
		else
			took time += ( exercise time - ((took time - t) % oc) )
			gap = rest time 
		t += my exercise time - gap
*/
int mytake[10];
int myrest[10];

int histake[10];
int hisrest[10];
int startt[10];

int total = 0;
int rest_t;

void usemachine(int i){
	if ( startt[i] > total ){
		rest_t = startt[i] - total;
		total += mytake[i] + myrest[i];

	}else{
		int arrive_gap = (total - startt[i]) % (histake[i] + hisrest[i]);
		if ( arrive_gap > histake[i] ){
			rest_t = (histake[i] + hisrest[i]) - arrive_gap;
			total += mytake[i] + myrest[i];

		}else{
			rest_t = hisrest[i];
			total += mytake[i] + myrest[i] + (histake[i] - arrive_gap);
		}
	}
	int addt = mytake[i] - rest_t;
	if (addt > 0)
		startt[i] += addt;
}

int main(){
	for( int i=0; i<10; ++i){
		cin >> mytake[i] >> myrest[i];
	}
	for( int i=0; i<10; ++i){
		cin >> histake[i] >> hisrest[i] >> startt[i];
	}

	for(int a=0; a<3; ++a){
		for(int i=0; i<10; ++i){
			usemachine(i);
		}
	}

	total -= myrest[9];
	cout << total << '\n';
}