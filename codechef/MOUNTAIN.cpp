#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#include <climits>
#include <fstream>
#include <queue>
#include <stack>
#define mod 1000000007
#define ll long long
using namespace std;

int main(){
    ll t;
    t=1;
    while(t--){
        ll n,m,q;
        cin>>n>>m>>q;
        ll arr[q];

        ll sm=(n*(n+1))/2;
        for(ll i=0;i<q;i++){
            cin>>arr[i];
        }
        for(ll j=0;j<q;j++){
            sm=n*(n+1)/2;
            ll num=arr[j];
            map<ll,ll> mp;
            if(num>=sm){
                ll f=num/sm;
                ll g=num-(f*sm);
                ll rm=m-f;
                if(rm<=0){
                    if(sm*f==num){
                        cout<<1<<" "<<n<<endl;
                        for(int i=1;i<=n;i++){
                            cout<<m<<" ";
                        }
                        cout<<endl;
                    }
                    else{
                        cout<<-1<<endl;
                    }
                    continue;
                }
                for(int i=n;i>=1;i--){
                    if(g-i>=0){
                        mp[i]++;
                        g-=i;
                    }
                }
                cout<<1<<" "<<n<<endl;
                for(int i=1;i<=n;i++){
                    cout<<f+mp[i]<<" ";
                }
                cout<<endl;
                continue;
            }
            else{
                ll num=arr[j];
                ll b;
                for(ll i=n;i>=1;i--){
                    if((i*(i+1)/2)<=num){
                        b=i;
                        break;
                    }
                }
                sm=b*(b+1)/2;
                ll f=num/sm;
                ll g=num-(f*sm);
                for(int i=b;i>=1;i--){
                    if(g-i>=0){
                        mp[i]++;
                        g-=i;
                    }
                }
                cout<<1<<" "<<b<<endl;
                for(int i=1;i<=b;i++){
                    cout<<f+mp[i]<<" ";
                }
                cout<<endl;

            }
        }

    }
}