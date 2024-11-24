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

int n;
cin>>n;

invec(hi,n);
invec(xi,n);

//invec(xi,n);
vector <int> you;
vector <int> ans(n,0);
// rep(i,0,n){
//   you[i]=xi[i];
// }
vector <int> nge(n);
stack <int> st;
for(int i=0;i<hi.size();++i){
    if(!st.empty()){
  while (!st.empty() && hi[i]>= hi[st.top()])
  {
     nge[st.top()]=i;
     st.pop();
  }
}
  st.push(i);
}
while(!st.empty()){
  nge[st.top()]=n;
  st.pop();
}
//   rep(i,0,n){
//     cout<<i<<" "<<nge[i]<<endl;
//   }
rep(i,0,n){
    if(xi[i]>0){
    for(int j=i+1;j<nge[i];++j){
        if(xi[i]>0){
        ans[j]+=1;
        xi[i]--;
        }
    }
    }
}
rep(i,0,n){
    cout<<ans[i]<<" ";
}
cout<<endl;

    return 0;
}

//9 8 7 6 7 4 10
//3 3 3 3 3 3 3
//stack -> 9
//stack -> (8<9) stackpush  8   (count9--) 8++
//stack -> (7<8)  stackpush   (c9--) (c8--) 8++ 7++
//stack -> 6<7  stackpush 6   (c9--) (c8--) (c7--) 8++ 7++ 6++
//stack -> 7!<6 stackpop  curren 7 7!<7 pop 8>7 (c8--) (c9--)8++ 7++
//stack looks like 9 8 7  4<7 c9-- c8-- c7-- c4++
//10!<4 10!<7 10!<8 10!<9

