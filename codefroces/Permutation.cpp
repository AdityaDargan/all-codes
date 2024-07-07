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
        int n;
        cin>>n;
        cout<<2<<endl;
        map<ll,ll> m;
        vector<ll> v;
        for(int i=1;i<=n;i++){
            if(m[i]==0){
                ll count=i;
                while(count<=n){
                    v.push_back(count);
                    m[count]=1;
                    count*=2;
                }
            }
        }
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}