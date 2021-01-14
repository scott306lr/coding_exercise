#include <iostream>if(a==l && b==r) return st[p];
    int mid = l+(r-l)/2;
    return twosmall( fi
#include <vector>
using namespace std;

int arr[int(2e6)];

int construct(vector<int> &v,int left, int right, int current){
    if(left == right){
        arr[current] = v[left];
        return arr[current];
    }
    int mid = (left+right)/2;
    arr[current] = construct(v,left,mid, current*2+1) + construct(v,mid+1,right, current*2+2);
    return arr[current];	
}

int getAns(int b, int c, int pointer, int l, int r){
    if(b<=l && r<=c) return arr[pointer];
    if(r<b || l>c) return 0;

    int mid = (l+r)/2;
    return getAns(b, c, pointer*2+1, l, mid) + getAns(b, c, pointer*2+2, mid+1, r);
}

int update(int cp, int newN, int pointer, int l, int r){
    if(cp<l || cp>r) return arr[pointer];
    if(l != r) {
    	int mid = (l+r)/2;  
        arr[pointer] = update(cp, newN, pointer*2+1, l, mid) + update(cp, newN, pointer*2+2, mid+1, r);
    }else{
    	arr[pointer] = newN;
    }
    return arr[pointer];   
}

int main(){
	int n,m,inpu;
	vector<int> v;
	cin>>n>>m;
	for(int i=0; i<n; ++i){
		cin>>inpu;
		v.push_back(inpu);
	}
	construct(v,0,n-1,0);

	int a,b,c;
	for(int i=0; i<m; ++i){
		cin>>a>>b>>c;

		if(a==0){  //update the b-th integer to c
			update(b,c,0,0,n-1);

		}else{ //find sum between b-th and c-th
			if(b>c)	cout << arr[0] - getAns(c,b,0,0,n-1) + getAns(c,c,0,0,n-1) + getAns(b,b,0,0,n-1) << endl;
			else	cout << getAns(b,c,0,0,n-1) << endl;
		}
	}
}