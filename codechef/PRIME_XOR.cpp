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
        ll x,y;
        cin>>x>>y;
        ll z=x^y;
        ll a,b,c;
        vector<ll> v;
        vector<ll> vx;
        vector<ll> vy;
        vector<ll> vz;
        while(x){
            vx.push_back(x%2);
            x/=2;
        }
        while(y){
            vy.push_back(y%2);
            y/=2;
        }
        while(z){
            vz.push_back(z%2);
            z/=2;
        }
        // reverse(vx.begin(),vx.end());
        // reverse(vy.begin(),vy.end());
        // reverse(vz.begin(),vz.end());
        ll sx=vx.size();
        ll sy=vy.size();
        ll sz=vz.size();
        ll s=max(sx,max(sy,sz));
        for(int i=0;i<s-sx;i++){
            vx.push_back(0);
        }
        for(int i=0;i<s-sy;i++){
            vy.push_back(0);
        }
        for(int i=0;i<s-sz;i++){
            vz.push_back(0);
        }
        for(int i=0;i<s;i++){
            
        }
    }
}