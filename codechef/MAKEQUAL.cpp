#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll a,b;
        ll arr[3];
        for(int i=0;i<3;i++){
            cin>>arr[i];
        }
        sort(arr,arr+3);
        a=arr[2]-arr[0];
        b=arr[2]-arr[1];
        if((a%2==0 && b%2==0)){
            cout<<"NO"<<endl;
            continue;
        }
        map<ll,ll> m;
        vector<ll> v;
        while(a){
            v.push_back(a%2);
            a/=2;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]==1){
                m[i]++;
            }
        }
        v.clear();
        while(b){
            v.push_back(b%2);
            b/=2;
        }
        for(int i=0;i<v.size();i++){
            if(v[i]==1){
                m[i]++;
            }
        }
        bool check=true;
        for(auto i:m){
            cout<<i.second<<endl;
            if(i.second!=1){
                check=false;
                break;
            }
        }
        if(check){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}