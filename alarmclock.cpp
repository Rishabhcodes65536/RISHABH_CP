#include<bits/stdc++.h>
using namespace std;
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
#define PI          atan(1)*4
#define INF          INT64_MAX
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
int n,h,m;
cin>>n>>h>>m;
vector <pair<int,int>> time;

rep(i,0,n){
    int a,b;
    cin>>a>>b;
    time.pb({a,b});
}
sort(all(time));
/*for(auto j :time){
    cout<<j.ff<<" "<<j.ss<<endl;
}*/
//cout<<endl;
//bool flag=true;
vector <pair<int,int>> ans;
rep(i,0,n){
    int a=time[i].ff;
    int b=time[i].ss;
    int u=a>=h ? (a-h):(a+24-h);
    int v=b>=m ? (b-m):(60-(m-b));
    if(b<m){
        u-=1;
    }
    if(u<0){
        u+=24;
    }
    ans.pb({u,v});
}
sort(all(ans));
cout<<ans[0].ff<<" "<<ans[0].ss<<endl;
/*for(auto g:ans){
    cout<<g.ff<<" "<<g.ss<<endl;
}*/
//cout<<endl;

}
    return 0;
}

//6 39
//6 38 // maximum time will be 23 59

//6 13   8 0

//8 0