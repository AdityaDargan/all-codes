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
        vector<int> v;
        int x=0;
        int y=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            int m=arr[i];
            while(m){
                if(m%2==0){
                    x++;
                    m/=2;
                }
                else{
                    break;
                }  
            }
            int k=i+1;
            while(k){
                if(k%2==0){
                    y++;
                    k/=2;
                }
                else{
                    v.push_back(y);
                    y=0;
                    break;
                }
            }
        }
        if(x>=n){
            cout<<0<<endl;
            continue;
        }
        int count=0;
        bool check2=true;
        sort(v.begin(),v.end());
        for(int i=v.size()-1;i>=0;i--){
            x+=v[i];
            if(v[i]>0){
                ++count;
            }
            if(x>=n){
                check2=false;
                break;
            }
            
        }
        if(check2){
            cout<<-1<<endl;
        }
        else{
            cout<<count<<endl;
        }
    }
}