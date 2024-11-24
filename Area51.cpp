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
#define f(i,n) for(int i = 0; i < n; i++)
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//cout << fixed << setprecision(9);
test
{
  string s;
  cin>>s;
  int even=0;
  int odd=0;
  for(int i=0;i<s.size();i+=2){
    if(s[i]=='1'){
        even++;
    }
  }
  for(int j=1;j<s.size();j+=2){
    if(s[j]=='1'){
        odd++;
    }
  }
  bool flag=false;
  rep(i,0,s.size()){
    if(s[i]!='0'){
        flag=true;
    }
  }
//   cout<<even<<" "<<s.size()<<endl;
//   cout<<odd<<"hi"<<endl;

  if((abs(odd-even))%3==0){
    cout<<"0"<<endl;
  }
  else if(odd%3==2 && even==0 || even%3==2 && odd==0){
    cout<<"2"<<endl;
  }
   else {
   cout<<"1"<<endl;
  }

}
    return 0;
}