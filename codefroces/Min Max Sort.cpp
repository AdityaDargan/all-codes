#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#include <climits>
#include <fstream>
#include <queue>
#include <stack>
#define mod 1000000007
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        map<int,int> m;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            m[arr[i]]=i;
        }

        int front=1;
        vector<pair<int,int>> v;
        int start=1;
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        for(int i=2;i<=n;i++){
            if(m[i]>m[i-1]){
                front++;
            }
            else{
                v.push_back(make_pair(front,start));
                start=i;
                front=1;
            }
        }
        v.push_back(make_pair(front,start));

        int ans = INT_MAX;
        for(int i=0;i<v.size();i++){
            if(max(v[i].second-1,n-v[i].second-v[i].first+1)<ans){
                ans=max(v[i].second-1,n-v[i].second-v[i].first+1);
            }
        }
        cout<<ans<<endl;
    }
}