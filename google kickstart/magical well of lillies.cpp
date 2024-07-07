#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#include <fstream>
#include <queue>
#include <climits>
#include <stack>
#define mod 1000000007
#define ll long long
using namespace std;

int L;
int f(int l,int count,vector<int> &dp){
    if(dp[l]!=-1){
        return dp[l];
    }
    if(l==0){  
        dp[l]=0;     
        return 0;
    }
    int a=f(l-1,count,dp);
    int b=INT_MAX-2;
    if(count>0 && l-count>=0){
        b=f(l-count,count,dp);
    }
    int c=INT_MAX-6;
    if(l<L && l-count-L+l>=0){
        c=f(l-count-L+l,count+L-l,dp);
    }
    a+=1;
    b+=2;
    c+=6;
    int mn = min(min(a,b),c);
    dp[l]=min(mn,dp[l]);
    return mn;
}
int main(){
    ll t;
    cin>>t;
    for(ll T=1;T<=t;T++){
        int l;
        cin>>l;
        L=l;
        vector<int> dp(l+1,-1);
        int ans = dp[l];
        cout<<"Case #"<<T<<": "<<ans<<endl;
        dp[0] = 0;

        for(int i=1;i<=l;i++){

        }
    }
}