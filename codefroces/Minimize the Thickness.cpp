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
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<ll> v;
        for(int i=0;i<n;i++){
            ll sum=0;
            for(int j=0;j<=i;j++){
                sum+=arr[j];
            }
            int count=i+1;
            int tempsum=0;
            int tempcount=0;
            bool check=true;
            for(int j=i+1;j<n;j++){
                tempsum+=arr[j];
                tempcount++;
                if(tempsum==sum){
                    tempsum=0;
                    if(tempcount>count){
                        count=tempcount;
                    }
                    tempcount=0;
                }
                else if(tempsum>sum){
                    check=false;
                    break;
                }
            }
            if(tempsum!=0 && tempsum<sum){
                continue;
            }
            if(check){
                v.push_back(count);
            }
        }
        cout<<*min_element(v.begin(),v.end())<<endl;
    }
}