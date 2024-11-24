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
sum[1]=0;
sum[2]=a[2];
for(int i=3;i<=n-1;++i){
    sum[i]=a[i];
    sum[i]+=sum[i-1];
}
int ans[n];
ans[1]=1;
for(int i=2;i<=n-1;++i){
    ans[i]=2;
}
// for(int i=1;i<=n-1;++i){
//     cout<<sum[i]<<" ";
// }
// cout<<endl;
ans[n]=1;
if(n>2){
int j=2;
rep(i,1,n-1){
  j=i+2;
  while(j<=n){
      int h=sum[j-1]-sum[i];
      if(a[i]>=h){
        //   cout<<a[i]<<" "<<h<<endl;
          ans[j]+=1;
      }
      if(a[j]>=h){
        //   cout<<a[j]<<" "<<h<<endl;
          ans[i]+=1;
      }
      j++;
  }
}
}
rep(i,1,n+1){
    cout<<ans[i]<<" ";
}
cout<<endl;
    return 0;
}