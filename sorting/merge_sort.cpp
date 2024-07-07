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
#include <climits>
#define mod 1000000007
#define ll long long
using namespace std;

int n;
int c;

void merge(vector<int> &v,int begin,int mid,int end){
    int i=begin;
    int j=mid+1;
    vector<int> v2;
    while(true){
        if(i>mid){
            for(int f=j;f<=end;f++){
                v2.push_back(v[f]);
            }
            break;
        }
        if(j>end){
            for(int f=i;f<=mid;f++){
                v2.push_back(v[f]);
            }
            break;
        }
        if(v[i]<v[j]){
            v2.push_back(v[i]);
            i++;
        }
        else {
            v2.push_back(v[j]);
            j++;
        }
    }
    for(int k=begin;k<=end;k++){
        v[k]=v2[k-begin];
    }
    return;
}

void mergesort(vector<int> &v,int begin,int end){
    int mid=(begin+end)/2;
    if(begin<end){
        mergesort(v,begin,mid);
        mergesort(v,mid+1,end);    
    }
    else{
        return;
    }
    merge(v,begin,mid,end);
    return;
}

int main(){
    vector<int> v={3,2,1,4,3,2,4,8,6,8};
    c=0;
    n=v.size();
    mergesort(v,0,n-1);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl<<c<<endl;
}