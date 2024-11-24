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
#define test int t; cin>>t; while(t--)
#define SUMI0(a)   accumulate(a , a+n ,0)
#define MAX(v)    *max_element((v).begin(),(v).end())
#define MINI(v)   *min_element((v).begin(),(v).end()) 
#define PI atan(1)*4
#define f(i,n) for(int i = 0; i < n; i++)
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//cout << fixed << setprecision(9);
int arr[30];
int res=0;
int mini=INT_MAX;
rep(i,0,26){
    cin>>arr[i];
    if(arr[i]<mini){
        mini=arr[i];
    }
}
//int mini=*min_element(arr , arr+26);
string s;
cin>>s;
sort(s.begin(),s.end());
map<int,int> map1;
int sum=0;
rep(i,0,s.size()){
    int c;
    c=s[i] - 'a';
    sum+=arr[c];
    map1[c]+=(arr[c]-mini);
}
int maxi=-INT_MAX;
for(auto x:map1){
    int y=x.second;
    if(y>maxi){
        maxi=y;
    }
}


// for(auto it1 : map1){
//     cout<<it1.first<<" "<<it1.second<<endl;
// }
// vector <int> v;
// int maxi=-1;
// int ans=0;
// int yu=0;
// for(auto it:map1){
//     int k=it.second * (arr[(it.first)]);
//     // int y=k-(mini * it.second);
//     // if(y>maxi){
//     //     ans=(mini*it.second);
//     //     yu=k;
//     //     maxi=y;
//     // }
//     v.pb(k);
// }

// for(auto h:v){
//     cout<<h<<" ";
// }
// cout<<endl;
//int res=accumulate(v.begin(),v.end(),0);
//cout<<res<<" "<<mini<<" "<<maxi<<endl;
res=sum-maxi;
cout<<res<<endl;
//v.clear();

    return 0;
}