// 

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
 
 
vector <int> prime;
int x[39] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,137,139,149,151,157,163,167,173};
int b[31623] = {0};
 
void initialize(){
    int m;
      for (int i = 0; i < 39LL; i++ ) {
        m = 2*x[i];
        while ( m < 31623LL ) {
            b[m] = 1LL;   //set all multiples of a[i] to 1
            m = m + x[i];
        }
    }
    for (int i = 2; i < 31623; i++ ) {
        if ( b[i] == 0 )
            prime.pb(i);
    }
}
void dosomething(){
int n;
cin>>n;
inarr(a,n);
map <int,int> pum;
// cout<<isprime(a[0])<<endl;
rep(i,0,n){
   if(a[i]>1 && pum[a[i]]!=0){
     cout<<"YES"<<endl;
     return;
   }
//    int u=sqrt(a[i]);
   for(auto y:prime){
    // if(y>u){
    //     break;
    // }
    if(a[i]%y==0LL){
        if(pum[y]==0LL){
            // cout<<i<<" "<<y<<endl;
           pum[y]++;
            // cout<<vec[7]<<endl;
        }
        else{
            // cout<<i<<" "<<y<<endl;
            cout<<"YES"<<endl;
            return;
        }
        pum[a[i]]++;
        while(!(a[i]%y))a[i]/=y;
    }
   }
   if(a[i]>1 && pum[a[i]]){
    cout<<"YES"<<endl;
     return;
   }
   pum[a[i]]++;
    
}
// disp(g);
 
cout<<"NO"<<endl;
return ;
}
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//cout << fixed << setprecision(9);
 
int t=1;
cin>>t;
initialize();
while(t--){
// set <int> g;
dosomething();
//Case #<<t<<'='<< ;
}
    return 0;
}