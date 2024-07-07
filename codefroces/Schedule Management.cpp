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
    float t;
    cin>>t;
    while(t--){
        ll n,m;
        cin>>n>>m;
        float arr[m];
        for(ll i=0;i<m;i++){
            cin>>arr[i];
        }
        sort(arr,arr+m);
        float count=1;
        vector<pair<float,float>> v;
        map<float,float> mp;
        for(ll i=1;i<m;i++){
            if(arr[i]==arr[i-1]){
                ++count;
            }
            else{
                v.push_back(make_pair(count,arr[i-1]));
                mp[arr[i-1]]++;
                count=1;
            }
            if(i==m-1){
                v.push_back(make_pair(count,arr[m-1]));
                mp[arr[m-1]]++;
            }
        }
        
        if(m==1){
            cout<<1<<endl;
            continue;
        }
        for(int i=1;i<=n;i++){
            if(mp[i]==0){
                v.push_back(make_pair(0,i));
            }
        }
        
        sort(v.begin(),v.end());
        // for(int i=0;i<n;i++){
        //     cout<<v[i].first<<" "<<v[i].second<<endl;
        // }
        vector<float> v2;
        for(int i=0;i<n;i++){
            v2.push_back(v[i].first);
        }
        float x=accumulate(v2.begin(),v2.end(),0);
        float y=ceil((x+n)/float(n));
        float sum=0;
        float tot=0;
        float stot=0;
        bool check=false;
        for(int i=0;i<n;i++){
            if(v2[i]<=y){
                if(int(y-v2[i])%2!=0){
                    check=true;
                }
                sum+=ceil((y-v2[i])/2);
            }
            else{
                tot+=1;
                stot+=v2[i];
            } 
        }
        ll a=(ceil(stot-sum)/tot);
        cout<<max(int(a),int(y))<<endl;
        // if(check){
        //     cout<<max(int(a),max(int(y),int(y+1)));
        // }
        // else{
        //     cout<<max(int(a),int(y))<<endl;
        // }



        // float mn=0;
        // float mx=n-1;

        // while(v[mx].first-v[mn].first>1){
        //     v[mx].first-=1;
        //     v[mn].first+=2;

        //     if(v[mx].first<v[mx-1].first){
        //         sort(v.begin(),v.end());
        //         mx=n-1;
        //     }
        //     if(v[mn].first>v[mn+1].first){
        //         sort(v.begin(),v.end());
        //         mn=0;
        //     }   
        // }
        // cout<<v[mx].first<<endl;
    }
}