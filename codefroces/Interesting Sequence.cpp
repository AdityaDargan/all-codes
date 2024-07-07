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
        ll n,x;
        cin>>n>>x;
        vector<ll> vn;
        vector<ll> vx;
        ll a=n;
        ll b=x;
        while(a){
            vn.push_back(a%2);
            a/=2;
        }
        while(b){
            vx.push_back(b%2);
            b/=2;
        }

        // for(int i=0;i<vn.size();i++){
        //     cout<<vn[i];
        // }
        // cout<<endl;
        // for(int i=0;i<vx.size();i++){
        //     cout<<vx[i];
        // }
        // cout<<endl;
        
        if(n==x){
            cout<<n<<endl;
            continue;
        }
        if(n==0){
            cout<<-1<<endl;
            continue;
        }
        else if(x==0){
            ll num=2;
            while(num<=n){
                num*=2;
            }
            cout<<num<<endl;
            continue;
        }
        if(vx.size()!=vn.size()){
            cout<<-1<<endl;
            continue;
        }


        ll s;
        bool check=false;
        for(ll i=0;i<vx.size();i++){
            if(vx[i]==1){
                s=i;
                break;
            }
        }
        for(ll i=s;i<vn.size();i++){
            if(vn[i]!=vx[i]){
                check=true;
                break;
            }
        }
        if(check){
            cout<<-1<<endl;
            continue;
        }


        ll j;
        for(ll i=s-1;i>=0;i--){
            if(vn[i]==1){
                j=i;
                break;
            }
        }
        if(s-j==1){
            cout<<-1<<endl;
            continue;
        }
        ll num=2;
        while(j--){
            num*=2;
        }
        ll ans=x+num;
        cout<<ans<<endl;
    }
}