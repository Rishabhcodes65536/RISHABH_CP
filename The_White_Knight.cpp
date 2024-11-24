#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define endl '\n'
#define ff first
#define ss second
#define pb emplace_back
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
#define MAXIARR(a) *max_element(a, a + n)
#define MANIARR(a) *min_element(a, a + n)
#define MAX(v) *max_element((v).begin(), (v).end())
#define MINI(v) *min_element((v).begin(), (v).end())
#define PI atan(1) * 4
#define INF INT64_MAX
#define fbo(x) find_by_order(x)
#define ook(x) order_of_key(x)
#define out(x) cout << x << endl;
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b)
{
    return (a.second < b.second);
}
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
int N=1e3;
vector <vector<int>> dp(N , vector <int> (N,-1));
int call(vector<vector<char>> vec, int e, int f, int n, int count)
{
    if (e >= n || f >= n || f < 0)
    {
        return count;
    }
    int ans = 0;
    if (vec[e][f] == 'P')
        count++;
    if(dp[e][f]!=-1) return dp[e][f];
    dp[e][f] = max(call(vec, e + 2, f + 1, n, count), max(call(vec, e + 2, f - 1, n, count), max(call(vec, e + 1, f + 2, n, count), call(vec, e + 1, f - 2, n, count))));

    //=max(call(vec,e+2,f+1,n,0),max(call(vec,e+2,f-1,n,0),max(call(vec,e+1,f+2,n,0),call(vec,e+1,f-2,n,0))));

    return dp[e][f];
}
void dosomething()
{
    int n;
    cin >> n;
    vector<string> vel;
    rep(i, 0, n)
    {
        string s;
        cin >> s;
        vel.pb(s);
    }
    vector<vector<char>> vec(n,vector <char> (n));
    int e = 0, f = 0;
    rep(i, 0, n)
    {
        string q = vel[i];
        rep(j, 0, n)
        {
            vec[i][j] = q[j];
            if (vec[i][j] == 'K')
            {
                e = i;
                f = j;
            }
        }
    }
    //cout << "HI";
    cout << call(vec, e, f, n, 0) << endl;
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