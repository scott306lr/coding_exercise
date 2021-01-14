#include <iostream>
#include <queue>
using namespace std;
#define ll long long

ll int f(ll int &a, ll int &b){
    ll int cost=0;
    //cout<<"use f:"<<"a:"<<a<<"b:"<<b<<endl;
    if (a==b){
        a = b = 0;
    }else if(a!=0 && b!=0){
        a = a-b;
        b = 0;
        cost = a;
    }else if(b==0){
        cost = a;
        a = 0;
        b = 0;
    }
    return cost;
}

void solve(priority_queue<ll int> &pq){
    ll int a,b,tcost=0;
    while(pq.top()!=0){
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        tcost += f(a,b);
        pq.push(b);
        pq.push(a);
        
    }
    cout<<tcost;
}

int main(){
    int inpu,n;
    priority_queue<ll int> pq;

    cin>>n;
    for(int i=0; i<n; ++i){
        cin>>inpu;
        pq.push(inpu);
    }
    solve(pq);
}