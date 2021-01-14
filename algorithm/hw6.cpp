#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compare(int a, int b, int c){
    int max;
    max = (a>b) ? a : b;
    max = (max>c) ? max : c;
    return max;
}

struct aNode{
	aNode operator+(const aNode &R){
	aNode a;
	a.all    = compare(this->all+R.noLeft , this->noRight+R.all , this->noRight+R.noLeft);
    a.noLeft = compare(this->noLeft+R.noLeft , this->noBoth+R.all , this->noBoth+R.noLeft);
    a.noRight= compare(this->all+R.noBoth , this->noRight+R.noRight , this->noRight+R.noBoth);
    a.noBoth = compare(this->noLeft+R.noBoth , this->noBoth+R.noRight , this->noBoth+R.noBoth);  
    return a;
	}
    int all=0;
    int noLeft=0;
    int noRight=0;
    int noBoth=0;
};
aNode arr[2000000];

aNode construct(vector<int> &v,int left, int right, int current){
    if(left == right){
        arr[current].all = v[left];
        return arr[current];
    }
    int mid = (left+right)/2;
    arr[current] = construct(v,left,mid, current*2+1) + construct(v,mid+1,right, current*2+2);
    return arr[current];	
}

aNode getAns(int b, int c, int pointer, int l, int r){
    if(b<=l && r<=c) return arr[pointer];
    if(r<b || l>c) return *(new aNode);

    int mid = (l+r)/2;
    return getAns(b, c, pointer*2+1, l, mid) + getAns(b, c, pointer*2+2, mid+1, r);
}

aNode update(int cp, int newN, int pointer, int l, int r){
    if(cp<l || cp>r) return arr[pointer];
    if(l != r) {
    	int mid = (l+r)/2;  
        arr[pointer] = update(cp, newN, pointer*2+1, l, mid) + update(cp, newN, pointer*2+2, mid+1, r);
    }else{
    	arr[pointer].all = newN;
    }
    return arr[pointer];
    
}

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
    int n, opnum, inpu;
    int a,b,c;
    vector<int> v;
    cin>>n>>opnum;
    for(int i=0; i<n; ++i){
        cin>>inpu;
        v.push_back(inpu);
    }

    construct(v,0,n-1,0);
    
    for(int i=0; i<opnum; ++i){
        cin>>a>>b>>c;
        
        if(a!=0){
            cout << getAns(b,c,0,0,n-1).all <<endl;
        }else{
            update(b,c,0,0,n-1);     
        }
    }
}