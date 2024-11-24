#include <bits/stdc++.h>

using namespace std;
// using namespace __gnu_pbds;
 
#define int long long
#define endl "\n"
#define sz(x) (int)x.size()
#define pb(x) push_back(x)
#define ppb pop_back
#define ff first
#define ss second
#define in(x) insert(x)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define acc(v) accumulate(all(v),0ll)
#define rep(i,k,n) for(int i = k; i < n; i++)
#define per(i,a,b) for(int i=(a)-1;i>=(b);i--)
#define tr(i,x) for(auto &i : x)
#define sp(x,y) fixed << setprecision(y) << x
 
typedef vector<int> vi;
typedef vector <vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef unsigned long long ull;
typedef long double lld;
// typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update > pbds;
//member functions :
//1. (type).order_of_key(k) : number of elements strictly lesser than k
//2. *(type).find_by_order(k) : k-th element in the set",
 
#define readv(v,n) vi v(n); rep(i,0,n) cin >> v[i];
 
/*----------------------(Debugging)----------------------*/
#ifndef ONLINE_JUDGE
#define dbg(x) cerr << #x << " "; _display(x); cerr << endl;
#else 
#define dbg(x)
#endif
 
void _display(int x){cerr << x;}
void _display(char x){cerr << x;}
void _display(string x){cerr << x;}
void _display(double x){cerr << x;}
void _display(lld x){cerr << x;}
void _display(ull x){cerr << x;}
 
template <class T> void _display(vector <T> v);
template <class T> void _display(set <T> v);
template <class T, class V> void _display(pair <T, V> p);
template <class T, class V> void _display(map <T, V> v);
template <class T> void _display(vector<T> v){cerr << "[ "; for(auto &i:v){_display(i); cerr << " ";} cerr << "]";}
template <class T> void _display(set<T> v){cerr << "[ "; for(auto &i:v){_display(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _display(pair <T, V> p) {cerr << "{"; _display(p.ff); cerr << ","; _display(p.ss); cerr << "}";}
template <class T, class V> void _display(map <T, V> v) {cerr << "[ "; for (auto &i:v){ _display(i); cerr << " ";} cerr << "]";}
 
/*----------------------(Constants)-----------------------*/
#define PI atan(1)*4
const int M = 1e9+7;
const int MM = 998244353;
const int INF = 9223372036854775807;
const int N = 1e5 + 5;
 
/*----------------------(Main Code)---------------------*/
 
 
int binpow(int a, int b, int m){
    int ans = 1;
    while(b>0){
        if(b&1){
        ans *= a;
        if(ans > m) ans %= m;
        }
    
        a *= a;
        if(a > m) a %= m;
    
        b>>=1;
      }
    return ans;
}
 
int inv_mod(int b,int mod){
    return binpow(b,mod-2,mod)%mod;
}
 
int f(int n){
    return (((n*(n+1))%M*(2*n+1))%M*inv_mod(6,M))%M;
}
void solve(){
    int n;
    cin >> n;
    int a = f(n);
    int b = f(n);
    int c = (((n*(n+1ll))%M*inv_mod(2,M)+M)%M);
    cout<<a<<" "<<b<<" "<<c<<endl;
    int ans = (a+b-c)%M;
    cout << (ans*2022)%M << endl;
}
/*
 
*/
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int t = 1;
    cin >> t;
    for(int i=1;i<t+1;i++) solve();
    
    return 0;
}