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
//int t;
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
int n,b;
cin>>n>>b; 
//int a[n];
inarr(a,n);
int max_1=b ;
rep(i,0,n-1){
    if(b>=a[i]){
    int k=b/a[i];
    int y=b%a[i];
    long long ele=*max_element(a+i+1,a+n);
    int bourle=k*ele+y;
    max_1=max(bourle,max_1);
    }

}
cout<<max_1<<endl;

}