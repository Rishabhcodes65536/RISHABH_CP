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
int n,k;
cin>>n>>k;
int ans = 0;
vector<pair <int,int>> vep;
for(int i = 0; i < n; i++){
    int u, v;
    cin >> u >> v;
    if(u>v){
        swap(u, v);
    }
    vep.pb({u, v});
}
sort(vep.begin(), vep.end());

vector<vector<int>> dp(n+3, vector<int>(k + 4, -1));
function<int(int, int)> recursive = [&](int i, int p) -> int{
    if(i == n){
        if (p==k){
            return 0;
        }
        return INT_MAX;
    }
    if(dp[i][p] != -1){
        return dp[i][p];
    }
    int u = vep[i].ff;
    int v = vep[i].ss;
    int diff = v - u;
    int offset = k - p;
    int incl=INT_MAX;
    int l = u;
    int r = u;
    int prev1 = 0, prev2 = 0;
    rep(h,1,min(offset+1,v+u+2)){
        if(h<=diff){
        incl = min(incl, u * h + recursive(i + 1, p + h));
        }
        else{
            // // cout << "hi" << endl;
            // // rep(j, 1, min(offset-(h-1) + 1, u + 1)){
            // int j = min(offset - (h - 1), u);
            // incl = min(incl, u * (h - 1) + j + recursive(i + 1, j == u ? (p + h + j) : (min(p + h - 1 + j, k))));
            // // }
            if(l<=r){
                prev2++;
                incl = min(incl, prev1+u*diff + l + recursive(i + 1,min(p + h+(l+r==0),k)));
                prev1 += l;
                r--;
            }
            else{
                prev2++;
                incl = min(incl, prev1+u*diff+ r + recursive(i + 1, min(p +h +(l+r==0),k)));
                prev1 += r;
                l--;
            }
            if(l==0 && r==0){
                break;
            }
            // cout << l << " " << r << endl;
        }
    }
    int excl = 0 + recursive(i + 1, p);
    return dp[i][p] = min(incl, excl);
};
int res=recursive(0, 0);
if(res==INT_MAX){
    cout << -1 << endl;
    return;
}
cout << res << endl;

// rep(i,0,n){
//     int u = vep[i].first, v = vep[i].second;
//     int h = min(k, v-1);
//     k -= h;
//     ans += h *(u);
//     int y = min(k, u);
//     cout << y << "->"<<k<< endl;
//     k -= y;
//     ans += y;
//     if(y==u){
//         k--;
//     }
//     cout << ans<<" "<<k << endl;
//     if(k<=0){
//         break;
//     }
// }
// if(k>0){
//     cout << -1 << endl;
//     return;
// }
// cout << ans << endl;
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



//30   -> 18
//56   -> 25