#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int> w;
vector<int> val;
// int f(int i,int maxw,vector<vector<int>> dp){
//     if(dp[i][maxw]!=-1){
//         return dp[i][maxw];
//     }
//     if(i==0){
//         if(w[0]<=maxw){
//             dp[0][maxw] = val[0];
//             return dp[0][maxw];
//         }
//         else{
//             dp[0][maxw] = 0;
//             return dp[0][maxw];
//         }
//     }
//     int x = INT_MIN;
//     int y = INT_MIN;
//     if(w[i]<=maxw){
//         x = f(i-1,maxw-w[i],dp)+val[i];
//     }
//     y = f(i-1,maxw,dp);
//     dp[i][maxw] = max(x,y);
//     return dp[i][maxw];
// }

int main(){
    int n;
    cin>>n;
    int maxw;
    cin>>maxw;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        w.push_back(a);
    }
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        val.push_back(a);
    }
    vector<vector<int>> dp(n,vector<int>(maxw+1,0));
    // cout<<f(n-1,maxw,dp)<<endl;
    for(int j=0;j<=maxw;j++){
        if(w[0]<=j){
            dp[0][j]=val[0];
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=maxw;j++){
            int x = INT_MIN;
            int y = INT_MIN;
            if(w[i]<=j){
                x = dp[i-1][j-w[i]]+val[i];
            }
            y = dp[i-1][j];
            dp[i][j] = max(x,y);
        }
    }
    cout<<dp[n-1][maxw];
}