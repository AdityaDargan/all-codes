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
        ll n;
        cin>>n;
        ll a[n];
        bool check=true;
        bool check2=true;
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll b[n];
        vector<ll> v;
        ll diff;
        for(ll i=0;i<n;i++){
            cin>>b[i];
            if(b[i]!=0){
                check2=false;
            }
            if(a[i]<b[i]){
                check=false;
                break;
            }
            else{
                if(b[i]!=0){
                    diff=a[i]-b[i];
                }
                v.push_back(a[i]-b[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(b[i]!=0){
                diff=a[i]-b[i];
                break;
            }
        }
        
        if(!check){
            cout<<"NO"<<endl;
            continue;
        }
        if(check2){
            cout<<"YES"<<endl;
            continue;
        }
        for(int i=0;i<n;i++){
            if(b[i]==0){
                if(v[i]>diff){
                    check=false;
                    break;
                }
            }
            else{
                if(v[i]!=diff){
                    check=false;
                    break;
                }
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