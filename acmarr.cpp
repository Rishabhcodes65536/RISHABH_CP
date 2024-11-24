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
// while(t--)
// {
// }
int n;
cin>>n;
int a[n],b[n];
for(int i=1;i<=n;++i){
    cin>>a[i];
}
for(int i=1;i<=n;++i){
    cin>>b[i];
}
pair<int,int> p_array[n];
pair<int,int> p1_array[n];
map<int,int> m1;
map<int,int> m2;
rep(i,1,n+1){
    m1[a[i]]=i;
}
rep(i,1,n+1){
    // p1_array[i]={i,b[i]};
    m2[b[i]]=i;
}
map<int,int> m;
map<int,int> m3;
rep(i,1,n+1){
    int k=m1[i]-m2[i];
    if(k<0){
        m3[k]+=1;
        k+=n;
    }
    else{
        m3[k-n]+=1;
    }
    m[k]++;
}
int maxi=-INT64_MAX;

for(auto &i :m){
    int g=i.second;
    maxi=max(g,maxi);
}
for(auto &y :m3){
    int g=y.second;
    maxi=max(g,maxi);
}
cout<<maxi<<endl;

    return 0;
}