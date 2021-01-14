#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e6;

struct Node {
    ll val, left=0, right=0;
} a[MAXN], b[MAXN];



ll total=0;
void merge(int start, int end, Node *A, Node *T){
    
    if ((end-start)<2) return;

    int mid = (start+end)/2;
    merge(start,mid,A,T);
    merge(mid,end,A,T);

    int p=start, q=mid, i=start;
    while( p<mid || q<end ){
        // total += 比x大的數 * 比x小的數
        if( ( A[p].val <= A[q].val && p<mid ) || q >= end ){ 
            total += A[p].left * (q-mid);//  { A[p].left, A[p], (end-q) } 符合條件
            A[p].right += (q-mid);
            //cout<<"start:"<<start<<" end:"<<end<<" A value:"<<A[p].val<<endl;
            T[i++]=A[p++]; 

        }else{
            total += (mid-p) * A[q].right;// { (mid-p), A[q], A[q].right } 符合條件
            A[q].left += (mid-p);

            T[i++]=A[q++];
        }
        // for(int i=start; i<end; ++i){
        //     cout<<T[i].val<<" ";
        // }
        // cout<<endl;
    }
    for(int i=start; i<end; ++i){
        A[i]=T[i];
    }
}


int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>a[i].val;
    }

    merge(0,n,a,b);
    cout<<total<<endl;
}