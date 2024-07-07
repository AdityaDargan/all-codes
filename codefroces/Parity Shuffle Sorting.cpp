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
        vector<pair<ll,ll>> odd;
        vector<pair<ll,ll>> even;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]%2==0){
                even.push_back(make_pair(arr[i],i+1));
            }
            else{
                odd.push_back(make_pair(arr[i],i+1));
            }
        }
        ll o=odd.size();
        ll e=even.size();
        ll ans;
        bool check;
        ll m=0;
        if(arr[0]%2==0){
            ans=o;
            check=true;
            m+=ans+e-1;
        }
        else{
            ans=e;
            check=false;
            m+=ans+o-1;
        }
        
        cout<<m<<endl;
        if(!check){
            for(int i=0;i<o-1;i++){
                cout<< odd[i].second <<" "<< odd[o-1].second <<endl;
            }
            for(int i=0;i<ans;i++){
                cout<<1<<" "<<even[i].second<<endl;
            }
        }
        else{
            for(int i=0;i<e-1;i++){
                cout<< even[i].second <<" "<< even[e-1].second <<endl;
            }
            for(int i=0;i<ans;i++){
                cout<<1<<" "<<odd[i].second<<endl;
            }
        }
        // if(check){
        //     for(int i=0;i<ans;i++){
        //         cout<<1<<" "<<odd[i].second<<endl;
        //     }
        // }
        // else{
        //     for(int i=0;i<ans;i++){
        //         cout<<1<<" "<<even[i].second<<endl;
        //     }
        // }
        
    }
}