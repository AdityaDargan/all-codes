// Q - You are given two numeric strings num1 and num2 and two integers max_sum and min_sum. We denote an integer x to be good if:

// num1 <= x <= num2
// min_sum <= digit_sum(x) <= max_sum.
// Return the number of good integers. Since the answer may be large, return it modulo 1e9 + 7.

// Note that digit_sum(x) denotes the sum of the digits of x.

// Constraints - 
// 1 <= num1 <= num2 <= 1022
// 1 <= min_sum <= max_sum <= 400



//**************APPROACH******************//

//TAKE 3 VARIABLES N,X,TIGHT 

// N is number of digits , x is their sum , and tight is the most important variable that if tight=0 we can take any number at that place and if tight =1 that means we can only take number allowed till max num

// best method to find ans(l,r)=ans(0,r)-ans(0,l)

//********************************************//



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



ll solve(string s,ll n,ll x,ll tight,vector<vector<vector<int>>> &v){
    if(x<0){
        return 0;
    }
    if(v[n][x][tight]!=-1){
        return v[n][x][tight];
    }
    ll k=s.length();
    
    if(n==1){
        if(tight){
            if(x>=0 && x<=s[k-n]-'0'){
                return 1;
            }
            return 0;
        }
        else{
            if(x>=0 && x<=9){
                return 1;
            }
            return 0;
        }
        
    }
    ll ans=0;
    for(ll i=0;i<=9;i++){
        if(tight && i>(s[k-n]-'0')){
            break;
        }
        ans+=solve(s,n-1,x-i,(tight && (s[k-n]-'0'==i)),v);
        ans%=mod;
    }
    v[n][x][tight]=ans;
    return ans;
}

int count(string num1, string num2, int min_sum, int max_sum) {
    ll x=0;
    ll y=0;
    ll n=num1.length();
    ll m=num2.length();
    vector<vector<vector<int>>> v1(n+1,vector<vector<int>>(min(207,max_sum)+1,vector<int>(2,-1)));
    vector<vector<vector<int>>> v2(m+1,vector<vector<int>>(min(207,max_sum)+1,vector<int>(2,-1)));

    for(ll i=min_sum;i<=max_sum;i++){
        x+=solve(num1,n,i,1,v1)%mod;
        x%=mod;
        
        y+=solve(num2,m,i,1,v2)%mod;
        y%=mod;
    }
    int temp=0;
    for(int i=0;i<num1.length();i++){
        temp+=(num1[i]-'0');
    }
    ll ans=0;
    if(temp>=min_sum && temp<=max_sum){
        ans++;
    }
    ans += ((y%mod)-(x%mod))%mod;
    return ans;
}

int main(){
    string num1,num2;
    int min_sum,max_sum;
    cin>>num1>>num2>>min_sum>>max_sum;
    cout<<count(num1,num2,min_sum,max_sum)<<endl;
}



