// cout<<"Case #"<<f<<": Possible"<<endl;
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
#define mod 1000000007
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    for(int T=1;T<=t;T++){
        ll n,l;
        cin>>l>>n;
        ll d[n];
        char c[n];
        for(ll i=0;i<n;i++){
            cin>>d[i]>>c[i];
        }
        ll dist=0;
        if(c[0]=='A'){
            dist-=d[0]%l;
        }
        else{
            dist+=d[0]%l;
        }
        ll lap = d[0]/l;
        ll dir = c[0];
        for(int i=1;i<n;i++){
            if(c[i]!=c[i-1]){
                if(c[i]=='A'){
                    ll x=dist-d[i];
                    if(x>0){
                        dist = x;
                    }
                    else{
                        dist=(-1)*(abs(x)%l);
                        lap+=abs(x)/l;
                    }
                }
                else{
                    ll x=dist+d[i];
                    if(x<0){
                        dist = x;
                    }
                    else{
                        dist=(x)%l;
                        lap+=x/l; 
                    }                 
                }
            }
            else{
                if(c[i]=='A'){
                    ll x=dist-d[i];
                    if(x>0){
                        dist = x;
                    }
                    else{
                        dist=(-1)*(abs(x)%l);
                        lap+=abs(x)/l;
                    }
                    // dist-=d[i]%l;
                    // lap+=d[i]/l;
                    // lap+=abs(dist)/l;
                    // dist=(abs(dist)%l)*(-1);
                }
                else{
                    ll x=dist+d[i];
                    if(x<0){
                        dist = x;
                    }
                    else{
                        dist=(x)%l;
                        lap+=x/l; 
                    }  
                    // dist+=d[i]%l;
                    // lap+=d[i]/l;
                    // lap+=dist/l;
                    // dist=dist%l;
                }
            }
        }
        cout<<"Case #"<<T<<": "<<lap<<endl;
    }
}