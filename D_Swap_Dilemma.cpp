#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
using namespace std;
// using namespace __gnu_pbds;
// typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define endl              '\n'
#define ff                first
#define ss                second
#define pb                emplace_back
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

void merge(vector <int>& arr,long long s,long long m,long long e,long long &cnt)
    {
        vector <int> temp(e-s+1);
        int i=s; 
        int j=m+1; 
        int k=0; 
        
        while(i<=m && j<=e)
        {
            if(arr[i] > arr[j])
            {
                cnt+=m-i+1;
                temp[k++]=arr[j++];
            }
            else
                temp[k++]=arr[i++];
        }
        while(i<=m)
            temp[k++]=arr[i++];
        while(j<=e)
            temp[k++]=arr[j++];    
        
        k=0;
        for(int i=s;i<=e;)
        {
            arr[i++]=temp[k++];
        }
    }
    void mergesort(vector <int>& arr,int s,int e,int &cnt)
    {
        if(s>=e){
            return;
            }
        long long m= s+(e-s)/2LL;
        mergesort(arr,s,m,cnt);
        mergesort(arr,m+1,e,cnt);
        merge(arr,s,m,e,cnt);
    }


void dosomething(){
    int n;
    cin >> n;
    invec(a, n);
    invec(b, n);
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        mp[a[i]]++;
    }
    rep(i,0,n){
        if(mp[b[i]]==0){
            cout << "NO" << endl;
            return;
        }
        mp[b[i]]--;
    }
    for(auto &h:mp){
        if(h.ss>0){
            cout << "NO" << endl;
            return;
        }
    }
    // set<int> st1, st2;
    int swap1 = 0, swap2 = 0;
    int cnt = 0;
    //Gosh Dangitt just changing from n to n-1 Would have scaled my rank  !!! DUHHHHHHHHHHHHHHHHHH
    mergesort(a, 0, n-1, swap1);
    mergesort(b, 0, n-1, swap2);
    if((swap1%2)==(swap2%2)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
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