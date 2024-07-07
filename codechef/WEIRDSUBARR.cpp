#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#include <fstream>
#include <queue>
#include <stack>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        ll count=1;
        ll c=1;// increasing
        ll k=1;
        if(arr[0]>arr[1]){
            c=0;   //decreasing
            k=0;
        }
        vector<ll> v;
        for(int i=0;i<n-1;i++){
            if(c){
                if(arr[i]<arr[i+1]){
                    count++;
                }
                else{
                    c=0;
                    v.push_back(count);
                    count=2;
                }
            }
            else{
                if(arr[i]>arr[i+1]){
                    count++;
                }
                else{
                    c=1;
                    v.push_back(count);
                    count=2;
                }
            }
        }
        v.push_back(count);
        ll ans=n;
        for(int i=0;i<v.size();i++){
            ans+=(v[i]*(v[i]+1)/2);
            ans-=v[i];
        }
        if(k){
            for(int i=1;i<v.size()-1;i+=2){
                ll f = (v[i]-1)*(v[i+1]-1);
                ans+=f;
            }
        }
        else{
            for(int i=0;i<v.size()-1;i+=2){
                ll f = (v[i]-1)*(v[i+1]-1);
                ans+=f;
            }
        }
        cout<<ans<<endl;
    }
}