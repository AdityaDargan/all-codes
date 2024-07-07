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
        ll n,x,y;
        cin>>n>>x>>y;
        string a;
        string b;
        cin>>a>>b;
        vector<ll> v;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                v.push_back(i);
            }
        }
        if(v.size()%2!=0){
            cout<<-1<<endl;
            continue;
        }
        if(v.size()==0){
            cout<<0<<endl;
            continue;
        }
        if(v.size()>=4){
            cout<<y*(v.size()/2)<<endl;
            continue;
        }
        else{
            if(abs(v[0]-v[1])==1){
                if(n>3){
                    cout<<min(2*y,x)<<endl;
                }
                else{
                    cout<<x<<endl;
                }
            }
            else{
                cout<<y<<endl;
            }
        }
    }
}