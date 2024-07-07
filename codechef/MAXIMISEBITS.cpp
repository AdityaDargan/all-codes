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
        ll n,k;
        cin>>n>>k;
        vector<int> v;
        ll count=0;
        if(k==0){
            cout<<0<<endl;
            continue;
        }
        while(k){
            v.push_back(k%2);
            count+=k%2;
            k/=2;
        }
        if(n==1){
            cout<<count<<endl;
            continue;
        }
        count=0;
        if(n==2){
            ll carry=0;
            if(v[0]==0){
                count+=2;
                carry=1;
            }
            else{
                count+=1;
            }
            for(int i=1;i<v.size()-1;i++){
                if(carry==1){
                    if(v[i]==1){
                        count+=2;
                    }
                    else{
                        count+=1;
                    }
                }
                else{
                    if(v[i]==1){
                        count+=1;
                    }
                    else{
                        count+=2;
                        carry=1;
                    }
                }
            }
        }
        else{
            if(v[0]==0){
                count+=2;
            }
            else{
                count+=3;
            }
            for(int i=1;i<v.size()-1;i++){
                if(v[i]==0){
                    count+=1;
                }
                else{
                    count+=2;
                }
            }
        }
        cout<<count<<endl;
    }
}