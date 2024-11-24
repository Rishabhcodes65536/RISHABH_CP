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
#define MAXIARR(a)  *max_element(a , a+n)
#define MANIARR(a)  *min_element(a , a+n)
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
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//cout << fixed << setprecision(9);
int t=1;
cin>>t;
for(int a=1;a<=t;++a){
int rs,rh;
cin>>rs>>rh;
int n,m;
cin>>n;
vector <pair<int,int>> red,yellow;
rep(i,0,n){
    int x,y;
    cin>>x>>y;
    red.pb(make_pair(x,y));
}
cin>>m;
rep(i,0,m){
    int x,y;
    cin>>x>>y;
    yellow.pb(make_pair(x,y));
}
vector <int> validred,validyellow;
rep(i,0,n){
    int u=red[i].ff;
    int v=red[i].ss;
        float g=(float)(rh);
        float w=(float)sqrt(pow(u,2LL)+pow(v,2LL));
        // float x=(float)sqrt(pow(u-rs,2LL)+pow(v,2LL));
        // float y=(float)sqrt(pow(u,2LL)+pow(v-rs,2LL));
        // float b=(float)sqrt(pow(u+rs,2LL)+pow(v,2LL));
        // float o=(float)sqrt(pow(u,2LL)+pow(v+rs,2LL));
        //cout<<w<<" "<<g<<endl;
        if(w<=rs+rh || w<=abs(rs-rh)){
            validred.pb(pow(u,2)+pow(v,2));
        }
        
    

}
rep(i,0,m){
    int u=yellow[i].ff;
    int v=yellow[i].ss;
    float g=(float)(rh);
        float w=(float)sqrt(pow(u,2LL)+pow(v,2LL));
        if(w<=rs+rh || w<=abs(rs-rh)){
            validyellow.pb(pow(u,2)+pow(v,2));
        
    }

}
sort(all(validred));
sort(all(validyellow));
int u=0,v=0;
if(sz(validyellow)==0){
    u=sz(validred);
}
else{
rep(i,0,sz(validred)){
    if(validred[i]<validyellow[0]){
        u++;
    }
    else{
        break;
    }
}
}
if(sz(validred)==0){
    v=sz(validyellow);
}
else{
rep(i,0,sz(validyellow)){
    if(validyellow[i]<validred[0]){
        v++;
    }
    else{
        break;
    }
}
}
//cout<<u<<" "<<v<<endl;

cout<<"Case #"<<a<<": "<<u<<" "<<v<<endl; 
}
    return 0;
}