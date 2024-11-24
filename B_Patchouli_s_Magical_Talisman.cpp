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
typedef vector<int> vi;
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
    int arr[n];
    int count0=0;
    inarr(a , n);
    sort(a , a+n);
    bool flag=1;
    vector <int> v;
    for(int j=0;j<n;++j){
        if(a[j]%2==0 && a[j]!=0){
            v.pb(a[j]);
            flag=0;
        }
        if(a[j]==0){
            count0++;
            flag=0;
        }
    }
    if(flag){
        cout<<"0"<<endl;
    continue;
    }
    sort(all(v));
    bool flagodd=false;
    for(int k=v.size()-1;k>=0;--k){
       int y=v[k]/2;
       if(y%2==1){
           flagodd=true;
       }
    }
    if(flagodd){
        cout<<v.size()<<endl;
        continue;
    }
     vi v2[32];
    rep(i,0,sz(v)){
        int count = 0;
        while((v[i]&1) == 0){
            v[i]=v[i]/2;
            count++;
        }
        v2[count].pb(1);
    }
    int c = 0,b = 0;
    rep(j,0,32){
        if(sz(v2[j])){
            c = sz(v2[j]);
            b = j;
            break;
        }
    }
     cout << b + sz(v) - 1 << endl;;
   
}
    return 0;
}