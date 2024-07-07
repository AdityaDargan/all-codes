#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#include <climits>
#include <queue>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        map<ll,pair<ll,ll>> m;
        ll mn=INT_MAX,mx=INT_MIN;
        queue<ll> v;
        for(int i=0;i<n;i++){
            ll a,b;
            cin>>a>>b;
            m[i+1]=make_pair(a,b);
            if(a<mn){
                mn=a;
            }
            if(b>mx){
                mx=b;
            }
            if(i+1>=a && i+1<=b){
                v.push(i+1);
            }
        }
        cout<<mx-mn+1-v.size()<<endl;
        for(int i=mn;i<=mx;i++){
            if(i!=v.front()){
                cout<<i<<endl;
            }
            else{
                v.pop();
            }
        }

    }
}