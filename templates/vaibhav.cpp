#include <bits/stdc++.h>
using namespace std;
#define faster_io                     \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
int mod = 998244353;
#define int long long
#define pii pair<int, int>
#define ppi pair<int, pii>
int power(int x, int y)
{
    int res = 1;
    x = x % mod;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % mod;
        y = y >> 1;
        x = (x * x) % mod;
    }
    return res;
}
//returns the gcd of a and b in O(log(max(a,b))) and x and y are set as bezouts coeff. i.e. ax+by=gcd(a,b)
int extendedgcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = extendedgcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
int mmi(int x)
{
    return power(x, mod - 2);
}
// in case mod is not prime but gcd(x,mod)=1
int mod_inv(int a, int m)
{
    int x, y;
    int g = extendedgcd(a, m, x, y);
    if (g != 1)
        return -1;
    else
    {
        x = (x % m + m) % m;
        return x;
    }
}
int fact(int n)
{
    int res = 1;
    for (int i = 1; i <= n; i++)
        res = (res * i) % mod;
    return res;
}
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// computes the value of nCr in O(r)
int ncr(int n, int r)
{
    int res = 1;
    if (n - r < r)
        return ncr(n, n - r);
    for (int i = 1; i <= r; i++)
        res = ((res * (n - i + 1)) % mod * mmi(i)) % mod;
    return res;
}
// the function below solves a system of linear
// congruences(Chinese Remainder theorem)
class Congruence
{
public:
    int a, m;
};
int chinese_remainder_theorem(vector<Congruence> const &congruences)
{
    int M = 1;
    for (auto const &congruence : congruences)
    {
        M *= congruence.m;
    }

    int solution = 0;
    for (auto const &congruence : congruences)
    {
        int a_i = congruence.a;
        int M_i = M / congruence.m;
        int N_i = mod_inv(M_i, congruence.m);
        solution = (solution + a_i * M_i % M * N_i) % M;
    }
    return solution;
}
// returns the euler totient function value for n in O(sqrt(n))
int phi(int n)
{
    int result = n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

vector<int> sieve(1e6 + 1);
vector<int> smallestprimesieve()
{
    for (int i = 0; i <= 1e6; i++)
        sieve[i] = i;
    for (int i = 2; i * i <= 1e6; i++)
        if (sieve[i] == i)
            for (int j = i * i; j <= 1e6; j += i)
                if (sieve[j] == j)
                    sieve[j] = sieve[i];
    vector<int> primes;
    for (int i = 2; i <= 1e6; i++)
        if (sieve[i] == i)
            primes.push_back(i);
    return primes;
}
// this function returns the xor from 1 to n in O(1)
int xortilln(int n)
{
    if (n % 4 == 0)
        return n;
    else if (n % 4 == 1)
        return 1;
    else if (n % 4 == 2)
        return n + 1;
    return 0;
}
// finding the nth term in the catalan series
//Cn=C0Cn-1+C1Cn-2+C2Cn-3...+Cn-1C0
int catalan(int n)
{
    return ncr(2 * n, n) / (n + 1);
}
//TRIE(note that here k is the no of bits in the
// numbers you can simply set it to
//31 in case of regular integers)
class node
{
public:
    node *links[2];
    int onecount = 0;
    int zerocount = 0;
    bool containskey(int x)
    {
        return links[x];
    }
    void addletter(int x, node *newnode)
    {
        links[x] = newnode;
        if (x)
            onecount++;
        else
            zerocount++;
    }
};
class trie
{
public:
    node *root;
    trie()
    {
        root = new node();
    }

    void insert(int x, int k)
    {
        node *currnode = root;
        for (int i = k - 1; i >= 0; i--)
        {
            int bit = (x & (1 << i)) ? 1 : 0;
            if (currnode->containskey(bit))
            {
                if (bit)
                    currnode->onecount++;
                else
                    currnode->zerocount++;
                currnode = currnode->links[bit];
            }
            else
            {
                node *newnode = new node();
                currnode->addletter(bit, newnode);
                currnode = newnode;
            }
        }
    }
    void deleteval(int x, int k)
    {
        node *currnode = root;
        for (int i = k - 1; i >= 0; i--)
        {
            int bit = (x & (1 << i)) ? 1 : 0;
            if (bit)
            {
                currnode->onecount--;
                if (!currnode->onecount)
                {
                    delete currnode->links[bit];
                    currnode->links[bit] = NULL;
                    break;
                }
            }
            else if (!bit)
            {
                currnode->zerocount--;
                if (!currnode->zerocount)
                {
                    delete currnode->links[bit];
                    currnode->links[bit] = NULL;
                    break;
                }
            }
            currnode = currnode->links[bit];
        }
    }
    //returns maximum xor with x of any number in trie
    int getmaxxor(int x, int k)
    {
        node *currnode = root;
        int res = 0;
        for (int i = k - 1; i >= 0; i--)
        {
            int bit = (x & (1 << i)) ? 1 : 0;
            if (currnode->containskey(!bit))
            {
                res = (res | (1 << i));
                currnode = currnode->links[!bit];
            }
            else
                currnode = currnode->links[bit];
        }
        return res;
    }
};
//DIJKSTRA
class comparator_dijkstra
{
public:
    bool operator()(const pii &p1, const pii &p2)
    {
        return p1.second > p2.second;
    }
};
vector<int> dijkstra(vector<vector<pii>> &graph, int source)
{
    vector<int> parent(graph.size(), -1);
    parent[source] = source;
    vector<int> ans(graph.size(), (int)1e18); //this will store the distances
    ans[source] = 0;
    priority_queue<pii, vector<pii>, comparator_dijkstra> pq;
    pq.push({source, 0});
    unordered_set<int> explored;
    while (pq.size())
    {
        pii leastdis = pq.top();
        pq.pop();
        if (explored.count(leastdis.first))
            continue;
        explored.insert(leastdis.first);
        for (const auto &x : graph[leastdis.first])
        {
            // leastdis.second is the distance from source
            // to leastdis and x.second is the distance from
            // leastdis.first to x.first
            if (leastdis.second + x.second < ans[x.first])
            {
                ans[x.first] = leastdis.second + x.second;
                pq.push({x.first, leastdis.second + x.second});
                parent[x.first] = leastdis.first;
            }
        }
    }
    return parent;
}
//PRIMS
pair<int, vector<vector<pii>>> prims(vector<vector<pii>> &graph)
{
    int n = graph.size();
    vector<vector<pii>> mst(n);
    vector<bool> visited(n, false);
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    pq.push({0, {0, -1}}); // base case
    int totalweight = 0;
    while (pq.size())
    {
        ppi p = pq.top();
        pq.pop();
        if (visited[p.second.first])
            continue; // this is already a part of our MST and
        // all edges from this vertex are already in the pq
        visited[p.second.first] = true;
        totalweight += p.first;
        if (p.second.second != -1)
        {
            mst[p.second.first].push_back({p.second.second, p.first});
            mst[p.second.second].push_back({p.second.first, p.first});
        }
        for (const auto &x : graph[p.second.first])
        {
            if (!visited[x.first])
                pq.push({x.second, {x.first, p.second.first}});
        }
    }
    return {totalweight, mst};
}
//FLOYD WARSHALL(O(V^3)) finds all pair
//shortest paths and also detects -ve loops
pair<bool, vector<vector<int>>> floydwarshall(vector<vector<pii>> &graph)
{
    int n = graph.size();
    vector<vector<int>> matrix(n, vector<int>(n, 1e7));
    for (int i = 0; i < n; i++)
    {
        matrix[i][i] = 0;
        for (const auto &p : graph[i])
        {
            matrix[i][p.first] = p.second;
        }
    }
    for (int k = 0; k < n; k++)
    {
        vector<vector<int>> temp = matrix;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                matrix[i][j] = min(matrix[i][j], temp[i][k] + temp[k][j]);
            }
        }
    }
    for (int i = 0; i < n; i++) //-ve weight cycle detection.
    {
        if (matrix[i][i] < 0)
            return {true, matrix};
    }
    return {false, matrix};
}
//TC is O(E.V) but in DAG get toposort and then apply
//on the edges in that order for O(E+V).
pair<bool, vector<int>> bellmanford(vector<vector<pii>> &graph, int src)
{
    vector<int> distance(graph.size(), 1e6);
    distance[src] = 0;
    for (int i = 0; i < graph.size() - 1; i++)
    {
        vector<int> temp = distance;
        for (int j = 0; j < graph.size(); j++)
        {
            for (const auto &x : graph[j])
            {
                if (x.second + distance[j] < distance[x.first])
                {
                    distance[x.first] = x.second + distance[j];
                }
            }
        }
        if (temp == distance)
            break;
    }
    for (int j = 0; j < graph.size(); j++)
    {
        for (const auto &x : graph[j])
        {
            if (x.second + distance[j] < distance[x.first])
            {
                return {true, distance}; // cycle detected
            }
        }
    }
    return {false, distance};
}
//Bridge
void dfs(vector<vector<int>> &graph, int u, int parent, int currtin,
         vector<int> &tin, vector<int> &lowtin, vector<vector<int>> &bridges)
{
    tin[u] = currtin;
    lowtin[u] = currtin;
    for (int x : graph[u])
    {
        if (tin[x] == -1)
            dfs(graph, x, u, ++currtin, tin, lowtin, bridges);
    }
    for (int x : graph[u])
    {
        if (x != parent)
            lowtin[u] = min(lowtin[u], lowtin[x]);
    }
    if (parent != -1 && lowtin[u] > tin[parent])
    {
        if (parent < u) // we prefer to denote edge from
                        //smaller vertex to larger vertex
            bridges.push_back({parent, u});
        else
            bridges.push_back({u, parent});
    }
}
vector<vector<int>> getbridges(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> tin(n, -1); // this will also act as a visited array for us
    vector<int> lowtin(n, -1);
    vector<vector<int>> bridges;
    for (int i = 0; i < n; i++)
    {
        if (tin[i] == -1)
            dfs(graph, i, -1, 0, tin, lowtin, bridges);
    }
    return bridges;
}
//Articulation Point
void setlowtin(vector<vector<int>> &graph, vector<int> &lowtin, vector<int> &depth, int u, int parent)
{
    depth[u] = parent != -1 ? 1 + depth[parent] : 1;
    for (int x : graph[u])
    {
        if (x == parent)
            continue;
        else if (depth[x] != -1) //backward edge
        {
            lowtin[u] = min(lowtin[u], depth[x]);
        }
        else //forward edge
        {
            setlowtin(graph, lowtin, depth, x, u);
            lowtin[u] = min(lowtin[u], lowtin[x]);
        }
    }
}
void findarticulation(vector<vector<int>> &graph, vector<int> &lowtin, vector<int> &depth, int u, int parent, vector<bool> &visited, vector<int> &res)
{
    visited[u] = true;
    bool isroot = false;
    bool isarticulation = false;
    int childno = 0;
    if (parent == -1)
        isroot = true;
    for (int x : graph[u])
    {
        if (!visited[x])
        {
            childno++;
            if (lowtin[x] >= depth[u])
                isarticulation = true;
            findarticulation(graph, lowtin, depth, x, u, visited, res);
        }
    }
    if ((isroot && childno > 1) || (!isroot && isarticulation))
        res.push_back(u);
}
vector<int> articulationpoints(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> lowtin(n, __INT_MAX__); // this denotes the lowest time of insertion of a node
    // which is nothing but min(time of lowtin of its descendants)
    vector<int> depth(n, -1);
    // this depth will also act as the visited.

    //first set the lowtin values
    for (int i = 0; i < n; i++)
    {
        if (depth[i] == -1)
            setlowtin(graph, lowtin, depth, i, -1);
    }
    vector<int> res; // we will store the articulation points here.
    vector<bool> visited(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            findarticulation(graph, lowtin, depth, i, -1, visited, res);
    }
    return res;
}

//Euler Tour
int eulertour1(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &tour, int u)
{
    visited[u] = true;
    tour.push_back(u);
    for (int x : graph[u])
    {
        eulertour1(graph, visited, tour, x);
    }
    tour.push_back(u);
}

int eulertour2(vector<vector<int>> &graph, vector<bool> &visited, vector<int> &tour,
               unordered_map<int, int> &height, int u, int ht)
{
    visited[u] = true;
    height[u] = ht;
    tour.push_back(u);
    for (int x : graph[u])
    {
        eulertour2(graph, visited, tour, height, x, ht + 1);
        tour.push_back(u);
    }
}

class dsu
{
public:
    int components, largestcomp;
    vector<int> parent, rank, compsize;
    dsu(int len)
    {
        largestcomp = 1;
        components = len;
        parent.resize(len);
        rank.resize(len);
        compsize.resize(len);
        for (int i = 0; i < len; i++)
        {
            parent[i] = i;
            rank[i] = 0;
            compsize[i] = 1;
        }
    }
    int find(int x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]);
    }
    int getcompsize(int x)
    {
        if (parent[x] == x)
            return compsize[x];
        return compsize[x] = compsize[find(x)];
    }
    void Union(int x, int y)
    {
        int parent_x = find(x);
        int parent_y = find(y);
        if (parent_x == parent_y)
            return;

        if (rank[parent_x] >= rank[parent_y])
            parent[parent_y] = parent[parent_x];

        else
            parent[parent_x] = parent[parent_y];

        if (rank[parent_x] == rank[parent_y])
            rank[parent_x]++;
        components--;
        compsize[parent_x] += compsize[parent_y];
        compsize[parent_y] = compsize[parent_x];
        largestcomp = max(compsize[parent_x], largestcomp);
    }
};
//for stress testing
srand(time(NULL));

//this function will compute all the values in the parents in O(nlogn)
void dfs(vector<vector<int>> &tree, vector<vector<int>> &parents, int node, int p)
{
    //we will assume the tree to be rooted at 0.
    if (p != -1)
    {
        parents[node][0] = p;
        for (int i = 1; i < parents[node].size(); i++)
        {
            int prevparent = parents[node][i - 1];
            if (parents[prevparent][i - 1] != -1)
                parents[node][i] = parents[prevparent][i - 1];
            else
                break;
        }
    }
    for (int x : tree[node])
    {
        if (x != p)
            dfs(tree, parents, x, node);
    }
}

vector<vector<int>> binarylifting(vector<vector<int>> &tree)
{
    int n = tree.size();
    //parent[node][i] stores the 2^i th parent of the node
    int maxlevel = log2(n) + 1;
    vector<vector<int>> parents(n, vector<int>(maxlevel, -1));
    dfs(tree, parents, 0, -1);
    return parents;
}

int kthancestor(vector<vector<int>> &parents, int node, int k)
{
    int powerof2 = 0, currnode = node;
    while (k)
    {
        if (parents[currnode][powerof2] == -1)
            return -1;
        if ((k & 1))
        {
            currnode = parents[currnode][powerof2];
        }
        powerof2++;
        k = k >> 1;
    }
    return currnode;
}
void getdepth(vector<vector<int>> &tree, vector<int> &depth, int u, int d)
{
    depth[u] = d;
    for (int x : tree[u])
        if (depth[x] == -1)
            getdepth(tree, depth, x, d + 1);
}
int lca(vector<vector<int>> &parents, vector<int> &depth, int u, int v)
{
    if (depth[u] < depth[v])
        swap(u, v);
    u = kthancestor(parents, u, depth[u] - depth[v]);
    if (u == v)
        return u;
    int jumppower = log2(depth[v]);
    while (true)
    {
        int newu = parents[u][jumppower];
        int newv = parents[v][jumppower];
        if (newu == newv)
            if (jumppower)
                jumppower--;
            else
                break;
        else
            v = newv, u = newu;
    }
    return parents[u][0];
}
int32_t main()
{
    int n;
    cin >> n;
    vector<vector<int>> tree(n);
    vector<vector<int>> parents = binarylifting(tree);
    vector<int> depth(n, -1);
    getdepth(tree, depth, 0, 0);
    cout << lca(parents, depth, 1, 0) << '\n';
}
//sort comparator('<' for ascending order)
//bool compareInterval(pii i1, pii i2){return (i1.first < i2.first)};
//pq comparator('<' for maxheap)
// class Compare { public:bool operator()(pii a, pii b){return a.first<b.first} };
//set comparator('<' for ascending )
// struct comp {  bool operator()(const pair<char, int>& p1, const pair<char, int>& p2)  {if (p1.first == p2.first) {return p1.second > p2.second;}return p1.first < p2.first;}};
