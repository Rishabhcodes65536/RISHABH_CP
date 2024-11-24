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
test
{
int n;
cin>>n;
string s;
cin>>s;
int carry=0;
string ans;
if(s[0]=='9'){
    for(int i=n-1;i>=0;--i){
    int u = s[i]- '0';
    int g= 1 - carry;
    if(g-u<0){
        char a= 10 + g - u + '0';
        ans+=(a);
        //cout<<ans<<endl;
        carry=1;
    }
    else{
        char b = g - u + '0';
        ans+=(b);
        //cout<<ans<<endl;
        carry=0;
    }

    }

reverse(all(ans));
cout<<ans<<endl;
}
else{
    for(int i=0;i<n;++i){
        int f='9'- s[i];
        //cout<<f<<"hi"<<endl;
        ans+=('0'+f);
        //cout<<ans<<endl;
    }
    cout<<ans<<endl;
}
}
    return 0;
}

//1 1 1 1 1 
//0 9 1 0 9
//  2 0 0 2