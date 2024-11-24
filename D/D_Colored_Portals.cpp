#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define endl              '\n'
#define ff                first
#define ss                second
#define pb                push_back
#define ppb               pop_back
#define int               long long
#define float             long double
#define lb                lower_bound
#define ub                upper_bound
#define sz(x)             (int)(x).size()
#define ppc               __builtin_popcountll
#define all(x)            (x).begin(), (x).end()
#define rall(x)           (x).rbegin(), (x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define per(i,a,b)        for(int i=(a);i>=(b);i--)
#define invec(a,n)        vector<int>a(n); rep(i,0,n) cin>>a[i]
#define inarr(a,n)        int a[n]; rep(i,0,n) cin>>a[i]
#define in(k,a) for(auto k : a)
#define disp(a) in(k,a){ cout<<k<<' ';} cout<<endl
const int M=1e9+7;
#define test int t; cin>>t; while(t--)
#define SUMARR(a)   accumulate(a , a+n ,0LL)
#define SUM(v)      accumulate(all(v),0LL)
#define MAXIARR(a,n)  *max_element(a , a+n)
#define MINIARR(a,n)  *min_element(a , a+n)
#define MAX(v)      *max_element((v).begin(),(v).end())
#define MINI(v)     *min_element((v).begin(),(v).end()) 
#define PRESUM(a)    partial_sum(a.begin(),a.end(),a.begin())
#define PI           atan(1)*4
#define INF          INT64_MAX
#define fbo(x)       find_by_order(x)
#define ook(x)       order_of_key(x)
#define out(x)       cout<<x<<endl;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
#define f(i,n) for(int i = 0; i < n; i++)
/////खुदी को कर बुलंद इतना के हर तकदीर से पहले खुदा बन्दे से खुद पूछे के बता तेरी रज़ा क्या है;/////
int countDivisors(int n)
{
int cnt = 0;
for (int i = 1; i <= sqrt(n); i++) {
 if (n % i == 0) {
 if (n / i == i)
  cnt++;
else // Otherwise count both
cnt = cnt + 2;
}
 }
return cnt;
}
int digitsSum(int n) {
int ans = 0;
while(n != 0) {
ans += n%10;
n /= 10;
}
return ans;
}
int binpow(int a, int b, int m){
//take INF if no Modulo
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
const int32_t N = 3e5 + 10;
int FLOOR(const int a, const int b) { if (a > 0 || a % b == 0) return a / b; return (a / b - 1); }
int CEIL(const int a, const int b) {return (a + b - 1) / b;}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int POW(int a, int b) { return b == 0 ? 1 : a * POW(a, b - 1); }
int mod_exp(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res % mod; }
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int extended_gcd(int a, int b, int &x, int &y) {if (b == 0) {x = 1; y = 0; return x; } int gcd = extended_gcd(b, a % b, y, x); y -= x * (a / b); return gcd; }
int mod_inv(int a, int b) {int r1, r2; int gcd = extended_gcd(a, b, r1, r2); assert(gcd == 1); return r1; }
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mod_inv(b, m), m) + m) % m;}
void dosomething(){
int n,q;
cin>>n>>q;
map<string, int> mp;
mp["BG"] = 0;
mp["BR"] = 1;
mp["BY"] = 2;
mp["GR"] = 3;
mp["GY"] = 4;
mp["RY"] = 5;
vector<vector<int>> v(9);
vector<string> ves;
rep(i,0,n){
    string s;
    cin>>s;
    ves.pb(s);
    v[mp[s]].pb(i);
}
rep(i,0,q){
    int l, r;
    cin >> l >> r;
    l--, r--;
    // if(l>r){
    //     swap(l, r);
    // }
    string p, w;
    p = ves[l];
    w = ves[r];
    set<char> st;
    st.insert(p[0]);
    st.insert(w[0]);
    st.insert(p[1]);
    st.insert(w[1]);
    if(st.size()==4){
        int c = mp[p];
        int d = mp[w];
        int ans = INT_MAX;
        rep(z,0,6){
            if(z!=c && z!=d){
                // cout << c << " " << d << " " << z << endl;
                auto ll = lower_bound(v[z].begin(), v[z].end(),l) - v[z].begin();      
                if(ll==v[z].size()){
                    if(v[z].size()>0){
                        ll--;
                    }
                }
                if(ll<v[z].size()){
                    // cout << ll <<" "<<z<<endl;
                    int lll = v[z][ll];
                    int f = abs(lll - l)+abs(lll-r);
                    ans = min(ans, f);
                    if(ll-1>=0){
                        int lllx = v[z][ll-1];
                        int fffx = abs(lllx - l)+abs(lllx-r);
                        ans = min(ans, fffx);
                    }
                }
                auto rr = lower_bound(v[z].begin(), v[z].end(), r) - v[z].begin();
                if (rr == v[z].size())
                {
                    if (v[z].size()>0)
                    {
                        rr--;
                    }
                }
                if (rr < v[z].size())
                {
                    int rrr = v[z][rr];
                    int ff = abs(rrr - l) + abs(rrr - r);
                    ans = min(ans, ff);
                    if (rr -1 >= 0){
                        int rrrr = v[z][rr - 1];
                        int fff = abs(rrrr - l) + abs(rrrr - r);
                        ans = min(ans, fff);
                    }
                }
                if(v[z].size()){
                    int zzz = v[z][0];
                    int fff = abs(zzz - l) + abs(zzz - r);
                    ans = min(ans, fff);
                    int nnnn = v[z].back();
                    int ffff = abs(nnnn - l) + abs(nnnn - r);
                    ans = min(ans, ffff);
                }
            }
        }
        if(ans==INT_MAX){
            cout << -1 << endl;
            // continue;
        }
        else{
        cout<<ans<<endl;
        }
    }
    else{
        cout << abs(r - l) << endl;
    }
}
}
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//cout << fixed << setprecision(9);
int t=1;
cin>>t;
while(t--){
dosomething();
//Case #<<t<<'='<< ;
}
    return 0;
}