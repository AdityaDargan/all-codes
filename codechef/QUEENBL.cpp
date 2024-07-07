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
        int x,y;
        cin>>x>>y;
        int arr[8][8];
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                arr[i][j]=0;
            }
        }
        arr[x-1][y-1]=1;
        if(x==1){
            if(y==1){
                arr[1][2]=2;
            }
            else if(y==8){
                arr[1][5]=2;
            }
            else{
                arr[2][y-1-1]=2;
                arr[2][y-1+1]=2;

            }
        }
        else if(x==8){
            if(y==1){
                arr[6][2]=2;
            }
            else if(y==8){
                arr[6][5]=2;
            }
            else{
                arr[5][y-1-1]=2;
                arr[5][y-1+1]=2;
            }
        }
        else{
            if(y==1){
                arr[x-1+1][2]=2;
                arr[x-1-1][2]=2;
            }
            else if(y==8){
                arr[x-1+1][5]=2;
                arr[x-1-1][5]=2;
            }
            else{
                if(x<4){
                    if(y<4){
                        arr[x-1+2][y-1-1]=2;
                        arr[x-1-1][y-1+3]=2;
                    }
                    else{
                        arr[x-1+2][y-1+1]=2;
                        arr[x-1-1][y-1-3]=2;
                    }
                }
                else{
                    if(y<4){
                        arr[x-1-2][y-1-1]=2;
                        arr[x-1+1][y-1+3]=2;
                    }
                    else{
                        arr[x-1-2][y-1+1]=2;
                        arr[x-1+1][y-1-3]=2;
                    }
                }
            }

        }
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}