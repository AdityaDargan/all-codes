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
        ll n;
        cin>>n;
        ll arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        int count=0;
        bool last=false;
        for(int i=0;i<n;i++){
            if(i==0){
                last=true;
                continue;
            }
            if(i==n-1){
                if(last || arr[i]<arr[i-1]){
                    count++;
                    continue;
                }
            }
            if(last){
                if(arr[i]==arr[i-1]){
                    continue;
                }
                else if(arr[i]>arr[i-1]){
                    count++;
                }
            }
            if(arr[i]>arr[i-1]){
                last=false;
            }
            else if(arr[i]<arr[i-1]){
                last=true;
            }
        }
        if(n==1){
            cout<<"yes"<<endl;
            continue;
        }
        if(count==1){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
    }
}