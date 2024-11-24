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
cin>>t;
while(t--)
{
    int n;
    cin>>n;
    int a[n];
    int b[n];
    rep(i,0,n){
        cin>>a[i];
    }
    rep(i,0,n){
        cin>>b[i];
    }
    int diff[n];
    bool flag=0;
    rep(i,0,n){
    diff[i]=a[i]-b[i];
    if(diff[i]<0){
        flag=1;
    }
    }
     if(flag){
     cout<<"NO"<<endl;   
    }
    else{
    int max=*max_element(diff, diff+n);
    rep(i,0,n){
        if(a[i]-max>0){
            a[i]=a[i]-max;
        }
        else{
            a[i]=0;
        }
    }
    bool flag1=1;
    rep(i,0,n){
        if(a[i]!=b[i]){
            flag1=0;
        }
    }
    
    if(flag1){
        cout<<"YES"<<endl;
    }
    else{
        // rep(i,0,n){
        //     cout<<a[i]<<" ";
        // }
        // cout<<endl;
        // rep(i,0,n){
        //     cout<<diff[i]<<" ";
        // }
        // cout<<endl;
        
        cout<<"NO"<<endl;
    }
    }
}
    return 0;
}