#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;

        vector<vector<int>> v(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        if(n==1 && m==1){
            cout<<-1<<endl;
            continue;
        }
        int prev = v[0][0];
        v[0][0] = v[n-1][m-1];

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0)continue;
                int temp = v[i][j];
                v[i][j] = prev;
                prev = temp;
            }
        }

        for(auto i:v){
            for(auto j:i)cout<<j<<" ";
            cout<<endl;
        }
    }
    
}