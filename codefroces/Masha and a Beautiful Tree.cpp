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
        int m;
        cin>>m;
        int arr[m];
        for(ll i=0;i<m;i++){
            cin>>arr[i];
        }
        int n=log2(m);
        bool check=false;
        ll ans=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<m;j=j+(int)pow(2,i)){
                if(abs(ceil(float(arr[j])/float(pow(2,i-1)))    -ceil(float(arr[j+(int)pow(2,i-1)])/float(pow(2,i-1))))==1){

                    if(arr[j]>arr[j+(int)pow(2,i-1)]){
                        ans++;
                    }
                }
                else{
                    check=true;
                    break;
                }
            }
            if(check){
                break;
            }
        }
        if(check){
            cout<<-1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
}