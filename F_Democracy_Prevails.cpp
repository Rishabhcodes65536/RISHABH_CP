
// void winterIsComing()
// {
//     int n, m;
//     cin >> n >> m;
//     invec(vv, m);
//     set<int> st;
//     for(auto &z:vv){
//         st.insert(z);
//     }
//     vector<vector<int>> g(n + 3);
//     for (int i = 0; i < n - 1; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         g[u].push_back(v);
//         g[v].push_back(u);
//     }
//     // vector<int> subtree_size(n + 1, 0);
//     // dfs(1, -1, subtree_size, g);
//     // long long total_paths = count_paths(1, -1, subtree_size, g);
//     // cout << total_paths << endl;
//     int total_paths = (n * (n + 1)) / 2;
//     int paths_containing_n = 0,node_n=0,sum_sq=0;
//     map <int,int> mp;
//     vector<int> dp(n + 1, -1);
//     int k = 0;
//     auto dfs = [&](int u, int parent, auto &&dfs) -> int
//     {
//         int tsz = 1; 
//         if(dp[u]!=-1 && mp[dp[u]]>0){
//             mp[dp[u]];
//         }
//         for (int v : g[u])
//         {
//             if (v != parent && !st.count(v))
//             {
//                 int r= dfs(v, u, dfs);
//                 tsz += r;
//                 if(parent==-1){
//                     sum_sq += r * r;
//                 }
//             }
//         }
//         // return dp[u]=k;
//         return k;
//     };
//     for (int i = 0; i < m;i++){
//         // node_n = vv[i];
//         // paths_containing_n = 0;
//         sum_sq = 0;
//         int val= dfs(vv[i], -1, dfs);
//         mp[k] = val;
//         k++;
//         val--;
//         int tot = (val * val - sum_sq) / 2 + (val + 1);
//         // cout << val <<" "<<vv[i]<<" "<<tot<<" "<<sum_sq<< endl;
//         total_paths -= tot;
//     }
//     cout << total_paths << endl;
// }
// signed main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     // cout << fixed << setprecision(9);
//     int t = 1;
//     // cin>>t;
//     while (t--)
//     {
//         winterIsComing();
//         // Case #<<t<<'='<< ;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define endl '\n'
#define ff first
#define ss second
#define pb push_back
#define ppb pop_back
#define int long long
#define float long double
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define ppc __builtin_popcountll
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)
#define invec(a, n)   \
    vector<int> a(n); \
    rep(i, 0, n) cin >> a[i]
#define inarr(a, n) \
    int a[n];       \
    rep(i, 0, n) cin >> a[i]
#define in(k, a) for (auto k : a)
#define disp(a)                    \
    in(k, a) { cout << k << ' '; } \
    cout << endl
const int M = 1e9 + 7;
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define SUMARR(a) accumulate(a, a + n, 0LL)
#define SUM(v) accumulate(all(v), 0LL)
#define MAXIARR(a, n) *max_element(a, a + n)
#define MINIARR(a, n) *min_element(a, a + n)
#define MAX(v) *max_element((v).begin(), (v).end())
#define MINI(v) *min_element((v).begin(), (v).end())
#define PRESUM(a) partial_sum(a.begin(), a.end(), a.begin())
#define PI atan(1) * 4
#define INF INT64_MAX
#define fbo(x) find_by_order(x)
#define ook(x) order_of_key(x)
#define out(x) cout << x << endl;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) { return (a.second < b.second); }
#define f(i, n) for (int i = 0; i < n; i++)
/////खुदी को कर बुलंद इतना के हर तकदीर से पहले खुदा बन्दे से खुद पूछे के बता तेरी रज़ा क्या है;/////
int countDivisors(int n)
{
    int cnt = 0;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                cnt++;
            else // Otherwise count both
                cnt = cnt + 2;
        }
    }
    return cnt;
}
template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
{
    if (vec.empty())
    {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < vec.size() - 1; i++)
    {
        out << vec[i] << ", ";
    }
    return out << vec.back() << ']';
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &pair)
{
    return out << '(' << pair.first << ", " << pair.second << ')';
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::deque<T> &deq)
{
    if (deq.empty())
    {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < deq.size() - 1; i++)
    {
        out << deq[i] << ", ";
    }
    return out << deq.back() << ']';
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::unordered_map<T1, T2> &map)
{
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++)
    {
        std::pair<T1, T2> element = *it;
        out << element.first << ": " << element.second;
        if (std::next(it) != map.end())
        {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &out, const std::map<T1, T2> &map)
{
    out << '{';
    for (auto it = map.begin(); it != map.end(); it++)
    {
        std::pair<T1, T2> element = *it;
        out << element.first << ": " << element.second;
        if (std::next(it) != map.end())
        {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::unordered_set<T> &set)
{
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++)
    {
        T element = *it;
        out << element;
        if (std::next(it) != set.end())
        {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::multiset<T> &set)
{
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++)
    {
        T element = *it;
        out << element;
        if (std::next(it) != set.end())
        {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::unordered_multiset<T> &set)
{
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++)
    {
        T element = *it;
        out << element;
        if (std::next(it) != set.end())
        {
            out << ", ";
        }
    }
    return out << '}';
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::set<T> &set)
{
    out << '{';
    for (auto it = set.begin(); it != set.end(); it++)
    {
        T element = *it;
        out << element;
        if (std::next(it) != set.end())
        {
            out << ", ";
        }
    }
    return out << '}';
}

// Source: https://stackoverflow.com/a/31116392/12128483
template <typename Type, unsigned N, unsigned Last>
struct TuplePrinter
{
    static void print(std::ostream &out, const Type &value)
    {
        out << std::get<N>(value) << ", ";
        TuplePrinter<Type, N + 1, Last>::print(out, value);
    }
};

template <typename Type, unsigned N>
struct TuplePrinter<Type, N, N>
{
    static void print(std::ostream &out, const Type &value)
    {
        out << std::get<N>(value);
    }
};

template <typename... Types>
std::ostream &operator<<(std::ostream &out, const std::tuple<Types...> &value)
{
    out << '(';
    TuplePrinter<std::tuple<Types...>, 0, sizeof...(Types) - 1>::print(out, value);
    return out << ')';
}
int digitsSum(int n)
{
    int ans = 0;
    while (n != 0)
    {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
int binpow(int a, int b, int m)
{
    // take INF if no Modulo
    int ans = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            ans *= a;
            if (ans > m)
                ans %= m;
        }
        a *= a;
        if (a > m)
            a %= m;
        b >>= 1;
    }
    return ans;
}
int inv_mod(int b, int mod)
{
    return binpow(b, mod - 2, mod) % mod;
}
const int32_t N = 3e5 + 10;
int FLOOR(const int a, const int b)
{
    if (a > 0 || a % b == 0)
        return a / b;
    return (a / b - 1);
}
int CEIL(const int a, const int b) { return (a + b - 1) / b; }
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int POW(int a, int b) { return b == 0 ? 1 : a * POW(a, b - 1); }
int mod_exp(int a, int b, int mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res % mod;
}
int mod_mul(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
int mod_sub(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
int extended_gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return x;
    }
    int gcd = extended_gcd(b, a % b, y, x);
    y -= x * (a / b);
    return gcd;
}
int mod_inv(int a, int b)
{
    int r1, r2;
    int gcd = extended_gcd(a, b, r1, r2);
    assert(gcd == 1);
    return r1;
}
int mod_div(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mod_inv(b, m), m) + m) % m;
}
int ask(int x, int y)
{
    printf("? %d %d\n", x, y);
    fflush(stdout);
    scanf("%d", &x);
    return x;
}

void give(int x, int y)
{
    printf("! %d %d\n", x, y);
    fflush(stdout);
}


void winterIsComing()
{
    int n, m;
    cin >> n >> m;
    invec(vv, m);
    set<int> st;
    for (auto &z : vv)
    {
        st.insert(z);
    }
    vector<vector<int>> g(n + 3);
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // vector<int> subtree_size(n + 1, 0);
    // dfs(1, -1, subtree_size, g);
    // long long total_paths = count_paths(1, -1, subtree_size, g);
    // cout << total_paths << endl;
    int total_paths = (n * (n + 1)) / 2;
    int paths_containing_n = 0, node_n = 0, sum_sq = 0;
    map<int, int> mp;
    vector<int> dp(n + 1, -1);
    int k = 0;
    auto dfs = [&](int u, int parent, auto &&dfs) -> int
    {
        int tsz = 1;
        if(dp[u]!=-1 && mp[dp[u]]>0){
            return mp[dp[u]];
        }
        for (int v : g[u])
        {
            if (v != parent && !st.count(v))
            {
                int r = dfs(v, u, dfs);
                tsz += r;
                if (parent == -1)
                {
                    dp[k] = r;
                    sum_sq += r * r;
                }
            }
        }
        // dp[u] = k;
        return tsz;
    };

    for (int i = 0; i < m; i++)
    {
        // node_n = vv[i];
        // paths_containing_n = 0;
        sum_sq = 0;
        int val = dfs(vv[i], -1, dfs);
        mp[k] = val;
        k++;
        val--;
        int tot = (val * val - sum_sq) / 2 + (val + 1);
        // cout << val <<" "<<vv[i]<<" "<<tot<<" "<<sum_sq<< endl;
        total_paths -= tot;
    }
    cout << total_paths << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cout << fixed << setprecision(9);
    int t = 1;
    // cin>>t;
    while (t--)
    {
        winterIsComing();
        // Case #<<t<<'='<< ;
    }
    return 0;
}