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
        string s1;
        cin>>s1;
        ll n=s1.length();
        string s;
        for(int i=0;i<n;i++){
            if(i==0){
                s+='(';
            }
            else if(i==n-1){
                s+=')';
            }
            else{
                s+=s1[i];
            }
        }
        int start=0;
        int end=0;
        int ques=0;

        for(int i=0;i<n;i++){
            if(s[i]=='('){
                start++;
            }
            else if(s[i]==')'){
                end++;
            }
            else{
                if(ques==end-start){
                    start++;
                    start+=ques;
                    ques=0;
                }
                else{
                    ques++;
                }
            }
        }
        if(n%2!=0){
            cout<<"no"<<endl;
            continue;
        }
        start=n/2-start;
        end=n/2-end;
        if(start<0 || end<0){
            cout<<"no"<<endl;
            continue;
        }
        if(ques==0){
            cout<<"yes"<<endl;
            continue;
        }
        if(ques==1){
            cout<<"yes"<<endl;
            continue;
        }
        if(start==0 || end==0){
            cout<<"yes"<<endl;
            continue;
        }
        else{
            cout<<"no"<<endl;
            continue;
        }

    }
}