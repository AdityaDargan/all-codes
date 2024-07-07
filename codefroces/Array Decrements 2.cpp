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
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        int b[n];
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        
        int m1=*max_element(a,a+n);
        int m2=*max_element(b,b+n);
        bool check=false;
        if(m2>m1){
            cout<<"NO"<<endl;
        }
        else{
            int aditya=m1-m2;
            for(int i=0;i<n;i++){
                if(a[i]-b[i]==aditya){
                    continue;
                }
                if(a[i]-b[i]!=aditya && b[i]!=0){
                    check=true;
                    break;
                }
                else{
                    if(b[i]==0 && a[i]-b[i]<=aditya){
                        continue;
                    }
                    else{
                        check=true;
                        break;
                    }
                }
            }
        if(!check){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
}

    }
}