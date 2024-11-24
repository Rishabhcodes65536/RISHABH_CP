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
while(t>0)
{
    int n;
    cin>>n;
     int y=log2(n)+1;
     bool flag1=true,flag0=true;
     int num=0;
     if(n==1){
         cout<<"3"<<endl;
         t--;
         continue;
     }
     double h=log2(n);
     bool flag=false;
     if(h==(int)h){
         flag=true;
     }
     int res=0,count=0;
    // Size of an integer is assumed to be 32 bits
    while(n>0){
        int k=n%2;
        if(k==1){
            res+=pow(2,count);
            break;
        }
        n/=2;
        count++;
    }
    if(flag){
        res+=1;
    }
    cout<<res<<endl;
    t--;
    //0 1 0 1
    //0 0 1 0 
    //0 0 1 0
}
    return 0;
}
