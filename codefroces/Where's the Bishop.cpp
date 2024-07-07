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
        char arr[8][8];
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cin>>arr[i][j];
            }
        }
        bool check=true;
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                if(arr[i][j]=='#'){
                    if(arr[i+1][j+1]=='#' && arr[i-1][j+1]=='#' && arr[i+1][j-1]=='#' && arr[i-1][j-1]=='#'){
                        cout<<i+1<<" "<<j+1<<endl;
                        check=false;
                    }
                }
            }
            if(!check){
                break;
            }
        }
    }
}