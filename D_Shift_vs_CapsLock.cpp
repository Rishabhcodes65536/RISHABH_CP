#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define endl              '\n'
#define ff                first
#define ss                second
#define pb                emplace_back
#define ppb               pop_back
#define int               long long
#define float             long double
#define lb                lower_bound
#define ub                upper_bound
#define sz(x)             (int)(x).size()
#define ppc               __builtin_popcountll
#define all(x)            (x).begin(), (x).end()
#define rall(x)           (x).rbegin(), (x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define per(i,a,b)        for(int i=(a);i>=(b);i--)
#define invec(a,n)        vector<int>a(n); rep(i,0,n) cin>>a[i]
#define inarr(a,n)        int a[n]; rep(i,0,n) cin>>a[i]
#define in(k,a) for(auto k : a)
#define disp(a) in(k,a){ cout<<k<<' ';} cout<<endl
const int M=1e9+7;
#define test int t; cin>>t; while(t--)


int dpsolver(string &s,int &x,int &y,int &z,int i,vector <vector <int>>& dp,int caps){
    if(i>=s.size()){
        return 0LL;
    }

    if(dp[i][caps]!=-1LL)return dp[i][caps];

    int ncaps=s[i]== ('A') ? (1) : (0);
    int u=INT_MAX;
    int v=INT_MAX;
    int w=INT_MAX;
    int p=INT_MAX;
    int q=INT_MAX;
    if(ncaps ^ caps){
        u=x+z+dpsolver(s,x,y,z,i+1,dp,ncaps);
        v=y+dpsolver(s,x,y,z,i+1,dp,caps);
        // w=x+y+z+dpsolver(s,x,y,z,i+1,dp,)
        // q=y+z+dpsolver(s,x,y,z,i+1,dp,caps^1);
    }
    else{
        u=x+dpsolver(s,x,y,z,i+1,dp,caps);
        v=y+z+dpsolver(s,x,y,z,i+1,dp,caps^1);
    }
    return dp[i][caps]=min(u,v);
}

void dosomething(){
int x,y,z;
cin>>x>>y>>z;
string s;
cin>>s;
// int ans=0;
int caps=0;
vector <vector<int>> dp(s.size()+2,vector <int> (2,-1LL));
cout<<dpsolver(s,x,y,z,0LL,dp,caps)<<endl;
// cout<<min(dp[s.size()-1][0],dp[s.size()-1][1]);
}


signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//cout << fixed << setprecision(9);
int t=1;
// cin>>t;
while(t--){
dosomething();
//Case #<<t<<'='<< ;
}
    return 0;
}