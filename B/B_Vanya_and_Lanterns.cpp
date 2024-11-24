#include<bits/stdc++.h>
using namespace std;
#define endl              '\n'
#define ff                first
#define ss                second
#define pb                push_back
#define int               long long
#define lb                lower_bound
#define ub                upper_bound
#define eb                emplace_back
#define sz(x)             (int)(x).size()
#define ppc               __builtin_popcountll
#define all(x)            (x).begin(), (x).end()
#define rall(x)           (x).rbegin(), (x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define invec(a,n)        vector<int>a(n); rep(i,0,n) cin>>a[i]
#define inarr(a,n)        int a[n]; rep(i,0,n) cin>>a[i]
#define in(k,a) for(auto k : a)
#define disp(a) in(k,a){ cout<<k<<' ';} cout<<endl
const int M=1e9+7;
#define test int t; cin>>t; while(t--)
#define SUMI0(a)   accumulate(a , a+n ,0)
#define MAX(v)    *max_element((v).begin(),(v).end())
#define MINI(v)   *min_element((v).begin(),(v).end()) 
#define PI atan(1)*4
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
#define f(i,n) for(int i = 0; i < n; i++)
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
cout << fixed << setprecision(10);

int n,m;
cin>>n>>m;
inarr(a,n);
sort(a,a+n);
bool flag0=0;
if(a[0]==0){
    flag0=1;
}
bool flag1 = 0;
if(a[n-1]==n){
    flag1=1;
}
int maxi=-1;
rep(i,0,n-1){
    maxi=max(maxi,abs(a[i+1]-a[i]));
}
long double ans=((long double)maxi)/2.0;
//cout<<setprecision(9)<<ans<<endl;
long double m0=(long double)*min_element(a,a+n);
long double mn=(long double)*max_element(a,a+n);
if(!(flag0)){
ans=max(ans,m0);
}
if(!(flag1)){
    ans=max(ans,m-mn);
}
cout<<ans<<endl;
    return 0;
}