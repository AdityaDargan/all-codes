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

int f(int i,int amt,vector<int> &coins,vector<vector<int>> &v){
    if(v[i][amt]!=-1){
        return v[i][amt];
    }
    if(i==0){
        if(amt%coins[i]!=0){
            v[i][amt]=INT_MAX;
            return INT_MAX;
        }
        v[i][amt] = amt/coins[i];
        return (amt/coins[i]);
    }

    int take=INT_MAX;

    if(amt-coins[i]<0){
        v[i][amt] = f(i-1,amt,coins,v);
        return v[i][amt];
    }
    else{
        int x = amt/coins[i];
        for(int j=x;j>=0;j--){
            if(amt-j*coins[i]==0){
                v[i][amt] = j;
                return v[i][amt];
            }
            if(amt-j*coins[i]>0){
                int s = f(i-1,(amt-j*coins[i]),coins,v);
                if(s<INT_MAX){
                    take=min(take,j+s);
                }
                v[i][amt]=take;
            }
        }
    }
    return v[i][amt];
}
int coinChange(vector<int>& coins, int amt) {
    int n = coins.size();
    sort(coins.begin(),coins.end());
    vector<vector<int>> v(n+1,vector<int>(amt+1,-1));
    int ans = f(n-1,amt,coins,v);
    if(ans == INT_MAX || ans==-1){
        return -1;
    }
    return ans;
}
int main(){
    vector<int> coins = {411,412,413,414,415,416,417,418,419,420,421,422};
    int amt = 9864;
    cout<<coinChange(coins,amt);
}