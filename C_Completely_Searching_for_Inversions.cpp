#include"bits/stdc++.h"
using namespace std;

#define int long long
#define endl "\n"
#define ff first
#define ss second

const int MOD2 = 998244353;
const int MOD1 = 1e9 + 7;
const int N = 1e5 + 5;


void dfs(vector<pair<int,int>> A[],vector <int>& dp,int i,int& res,int& count){
    if(dp[i]!=-1){
        res=(0ll+res-dp[i])%MOD2;
        count=(0ll+count%MOD2+dp[i]%MOD2)%MOD2;
        return;
    }

    for(auto f:A[i]){
        if(f.ss){
            dfs(A,dp,f.ff,res,count);

            res=(0ll+res+(count%MOD2))%MOD2;
             
            // res%=MOD2;
        }
        else{
            dfs(A,dp,f.ff,res,count);
            count=(count+1)%MOD2; 
        }
    }
    
    dp[i]=count%MOD2;
}

void SoLvE(){ 
    int n;cin>>n;
    vector<pair<int,int>> A[n+1];

    for(int i=1;i<=n;i++){
        int s;cin>>s;
        for(int j=1;j<=s;j++){
            int u;cin>>u;
            int w;cin>>w;
            A[i].push_back({u,w});            
        }
    }

    vector <int> dp(n+2,-1);
    int i=1;
    int res=0,count=0;
    dfs(A,dp,i,res,count);
    cout<<res<<endl;
    // cout<<count<<endl;
}

signed main(){

    ios_base::sync_with_stdio(0);
       cin.tie(0);cout.tie(0);  


   
    int T=1;
    // cin>>T;
    while(T--)
        SoLvE();
    
    return 0;
}

/*
*/