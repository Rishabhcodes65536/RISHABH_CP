#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define endl              '\n'
#define ff                first
#define ss                second
#define pb                push_back
#define int               long long
#define float             long double
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
 
 

static const int MOD=1e9+7;
struct Mint {
    int val;
    Mint(long long v = 0) {
        if (v < 0) {
            v = v % MOD + MOD;
        }
        if (v >= MOD) {
            v %= MOD;
        }
        val = v;
    }
    static int mod_inv(int a, int m = MOD) {
        int g = m, r = a, x = 0, y = 1;
        while (r != 0) {
            int q = g / r;
            g %= r; swap(g, r);
            x -= q * y; swap(x, y);
        }
        return x < 0 ? x + m : x;
    }
    explicit operator int() const {
        return val;
    }
    Mint& operator+=(const Mint &other) {
        val += other.val;
        if (val >= MOD) val -= MOD;
        return *this;
    }
    Mint& operator-=(const Mint &other) {
        val -= other.val;
        if (val < 0) val += MOD;
        return *this;
    }
    typedef unsigned long long ull;
    ull fast_mod(ull a, ull b, ull M = MOD) {
        long long ret = a * b - M * ull(1.L / M * a * b);
        return ret + M * (ret < 0) - M * (ret >= (long long)M);
    }
    Mint& operator*=(const Mint &other) {
        val = fast_mod((ull) val, other.val);
        return *this;
    }
    Mint& operator/=(const Mint &other) {
        return *this *= other.inv();
    }
    friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }
    friend Mint operator-(const Mint &a, const Mint &b) { return Mint(a) -= b; }
    friend Mint operator*(const Mint &a, const Mint &b) { return Mint(a) *= b; }
    friend Mint operator/(const Mint &a, const Mint &b) { return Mint(a) /= b; }
    Mint& operator++() {
        val = val == MOD - 1 ? 0 : val + 1;
        return *this;
    }
    Mint& operator--() {
        val = val == 0 ? MOD - 1 : val - 1;
        return *this;
    }
    Mint operator++(int32_t) { Mint before = *this; ++*this; return before; }
    Mint operator--(int32_t) { Mint before = *this; --*this; return before; }
    Mint operator-() const {
        return val == 0 ? 0 : MOD - val;
    }
    bool operator==(const Mint &other) const { return val == other.val; }
    bool operator!=(const Mint &other) const { return val != other.val; }
    Mint inv() const {
        return mod_inv(val);
    }
    Mint pow(long long p) const {
        assert(p >= 0);
        Mint a = *this, result = 1;

        while (p > 0) {
            if (p & 1)
                result *= a;

            a *= a;
            p >>= 1;
        }
        return result;
    }
    friend ostream& operator<<(ostream &stream, const Mint &m) {
        return stream << m.val;
    }
    friend istream& operator >> (istream &stream, Mint &m) {
        return stream >> m.val;
    }
};
Mint prob=1;
int dp[155][105][10][62][2];

int func1(int n,int b,int w,int x,int u){
    if(n<=0){
        if(x==0){
            return 1;
        }
        return 0;
    }
    if(b<=0){
        return 0;
    }
    if(w<=0){
        return 0;
    }
    if(dp[n][x][w][b][u]!=-1){
        return dp[n][x][w][b][u];
    }
    Mint op1=0;
    //1 run
    op1+=prob*func1(max(0ll,n-1),b-1,w,u==0 ? (max(0LL,x-1)):(x),(u^1)^((b%6)==1));

    //2 run
    op1+=prob*func1(max(0ll,n-2),b-1,w,u==0 ? max(0LL,x-2):(x),u^((b%6)==1));

    //3 run
    op1+=prob*func1(max(0ll,n-3),b-1,w,u==0 ? max(0LL,x-3):(x),(u^1)^((b%6)==1));

    //4 run
    op1+=prob*func1(max(0ll,n-4),b-1,w,u==0 ? max(0LL,x-4):(x),u^((b%6)==1));

    //6 run
    op1+=prob*func1(max(0ll,n-6),b-1,w,u==0 ? max(0LL,x-6):(x),u^((b%6)==1));

    //wicket
    if(u!=0 || (u==0 && x==0)){
    op1+=prob*func1(n,b-1,w-1,x,u^(b%6==1));
    }
    // cout<<(op1%M+op2%M+op3%M+op4%M+op5%M+op6%M)%M<<endl;
    return dp[n][x][w][b][u]=op1.val;
}
void dosomething(){
int n,b,w,x;
cin>>n>>b>>w>>x;
int u=0;
x=100-x;
w=10-w;
int res=func1(n,b,w,x,u);
cout<<res<<endl;
}
 
 
signed main(){
// auto begin = std::chrono::high_resolution_clock::now();
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//cout << fixed << setprecision(9);
int t=1;
cin>>t;
prob=1;
prob/=6;
rep(i,0,155){
    rep(j,0,62){
        rep(k,0,10){
            rep(u,0,105){
                rep(v,0,2){
                    dp[i][u][k][j][v]=-1;
                }
            }
        }
    }
}
while(t--){
dosomething();
//Case #<<t<<'='<< ;
}
 
return 0;
}