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
        ll n,k;
        cin>>n>>k;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        k--;
        if(k==0 || k==n){
            cout<<"YES"<<endl;
            continue;
        }

        ll end=0;
        vector<ll> e;
        for(int i=k+1;i<n;i++){
            end+=arr[i];
            e.push_back(end);
        } 
        if(e.size()>0){
            end=*max_element(e.begin(),e.end());
        }
        bool check=false;
        ll ans;
        if(end>0){
            ans=end;
        }
        else{
            ans=0;
        }
        for(int i=k;i>=0;i--){
            ans+=arr[i];
            if(ans<0){
                check=true;
                break;
            }
        }

        ll start=0;
        vector<ll> s;
        for(int i=k-1;i>=0;i--){
            start+=arr[i];
            s.push_back(start);
        }
        if(s.size()>0){
            start=*max_element(s.begin(),s.end());
        }
        bool check2=false;
        ll ans2;
        if(start>0){
            ans2=start;
        }
        else{
            ans2=0;
        }
        for(int i=k;i<n;i++){
            ans2+=arr[i];
            if(ans2<0){
                check2=true;
                break;
            }
        }

        if(!check || !check2){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}