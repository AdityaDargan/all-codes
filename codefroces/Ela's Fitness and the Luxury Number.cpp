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
        ll l,r;
        cin>>l>>r;
        ll start = (int)pow(l,0.5);
        ll end = (int)pow(r,0.5);
        ll ans=1;
        if(start*start != l){
            start+=1;
        }
        ans+=(end-start)*3;
        cout<<ans<<endl;
        for(int i=l;i<start*start;i++){
            if(i%(ll)(pow(i,0.5))==0){
                ans+=1;
            }
        }
        for(int i=end*end+1;i<=r;i++){
            if(i%(ll)(pow(i,0.5))==0){
                ans+=1;
            }
        }
        cout<<ans<<endl;
        

        
    }
}