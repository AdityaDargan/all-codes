#include <bits/stdc++.h>

using namespace std;

#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int		long long
#define ll 		long long
#define lld		long double
#define PI 		3.141592653589793238462
#define INF 	1e18
#define M    	1000000007
#define MOD1	998244353
#define nline 	"\n"
#define set_bits __builtin_popcountll

ll binExpo(ll a, ll b, ll mod) {ll res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}

vector<ll> sieveVector(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
vector<int> sieve(int n){vector<int> primes(n + 1,1);primes[0] = 0;primes[1] = 0;for(int i = 2;i*i<=n;i++){if(primes[i]){for(int j = 2*i;j<=n;j+=i){primes[j] = 0;}}}return primes;}
// change to j = i*i for better performance
vector<int> spf(int n){vector<int> spf(n + 1);for(int i = 2;i<=n;i++){spf[i] = i;}for(int i = 2;i*i<=n;i++){if(spf[i] == i){for(int j = i * i;j<=n;j+=i){if(spf[j] == j)spf[j] = i;}}}return spf;}

/*.....................................................*/

void testcases(int t){

}

signed main(){
	fastio();
	int t=1;
	// cin>>t;
	for(int i=0;i<t;i++){
		testcases(i + 1);
	}
}

bool bellmanFord(vector<pair<int,pair<int,int>>> &edges,int n,int m){
	vector<int> parent(n); vector<int> dist(n,INF);
	parent[0] = -1; dist[0] = 0; bool updated;
	for(int i = 0;i<n-1;i++){
		updated = false;
		for(int j = 0;j<m;j++){
			int x = edges[j].second.first;
			int y = edges[j].second.second;
      		int wt = edges[j].first;
			if(dist[x]!=INT_MAX && dist[x] + wt < dist[y]){
				dist[y] = dist[x] + wt; parent[y] = x;
				updated = true;
			}
		}
		if(updated == false) break;
	}
	if(updated == true){
		for(int j = 0;j<m;j++){
			int x = edges[j].second.first;
      		int y = edges[j].second.second;
			int wt = edges[j].first;
			if(dist[x]!=INT_MAX && dist[x] + wt < dist[y]){
				return true;
			}
		}
	}
	return false;
}

int main(){ //Time Complexity is O(VE)
	int n;int m; cin>>n>>m; vector<pair<int,pair<int,int>>> edges(m);
	while(m--){
		int x,y,wt;cin>>x>>y>>wt;
		edges.emplace_back(make_pair(wt,make_pair(x,y)));
	}
	cout<<bellmanFord(edges,n,m)<<endl;
}

void bfs(int source,vector<int> g[],
vector<int> &visited,vector<int> &level){
	queue<int> q; q.push(source); visited[source] = 1;
	while(!q.empty()){
		int currVertex = q.front();q.pop();
		for(int child : g[currVertex]){
			if(!visited[child]){
				q.push(child); visited[child] = 1;
				level[child] = level[currVertex] + 1;
			}
		}
	}
}

//Binary Lifting code to find the LCA of the given two nodes(q queries)
void dfs(int vertex,int parent,vector<int> &levels,vector<int> adj[]){
	levels[vertex] = levels[parent] + 1;
	for(auto child : adj[vertex]){
		if(child != parent) dfs(child,vertex,levels,adj);
	}
}
int kthParent(int a,int k,vector<vector<int>> &parents,int n){
	for(int i = 0;i<=log2(n);i++){
		if(parents[i][a] != -1 && (k & (1 << i))) a = parents[i][a];
	} return a;
}
void testcases(int t){
	int n; int q; cin>>n>>q; vector<int> adj[n+1];
	vector<vector<int>> parents(log2(n) +1,vector<int> (n + 1,-1));
	parents[0][1] = -1;
	for(int i = 2;i<=n;i++){
		int x;cin>>x; parents[0][i] = x;
		adj[x].emplace_back(i); adj[i].emplace_back(x);
	}
	vector<int> levels(n+1); dfs(1,0,levels,adj);
	for(int i = 1;i<=log2(n);i++){
		for(int j = 1;j<=n;j++){
			int intermediate = parents[i-1][j];
			if(intermediate != -1){
				parents[i][j] = parents[i-1][intermediate];
			}
		}
	}
	while (q){
		int a,b; cin>>a>>b;
		if(levels[a] > levels[b]) swap(a,b);
		int levelDiff = levels[b] - levels[a];
		b = kthParent(b,levelDiff,parents,n);
		if(a != b){
			for(int i = log2(n);i>=0;i--){
				int ka = parents[i][a]; int kb = parents[i][b];
				if(kb != ka){ a = ka; b = kb; }
			}
			cout<<parents[0][a]<<endl;
		}
		else cout<<a<<endl; q--;
	}
}

void dijkstra(vector<pair<int,int>> graph[],vector<int> &visited,
vector<int> &dis,vector<int> &parent,vector<int> &path,int n,int m){
  	// parent is only required for this particular question, 1 based indexing
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
	minHeap.push(make_pair(0,1)); dis[1] = 0;
	while(!minHeap.empty()){
		auto p = minHeap.top(); minHeap.pop();
		int dist = p.first; int v = p.second;
		if(visited[v]) continue; visited[v] = 1;
		for(auto child : graph[v]){
			int childV = child.first; int wt = child.second;
			if(dist + wt < dis[childV]){
				dis[childV] = dist + wt; parent[childV] = v;
				minHeap.push(make_pair(dis[childV],childV));
			}
		}
	}
	if(dis[n] == INF) return;
	else{
		while(n != -1){
		path.push_back(n); n = parent[n];
		}
		reverse(path.begin(),path.end());
	}
}

// Kruskal Algo
const int N = 1e5 + 10; vector<int> parent(N),sz(N);
void make(int x) {parent[x] = x; sz[x] = 1;}
int find(int v){
	if(parent[v] == v) return v;
	return find(parent[v]);
}
void Union(int a,int b){
	a = find(a); b = find(b);
	if(a!=b){
		if(sz[a] < sz[b]) swap(a,b); parent[b] = a;
		sz[a] = sz[b] + sz[a];
	}
}
signed main(){
	int n,m; cin>>n>>m;
	vector<pair<int,pair<int,int>>> edges;
	while(m--){
		int x,y,wt; cin>>x>>y>>wt;
		edges.emplace_back(make_pair(wt,make_pair(x,y)));
	}
	sort(edges.begin(),edges.end());
	for(int i = 1;i<=n;i++) make(i);
	int totalWeight = 0;
	for(auto &edge : edges){
		int wt = edge.first; int x = edge.second.first;
		int y = edge.second.second;
		if(find(x) == find(y)) continue;
		Union(x,y); totalWeight += wt;
	}
	cout<<totalWeight<<endl;
}

void dfs(int vertex,int parent,vector<int> &levels,vector<int> adj[]){
	levels[vertex] = levels[parent] + 1;  // Binary Lifting
	for(auto child : adj[vertex]){ // N(log(N)) + Q*(log(N))
		if(child != parent) dfs(child,vertex,levels,adj);
	}
} // SCC ka code hai ye poora ka poora
int kthParent(int a,int k,vector<vector<int>> &parents,int n){
	for(int i = 0;i<=log2(n);i++){
		if(parents[i][a] != -1 && (k & (1 << i))) a = parents[i][a];
	} return a;
}
void testcases(int t){
	int n; int q; cin>>n>>q;
	vector<int> adj[n+1];
	vector<vector<int>> parents(log2(n) +1,vector<int> (n + 1,-1));
	parents[0][1] = -1;

	for(int i = 2;i<=n;i++){
		int x; cin>>x;
		adj[x].emplace_back(i); adj[i].emplace_back(x);
		parents[0][i] = x;
	}
	vector<int> levels(n+1);
	dfs(1,0,levels,adj);
	for(int i = 1;i<=log2(n);i++){
		for(int j = 1;j<=n;j++){
			int intermediate = parents[i-1][j];
			if(intermediate != -1){
				parents[i][j] = parents[i-1][intermediate];
			}
		}
	}

	while (q){
		int a,b; cin>>a>>b;
		if(levels[a] > levels[b]) swap(a,b);
		int levelDiff = levels[b] - levels[a];
		b = kthParent(b,levelDiff,parents,n);
		if(a != b){
			for(int i = log2(n);i>=0;i--){
				int ka = parents[i][a];
				int kb = parents[i][b];
				if(kb != ka){a = ka; b = kb;}
			}
			cout<<parents[0][a]<<endl;
		}
		else cout<<a<<endl; q--;
	}
}
void dfs1(int vertex,stack<int> &st,vector<int> &visited,vector<int> adj[]){
	visited[vertex] = 1;
	for(auto child : adj[vertex]){
		if(visited[child] == 0) dfs1(child,st,visited,adj);
	}	st.push(vertex);
}
void dfs2(int vertex,vector<int> &temp,vector<int> &visited,vector<int> adj[]){
	visited[vertex] = 1; temp.emplace_back(vertex);
	for(auto child :  adj[vertex]){
		if(visited[child] == 0) dfs2(child,temp,visited,adj);
	}
}

void testcases(int t){
	int n,m; cin>>n>>m;	vector<int> adj[n+1],tadj[n+1];
	for(int i = 0;i<m;i++){
		int a,b; cin>>a>>b;
		adj[a].emplace_back(b);
	  	tadj[b].emplace_back(a);
	}
	vector<int> visited(n + 1); stack<int> st;
	for(int i = 1;i<=n;i++){
		if(visited[i] == 0) dfs1(i,st,visited,adj);
	}
	for(int i = 1;i<=n;i++) visited[i] = 0;
	vector<vector<int>> scc;
	while (!st.empty()){	
		int vertex = st.top(); st.pop(); vector<int> temp;
		if(visited[vertex] == 0){
			dfs2(vertex,temp,visited,tadj);
			scc.emplace_back(temp);
		}
	}
	vector<int> ans(n + 1); int cnt = 0;
	for(auto component : scc){
		cnt++;
		for(auto vertex : component) ans[vertex] = cnt;
	} cout<<scc.size()<<endl;
	for(int i= 1;i<=n;i++) cout<<ans[i]<<" ";
}

vector<vector<int>> dis(N,vector<int> (N,INF)); // Floyd Warshall
for(int k = 1;k<=n;k++)
  for(int i = 1;i<=n;i++)
    for(int j = 1;j<=n;j++)
      if(dis[i][k] != INF && dis[k][j] != INF)
        dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);

#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;


vector<int> rabin_karp(string const& s, string const& t) {
    const int p = 31; // to find occurences of string s 
    const int m = 1e9 + 9; // in string t, single hashing
    int S = s.size(), T = t.size();
	// to avoid collisions do double hashing
    vector<long long> p_pow(max(S, T)); 
    p_pow[0] = 1;
    for (int i = 1; i < (int)p_pow.size(); i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<long long> h(T + 1, 0); 
    for (int i = 0; i < T; i++)
        h[i+1] = (h[i] + (t[i] - 'a' + 1) * p_pow[i]) % m; 
    long long h_s = 0; 
    for (int i = 0; i < S; i++) 
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 

    vector<int> occurrences;
    for (int i = 0; i + S - 1 < T; i++) {
        long long cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
			occurrences.push_back(i);
    }
    return occurrences;
}