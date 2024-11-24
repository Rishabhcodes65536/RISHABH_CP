#include <bits/stdc++.h>

const int MOD = 1e9 + 7;
  
using namespace std;
 
  
void solve()
{
  int n,k;
  cin>>n;
  vector<int>dis(n);
  for (int i = 0; i < n;i++){
    cin >> dis[i];
  }
  cin >> k;
  vector<int>order(k);
  for (int i = 0; i < k;i++){
    cin >> order[i];
  }
  vector<int> pre(n + 1);
  // vector<int> suf(n + 1);
  pre[1] = dis[0];
  for (int i = 2; i <= n;i++){
    pre[i] = pre[i - 1] + dis[i-1];
  }
  // suf[n-1]=dis[n-1];
  // for(int i=n-2;i>=0;i--){
  //   suf[i]=suf[i+1]+dis[i];
  // }
  // for(auto r:pre){
  //   cout<<r<<" ";
  // }
  // cout<<endl;
  // for(auto r:suf){
  //   cout<<r<<" ";
  // }
  // cout<<endl;
  int pos=0;
  int res=0;
  int tsum=pre[n];
  for(int i=0;i<k;i++){
    int go=order[i];
    if(go<pos){
      swap(pos,go);
    }
    int r=pre[go]-pre[pos];
    res+=min(r,tsum-r);
    pos=order[i];
  }
  cout<<res<<endl;
}
  
signed main() 
{
  ios_base::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);
  freopen("big_input.txt", "r", stdin);
  freopen("big_output.txt","w", stdout);
  int t=1;
  cin>>(t);
  while(t--)
  {
  solve();
  }
  
}





//