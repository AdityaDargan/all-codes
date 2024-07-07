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
#include <cstring>
#define ll long long
using namespace std;

map<int,int> m3;
void SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= n; p++)
        if (prime[p])
            m3[p]=1;
}
vector<int> v;
void primef(int n)
{
    map<int,int> m2;
    v.clear();
    while (n % 2 == 0)
    {
        if(m2[2]==0){
            v.push_back(2);
        }
        m2[2]=1;
        n = n/2;
    }
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            if(m2[i]==0){
                v.push_back(i);
            }
            m2[i]++;
            n = n/i;
        }
    }
     if (n > 2)
        v.push_back(n);
}
int main(){
    int t;
    cin>>t;
    SieveOfEratosthenes(1000);
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int index;
        int count2=0;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]==1){
                count2++;
                index=i+1;
            }
        }
        map<int,int> m;
        primef(arr[n-1]);
        for(int i=0;i<v.size();i++){
            m[v[i]]++;
        }
        bool check2=false;
        int first;
        for(int i=n-2;i>=0;i--){
            primef(arr[i]);
            bool check=true;
            for(int j=0;j<v.size();j++){
                if(m[v[j]]>0 && v[j]!=1){
                    check=false;
                    break;
                }
                m[v[j]]++;
            }

            if(check){
                first=i+1;
                // cout<<i;
                check2=true;
                break;
            }
        }
        int num;
        if(!check2){
            cout<<-1<<endl;
            continue;
        }
        int second;
        m.clear();
        primef(arr[first-1]);
        for(int i=0;i<v.size();i++){
            m[v[i]]++;
        }
        for(int i=n-1;i>=first;i--){
            primef(arr[i]);
            bool check=true;
            for(int j=0;j<v.size();j++){
                if(m[v[j]]>0 && v[j]!=1){
                    check=false;
                    break;
                }
                m[v[j]]++;
            }
            if(check){
                second=i+1;
                break;
            }
        }

        vector<int> v5;
        int count=0;
        map<int,int> m7;
        for(int i=n-1;i>=0;i--){
            if(m3[arr[i]]>0 && m7[arr[i]]==0){
                v5.push_back(i+1);
                m7[arr[i]]++;
                count++;
            }
        }

        num = first+second;
        if(count>=2){
            if(v5[0]+v5[1]>num){
                num=v5[0]+v5[1];
            }
        }
        if(count2>0){
            if(index*2>num){
                num=index*2;
            }
        }
        cout<<num<<endl;
        
    }
}