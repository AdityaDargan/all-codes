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
        int n,x;
        cin>>n>>x;
        int arr[n];
        arr[n-1]=1;
        arr[0]=x;
        if(n%x!=0){
            cout<<-1<<endl;
            continue;
        }
        else{
            int a=n;
            vector<int> v;
            map<int,int> m;
            int k=2;
            int b=x;
            while(x*k<=a){
                if(a%(x*k)==0){
                    x*=k;
                    k=1;
                    v.push_back(x);
                }
                k++;
            }
            x=b;
            // for(int i=0;i<v.size();i++){
            //     cout<<v[i]<<" ";
            // }
            // cout<<endl;
            int j=0;
            for(int i=1;i<=n-2;i++){
                if(i+1==x && j<v.size()){
                    arr[i]=v[j];
                    x=v[j];
                    j++;
                }
                else{
                    arr[i]=i+1;
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
}