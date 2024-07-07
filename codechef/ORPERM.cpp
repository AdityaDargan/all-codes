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
        ll arr[n];
        ll ora=0;
        ll orb=0;
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            ora|=arr[i];
        }
        ll brr[n];
        for(ll i=0;i<n;i++){
            cin>>brr[i];
            orb|=brr[i];
        }
        string sa="";
        string sb="";
        
        while(ora){
            ll mod=ora%2;
            sa+=to_string(mod);
            ora/=2;
        }
        while(orb){
            ll mod=orb%2;
            sb+=to_string(mod);
            orb/=2;
        }
        cout<<sa<<endl<<sb<<endl;
        ll ans=0;
        ll multi=1;
        bool check=true;
        for(int i=0;i<sa.length();i++){
            if(sb[i]=='1'){
                ans+=multi;
            }
            multi*=2;
        }
        cout<<ans<<endl; 

    }
}