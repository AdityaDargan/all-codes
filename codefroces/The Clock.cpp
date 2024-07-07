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
        int n=5;
        int x;
        string s;
        cin>>s;
        cin>>x;
        string s1=s.substr(0,2);
        string s2=s.substr(3,2);
        int h=stoi(s1);
        int m=stoi(s2);
        map<pair<ll,ll>,ll> mp;
        ll count=0;
        while(mp[make_pair(h,m)]==0){
            mp[make_pair(h,m)]++;
            ll temp=m+x;
            h=(h+temp/60)%24;
            m=temp%60;
            if(h%10==m/10 && h/10==m%10){
                count++;
            }
        }
        cout<<count<<endl;

    }
}