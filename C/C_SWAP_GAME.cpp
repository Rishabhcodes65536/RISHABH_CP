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
void dosomething(){
int n;
cin>>n;
inarr(a,n);
// if(arr[0]==1){
//     cout<<"Bob"<<endl;
//     return ;
// }
// for(int i=1;i<n;++i){
//     if(a[i]==1){
//         cout<<"Alice"<<endl;
//         return;
//     }
// }

// if(a[0]==2){
//     cout<<"Bob"<<endl;
// }
int mini=MINIARR(a,n);
if(a[0]==mini){
    cout<<"Bob"<<endl;
}
else{
    cout<<"Alice"<<endl;
}

}
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//cout << fixed << setprecision(9);
// #ifdef ONLINE_JUDGE
// freopen(
// , 
// , stdin);
// freopen(
// , 
// , stderr);
// freopen(
// , 
// , stdout);
// #endif
int t=1;
cin>>t;
while(t--){
dosomething();
//Case #<<t<<'='<< ;
}
    return 0;
}

//2 3 4 allice khela
//3 1 4     4 3 1  bob khela
//1 2 4     1 3 3     allice khela har gaya in step 1 and 2

//5 4 4  allice plays
//4 4 4     bob plsys
//4 3 4     allice plays
//2 3 4     bob plays
//3 1 4     allice plays
//1 2 4      bob plays bob loses

//3 4 4 allice plays
//4 2 4 bob plays
//2 3 4 a
//3 1 4 b
//1 2 4 a   a loses

//5 4 3 a
//3 4 4 b
//4 2 4 a
//2 3 4 b b loses

//5 4 5 a
//5 4 4 b plays alice loses
//

//4 4 5 allice plays
//4 3 5 bob plays
//3 3 5 allice plays
//3 2 5 bob plays
//2 2 5 allice plays bob loses


//min is odd allice wins

//3 2 allice khela
//2 2   bob khela bob loses


//3 3 allice plays
//3 2 bob plays
//2 2 allice plays allice loses
