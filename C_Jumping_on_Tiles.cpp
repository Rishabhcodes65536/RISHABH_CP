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
#define eb                emplace_back
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
#define MAXIARR(a)  *max_element(a , a+n)
#define MANIARR(a)  *min_element(a , a+n)
#define MAX(v)      *max_element((v).begin(),(v).end())
#define MINI(v)     *min_element((v).begin(),(v).end()) 
#define PI           atan(1)*4
#define INF          INT64_MAX
#define fbo(x)       find_by_order(x)
#define ook(x)       order_of_key(x
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
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//cout << fixed << setprecision(9);
test
{
    string s;
    cin>>s;
    int ans=0;
    vector <int> res,res2;
    vector <pair <int,int> > vep;
    rep(i,0,sz(s)){
        vep.pb({s[i]-'a'+1,i});
    }
    sort(all(vep));
    int p=s[0]-'a'+1;
    int q=s[sz(s)-1]-'a'+1;
    //res.pb((int)s[0]);
    //res2.pb(1);
    int sum;
    res2.pb(1);
    if(p>q){
        
    per(i,sz(s)-1,0){
        if(vep[i].ff<=p && vep[i].ff>=q && vep[i].ss!=sz(s)-1 && vep[i].ss!=0){
         ans+=abs(vep[i].ff-p);
         res2.pb(vep[i].ss+1);
         p=vep[i].ff;
        }
    }
        ans+=abs(q-p);
       // p=vep[i].ff;
        res2.pb(sz(s));
    }
    else{

        rep(i,0,sz(s)){
            if(vep[i].ff>=p && vep[i].ff<=q && vep[i].ss!=sz(s)-1 && vep[i].ss!=0){
               ans+=abs(vep[i].ff-p);
               p=vep[i].ff;
               res2.pb(vep[i].ss+1);
            }
        }
        ans+=abs(q-p);
        //p=vep[i].ff;
        res2.pb(sz(s));
    }
    cout<<ans<<" "<<sz(res2)<<endl;
    disp(res2);
}
    return 0;
}