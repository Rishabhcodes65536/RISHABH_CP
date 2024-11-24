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

int recursive(int i,vector <int>& a,vector <int>& b,vector <int>& dp,int n,int &ans){
    if(i==n){
        return 0;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    int temp=0;
    for(int k=i+1;k<n;k++){
        if(a[k]-1<=i && i<=b[k]-1){
            temp=max(temp,(a[k]+recursive(k,a,b,dp,n,ans))%M);
        }
        ans=max(ans,temp);
        // cout<<temp<<endl;
    }
    return dp[i]=ans;
}



void dosomething(){
int n;
cin>>n;
invec(a,n);
invec(b,n);

vector <int> dp(n+3,-1);
int maxi=0;
rep(i,0,n){
int ans=0;
maxi=max(maxi,(a[i]+recursive(i,a,b,dp,n,ans))%M);
}
cout<<maxi<<endl;
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

