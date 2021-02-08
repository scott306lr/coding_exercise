#include <bits/stdc++.h>
using namespace std;

int month_arr[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int mtoi(string s){
	if (s == "JAN") return 1;
	if (s == "FEB") return 2;
	if (s == "MAR") return 3;
	if (s == "APR") return 4;
	if (s == "MAY") return 5;
	if (s == "JUN") return 6;
	if (s == "JUL") return 7;
	if (s == "AUG") return 8;
	if (s == "SEP") return 9;
	if (s == "OCT") return 10;
	if (s == "NOV") return 11;
	if (s == "DEC") return 12;
	cout<<"mtoi error!"<<'\n';
	return -1;
}

int dtoi(string s){
	if (s == "MON") return 1;
	if (s == "TUE") return 2;
	if (s == "WED") return 3;
	if (s == "THU") return 4;
	if (s == "FRI") return 5;
	if (s == "SAT") return 6;
	if (s == "SUN") return 7;
	cout<<"dtoi error!"<<'\n';
	return -1;
}

int main(){
	cin.tie(0), cout.sync_with_stdio(0);
	int date; string month, day;
	cin >> date;
	cin >> month >> day;

	int imonth = mtoi(month);
	int iday = dtoi(day);

	int total = 0;
	for( int i=1; i<imonth; ++i){
		total += month_arr[i];
	}

	int rem = (total + date - 1) % 7;
	int newday = (iday + rem) % 7;

	if (imonth <= 2){
		if ( newday == 5 ){
			cout << "TGIF" << '\n';
		}else{
			cout << ":(" << '\n';
		}
	}else {
		if ( newday == 5 || newday == 4 ){
			cout << "not sure" << '\n';
		}else{
			cout << ":(" << '\n';
		}
	}

}