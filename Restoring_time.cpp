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
//cout << fixed << setprecision(9);
int n,t;
cin>>n>>t;
inarr(a,n);
sort(a,a+n,greater<int>());
stack <int> s1;
stack <int> s2;
rep(i,0,n){
    s1.push(a[i]);
}
int last=0;
int m;
cin>>m;
vector<pair<int,int>> times;
set <int> q;
rep(i,0,m){
    int x,y;
    cin>>x>>y;
    rep(i,x,y+1){
      q.insert(i);  
    }
}
rep(i,1,t+1){
if(q.find(i)!=q.end()){
    if((!s1.empty())){
        int z=s1.top();
        s2.push(z);
        //cout<<"s2 me push "<<z<<endl;
        s1.pop();
    }
}
else{
    if(!s2.empty()){
        int w=s2.top();
        //cout<<"s1 me push "<<w<<endl;
        s1.push(w);
        s2.pop();
    }
}
}
int sum=0;
while(!s1.empty()){
    sum+=s1.top();
    s1.pop();
}
cout<<sum<<endl;
    return 0;
}