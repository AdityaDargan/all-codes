#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#include <climits>
#include <fstream>
#include <queue>
#include <stack>
#include <set>
#define mod 1000000007
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        int num=0;
        if(n%2!=0){
            num++;
            for(int i=0;i<(n/2);i++){
                if(arr[i]==arr[n-1-i]){
                    num+=2;
                }
            }
            if(num==n){
                cout<<"YES"<<endl;
                continue;
            }
            if(n==k){
                cout<<"NO"<<endl;
                continue;
            }
            cout<<"YES"<<endl;
            continue;
        }
        else{
            int sm=0;
            for(int i=0;i<(n/2);i++){
                if(arr[i]==arr[n-1-i]){
                    num+=2;
                }
                else{
                    sm+=abs(arr[i]-arr[n-1-i]);
                }
            }
            if(num==n){
                cout<<"YES"<<endl;
                continue;
            }
            if(n==k){
                cout<<"NO"<<endl;
                continue;
            }
            if(k%2!=0){
                cout<<"YES"<<endl;
                continue;
            }
            if(sm%2==0){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
            continue;            
        }
    }
}