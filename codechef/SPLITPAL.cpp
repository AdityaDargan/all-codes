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
        int start=0;
        int end=n-1;
        int count=0;
        int ns=arr[start];
        int ne=arr[end];
        while(start<end){
            if(ns==ne){
                start++;
                end--;
                ns=arr[start];
                ne=arr[end];
            }
            else{
                count++;
                if(ns<ne){
                    ne=ne-ns;
                    start++;
                    ns=arr[start];
                }
                else{
                    ns=ns-ne;
                    end--;
                    ne=arr[end];
                }
            }
        }
        cout<<count<<endl;
    }
}