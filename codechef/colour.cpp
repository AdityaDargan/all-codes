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
        int x,y,z;
        cin>>x>>y>>z;
        int arr[3]={x,y,z};
        sort(arr,arr+3);
        if(arr[0]==0 && arr[1]==0 && arr[2]==0){
            cout<<0<<endl;
            continue;
        }
        if(arr[0]==0 && arr[1]==0 && arr[2]>0){
            cout<<1<<endl;
            continue;
        }
        if(arr[0]==0){
            if(arr[1]==1){
                cout<<2<<endl;
                continue;
            }
            if(arr[1]>=2){
                cout<<3<<endl;
                continue;
            }
        }
        if(arr[0]==1){
            if(arr[1]==1){
                cout<<3<<endl;
                continue;
            }
            if(arr[1]>=2){
                cout<<4<<endl;
                continue;
            }
        }
        if(arr[0]==2){
            if(arr[1]==2){
                if(arr[2]==2){
                    cout<<4<<endl;
                    continue;
                }
                if(arr[2]>2){
                    cout<<5<<endl;
                    continue;
                }
            }
            if(arr[1]>2){
                cout<<5<<endl;
                continue;
            }
        }
        if(arr[0]>2){
            cout<<6<<endl;
            continue;
        }
        cout<<arr[0]<<arr[1]<<arr[2]<<endl;
    }
}