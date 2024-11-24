#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
 
//10^5 * 30
int recursive(int arr[],vector <vector <int>>& dp,int i,int g,int& k,int& n){
    if(i==n){
        return 0;
    }
    if(dp[i][g]!=INT_MIN){
        return dp[i][g];
    }
 
    int op1=-1e9,op2=-1e9;
    int curr=arr[i]>>g;
    op1=curr-k+recursive(arr,dp,i+1,g,k,n);
    int news=min(30LL,g+1);
    curr=arr[i]>>news;  
    op2=curr+recursive(arr,dp,i+1,news,k,n);
 
    return dp[i][g]=max(op1,op2);
}
 
void func(){
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector <vector <int>> dp(n,vector <int> (31,INT_MIN));
    int i=0,g=0;
 
    cout<<recursive(arr,dp,i,g,k,n)<<endl;
}
signed main(){
    int t;
    cin>>t;
    while(t--){
        func();
    }
}