#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;


ll solve(vector<ll> &v,ll num, ll i, vector<map<ll,ll>> &dp, vector<map<ll,ll>> &dp2){
    if(num==1){
        return 0;
    }
    if(i==0 || v[i]==1){
        return INT_MAX;
    }

    if(dp2[i][num]){
        return dp[i][num];
    }

    if(num%v[i]==0){
        ll x = solve(v,num/v[i],i,dp,dp2)+1;
        ll y = solve(v,num,i-1,dp,dp2);
        dp2[i][num] = 1;
        return dp[i][num] = min(x,y);
    }
    else{
        ll x = solve(v,num,i-1,dp,dp2);
        dp2[i][num] = 1;
        return dp[i][num] = x;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        ll x,y,k;
        cin>>x>>y>>k;

        ll g = __gcd(x,y);
        x/=g;
        y/=g;

        vector<ll> sx,sy;
        
        for(int i=1;i*i<=x;i++){
            if(x%i==0 && i<=k){
                sx.push_back(i);
                if(i*i==x || (x/i)>k)continue;
                sx.push_back(x/i);
            }
        }
        for(int i=1;i*i<=y;i++){
            if(y%i==0 && i<=k){
                sy.push_back(i);
                if(i*i==y || (y/i)>k)continue;
                sy.push_back(y/i);
            }
        }

        sort(sx.begin(),sx.end());
        sort(sy.begin(),sy.end());


        vector<map<ll,ll>> dp(sx.size()+1);
        vector<map<ll,ll>> dp2(sx.size()+1);
        ll ans2 = solve(sx,x,sx.size()-1,dp,dp2);

        vector<map<ll,ll>> dp3(sy.size()+1);
        vector<map<ll,ll>> dp4(sy.size()+1);
        ans2 += solve(sy,y,sy.size()-1,dp3,dp4);

        if(ans2>=INT_MAX){
            cout<<-1<<endl;
            continue;
        }

        cout << ans2 << endl;
        
    }
}