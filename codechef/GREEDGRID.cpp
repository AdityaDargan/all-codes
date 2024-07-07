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

// int n,m;
// int f(int i,int j,vector<vector<int>> v,vector<vector<int>> dp){
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }
//     if(i==n-1 && j==m-1){
//         dp[i][j] = v[i][j];
//         return v[i][j];
//     }
//     int right = INT_MAX;
//     int down = INT_MAX;
//     if(i<n-1){
//         int temp;
//         if(i+1<n-1 && j<m-1){
//             if(v[i+2][j]>v[i+1][j+1]){
//                 temp=f(i+2,j,v,dp);
//             }
//             else if(v[i+2][j]<v[i+1][j+1]){
//                 temp=f(i+1,j+1,v,dp);
//             }
//             else{
//                 temp=min(f(i+1,j+1,v,dp),f(i+2,j,v,dp));
//             }
//         }
//         else if(j==m-1 && i+1==n-1){
//             dp[i][j] = max(v[i+1][j],v[i][j]);
//             return max(v[i+1][j],v[i][j]);
//         }
//         else if(i+1==n-1){
//             temp=f(i+1,j+1,v,dp);
//         }
//         else if(j==m-1){
//             temp=f(i+2,j,v,dp);
//         }
//         right = max(temp,v[i+1][j]);
//     }
//     if(j<m-1){
//         int temp;
//         if(i<n-1 && j+1<m-1){
//             if(v[i][j+2]>v[i+1][j+1]){
//                 temp=f(i,j+2,v,dp);
//             }
//             else if(v[i][j+2]<v[i+1][j+1]){
//                 temp=f(i+1,j+1,v,dp);
//             }
//             else{
//                 temp=min(f(i+1,j+1,v,dp),f(i,j+2,v,dp));
//             }
//         }
//         else if(j+1==m-1 && i==n-1){
//             dp[i][j] = max(v[i][j+1],v[i][j]);
//             return max(v[i][j+1],v[i][j]);
//         }
//         else if(j+1==m-1){
//             temp=f(i+1,j+1,v,dp);
//         }
//         else if(i==n-1){
//             temp=f(i,j+2,v,dp);
//         }
//         down = max(temp,v[i][j+1]);
//     }
//     int ans = min(right,down);
//     dp[i][j] = max(ans,v[i][j]);
//     return max(ans,v[i][j]);
// }
int main(){
    ll t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> v(n,vector<int>(m));
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        int i=0,j=0;
        // cout<<f(i,j,v,dp)<<endl;
        dp[n-1][m-1] = v[n-1][m-1];
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1){
                    continue;
                }
                int right = INT_MAX;
                int down = INT_MAX;
                if(i<n-1){
                    int temp;
                    if(i+1<n-1 && j<m-1){
                        if(v[i+2][j]>v[i+1][j+1]){
                            temp=dp[i+2][j];
                        }
                        else if(v[i+2][j]<v[i+1][j+1]){
                            temp=dp[i+1][j+1];
                        }
                        else{
                            temp=min(dp[i+1][j+1],dp[i+2][j]);
                        }
                    }
                    else if(j==m-1 && i+1==n-1){
                        dp[i][j] = max(v[i+1][j],v[i][j]);
                        continue;
                    }
                    else if(i+1==n-1){
                        temp=dp[i+1][j+1];
                    }
                    else if(j==m-1){
                        temp=dp[i+2][j];
                    }
                    right = max(temp,v[i+1][j]);
                }
                if(j<m-1){
                    int temp;
                    if(i<n-1 && j+1<m-1){
                        if(v[i][j+2]>v[i+1][j+1]){
                            temp=dp[i][j+2];
                        }
                        else if(v[i][j+2]<v[i+1][j+1]){
                            temp=dp[i+1][j+1];
                        }
                        else{
                            temp=min(dp[i+1][j+1],dp[i][j+2]);
                        }
                    }
                    else if(j+1==m-1 && i==n-1){
                        dp[i][j] = max(v[i][j+1],v[i][j]);
                        continue;
                    }
                    else if(j+1==m-1){
                        temp=dp[i+1][j+1];
                    }
                    else if(i==n-1){
                        temp=dp[i][j+2];
                    }
                    down = max(temp,v[i][j+1]);
                }
                int ans = min(right,down);
                dp[i][j] = max(ans,v[i][j]);
            }
        }
        cout<<dp[0][0]<<endl;
    }
}