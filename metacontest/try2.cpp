#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int main(){  
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ll t;
    cin>>t;
    // cout<<"Case #"<<ii<<": YES"<<"\n";
    for(ll ii=1;ii<=t;ii++){
        ll r,c,k;
        cin>>r>>c>>k;
        vector<vector<ll>> arr(r,vector<ll>(c));

        for(ll i=0;i<r;i++){
            for(ll j=0;j<c;j++){
                cin>>arr[i][j];
            }
        }
        
        vector<ll> ans(801,0);

        for(ll res=1;res<=r;res++){
            for(ll i=0;i<r;i++){
                if(i+res>=r)continue;
                ll row = i+res;
                for(ll j=0;j<c;j++){
                    for(ll col=max(0LL,j-res+1);col<=min(c-1,j+res-1);col++){
                        if(arr[i][j]!=arr[row][col]){
                            ans[res]+=2;
                        }
                    }
                }
            }
        }
        for(ll res=1;res<=c;res++){
            for(ll j=0;j<c;j++){
                if(j+res>=c)continue;
                ll col = j+res;
                for(ll i=0;i<r;i++){
                    for(ll row=max(0LL,i-res);row<=min(r-1,i+res);row++){
                        if(arr[i][j]!=arr[row][col]){
                            ans[res]+=2;
                        }
                    }
                }
            }
        }

        ll val = 0;
        for(ll i=1;i<=800;i++){
            k-=ans[i];
            if(k<=0){
                val = i;
                break;
            }
        }

        cout<<"Case #"<<ii<<": "<<val<<"\n";
    }
}