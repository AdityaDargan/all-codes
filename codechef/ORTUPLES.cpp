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
        ll p1,q1,r1;
        cin>>p1>>q1>>r1;
        int num=max(max(p1,q1),r1);

        int n=log2(num)+1;

        vector<int> p;
        vector<int> q;
        vector<int> r;

        while(p1>0){
            p.push_back(p1%2);
            p1=p1/2;
        }
        while(q1>0){
            q.push_back(q1%2);
            q1/=2;
        }
        while(r1>0){
            r.push_back(r1%2);
            r1/=2;
        }
        ll count=0;
        bool check=true;
        for(int i=0;i<n;i++){
            p.push_back(0);

        }
        for(int i=0;i<n;i++){
            q.push_back(0);
        }
        for(int i=0;i<n;i++){
            r.push_back(0);
        }
        // for(int i=0;i<n;i++){
        //     cout<<p[i]<<" ";
            
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<q[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<r[i]<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<n;i++){
            
            if(p[i]==r[i] && p[i]==q[i] && p[i]==1){
                count++;
            }
            else{
                if(p[i]+q[i]+r[i]==1){
                    check=false;
                    break;
                }
            }
        }
        if(!check){
            cout<<0<<endl;
        }
        else{
            cout<<(ll)pow(4,count)<<endl;
        }
        
    }
}