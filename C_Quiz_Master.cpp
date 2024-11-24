#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
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

vector <vector <int>> factors(1e5+5,vector <int> ());
void initiate(){
    for(int i=1LL;i<=(int)1e5;i++){
        for(int j=i;j<=(int)1e5;j+=i){
            factors[j].pb(i);
        }
    }
}
void init()
{
    for (int i = 1; i <= (int)1e5; i++)
    {
        for (int j = i; j <= (int)1e5; j += i)
        {
            factors[j].pb(i);
        }
    }
}
void dosomething(){
int n,m;
cin>>n>>m;
inarr(a,n);
sort(a,a+n);
vector <int> freq(m+5,0LL);
int countfac=0,j=0;
int res=1e17;
for(int i=0;i<n;i++){
    for(auto k:factors[a[i]]){
        if(k>m){
            break;
        }
        if(!freq[k]++){
            // cout<<k<<" "<<a[i]<<endl;
            countfac++;
        }
    }
    while(countfac==m){
        int curr_ans = a[i] - a[j];
            if (curr_ans < res)
            {
                res = curr_ans;
            }
        // res=min(res,a[i]-a[j]);
        for(auto k:factors[a[j]]){
        if(k>m){
            break;
        }
        if(--freq[k]==0){
            countfac--;
        }
        }
    j++;
    }
}
cout<<(res>=1e17 ? (-1):(res))<<endl;
}
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//cout << fixed << setprecision(9);
// initiate();
init();
int t=1;
cin>>t;
while(t--){
dosomething();
//Case #<<t<<'='<< ;
}
    return 0;
}

// #include <bits/stdc++.h>
// #define all(v) v.begin(), v.end()
// #define var(x, y, z) cout << x << " " << y << " " << z << endl;
// #define ll long long int
// #define pii pair<ll, ll>
// #define pb push_back
// #define ff first
// #define ss second
// #define FASTIO                \
//     ios ::sync_with_stdio(0); \
//     cin.tie(0);               \
//     cout.tie(0);

// using namespace std;

// const ll inf = 1e17;
// const ll MAXM = 1e5;
// vector<ll> factors[MAXM + 5];

// void init()
// {
//     for (ll i = 1; i <= MAXM; i++)
//     {
//         for (ll j = i; j <= MAXM; j += i)
//         {
//             factors[j].pb(i);
//         }
//     }
// }

// void solve()
// {
//     ll n, m;
//     cin >> n >> m;
//     vector<pii> vec;
//     for (ll i = 0; i < n; i++)
//     {
//         ll value;
//         cin >> value;
//         vec.pb({value, i});
//     }
//     sort(all(vec));
//     vector<ll> frequency(m + 5, 0);
//     ll curr_count = 0;
//     ll j = 0;
//     ll global_ans = inf;
//     for (ll i = 0; i < n; i++)
//     {
//         for (auto x : factors[vec[i].ff])
//         {
//             if (x > m)
//                 break;
//             if (!frequency[x]++)
//             {
//                 curr_count++;
//             }
//         }
//         while (curr_count == m)
//         {
//             ll curr_ans = vec[i].ff - vec[j].ff;
//             if (curr_ans < global_ans)
//             {
//                 global_ans = curr_ans;
//             }
//             for (auto x : factors[vec[j].ff])
//             {
//                 if (x > m)
//                     break;
//                 if (--frequency[x] == 0)
//                 {
//                     curr_count--;
//                 }
//             }
//             j++;
//         }
//     }
//     cout << (global_ans >= inf ? -1 : global_ans) << "\n";
// }

// int main()
// {
//     FASTIO
//     init();
//     ll t;
//     cin >> t;
//     while (t--)
//     {
//         solve();
//     }
//     return 0;
// }