#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        int arr[n];
        arr[0]=1;
        arr[1]=3;
        arr[2]=4;
        arr[3]=2;
        if(n==3){
            cout<<-1<<endl;
            continue;
        }
        else{
            for(int i=0;i<n-4;i++){
                arr[i+4]=i+5;
            }
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        // cout<<endl;
        // for(int i=0;i<n-2;i++){
        //     if((arr[i]^arr[i+1])==arr[i+2]){

        //         cout<<"YES"<<endl;
        //     }
        //     else{
        //         cout<<"NO"<<endl;
        //     }
        // }
    }
}