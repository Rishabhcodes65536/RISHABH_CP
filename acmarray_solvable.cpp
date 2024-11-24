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
// cin>>t;
// while(t>0)
// {
// }
int M,N,k,q;
cin>>M>>N>>k>>q;
 int a[k+10];
 rep(i,1,k+1){
     cin>>a[i];
 }
int B[q+10];
int C[q+10];
int D[q+10];
 int y=q;
 map<pair<int,int>,int> map;
 for(int z=q;z>0;--z){
     int ci,ni,ki;
     cin>>ci>>ni>>ki;
     B[z]=ci;
     C[z]=ni;
     map[{B[z],C[z]}]+=1;
     D[z]=ki;
  }
//   rep(i,1,q+1){
//       cout<<B[i]<<" "<<C[i]<<" "<<D[i]<<endl;
//   }
//   for(auto L : map){
//       cout<<(L.first).first<<" "<<(L.first).second<<" "<<L.second<<endl;
//   }
 bool flag =1;
 int v=1;
 int countrow=0,countcolumn=0;
 int res=0;
 while(countrow<M && countcolumn<N && v<=y){
    if(B[v]==2){
        if(map[{B[v],C[v]}]>=1){
        countcolumn+=1;
        res+=((M-countrow)*a[D[v]]);
        map[{B[v],C[v]}]=-1;
    }
    }
    else if(B[v]==1){
        if(map[{B[v],C[v]}]>=1){
        countrow+=1;
        res+=((N-countcolumn)*a[D[v]]);
        map[{B[v],C[v]}]=-1;
        }
    }
    v++;
    if(v>y){
        break;
    }
 }
cout<<abs(res)<<endl;
    return 0;
}