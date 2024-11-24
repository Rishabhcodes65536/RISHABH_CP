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
const int M=1e9+7;
signed main(){
int t;
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//int n,k;
//string s
//array arr[n]
//char arr[n]
// cin>>t;
// while(t>0)
// {
// }
int n;
cin>>n;
inarr(a,n);
if(n==1){
    cout<<1<<endl;
    return 0;   
}
if(n==2){
    cout<<'2'<<endl;
    return 0;
}
int res=2;
int i=0;
while(i<n-2){
  int fib=a[i]+a[i+1];
  int count=2;
  if(fib==a[i+2]){
      count=2;
      count++;
      bool flag = true;
     while(flag){
     i++;
     if(a[i]+a[i+1]==a[i+2] && i<n-2){
         count++;
     }
     else{
         flag=false;
     }
     }
     res=max(res,count);
  }
  else{
      i++;
  }
}
cout<<res<<endl;
    return 0;
}