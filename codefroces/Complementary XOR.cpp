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
        string a;
        string b;
        vector<int> v;
        cin>>a>>b;
        bool check=true;
        vector<int> v2;
        int count=0;
        int count2=0;
        for(int i=0;i<n;i++){
            if(a[i]=='1'){
                v.push_back(i+1);
                count++;
            }
            else{
                count2++;
                v2.push_back(i+1);
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]=='1' && b[i]=='0'){
                continue;
            }
            else if(a[i]=='0' && b[i]=='1'){
                continue;
            }
            else{
                check=false;
                break;
            }
        }
        if(a==b){
            cout<<"yes"<<endl;
            if(count%2==0){
                cout<<count<<endl;
                for(int i=0;i<count;i++){
                    cout<<v[i]<<" "<<v[i]<<endl;
                }
            }
            else{
                cout<<count+3<<endl;
                for(int i=0;i<count;i++){
                    cout<<v[i]<<" "<<v[i]<<endl;
                }
                cout<<1<<" "<<n<<endl;
                cout<<1<<" "<<n-1<<endl;
                cout<<n<<" "<<n<<endl;
            }
            continue;
        }
        if(!check){
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"yes"<<endl;
        if(count2%2==0){
            cout<<count2+1<<endl;
            cout<<1<<" "<<n<<endl;
            for(int i=0;i<count2;i++){
                cout<<v2[i]<<" "<<v2[i]<<endl;
            }
        }
        else{
            cout<<count2+4<<endl;
            cout<<1<<" "<<n<<endl;
            for(int i=0;i<count2;i++){
                cout<<v2[i]<<" "<<v2[i]<<endl;
            }
            cout<<1<<" "<<n<<endl;
            cout<<1<<" "<<n-1<<endl;
            cout<<n<<" "<<n<<endl;
        }
        
    }
}