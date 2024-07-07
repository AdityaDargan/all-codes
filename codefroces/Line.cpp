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
        string s;
        cin>>s;
        ll ans=0;
        vector<ll> v;
        for(ll i=0;i<n;i++){
            if(i<n/2){
                if(s[i]=='R'){
                    ans+=(n-1-i);
                }
                else{
                    ans+=i;
                    v.push_back(n-1-i-i);
                }
            }
            else{
                if(s[i]=='L'){
                    ans+=i;
                }
                else{
                    ans+=(n-1-i);
                    v.push_back(i-n+1+i);
                }
            }
        }
        sort(v.begin(),v.end(),greater<ll>());
        map<ll,ll> m;
        // for(int i=0;i<v.size();i++){
        //     m[i+1]
        // }
        for(int i=0;i<n;i++){
            if(i<v.size()){
                ans+=v[i];
                cout<<ans<<" ";
            }
            else{
                cout<<ans<<" ";
            }
        }
        cout<<endl;
        
    }
}