#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <cmath>
#include <map>
#include <fstream>
#include <queue>
#include <set>
#include <stack>
#include <climits>
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
        char arr[n];
        map<char,int> m;
        set<char> se;
        for(int i=0;i<n;i++){
            m[s[i]]++;
            se.insert(s[i]);
        }

        int j=0;
        vector<char> v;
        for(auto i:se){
            v.push_back(i);
        }
        for(auto itr=v.begin();itr!=v.end();itr++){
            int x = m[*itr];
            if(x%2==0){
                for(int i=0;i<x/2;i++){
                    arr[j]=*itr;
                    arr[n-1-j]=*itr;
                    j++;
                    m[*itr]-=x;
                }
                continue;
            }

            for(int i=0;i<x/2;i++){
                arr[j]=*itr;
                arr[n-1-j]=*itr;
                j++;
                m[*itr]-=(x-1);
            }

            if(itr+1==v.end()){
                arr[j]=*itr;
                break;
            }
            else if(itr+2==v.end()){
                int y=m[*(itr+1)];
                if(y%2==0){
                    for(int i=0;i<y/2;i++){
                        arr[j]=*(itr+1);
                        arr[n-1-j]=*(itr+1);
                        j++;
                        m[*(itr+1)]-=y;
                    }
                    arr[j]=*itr;
                    break;
                }
                else{
                    for(int i=0;i<y/2;i++){
                        arr[j]=*(itr+1);
                        arr[n-1-j]=*(itr+1);
                        j++;
                        m[*(itr+1)]-=(y-1);
                    }
                    arr[j]=*(itr+1);
                    arr[j+1]=*itr;
                }
                break;
            }
            else{
                arr[n-1-j]=*itr;
                arr[j]=*(itr+1);
                m[*(itr+1)]--;
                itr++;
                j++;
                while(itr!=v.end()){
                    for(int k=0;k<m[*itr];k++){
                        arr[j]=*itr;
                        j++;
                    }
                    itr++;
                }
                break;
            }
        }
        string ans="";
        for(int f=0;f<n;f++){
            ans+=arr[f];
        }
        cout<<ans<<endl;
    }
}
