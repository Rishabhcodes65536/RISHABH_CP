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
void dosomething()
{
    int m, n;
    cin >> m >> n;
    invec(v, n);
    vector<int> a_f(n, 0), b_f(n, 0);
    vector<int> a_pref(n, 0), b_pref(n, 0);
    vector<int> a_suff(n, 0), b_suff(n, 0);
    rep(i, 0, n)
    {
        if(i-1>=0){
            a_f[i] = a_f[i-1];
            a_pref[i] = a_pref[i-1];
            b_f[i] = b_f[i-1];
            b_pref[i] = b_pref[i-1];
        }
        if (v[i] == 1 || v[i] == 3)
        {
            a_f[i] = (i-1 >=0 ? (a_f[i - 1]) :(0)) + 1;
            a_pref[i] = (i - 1 >= 0 ? (a_pref[i - 1]):(0)) + i;
        }
        if (v[i] == 2 || v[i] == 3)
        {
            b_f[i] = (i - 1 >= 0 ? (b_f[i - 1]):(0)) + 1;
            b_pref[i] = (i - 1 >= 0 ? (b_pref[i - 1]) : (0)) + i;
        }
    }
    per(i, n - 1, 0)
    {
        if (i + 1 < n)
        {
            // a_f[i] = a_f[i + 1];
            a_suff[i] = a_suff[i + 1];
            // b_f[i] = b_f[i + 1];
            b_suff[i] = b_suff[i + 1];
        }
        if (v[i] == 1 || v[i] == 3)
        {
            a_suff[i] = (i+1 < n  ? (a_suff[i + 1]):(0)) + i;
        }
        if (v[i] == 2 || v[i] == 3)
        {
            b_suff[i] =( i + 1 < n ? (b_suff[i + 1]) : (0)) + i;
        }
    }
    vector<int> res;
    rep(i, 0, n)
    {
        int a_prev =0, a_prev_f = a_f[n - 1], a_aft = 0, a_aft_f = 0;
        int b_prev=0, b_prev_f=0,b_aft=0, b_aft_f=0;
        a_prev = a_pref[i];
        a_prev_f = a_f[i];
        b_prev = b_pref[i];
        b_prev_f = b_f[i];
        if (i +1 < n)
        {
            a_aft = a_suff[i +1];
            b_aft = b_suff[i + 1];
            a_aft_f = a_f[n-1]-a_f[i];
            b_aft_f = b_f[n-1]-b_f[i];
        }
        int alice_score = ((a_prev_f *i)-a_prev) + (a_aft- (a_aft_f*(i)));
        int bob_score = ((b_prev_f *i)-b_prev) +  (b_aft- (b_aft_f*(i)));
        res.push_back(abs(alice_score - bob_score));
    }
    disp(res);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // cout << fixed << setprecision(9);
    int t = 1;
    cin >> t;
    while (t--)
    {
        dosomething();
        // Case #<<t<<'='<< ;
    }
    return 0;
}