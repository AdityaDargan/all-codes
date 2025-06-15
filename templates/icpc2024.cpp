/*
Simple segtree-1
Lazy segtree-3
Fenwick tree-4
Kmp-5
KmpAnil-6
Scc-6
Dsu-7
Z function-8
Flow algo-8
Xor1ton-9
Power-9
Extended gcd-10
Mmi-10
Mod_inv-10
ncr-10
Catalan-10
Comparator-11
Sieve,spf,primefactorization-11
Prims-11
Manacher-12
Articulation point-13
Bridges-14
Bin coeff-15
CHT-max-16
Hashed string-17
Bitwise trie-17
Normal trie-18
Binary lifting-20/21
Phi1ton-22
Crt-22
Fft-23
Hld-24
*/

#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
int main(){ ios_base::sync_with_stdio(false); cin.tie(0); }
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define pbds tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
//*(find_by_order(i)) -> return element at index i
//order_of_key(i) -> return lower_bound of element i
// Segment Tree
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
    void update(int ind,int low,int high,int index,int val){
        // no overlap
        if( index<low || index>high ){
            return;
        }
        // overlap is there
        if(low==high && low==index){
            seg[ind] = val;
            return;
        }
        int mid = (low+high)/2;
        update(2*ind+1,low,mid,index,val);
        update(2*ind+2,mid+1,high,index,val);
        seg[ind] = seg[2*ind+1] + seg[2*ind+2];
        return;
    }
    ll query(ll ind,ll low,ll high,ll l,ll r){
        // No Overlap
        if(l>high || r<low){
            return 0;
        }
        // Full Overlap
        if(low>=l && high<=r){
            return seg[ind];
        }
        // Partial Overlap
        ll mid=(low+high)/2;
        ll left = query(2*ind+1,low,mid,l,r);
        ll right = query(2*ind+2,mid+1,high,l,r);
        return left + right;
    }
};
// segTree st(n); // st.build(0,0,n-1,arr);
// st.query(0,0,n-1,l,r)<<endl; // st.update(0,0,n-1,index,val);

// LAZY SEG - ANIL 
template <class T>
struct SegTree{
    int n;
    std::vector<T> tree, lz;
    std::vector<bool> haslazy;
    SegTree(int _n){
        n = 1;
        while(n<_n) n*=2;
        tree.assign(2*n, /* add identity element which wont effect the merge operation*/);
        lz.assign(2*n, /* add identity element which wont effect the update of lazy value*/);
        haslazy.assign(2*n, false);
    }
    void pushup(int node){
        tree[node] = tree[node<<1] /* add merge operation */ tree[node<<1|1];
    }
    void pushdown(int node, int l, int r){
        if (!haslazy[node]) return;
        tree[node<<1] = /* add child main value update*/
        tree[node<<1|1] = 
        lz[node<<1] = /* add child lazy value update*/
        lz[node<<1|1] = 
        haslazy[node<<1] = true;
        haslazy[node<<1|1] = true;
        lz[node] = /* add id used in lz[]*/;
        haslazy[node] = false;
    }
    void build(vector<T> m){
        for (int i = 0;i<sz(m);i++) tree[i+n] = m[i];
        for (int i = n-1;i>0;i--) pushup(i);
    }
    void update(int l, int r, T val, int x, int lx, int rx){
        if (l<=lx && rx<=r) {
            tree[x] = // add update
            lz[x] = // add lazy update
            haslazy[x] = true;
            return;
        }
        if (l>=rx || r<=lx) return;
        pushdown(x, lx, rx);
        int mid = (lx+rx)/2;
        update(l, r, val, 2*x, lx, mid);
        update(l, r, val, 2*x+1, mid, rx);
        pushup(x);
    }
    void update(int l, int r, T val){
        update(l, r, val, 1, 0, n);
    }
    T query(int l, int r, int x, int lx, int rx){
        if (l<=lx && rx<=r) return tree[x];
        if (l>=rx || r<=lx) return /* add id used in tree[]*/;
        int mid = (lx+rx)/2;
        pushdown(x, lx, rx);
        return query(l, r, 2*x, lx, mid)+query(l, r, 2*x+1, mid, rx);
    }
    T query(int l, int r){
        return query(l, r, 1, 0 , n);
    }
};
// FENWICK TREE
int n;
vector<int> fen; // only 1 based indexing
void update(int i,int val){
    while(i<=n){
        fen[i]+=val;
        i = i + (i & (-i));
    }
    return;
}
int query(int ind){
    int ans = 0;
    while(ind>0){
        ans+=fen[ind];
        ind = ind - (ind & (-ind));
    }
    return ans;
}
// fen.resize(n+1,0);
// KMP - 
void constructLps(string &pat, vector<int> &lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < pat.length()) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
vector<int> search(string &pat, string &txt) {
    int n = txt.length();  int m = pat.length();
    vector<int> lps(m),res;
    constructLps(pat, lps);
    int i = 0,j=0;
    while (i < n) {
        if (txt[i] == pat[j]) {
            i++; j++;
            if (j == m) {
                res.push_back(i - j);
                j = lps[j - 1];
            }
        }
        else {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return res;
}
// KMP ANIL
vector<int> pi(const string &s) {
	int n = (int)s.size();
	vector<int> pi_s(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j > 0 && s[j] != s[i]) { j = pi_s[j - 1]; }
		if (s[i] == s[j]) { j++; }
		pi_s[i] = j;
	}
	return pi_s;
}
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
    for (int i = 1; i < n; i++) { if (!vis[i]) dfs(i, vis, adj, st); }
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
// DSU 
struct DSU {
	vector<int> e; void init(int N) { e = vector<int>(N,-1); }
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); } 
	bool sameSet(int a, int b) { return get(a) == get(b); }
	int size(int x) { return -e[get(x)]; }
	bool unite(int x, int y) { // union by size
		x = get(x), y = get(y); if (x == y) return 0;
		if (e[x] > e[y]) swap(x,y);
		e[x] += e[y]; e[y] = x; return 1;
	}
};
// Z function 
vector<int> z_function(const string &s) {
	vector<int> z(s.size());
	z[0] = s.size();
	int l=0,r=0;
	for (int i = 1; i < s.size(); i++) {
		z[i] = max(0, min(z[i - l], r - i + 1));
		while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
			l = i; r = i + z[i]; z[i]++;
		}
	}
	return z;
}
// FLOW ALGORITHM
// * $lev[u] \neq -1,$ $lev[v] = -1$ are part of min cut.
// * Time: $O(N^2M)$ flow, $O(M\sqrt N)$ bipartite matching
struct Dinic {
	using F = long long; // flow type
	struct Edge { int to; F flo, cap; };
	int N; vector<Edge> eds; vector<vector<int>> adj;
	void init(int _N) { N = _N; adj.resize(N), cur.resize(N); }
	/// void reset() { each(e,eds) e.flo = 0; }
	void ae(int u, int v, F cap, F rcap = 0) { assert(min(cap,rcap) >= 0); 
		adj[u].push_back(eds.size()); eds.push_back({v,0,cap});
		adj[v].push_back(eds.size()); eds.push_back({u,0,rcap});
	}
	vector<int> lev; vector<vector<int>::iterator> cur;
	bool bfs(int s, int t) { // level = shortest distance from source
		lev = vector<int>(N,-1); 
        for (int i = 0;i<N;i++) cur[i] = begin(adj[i]);
		queue<int> q({s}); lev[s] = 0; 
		while (q.size()) { int u = q.front(); q.pop();
			for (auto e:adj[u]) { const Edge& E = eds[e];
				int v = E.to; if (lev[v] < 0 && E.flo < E.cap) 
					q.push(v), lev[v] = lev[u]+1;
			}
		}
		return lev[t] >= 0;
	}
	F dfs(int v, int t, F flo) {
		if (v == t) return flo;
		for (; cur[v] != end(adj[v]); cur[v]++) {
			Edge& E = eds[*cur[v]];
			if (lev[E.to]!=lev[v]+1||E.flo==E.cap) continue;
			F df = dfs(E.to,t,min(flo,E.cap-E.flo));
			if (df) { E.flo += df; eds[*cur[v]^1].flo -= df;
				return df; } // saturated >=1 one edge
		}
		return 0;
	}
	F maxFlow(int s, int t) {
		F tot = 0; while (bfs(s,t)) while (F df = 
			dfs(s,t,numeric_limits<F>::max())) tot += df;
		return tot;
	}
};
int xor_from_1_to_n(int n)
{
    if (n % 4 == 0) return n;
    else if (n % 4 == 1) return 1;
    else if (n % 4 == 2) return n + 1;
    return 0;
}
ll power(ll x, ll y, ll p) { // POWER (x^y)%modd
    ll res = 1;     // Initialize result 
    x = x % p;
    if (x == 0) return 0; // In case x is divisible by p;
    while (y > 0){ 
        if (y & 1) res = (res*x) % p; 
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
//returns the gcd of a and b in O(log(max(a,b))) and x and y are set as bezouts coeff. i.e. ax+by=gcd(a,b)
int extendedgcd(ll a, ll b, ll& x, ll& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
        int q = a1 / b1;
        tie(x, x1) = make_tuple(x1, x - q * x1);
        tie(y, y1) = make_tuple(y1, y - q * y1);
        tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
}
int mmi(int x){ return power(x, mod - 2,mod); }
int mod_inv(int a, int m){
    ll x, y;
    int g = extendedgcd(a, m, x, y);
    if (g != 1) return -1;
    else{
        x = (x % m + m) % m;
        return x;
    }
}
// computes the value of nCr in O(r)
int ncr(int n, int r){
    int res = 1;
    if (n - r < r)
        return ncr(n, n - r);
    for (int i = 1; i <= r; i++)
        res = ((res * (n - i + 1)) % mod * mmi(i)) % mod;
    return res;
}
// finding the nth term in the catalan series -> Cn=C0Cn-1+C1Cn-2+C2Cn-3...+Cn-1C0
int catalan(int n){
    return ncr(2 * n, n) / (n + 1);
}
// custom comparator
struct comp {
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.second - p2.second;
    }
};
#define MAXN 100001
vector<int> spf(MAXN + 1, 1);
void sieve(){
    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) {
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j]== 1) spf[j] = i;
            }
        }
    }
}
vector<int> getFactorization(int x){
    vector<int> ret;
    while (x != 1) { ret.push_back(spf[x]); x = x / spf[x]; }
    return ret;
}
// PRIMS
pair<int, vector<vector<pii>>> prims(vector<vector<pii>> &graph){
    int n = graph.size();   // #define pii pair<int, int>
    vector<vector<pii>> mst(n); // #define ppi pair<int, pii>
    vector<bool> visited(n, false);
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    pq.push({0, {0, -1}}); // base case
    int totalweight = 0;
    while (pq.size()){
        ppi p = pq.top();
        pq.pop();
        if (visited[p.second.first])
            continue; // this is already a part of our MST and
        // all edges from this vertex are already in the pq
        visited[p.second.first] = true;
        totalweight += p.first;
        if (p.second.second != -1){
            mst[p.second.first].push_back({p.second.second, p.first});
            mst[p.second.second].push_back({p.second.first, p.first});
        }
        for (const auto &x : graph[p.second.first]){
            if (!visited[x.first])
                pq.push({x.second, {x.first, p.second.first}});
        }
    }
    return {totalweight, mst};
}


// manacher // right of center for even
vector<vector<int>> manacher(int n,string &s) {
    vector<vector<int>> p(2,vector<int>(n,0));
    for(int z=0,l=0,r=0;z<2;z++,l=0,r=0)
        for(int i=0;i<n;i++) {
            if(i<r) p[z][i]=min(r-i+!z,p[z][l+r-i+!z]);
            int L=i-p[z][i], R=i+p[z][i]-!z;
            while(L-1>=0 && R+1<n && s[L-1]==s[R+1]) p[z][i]++,L--,R++;
            if(R>r) l=L,r=R;
        }
}









// Articulation Point
class Solution {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis, int tin[], int low[],
             vector<int> &mark, vector<int>adj[]) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (!vis[it]) {
                dfs(it, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1) {
                    mark[node] = 1;
                }
                child++;
            }
            else {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1) {
            mark[node] = 1;
        }
    }
public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<int> mark(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (mark[i] == 1) {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0) return { -1};
        return ans;
    }
};
// vector<int> adj[n];
// Solution obj;
// vector<int> nodes = obj.articulationPoints(n, adj);

// bridges
class Solution2 {
private:
    int timer = 1;
    void dfs(int node, int parent, vector<int> &vis,
             vector<int> adj[], int tin[], int low[], vector<vector<int>> &bridges) {
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer++;
        for (auto it : adj[node]) {
            if (it == parent) continue;
            if (vis[it] == 0) {
                dfs(it, node, vis, adj, tin, low, bridges);
                low[node] = min(low[it], low[node]);
                // node --- it
                if (low[it] > tin[node]) {
                    bridges.push_back({it, node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n,
    vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto it : connections) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<vector<int>> bridges;
        dfs(0, -1, vis, adj, tin, low, bridges);
        return bridges;
    }
};
// Solution2 obj;
// vector<vector<int>> bridges = obj.criticalConnections(n, connections);
// for (auto it : bridges) cout << "[" << it[0] << ", " << it[1] << "] ";

struct BinCoeff{
    int maxn, modd;// prime modd
    std::vector<long long> fact;
    std::vector<long long> inv;
    BinCoeff(int _m, int _md):maxn(_m), modd(_md){}
    BinCoeff():BinCoeff(1e6, 1e9+7){}
    void build(){
        fact.resize(maxn+1);
        inv.resize(maxn+1);
        fact[0] = fact[1] = inv[1] = inv[0] = 1;
        for (int i = 2;i<=maxn;i++){
            fact[i] = (fact[i-1]*i)%modd;
            inv[i] = (modd - (long long)(modd/i) * inv[modd%i] % modd) % modd;
        }
        for (int i = 2;i<=maxn;i++) inv[i] = (inv[i-1] * inv[i])%modd;
    }
    long long comb(int n, int r){// n <= maxn
        if (n<0 || r>n) return 0;
        return (((fact[n]*inv[r])%modd)*inv[n-r])%modd;
    }
};
// CHTmax
// Description: Container where you can add lines of the form kx+m, and query maximum values at points x.
struct Line {
	mutable ll k, m, p;// change to                > for cht min
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(ll x) const { return p < x; }
};
struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	static const ll inf = LLONG_MAX;
	ll div(ll a, ll b) { // floored division
		return a / b - ((a ^ b) < 0 && a % b); }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		// change this to             < for cht min
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(ll k, ll m) {
		auto z = insert({k, m, 0}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	ll query(ll x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return l.k * x + l.m;
	}
};
class HashedString {
  public:
	// change M and B if you want
	static const ll M = (1LL << 61) - 1;
	static const ll B;
	static __int128 mul(ll a, ll b) { return (__int128)a * b; }
	static ll mod_mul(ll a, ll b) { return mul(a, b) % M; }
  private:
	// pow[i] contains P^i % M
	static vector<ll> pow;
	// p_hash[i] is the hash of the first i characters of the given string
	vector<ll> p_hash;
  public:
	HashedString(const string &s) : p_hash(s.size() + 1) {
		while (pow.size() < s.size()) { pow.push_back(mod_mul(pow.back(), B)); }
		p_hash[0] = 0;
		for (int i = 0; i < s.size(); i++) {
			p_hash[i + 1] = (mul(p_hash[i], B) + s[i]) % M;
		}
	}
	ll get_hash(int start, int end) {
		ll raw_val = p_hash[end + 1] - mod_mul(p_hash[start], pow[end - start + 1]);
		return (raw_val + M) % M;
	}
};
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
vector<ll> HashedString::pow = {1};
const ll HashedString::B = uniform_int_distribution<ll>(0, M - 1)(rng);
// bitwise trie
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
// trie
class node{
    public:
    node * arr[26];
    int count[26] = {0};
    bool flag = false;
    int flag_count = 0;
    
    bool check_key(char c){ return (arr[c-'a']!=NULL);}
    void add_key(char c){ arr[c-'a'] = new node();return;}
    void increase(char c){ count[c-'a']++;}
    node * next_node(char c){ return arr[c-'a'];}
    void set_last(){ flag = true; flag_count++; return;}
    int no_of_flag(){ return flag_count; }
    int char_count(char &c){ return count[c-'a']; }

    void erase_char(char &c){ count[c-'a']--;
        if(count[c-'a']==0){
            arr[c-'a']=NULL;
        }
        return;
    }
    void erase_flag(){ flag_count--;
        if(flag_count==0)flag=true;
        return;
    }
};
class Trie{
    public:
    node* root;
    Trie(){
        root = new node();
    }
    void insert(string &s){
        node* cur = root;
        for(int i=0;i<s.length();i++){
            bool check = cur->check_key(s[i]);
            if(!check){
                cur->add_key(s[i]);
            }
            cur->increase(s[i]);
            cur = cur->next_node(s[i]);
        }
        cur->set_last();
    }
    int countWordsEqualTo(string &s){
        node *cur = root;
        for(int i=0;i<s.length();i++){
            bool check = cur->check_key(s[i]);
            if(!check) return 0;
            cur = cur->next_node(s[i]);
        }
        return cur->no_of_flag();
    }
    int countWordsStartingWith(string &s){
        node *cur = root;
        int ret = 0;
        for(int i=0;i<s.length();i++){
            bool check = cur->check_key(s[i]);
            if(!check) return 0;
            if(i==s.length()-1){
                return cur->char_count(s[i]);
            }
        }
    }
    void erase(string &s){
        node *cur = root;
        for(int i=0;i<s.length();i++){
            node *temp = cur->next_node(s[i]);
            cur->erase_char(s[i]);
            cur = temp;
        }
        cur->erase_flag();
        return;
    }
};
// binary lifting
vvl adj;
ll kthParent(ll x,ll k,vvl& parents){
    ll maxparents=parents[0].size();
    for(ll i=0;i<maxparents;i++){
        if((k&(1<<i))!=0){
            if(x!=-1) x=parents[x][i];
        }
    }
    return x;
}
void dfs(ll cv,ll par,vvl& parents){
    parents[cv][0]=par;
    for(auto it:adj[cv]){
    if(it==par) continue;
        dfs(it,cv,parents);
    }
}
void dfs3(ll cv,ll par,vl& depth,ll no){
    depth[cv]=no;
    for(auto it:adj[cv]){
    if(it==par) continue;
        dfs3(it,cv,depth,no+1);
    }
}
int lca(int x,int y,vl& depth,vvl& parents){
    ll dx=depth[x],dy=depth[y];
    if(dx>dy){
        x=kthParent(x,dx-dy,parents);
    }
    else if(dy>dx) y=kthParent(y,dy-dx,parents);
    if(x==y){
        return x;
    }
    else{
        ll maxlog=parents[0].size();
        for(int i=maxlog-1;i>=0;i--){
            int pox=parents[x][i];
            int poy=parents[y][i];
            if(pox!=poy){
                x=pox;y=poy;
            }
        }
        return parents[x][0];
    }
}
void solve(){
    ll maxparents=log2(n)+1;
    vvl parents(n+1,vl(maxparents,-1));
    dfs(1,-1,parents);
    vl depth(n+1);
    dfs3(1,-1,depth,0);
    for(ll i=1;i<maxparents;i++){
        for(ll j=1;j<=n;j++){
            ll intermediate=parents[j][i-1];
            if(intermediate!=-1) parents[j][i]=parents[intermediate][i-1];
        }
    }
}
void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;
    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
}
// CRT
struct Congruence {
    long long a, m;
};
long long chinese_remainder_theorem(vector<Congruence> const& congruences) {
    long long M = 1;
    for (auto const& congruence : congruences) {
        M *= congruence.m;
    }
    long long solution = 0;
    for (auto const& congruence : congruences) {
        long long a_i = congruence.a;
        long long M_i = M / congruence.m;
        long long N_i = mod_inv(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}
// FFT
typedef complex<double> C;
void fft(vector<C> &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n);
		rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i, k, 2 * k) rt[i] = R[i] = i & 1 ? R[i / 2] * x : R[i / 2];
	}
	vector<ll> rev(n);
	rep(i, 0, n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i, 0, n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j, 0, k) {
				// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  ///
				// include-line
				auto x = (double *)&rt[j + k],
				     y = (double *)&a[i + j + k];  /// exclude-line
				C z(x[0] * y[0] - x[1] * y[1],
				    x[0] * y[1] + x[1] * y[0]);  /// exclude-line
				a[i + j + k] = a[i + j] - z;
				a[i + j] += z;
			}
}
template <int M> vector<ll> convMod(const vector<ll> &a, const vector<ll> &b) {
	if (a.empty() || b.empty()) return {};
	vector<ll> res(sz(a) + sz(b) - 1);
	int B = 32 - __builtin_clz(sz(res)), n = 1 << B, cut = int(sqrt(M));
	vector<C> L(n), R(n), outs(n), outl(n);
	rep(i, 0, sz(a)) L[i] = C((int)a[i] / cut, (int)a[i] % cut);
	rep(i, 0, sz(b)) R[i] = C((int)b[i] / cut, (int)b[i] % cut);
	fft(L), fft(R);
	rep(i, 0, n) {
		int j = -i & (n - 1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
	}
	fft(outl), fft(outs);
	rep(i, 0, sz(res)) {
		ll av = ll(real(outl[i]) + .5), cv = ll(imag(outs[i]) + .5);
		ll bv = ll(imag(outl[i]) + .5) + ll(real(outs[i]) + .5);
		res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
	}
	return res;
}
// HLD
vector<int> parent, depth, heavy, head, pos;
int cur_pos;
int dfs(int v, vector<vector<int>> const& adj) {
    int size = 1;
    int max_c_size = 0;
    for (int c : adj[v]) {
        if (c != parent[v]) {
            parent[c] = v, depth[c] = depth[v] + 1;
            int c_size = dfs(c, adj);
            size += c_size;
            if (c_size > max_c_size)
                max_c_size = c_size, heavy[v] = c;
        }
    }
    return size;
}
void decompose(int v, int h, vector<vector<int>> const& adj) {
    head[v] = h, pos[v] = cur_pos++;
    if (heavy[v] != -1)
        decompose(heavy[v], h, adj);
    for (int c : adj[v]) {
        if (c != parent[v] && c != heavy[v])
            decompose(c, c, adj);
    }
}
void init(vector<vector<int>> const& adj) {
    int n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 0;
    dfs(0, adj);
    decompose(0, 0, adj);
}
int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = segment_tree_query(pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = segment_tree_query(pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}