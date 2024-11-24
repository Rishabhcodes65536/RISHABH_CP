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
    int n,k;
    cin>>n>>k;
    int countb=0,countw=0,res=INT_MAX;
    string s;
    cin>>s;
    int j=0;
    rep(i,0,k){ 
        if(s[i]=='B'){
            countb++;
        }
        else{
            countw++;
        }
    }
    res=min(res,countw);
    rep(i,k,n){
        if(s[i]=='B'){
            countb++;
        }
        else{
            countw++;
        }
        if(s[i-k]=='B'){
            countb--;
        }
        else{
            countw--;
        }
        res=min(res,countw);
    }
   
   cout<<res<<endl;
}
    return 0;
}