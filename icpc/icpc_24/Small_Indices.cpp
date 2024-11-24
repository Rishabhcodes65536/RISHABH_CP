/*██████████████████████████████████████████████████████████████████████████████████████
███*SHIVAM-SIKOTRA*████
██████████████████████████████████████████████████████████████████████████████████████*/
#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define st string
#define in int
#define ch char

#define Fz(i, a) for (int i = 0; i < a; i++)
#define F(i, a, b) for (int i = a; i < b; i++)
#define Fe(i, a, b) for (int i = a; i <= b; i++)
#define Fd(i, a, b) for (int i = a; i > b; i--)
#define Fde(i, a, b) for (int i = a; i >= b; i--)
#define Fa(i, v) for (auto i : v)

#define min3(a, b, c) min({a, b, c})
#define max3(a, b, c) max({a, b, c})
#define even(n) n % 2 == 0
#define odd(n) n % 2 != 0

#define vec(op) vector<op>
#define vin vector<int>
#define vec2d(op) vector<vector<op>>

#define mp(a1, a2) map<a1, a2>
#define ump(a1, a2) unordered_map<a1, a2>

#define maxh(a1) priority_queue<a1>
#define minh(a1) priority_queue<a1, vector<a1>, greater<a1>>

#define isPresent(ds, k) ds.find(k) != ds.end()

#define x first
#define y second

#define Rng(v) v.begin(), v.end()
#define rRng(v) v.rbegin(), v.rend()
#define LB(v, val) lower_bound(Rng(v), val) - v.begin()
#define UB(v, val) upper_bound(Rng(v), val) - v.begin()

void ip(int &n) { std::cin >> n; }
void ip(int &n, int &m) { std::cin >> n >> m; }
void ip(int &n, int &m, int &k) { std::cin >> n >> m >> k; }
void ip(int &n, int &m, int &k, int &l) { std::cin >> n >> m >> k >> l; }
#define endl '\n'
#define ce cout << endl

#define PRE(v) partial_sum(Rng(v), v.begin())
int SUM(vector<int> v)
{
    int ans(0);
    for (auto e : v)
        ans += e;
    return ans;
}
#define MAX(v) *max_element(Rng(v))
#define MIN(v) *min_element(Rng(v))

#define DIN(v, op, n) \
    vector<op> v(n);  \
    F(i, 0, n)        \
        cin >> v[i];
#define din(v, n)     \
    vector<int> v(n); \
    F(i, 0, n)        \
        cin >> v[i];

#define W while
#define sz size()
#define inf INT64_MAX
#define ninf INT64_MIN
#define digs_in_no(n) (int)(log10(n) + 1)
#define ret return

int digitsSum(int n)
{
    int r = 0;
    W(n)
    {
        r += n % 10;
        n /= 10;
    }
    return r;
}
int countDivisors(int n)
{
    int c(0);
    Fe(i, 1, sqrt(n))
    {
        if (n % i == 0)
        {
            if (n / i == i)
                c++;
            else
                c += 2;
        }
    }
    return c;
}

class DisjointSet
{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    { // time complexity- O(4alpha) - Constant
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]); // Path Compression
    }

    void unionByRank(int u, int v)
    { // time complexity- O(4alpha) - Constant
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    { // time complexity- O(4alpha) - Constant
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class BinaryLifting
{
private:
    vector<vector<int>> up;     // Stores 2^i parent of each node
    vector<int> tin, tout, dep; // Entry, exit times and depth of nodes
    vector<vector<int>> adj;    // Adjacency list for the tree
    int timer, log, n;          // Timer for tin/tout, max power of 2, number of nodes

public:
    BinaryLifting(int n, vector<vector<int>> adj = {{}})
    {
        this->n = n;
        if (!adj[0].empty())
        {
            adj.resize(n + 1);
        }
        else
        {
            this->adj = adj;
        }
        log = ceil(log2(n)); // Calculate the maximum level of ancestors needed
        tin.resize(n + 1);
        tout.resize(n + 1);
        dep.resize(n + 1, 0);
        up.assign(n + 1, vector<int>(log + 1, 0));
        timer = 0;
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int node, int par)
    {
        tin[node] = ++timer; // Set the entry time of the node
        up[node][0] = par;   // The immediate parent (2^0) of the node
        for (int i = 1; i <= log; i++)
        {
            up[node][i] = up[up[node][i - 1]][i - 1]; // Set the 2^i-th parent using dynamic programming
        }
        for (auto v : adj[node])
        {
            if (v != par)
            {
                dep[v] = dep[node] + 1;
                dfs(v, node);
            }
        }
        tout[node] = ++timer; // Set the exit time of the node
    }

    bool isAncestor(int u, int v)
    {
        return (tin[u] <= tin[v] && tout[u] >= tout[v]); // Check if u is an ancestor of v
    }

    int lca(int u, int v)
    {
        if (isAncestor(u, v))
            return u;
        if (isAncestor(v, u))
            return v;
        for (int i = log; i >= 0; i--)
        {
            if (!isAncestor(up[u][i], v))
            {
                u = up[u][i]; // Move u upwards until we find the LCA
            }
        }
        return up[u][0]; // The parent of u is the LCA
    }

    int getDepth(int node)
    {
        return dep[node];
    }

    void prepare(int root = 1)
    {
        dfs(root, root); // Perform DFS from the root node
    }
};
vector<int> SieveOfEratosthenes(int n)
{ // to print prime numbers from 1->n in O(n*log(log(n))) time
    vector<int> prime(n + 1, 1);
    prime[0] = 0;
    prime[1] = 0;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == 1)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
        }
    }
    return prime;
}
int BinaryExponential(int a, int b, int M)
{
    // Complexity- O(log(b))
    // a^b
    int ans = 1;
    while (b > 0)
    {
        if (b % 2 == 0)
        {
            a = (a * a) % (M);
            b /= 2;
        }
        else
        {
            ans = (ans * a) % (M);
            b -= 1;
        }
    }
    return ans;
}
bool isprime(int n)
{
    if (n == 1 || n == 0)
    {
        return false;
    }
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int factorial(int n)
{
    // Complexity- O(n)
    if (n == 0 || n == 1)
        return 1;
    else
        return (long long)(n * factorial(n - 1));
}
int __gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
        return __gcd(b, a % b);
}
int __lcm(int a, int b)
{
    return (a * b) / __gcd(a, b);
}
void fundtheoremofarith(int n, unordered_map<int, int> &arithmetic)
{ // O(sqrt(n))
    for (int i = 2; (i * i) <= n; i++)
    {
        while (n % i == 0)
        {
            arithmetic[i]++;
            n /= i;
        }
    }
    if (n != 1)
        arithmetic[n]++;
}
vector<int> divisors(int n)
{
    vector<int> v;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if ((n / i) == i)
            {
                v.push_back(i);
            }
            else
            {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }
    return v;
}
bool is_palindrome(string s)
{
    int i = 0, j = s.length() - 1;
    while (i <= j)
    {
        if (s[i] != s[j])
            return false;
        else
        {
            i++;
            j--;
        }
    }
    return true;
}
// When we want to find string a in s in O(a.length()+b.length()) time and space
//  Kmp func return the indexes where a can be found in s(first occurances),
//  in linear time
vector<int> kmp(string a, string s)
{
    string st = a + '#' + s;
    vector<int> lps(st.size(), 0);
    int i = 0, j = 1;
    while (j < lps.size())
    {
        if (st[i] == st[j])
        {
            i++;
            lps[j] = i;
            j++;
        }
        else
        {
            if (i == 0)
                j++;
            else
            {
                i = lps[i - 1];
            }
        }
    }
    vector<int> indexes;
    for (int i = a.size(); i < lps.size(); i++)
    {
        if (lps[i] == a.size())
        {
            int ind = i - 2 * a.size();
            if (ind >= 0)
                indexes.push_back(ind);
        }
    }
    return indexes;
}
// When we want to find string a in s in O(a.length()+b.length()) time and space
//  Zalgo func return the indexes where a can be found in s(first occurances),
//  in linear time. Here Z[i] array gives longest substring starting at index
// i which is also prefix of string a+"#"+b
vector<int> Zalgo(string a, string b)
{
    string str = a + "#" + b;
    int n = str.length();
    vector<int> Z(n);
    int L, R, k;
    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && str[R - L] == str[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else
        {
            k = i - L;
            if (Z[k] < R - i + 1)
                Z[i] = Z[k];
            else
            {
                L = i;
                while (R < n && str[R - L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
    vector<int> ans;
    for (int i = 0; i < Z.size(); ++i)
    {
        if (Z[i] == a.length())
            ans.push_back(i - a.length() - 1);
    }
    return ans;
}
pair<vin, vin> Dijkstra(int v, int src, vector<vector<pair<int, int>>> &g)
{
    vin dis(v, inf);       // Distance vector
    vin count(v, 0);       // Count of shortest paths to each node
    set<pair<int, int>> s; // Min-heap set (distance, node)

    dis[src] = 0;       // Distance to source is 0
    count[src] = 1;     // Only 1 way to reach the source (itself)
    s.insert({0, src}); // Insert source into the set

    while (!s.empty())
    {
        auto top = *s.begin();
        int nodeDis = top.x; // Distance to the current node
        int topNode = top.y; // Current node
        s.erase(s.begin());

        // Explore neighbors of topNode
        for (auto neighbour : g[topNode])
        {
            int nextNode = neighbour.x;
            int edgeWeight = neighbour.y;

            // If a shorter path is found to nextNode
            if (nodeDis + edgeWeight < dis[nextNode])
            {
                auto record = s.find({dis[nextNode], nextNode});
                if (record != s.end())
                {
                    s.erase(record); // Remove old distance
                }

                dis[nextNode] = nodeDis + edgeWeight; // Update distance
                count[nextNode] = count[topNode];     // Update path count (inherit from topNode)
                s.insert({dis[nextNode], nextNode});
            }
            // If an alternative shortest path is found
            else if (nodeDis + edgeWeight == dis[nextNode])
            {
                count[nextNode] += count[topNode]; // Add the number of ways to reach topNode
            }
        }
    }

    return {dis, count}; // Return both distance and path count vectors
}
const int N = 2e5 + 10, MOD = 1e9 + 7;
int modInverse(int n, int p)
{
    return BinaryExponential(n, p - 2, MOD);
}
vector<int> fac(N + 1);
// Returns nCr % p using Fermat's little theorem.(Used to calc ncr of large numbers in O(n) time and space)
int nCrModPFermat(int n, int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}
int countOdd(int L, int R)
{

    int N = (R - L) / 2;

    // if either R or L is odd
    if (R % 2 != 0 || L % 2 != 0)
        N += 1;

    return N;
}

#define fbo(v, k) find_by_order(v, k)

void print(vec(in) v)
{
    string space(1, ' ');
    Fa(i, v)
            cout
        << i << space;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    vector<vector<array<int, 3>>> dp(n + 1);

    dp[1] = {{0, a[1], -1}, {0, b[1], -1}};

    for (auto prev : dp[1])
    {
        dp[2].push_back({0, a[2], prev[1]});
        dp[2].push_back({0, b[2], prev[1]});
    }
    for (int i = 3; i <= n; i++)
    {
        int max_small = 0;
        vector<array<int, 3>> curr;
        for (auto prev : dp[i - 1])
        {
            int prev_small = prev[0];
            int prev1 = prev[1];
            int prev2 = prev[2];
            bool small_with_a = (prev2 != -1 && a[i] <= prev1 + prev2);
            curr.push_back({prev_small + small_with_a, a[i], prev1});
            max_small = max(max_small, prev_small + small_with_a);
            bool small_with_b = (prev2 != -1 && b[i] <= prev1 + prev2);
            curr.push_back({prev_small + small_with_b, b[i], prev1});
            max_small = max(max_small, prev_small + small_with_b);
        }
        dp[i].clear();
        for (auto state : curr)
        {
            if (state[0] == max_small)
            {
                dp[i].push_back(state);
            }
        }
    }
    int result = 0;
    for (auto state : dp[n])
    {
        result = max(result, state[0]);
    }
    cout << result << "\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}