#include <iostream> 
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, int> pli;

struct Node{
	int x;
	int y;
	int z;
	int id;

	bool operator< (const Node &nd) const{
		if (x != nd.x) return x < nd.x;
		if (y != nd.y) return y < nd.y;
		return z < nd.z;
	}
	bool operator== (const Node &nd) const{
		if ( x==nd.x && y==nd.y && z==nd.z ) return true;
		else return false;
	}
};

ll mkll(ll a, ll b){
	return a*10000001 + b;
}

int n;
int cntx[1000001];
int cnty[1000001];
int cntz[1000001];

int total[1000001];
Node inpu[1000001];
vector <pli> xy,yz,xz;

void addup(vector<pli> &vec){ //addup sum of all different num
	for(int i=0; i<n; ++i){
		int tempi = i;
		while( i<n && vec[tempi].first==vec[i+1].first) 
			i++;b3
		
		int samecnt = i-tempi;
		for(int j=tempi; j<=i; ++j)
			total[vec[j].second] += samecnt;
	}
}

void singleCnt(){
	for(int i=0; i<n; ++i){
		int tempi = i;
		while( i<n && inpu[tempi]==inpu[i+1] ) 
			i++;
		int all = n-1; // all
		all -= cntx[ inpu[tempi].x ] -1;   // 1same
		all -= cnty[ inpu[tempi].y ] -1;
		all -= cntz[ inpu[tempi].z ] -1;

		all -= (i-tempi);  // 3same
		for(int j=tempi; j<=i; ++j)
			total[inpu[j].id] += all;
	}
}

int main(){    //  all - 1same + 2same -same
	cin.tie(0), cout.sync_with_stdio(0);

	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>inpu[i].x>>inpu[i].y>>inpu[i].z;
		inpu[i].id = i;
		xy.push_back(make_pair(mkll(inpu[i].x,inpu[i].y),i));
		yz.push_back(make_pair(mkll(inpu[i].y,inpu[i].z),i));
		xz.push_back(make_pair(mkll(inpu[i].x,inpu[i].z),i));
		cntx[inpu[i].x] += 1;
		cnty[inpu[i].y] += 1;		
		cntz[inpu[i].z] += 1;
	}

	sort(inpu,inpu+n);	singleCnt();
	sort(xy.begin(),xy.end());	addup(xy);
	sort(yz.begin(),yz.end());	addup(yz);
	sort(xz.begin(),xz.end());	addup(xz);
	
	for(int i=0; i<n; ++i){
		cout<< total[i] << " ";
	}
} 