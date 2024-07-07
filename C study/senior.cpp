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
#include <climits>
#define mod 1000000007
#define ll long long
using namespace std;

vector<ll> arr;
vector<vector<ll>> dp;

//recursion
// ll solve(ll i,ll sum){
//     if(sum==0) return dp[i][sum] = 0;
//     if(sum<0 || i<0) return INT_MAX;

//     //memoization
//     if(dp[i][sum]!=-1)return dp[i][sum];

//     return dp[i][sum] = min(solve(i-1,sum),1+solve(i,sum-arr[i]));

    // we take the current element - 1+solve(i,sum-arr[i])
    // or we dont take - solve(i-1,sum)
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t=1;
    // cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        arr.resize(n);
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(),arr.end());


        // recursion
        // dp.resize(n,vector<ll>(x+1,-1));
        // // 3*(12)
        // solve(n-1,x);
        // ll ans = dp[n-1][x];
        // if(ans==INT_MAX) cout<<-1<<endl;
        // else cout<<ans<<endl;


        //tabulation
        // dp.resize(n,vector<ll>(x+1,INT_MAX));


        // recieving dp - pull dp

        // base case
        // for(int i=0;i<n;i++){
        //     dp[i][0] = 0;
        // }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=x;j++){

        //         if(i>=1) dp[i][j] = dp[i-1][j];

        //         if(j>=arr[i]) dp[i][j] = min(dp[i][j],1+dp[i][j-arr[i]]);
        //     }
        // }
        // ll ans = dp[n-1][x];
        // if(ans==INT_MAX) cout<<-1<<endl;
        // else cout<<ans<<endl;



        // distributing dp - push dp
        // for(int i=0;i<n;i++){
        //     dp[i][0] = 0;
        // }

        // for(int j=0;j<=x;j++){
        //     for(int i=0;i<n;i++){
        //         if(i<n-1) dp[i+1][j] = min(dp[i+1][j],dp[i][j]);
        //         if(j+arr[i]<=x) dp[i][j+arr[i]] = min(dp[i][j+arr[i]],1+dp[i][j]);
        //     }
        // }
        
        // ll ans = dp[n-1][x];
        // if(ans==INT_MAX) cout<<-1<<endl;
        // else cout<<ans<<endl;

        // dp - n*x => dp - 10^8



        // space optimization and state elimination
        

        // n*x = 10^8
        // 2*x = 10^6

        vector<ll> prev(x+1,INT_MAX);//previous
        vector<ll> curr(x+1,INT_MAX);//current
        curr[0] = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<=x;j++){
                if(i>=1) curr[j] = prev[j];
                if(j>=arr[i]) curr[j] = min(curr[j],1+curr[j-arr[i]]);
            }
            prev = curr;
        }

        ll ans = curr[x];
        if(ans==INT_MAX) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}
