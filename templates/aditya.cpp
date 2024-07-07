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
class segTree{
    public:
    vector<ll> seg;
    segTree(ll n){
        seg.resize(4*n+1); 
    }
    void build(ll ind, ll low, ll high, vector<ll> &arr){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }
        ll mid=(low+high)/2;
        build(2*ind+1, low, mid, arr);
        build(2*ind+2, mid+1, high, arr);

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        return;
    }
    void update(ll ind,ll low,ll high,ll index,ll val){
        if(low==high){
            seg[ind]=val;
            return;
        }
        ll mid = (low+high)/2;

        if(index<=mid){update(2*ind+1,low,mid,index,val);}
        
        else{update(2*ind+2,mid+1,high,index,val);}

        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        return;
    }
    ll query(ll ind,ll low,ll high,ll l,ll r){
        if(l>high || r<low){
            return 0;
        }
        if(low>=l && high<=r){
            return seg[ind];
        }
        ll mid=(low+high)/2;
        ll left = query(2*ind+1,low,mid,l,r);
        ll right = query(2*ind+2,mid+1,high,l,r);
        return left + right;
    }
};
//         segTree st(n);
//         st.build(0,0,n-1,arr);
//         st.update(0,0,n-1,index,val);
//         cout<<st.query(0,0,n-1,l,r)<<endl;

// LAZY SEG TREE
class segTree{
    vector<ll> seg;
    vector<ll> lazy;
public:
    segTree(ll n){
        seg.resize(4*n+1);
        lazy.resize(4*n+1);
        fill(lazy.begin(),lazy.end(),0);
    }
    void build(ll ind,ll low, ll high, vector<ll> &arr){
        if(low==high){
            seg[ind] = arr[low];
            return;
        }
        ll mid=(low+high)/2;
        build(2*ind+1,low,mid,arr);
        build(2*ind+2,mid+1,high,arr);
        seg[ind] = seg[2*ind+1]+seg[2*ind+2];
        return;
    }
    void updateRange(ll ind,ll low,ll high, ll l,ll r, ll val){    
        //update previous changes
        seg[ind] += lazy[ind]*(high-low+1);
        lazy[2*ind+1]+=lazy[ind];
        lazy[2*ind+2]+=lazy[ind];
        //No overlap
        if(l>high || r<low){
            return;
        }
        //Full overlap
        if(low>=l && high<=r){
            seg[ind]+=(high-low+1)*val;
            lazy[2*ind+1]+=val;
            lazy[2*ind+2]+=val;
            return;
        }
        //Partial overlap
        ll mid=(low+high)/2;
        updateRange(2*ind+1,low,mid,l,r,val);
        updateRange(2*ind+2,mid+1,high,l,r,val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        return;
    }
    ll query(ll ind, ll low, ll high, ll l, ll r){
        //previous update
        seg[ind] += lazy[ind]*(high-low+1);
        lazy[2*ind+1]+=lazy[ind];
        lazy[2*ind+2]+=lazy[ind];   

        //No overlap
        if(l>high || r<low){
            return 0;
        }
        //Full overlap
        if(low>=l && high<=r){
            return seg[ind];
        }
        //Partial Overlap
        ll mid=(low+high)/2;
        ll left = query(2*ind+1,low,mid,l,r);
        ll right = query(2*ind+2,mid+1,high,l,r);
        return left + right;
    }
};
//         segTree st(n);
//         st.build(0,0,n-1,arr);
//         st.updateRange(0,0,n-1,l,r,val);
//         cout<<st.query(0,0,n-1,l,r)<<endl;

// trie starts
class node{
    public:
    node * arr[26];
    bool flag = false;
    bool check_key(char &c){ return (arr[c-'a']!=NULL);}

    void add_key(char &c){ arr[c-'a'] = new node(); return;}
    
    node * next_node(char &c){ return arr[c-'a'];}
    
    void set_last(){flag = true;return;}
    
    bool is_last(){return flag;}
};
class Trie{
    public:
    node* root;
    // initialize 
    Trie(){
        root = new node();
    }
    void insert(string &s){
        node* cur = root;
        for(int i=0;i<s.length();i++){
            bool check = cur->check_key(s[i]);
            if(!check) cur->add_key(s[i]);
            cur = cur->next_node(s[i]);
        }
        cur->set_last();
    }
    bool search(string &s){
        node *cur = root;
        for(int i=0;i<s.length();i++){
            bool check = cur->check_key(s[i]);
            if(!check) return false;
            cur = cur->next_node(s[i]);
        }
        return cur->is_last();
    }
    bool startswith(string &s){
        node *cur = root;
        for(int i=0;i<s.length();i++){
            bool check = cur->check_key(s[i]);
            if(!check) return false;
            cur = cur->next_node(s[i]);
        }
        return true;
    }
};

// kmp - 
void computeLPSArray(char* pat, int M, int* lps);
void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int lps[M];
	computeLPSArray(pat, M, lps);
	int i = 0; int j = 0;
	while ((N - i) >= (M - j)) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}
		if (j == M) {
			printf("Found pattern at index %d ", i - j);
			j = lps[j - 1];
		}
		else if (i < N && pat[j] != txt[i]) {
			if (j != 0) j = lps[j - 1];
			else i = i + 1;
		}
	}
}
void computeLPSArray(char* pat, int M, int* lps)
{
	int len = 0;
	lps[0] = 0;
	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]){
			len++; lps[i] = len; i++;
		}
		else{
			if (len != 0) {len = lps[len - 1];}
			else{lps[i] = 0;i++;}
		}
	}
}
// 	char txt[] = "ABABDABACDABABCABAB";
// 	char pat[] = "ABABCABAB";
// 	KMPSearch(pat, txt);
// 	return 0;

// topo sort
void dfs(int node, vector<int> &vis, stack<int> &st,vector<vector<int>> adj) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) dfs(it, vis, st, adj);
    }
    st.push(node);
}
vector<int> topoSort(int n, vector<vector<int>> adj)
{
    vector<int> vis(n,0);

    stack<int> st;
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            dfs(i, vis, st, adj);
        }
    }
    vector<int> ans;
    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}

// fenwick tree
int n;
vector<int> fen;
void update(int i,int val){
    while(i<n){
        fen[i]+=val;
        i = i + (i & (-i));
    }
    return;
}
int sum(int ind){
    int ans = 0;
    while(ind!=0){
        ans+=fen[ind];
        ind = ind - (ind & (-ind));
    }
    return ans;
}
//     fen.resize(n,0);
//     vector<int> v(n);
//     for(int i=0;i<n;i++){
//         cin>>v[i];
//         update(i,v[i]);
//     }
//     cout<<sum(12)<<endl;

// strongly connected components
void dfs(int node, vector<int> &vis, vector<vector<int>> &adj,stack<int> &st) {
    vis[node] = 1;
    for (auto it : adj[node]) {
        if (!vis[it]) dfs(it, vis, adj, st);
    }
    st.push(node);
}
void dfs3(int node, vector<int> &vis, vector<vector<int>> &adjT,vector<int> &temp) {
    vis[node] = 1;
    temp.push_back(node);
    for (auto it : adjT[node]) {
        if (!vis[it]) dfs3(it, vis, adjT,temp);
    }
}
vector<vector<int>> kosaraju(vector<vector<int>> &adj)
{
    int n = adj.size();
    vector<int> vis(n, 0);
    stack<int> st;
    for (int i = 1; i < n; i++) {
        if (!vis[i]) {
            dfs(i, vis, adj, st);
        }
    }
    vector<vector<int>> adjT(n);
    for (int i = 1; i < n; i++) {
        vis[i] = 0;
        for (auto it : adj[i]) {
            adjT[it].push_back(i);
        }
    }
    vector<vector<int>> all_scc;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]){
            vector<int> temp;
            dfs3(node, vis, adjT, temp);
            all_scc.push_back(temp);
        }
    }
    return all_scc;
}