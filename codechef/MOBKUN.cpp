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
        ll n,m,k,x;
        cin>>n>>m>>k>>x;
        ll days = n*k+m;
        ll temp=x/days;
        ll rem = x%days;

        if((rem>n*(k-1) && rem<=n*k+m) || rem==0){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
}