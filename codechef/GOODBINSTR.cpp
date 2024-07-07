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
        string s;
        cin>>s;
        int n=s.length();
        int zero=0;
        int one=0;
        for(int i=0;i<n-1;i++){
            if(s[i]=='0' && s[i+1]=='1'){
                zero++;
            }
            if(s[i]=='1' && s[i+1]=='0'){
                one++;
            }
        }
        int count=0;
        for(int i=1;i<n-1;i++){
            int tz=zero;
            int to=one;
            if(s[i]=='1'){
                if(s[i-1]=='0'){
                    tz--;
                }
                else{
                    to++;
                }
                if(s[i+1]=='0'){
                    to--;
                }
                else{
                    tz++;
                }
            }
            else{
                if(s[i-1]=='0'){
                    tz++;
                }
                else{
                    to--;
                }
                if(s[i+1]=='0'){
                    to++;
                }
                else{
                    tz--;
                }
            }
            if(to==tz){
                count++;
            }
        }
        int tz=zero;
        int to=one;
        if(s[0]=='0'){
            if(s[1]=='1'){
                tz--;
            }
            else{
                to++;
            }
        }
        else{
            if(s[1]=='1'){
                tz++;
            }
            else{
                to--;
            }
        }
        if(tz==to){
            count++;
        }
        tz=zero;
        to=one;
        if(s[n-1]=='0'){
            if(s[n-2]=='1'){
                to--;
            }
            else{
                tz++;
            }
        }
        else{
            if(s[1]=='1'){
                tz--;
            }
            else{
                to++;
            }
        }
        if(tz==to){
            count++;
        }

        cout<<count<<endl;
    }
}