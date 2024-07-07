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
        ll arr[n];
        ll one=0;
        ll zero=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==0){
                zero++;
            }
            else{
                one++;
            }
        }
        if(n==1){
            cout<<"Bob"<<endl;
            continue;
        }
        if(zero==0 || one==0){
            cout<<"Bob"<<endl;
            continue;
        }
        vector<pair<ll,ll>> v;
        bool var=true;
        if(arr[0]==1){
            var=true;
        }
        else{
            var=false;
        }
        ll count=1;
        for(int i=1;i<n;i++){
            if(arr[i]==0){
                if(var){
                    v.push_back(make_pair(count,1));
                    count=1;
                }
                else{
                    count++;
                }
                var=false;
            }
            else{
                if(var){
                    count++;
                }
                else{
                    v.push_back(make_pair(count,0));
                    count=1;
                }
                var=true;
            }
        }
        
        if(arr[0]==arr[n-1]){
            v[0].first=count+v[0].first;
        }
        else{
            v.push_back(make_pair(count,(int)var));
        }
        ll ans0=0;
        ll ans1=0;
        for(int i=0;i<v.size();i++){
            if(v[i].second){
                ans1+=v[i].first-1;
            }
            else{
                ans0+=v[i].first-1;
            }
            
            // cout<<v[i].first<<" "<<v[i].second<<endl;
        }
        ll ans=0;
        if(zero<one){
            ans=ans0;
        }
        else{
            ans=ans1;
        }
        // cout<<ans<<endl;
        if(ans%2!=0){
            cout<<"Alice"<<endl;
        }
        else{
            cout<<"Bob"<<endl;
        }
    }
}