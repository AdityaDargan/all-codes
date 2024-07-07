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
        int n;
        cin>>n;
        if(n==1){
            int temp;
            cin>>temp;
            cout<<0<<endl;
            continue;
        }
        string arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        int sum=0;
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                int one=0;
                int zero=0;
                if(arr[i][j]=='0'){
                    zero++;
                }
                else{
                    one++;
                }
                if(arr[j][n-1-i]=='0'){
                    zero++;
                }
                else{
                    one++;
                }
                if(arr[n-1-i][n-1-j]=='0'){
                    zero++;
                }
                else{
                    one++;
                }
                if(arr[n-1-j][i]=='0'){
                    zero++;
                }
                else{
                    one++;
                }
                sum+=min(one,zero);
            }
        }
        cout<<sum<<endl;
    }
}