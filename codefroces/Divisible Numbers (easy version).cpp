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
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        bool check=false;
        vector<pair<ll,ll>> v;
        ll prod=a*b;
        for(ll i=a+1;i<=c;i++){
            v.push_back(make_pair(prod/__gcd(prod,i),i));
        }
        ll num;
        for(int i=0;i<v.size();i++){
            num = b/(v[i].first);
            num*=v[i].first;
            num+=v[i].first;
            if(num>b && num<=d){
                check=true;
                ll ans=v[i].second;
                cout<<ans<<" "<<num<<endl;
                break;
            }
        }
        if(!check){
            cout<<-1<<" "<<-1<<endl;
        }
    }
}