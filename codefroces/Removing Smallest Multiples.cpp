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
        string s;
        cin>>s;
        map<ll,ll> m;
        vector<ll> v;
        vector<ll> v2;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                v.push_back(i+1);
                v2.push_back(i+1);
                m[i+1]=1;
            }
        }
        ll ans=0;
        for(int i=0;i<v.size();i++){
            ll k=v[i];
            m[k]=0;
            ans+=k;
            ll f=k;
            k+=f;
            v2.erase(std::remove(v2.begin(), v2.end(), k), v2.end());
            while(m[k]==1){
                m[k]=0;
                v2.erase(std::remove(v2.begin(), v2.end(), k), v2.end());
                ans+=f;
                k=k+f;
                if(v2.size()==0){
                    break;
                }
            }
            if(v2.size()==0){
                break;
            }
        }
        cout<<ans<<endl;
    }
}