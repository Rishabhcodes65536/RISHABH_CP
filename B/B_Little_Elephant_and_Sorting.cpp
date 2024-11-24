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
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//cout << fixed << setprecision(9);
int n;
cin>>n;
invec(v,n);
stack <int> sta;
int maxi=v[0];
sta.push(v[0]);
int ans=0LL;
int res=0LL;
rep(i,1,n){
if(v[i]>=maxi){
    sta.push(v[i]);
    //maxi=v[i];
    ans=0LL;
    while(!sta.empty()){
        sta.pop();
        if(!sta.empty()){
            ans=max(ans,maxi-sta.top());
        }
    }
    sta.push(v[i]);
    //maxi=v[i];
    res+=ans;
}
else{
    sta.push(v[i]);
}
}
ans=0LL;
while(!sta.empty()){
    ans=max(ans,maxi-sta.top());
    sta.pop();
}
res+=ans;
cout<<res<<endl;
    return 0;
}

//50  100  8 33 3 62  +50->+38 100 100 46 71 41 100 -> +29xor 100 100 75 100 70 100 -> +25 +20  