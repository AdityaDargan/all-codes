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
        int n;
        cin>>n;
        int arr[n];
        for(ll i=0;i<n;i++){
            cin>>arr[i];
        }
        vector<int> v;
        bool check=true;
        for(int i=0;i<n/2;i++){
            if(arr[i]<=arr[n-1-i]){
                v.push_back(int(arr[n-1-i]-arr[i]));
            }
            else{
                check=false;
            }
        }
        if(!check){
            cout<<-1<<endl;
            continue;
        }
        for(int i=0;i<v.size()-1;i++){
            if(v[i]<v[i+1]){
                check=false;
                break;
            }
        }
        if(check){
            cout<<v[0]<<endl;
        }
        else{
            cout<<-1<<endl;
        }
    }
}