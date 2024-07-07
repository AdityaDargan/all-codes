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
    while(t--){
        ll n;
        cin>>n;
        ll a[n];
        ll b[n];
        ll c[n];
        bool check=false;
        ll onec=0;
        ll oneb=0;
        ll onea=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            b[i]=a[i];
            c[i]=a[i];
            if(a[i]==0 && !check){
                a[i]=1;
                check=true;  
            }
            if(a[i]==1){
                onea++;
            }
            if(c[i]==1){
                onec++;
            }
        }
        check=true;
        for(ll i=n-1;i>=0;i--){
            if(b[i]==1 && check){
                check=false;
                b[i]=0;
            }
        }
        for(ll i=0;i<n-1;i++){
            if(b[i]==1){
                oneb++;
            }
        }

        ll count=0;
        vector<ll> v;
        ll ans=0;
        for(ll i=0;i<n-1;i++){
            if(a[i]==1){
                count++;
                ans=ans+ n-i-1-onea+count;
            }
        }
        v.push_back(ans);

        count=0;
        ans=0;
        for(ll i=0;i<n-1;i++){
            if(b[i]==1){
                count++;
                ans=ans+ n-i-1-oneb+count;
            }
            
        }
        v.push_back(ans);

        count=0;
        ans=0;
        for(ll i=0;i<n-1;i++){
            if(c[i]==1){
                count++;
                ans=ans+ n-i-1-onec+count;
            }
            
        }
        v.push_back(ans);

        cout<<*max_element(v.begin(),v.end())<<endl;
    }
}