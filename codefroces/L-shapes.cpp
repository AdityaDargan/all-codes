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
        int n,m;
        cin>>n>>m;
        char arr[n][m];
        bool check1=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>arr[i][j];
                if(arr[i][j]=='*'){
                    check1=true;
                }
            }
        }
        if(!check1){
            cout<<"YES"<<endl;
            continue;
        }
        for(int i=1;i<n-1;i++){
            for(int j=1;j<m-1;j++){
                if(arr[i][j]=='*'){
                    
                    if(arr[i+1][j]=='*'){
                        if(arr[i][j-1]=='*'){
                            arr[i][j]='-';
                            arr[i+1][j]='-';
                            arr[i][j-1]='-';
                        }
                        else if(arr[i][j+1]=='*'){
                            arr[i][j]='-';
                            arr[i+1][j]='-';
                            arr[i][j+1]='-';
                        }
                    }
                    else if(arr[i-1][j]=='*'){
                        if(arr[i][j-1]=='*'){
                            arr[i][j]='-';
                            arr[i-1][j]='-';
                            arr[i][j-1]='-';
                        }
                        else if(arr[i][j+1]=='*'){
                            arr[i][j]='-';
                            arr[i-1][j]='-';
                            arr[i][j+1]='-';
                        }
                    }
                }
            }
        }
        for(int j=1;j<m-1;j++){
            if(arr[0][j]=='*'){
                if(arr[1][j]=='*'){
                    if(arr[0][j-1]=='*'){
                        arr[0][j]='-';
                        arr[1][j]='-';
                        arr[0][j-1]='-';
                    }
                    else if(arr[0][j+1]=='*'){
                        arr[0][j]='-';
                        arr[1][j]='-';
                        arr[0][j+1]='-';
                    }
                }
            }
            if(arr[n-1][j]=='*'){
                if(arr[n-2][j]=='*'){
                    if(arr[n-1][j-1]=='*'){
                        arr[n-1][j]='-';
                        arr[n-2][j]='-';
                        arr[n-1][j-1]='-';
                    }
                    else if(arr[n-1][j+1]=='*'){
                        arr[n-1][j]='-';
                        arr[n-2][j]='-';
                        arr[n-1][j+1]='-';
                    }
                }
            }
        }
        for(int i=1;i<n-1;i++){
            if(arr[i][0]=='*'){
                if(arr[i][1]=='*'){
                    if(arr[i-1][0]=='*'){
                        arr[i][0]='-';
                        arr[i][1]='-';
                        arr[i-1][0]='-';
                    }
                    else if(arr[i+1][0]=='*'){
                        arr[i][0]='-';
                        arr[i][1]='-';
                        arr[i+1][0]='-';
                    }
                }
            }
            if(arr[i][m-1]=='*'){
                if(arr[i][m-2]=='*'){
                    if(arr[i-1][m-1]=='*'){
                        arr[i][m-1]='-';
                        arr[i][m-2]='-';
                        arr[i-1][m-1]='-';
                    }
                    else if(arr[i+1][m-1]=='*'){
                        arr[i][m-1]='-';
                        arr[i][m-2]='-';
                        arr[i+1][m-1]='-';
                    }
                }
            }
        }
        if(arr[0][0]=='*' && arr[0][1]=='*' && arr[1][0]=='*'){
            arr[0][0]='-';
            arr[0][1]='-';
            arr[1][0]='-';
        }
        if(arr[n-1][m-1]=='*' && arr[n-2][m-1]=='*' && arr[n-1][m-2]=='*'){
            arr[n-1][m-1]='-';
            arr[n-2][m-1]='-';
            arr[n-1][m-2]='-';
        }
        if(arr[0][m-1]=='*' && arr[1][m-1]=='*' && arr[0][m-2]=='*'){
            arr[0][m-1]='-';
            arr[0][m-2]='-';
            arr[1][m-1]='-';
        }
        if(arr[n-1][0]=='*' && arr[n-1][1]=='*' && arr[n-2][0]=='*'){
            arr[n-1][0]='-';
            arr[n-1][1]='-';
            arr[n-2][0]='-';
        }
        bool check2=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                // cout<<arr[i][j];
                if(arr[i][j]=='*'){
                    check2=false;
                }
            }
        }
        if(!check2){
            cout<<"NO"<<1<<endl;

            continue;
        }
        bool check3=true;
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[i][j]=='-'){
                    if(arr[i-1][j]=='-' && arr[i+1][j]=='-'){
                        check3=false;
                    }
                    if(arr[i][j-1]=='-' && arr[i][j+1]=='-'){
                        check3=false;
                    }
                    int count=0;
                    if(arr[i+1][j+1]=='-'){
                        count++;
                    }
                    if(arr[i+1][j-1]=='-'){
                        count++;
                    }
                    if(arr[i-1][j+1]=='-'){
                        count++;
                    }
                    if(arr[i-1][j-1]=='-'){
                        count++;
                    }
                    if(count>1){
                        check3=false;
                    }
                }
            }
        }
        if(!check3){
            cout<<"NO"<<2<<endl;
            continue;
        }
        bool check4=true;
        for(int i=1;i<n-1;i++){
            if(arr[i][0]=='-' && arr[i+1][0]=='-' && arr[i-1][0]=='-'){
                check4=false;
            }
            if(arr[i][m-1]=='-' && arr[i+1][m-1]=='-' && arr[i-1][m-1]=='-'){
                check4=false;
            }
        }
        for(int j=1;j<m-1;j++){
            if(arr[0][j]=='-' && arr[0][j+1]=='-' && arr[0][j-1]=='-'){
                check4=false;
            }
            if(arr[n-1][j]=='-' && arr[n-1][j+1]=='-' && arr[n-1][j-1]=='-'){
                check4=false;
            }
        }
        if(!check4){
            cout<<"NO"<<3<<endl;
            continue;
        }
        cout<<"YES"<<4<<endl;

    }
}