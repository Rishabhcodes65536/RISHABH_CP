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
signed main(){
int t;
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//int n,k;
//string s
//array arr[n]
//char arr[n]
int n;
cin>>n;
int a[n];
for(int i=1;i<=n;++i){
    cin>>a[i];
}
int sum[n-1];
int b[n];
rep(i,1,n+1){
    b[i]=a[n+1-i];
}
int sum2[n-1];
sum[1]=0;
sum[2]=a[2];
for(int i=3;i<=n-1;++i){
    sum[i]=a[i];
    sum[i]+=sum[i-1];
}
int ans[n];
sum2[1]=0;
sum2[2]=b[2];
for(int i=3;i<=n-1;++i){
    sum2[i]=b[i];
    sum2[i]+=sum2[i-1];
}
for(int i=1;i<=n;++i){
    ans[i]=0;
}
// ans[1]=1;
// for(int i=2;i<=n-1;++i){
//     ans[i]=2;
// }
// for(int i=1;i<=n-1;++i){
//     cout<<sum[i]<<" ";
// }
// cout<<endl;
//ans[n]=1;
// ans[1]=1;
// ans[n]=1;

rep(i,1,n){
    int D=sum[i]-a[i+1];
    if(D<0){
        for(int f=1;f<i+1;++f){
            ans[f]+=1;
        }
    }
    else{
  auto y=lower_bound(sum+1 , sum+n - 1, D ) - sum+1;
  for(int u=y-1;u<i+1;++u){
    ans[u]+=1;
  }
 
  }
}
rep(i,1,n){
    int D=sum2[i]-b[i+1];
    if(D<0){
        for(int f=1;f<i+1;++f){
            ans[n+1-f]+=1;
        }
    }
    else{
  auto y=lower_bound(sum2+1 , sum2+n - 1, D ) - sum2+1;
  for(int u=y-1;u<i+1;++u){
    ans[n+1-u]+=1;
  }
 
  }
}


rep(i,1,n+1){
    cout<<ans[i]<<" ";
}
    cout<<endl;
    return 0;
}