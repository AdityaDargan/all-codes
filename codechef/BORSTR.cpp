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
#define mod 1000000007
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count=1;
        int temp=1;
        map<char,int> m;
        vector<int> v;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                temp++;
            }
            else{
                if(m[s[i-1]]!=0){
                    v.push_back(min(temp,m[s[i-1]]));
                    
                }
                m[s[i-1]]=max(temp,m[s[i-1]]);
                // cout<<m[s[i-1]]<<endl;
                if(temp>count){
                    count=temp;
                    temp=1;
                }
                temp=1;
            }
        }
        // cout<<m[s[n-1]]<<temp;
        if(m[s[n-1]]!=0){
            v.push_back(min(temp,m[s[n-1]]));
        }
        if(temp>count){
            count=temp;
        }
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<endl;
        bool check=false;

        if(count==1){
            sort(s.begin(),s.end());
            for(int i=1;i<n;i++){
                if(s[i]==s[i-1]){
                    check=true;
                }
            }
            if(check){
                cout<<1<<endl;
            }
            else{
                cout<<0<<endl;
            }
        }
        else{
            if(v.empty()){
                cout<<count-1<<endl;
                continue;
            }
            cout<<max(count-1,*max_element(v.begin(),v.end()))<<endl;
        }
        
    }
}