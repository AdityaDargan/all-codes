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
        int count=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==1){
                count++;
            }
        }
        sort(arr,arr+n);
        if(count==0){
            cout<<count<<endl;
            continue;
        }
        
        for(int f=count;f>0;f--){
            int index=n-1;
            for(int i=0;i<n;i++){
                if(arr[i]>f){
                    index=i-1;
                }
            }
            int c=f;
            int cnt=index+1;
            while(index>=0 && c>0){
                if(arr[index]<=c){
                    cnt-=2;
                    c--;
                    index--;
                }
                else{
                    index--;
                    cnt--;
                }
                if(cnt==0){
                    break;
                }
                if(cnt==1){
                    if(arr[index]<=c){
                        c--;
                        break;
                    }
                }
            }
            if(c==0){
                cout<<f<<endl;
                break;
            }
        }
    }
}