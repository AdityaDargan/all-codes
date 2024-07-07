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
        ll a[n];
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
        ll b[n];
        for(ll i=0;i<n;i++){
            cin>>b[i];
        }
        map<int,bool> m;
        ll counta=0;
        ll countb=0;
        ll count=0;
        for(int i=0;i<n;i++){
            if(a[i]==0){
                counta++;
            }
            if(b[i]==0){
                countb++;
            }
            if(a[i]!=b[i]){
                m[i]=true;
                count++;
            }
            else{
                m[i]=false;
            }
        }
        ll diff=abs(countb-counta);
        if(diff==count){
            cout<<diff<<endl;
        }
        else{
            cout<<diff+1<<endl;
        }
    }
}