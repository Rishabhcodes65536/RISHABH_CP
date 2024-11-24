#include<bits/stdc++.h>
using namespace std;
#define endl              '\n'
#define ff                first
#define ss                second
#define pb                push_back
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
//123
long long func (long long a){
    long long u=a;
    long long ans=0LL;
    while(u>0){
    ans+=u%10;
    u/=10LL;
    }
    return ans;
}
int floorSqrt(int x)
{
    // Base cases
    if (x == 0 || x == 1)
    return x;
 
    // Starting from 1, try all numbers until
    // i*i is greater than or equal to x.
    int i = 1, result = 1;
    while (result <= x)
    {
    i++;
    result = i * i;
    }
    return i - 1;
}
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//cout << fixed << setprecision(9);
long func (long long );
int floorSqrt(int );
int n;
cin>>n;
//int lo=1;
//int hi=floorSqrt(n)+1;
int ans=LLONG_MAX;
for(int s=1;s<82;++s){
int lo=1;
int hi=1e9;
while(lo<=hi){
int mid=lo + (hi-lo)/2;
//cout<<mid<<endl;
if(mid * mid + mid*func(mid) == n && func(mid)==s){
    ans=min(ans,mid);
    hi=mid-1;
}
else if(mid * (mid + s) < n){
     //cout<<"hi"<<mid*(mid + func(mid));
     lo=mid+1;
}
else{
     //cout<<"BYE"<<mid*(mid + func(mid));
    hi=mid-1;
}
}
}
 if(ans==LLONG_MAX){
  cout<<-1<<endl;
 }
 else{
    cout<<ans<<endl;
 }
    return 0;
}

//x * (x + s(x)) = n