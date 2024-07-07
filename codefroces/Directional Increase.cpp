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
        vector<ll> v;
        ll sm=0;
        for(ll i=0;i<n;i++){
            ll temp;
            cin>>temp;
            sm+=temp;
            v.push_back(temp);
        }
        if(sm!=0){
            cout<<"NO"<<endl;
            continue;
        }
        bool check1=true;
        for(int i=n-1;i>=0;i--){
            if(v[i]==0){
                v.pop_back();
            }
            else{
                if(v[i]>0){
                    check1=false;
                }
                break;
            }
        }
        
        // if(!check1){
        //     cout<<"NO"<<endl;
        //     continue;
        // }
        n=v.size();
        vector<ll> v2;
        for(int i=0;i<n-1;i++){
            v2.push_back(1);
        }
        v2.push_back(0);
        bool check2=true;
        for(int i=n-1;i>=1;i--){
            if(v[i]>=v2[i]){
                check2=false;
                break;
            }
            v2[i-1]=1-((v[i]-v2[i])+1);
        }
        if(!check2){
            cout<<"NO"<<endl;
            continue;
        }
        if(v2[0]==v[0]){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}