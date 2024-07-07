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
        string a[n];
        string b[n];
        string c[n];
        map<string,int> m1;
        map<string,int> m2;
        map<string,int> m3;
        for(int i=0;i<n;i++){
            cin>>a[i];
            m1[a[i]]++;
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            m2[b[i]]++;
        }
        for(int i=0;i<n;i++){
            cin>>c[i];
            m3[c[i]]++;
        }
        ll a1=0;
        ll b1=0;
        ll c1=0;
        for(int i=0;i<n;i++){
            int count=0;
            if(m2[a[i]]==1){
                count++;
            }
            if(m3[a[i]]==1){
                count++;
            }
            if(count==0){
                a1+=3;
            }
            else if(count==1){
                a1+=1;
            }
        }
        for(int i=0;i<n;i++){
            int count=0;
            if(m2[c[i]]==1){
                count++;
            }
            if(m1[c[i]]==1){
                count++;
            }
            if(count==0){
                c1+=3;
            }
            else if(count==1){
                c1+=1;
            }
        }
        for(int i=0;i<n;i++){
            int count=0;
            if(m1[b[i]]==1){
                count++;
            }
            if(m3[b[i]]==1){
                count++;
            }
            if(count==0){
                b1+=3;
            }
            else if(count==1){
                b1+=1;
            }
        }
        cout<<a1<<" "<<b1<<" "<<c1<<endl;
    }
}