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

struct node{
    node * arr[2];
    int flag = 0;
};

class Trie{
    public:
    node * root;

    Trie(){
        root = new node();
    }
    
    void insert(int x){
        node *cur = root;
        for(int i=31;i>=0;i--){
            int bit = (x>>i)&1;
            if(cur -> arr[bit] == NULL){
                cur->arr[bit] = new node();
            }
            cur = cur->arr[bit];
        }
    }

    int check(int x){
        node *cur = root;
        int ans = 0;
        for(int i=31;i>=0;i--){
            int bit = (x>>i)&1;
            if(cur -> arr[!bit] == NULL){
                cur = cur->arr[bit];
            }
            else{
                ans += 1<<i;
                cur = cur->arr[!bit];
            }
        }
        return ans;
    }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        Trie tr;
        for(int i=0;i<n;i++){
            cin>>v[i];
            tr.insert(v[i]);
        }
        int mx = 0;
        for(int i=0;i<n;i++){
            int a = tr.check(v[i]);
            mx = max(mx,a);
        }
        cout<<mx<<endl;
    }
}