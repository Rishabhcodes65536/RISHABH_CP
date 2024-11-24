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
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
#define f(i,n) for(int i = 0; i < n; i++)
int countDivisors(int n)
{
int cnt = 0;
for (int i = 1; i <= sqrt(n); i++) {
 if (n % i == 0) {
 if (n / i == i)
  cnt++;
else // Otherwise count both
cnt = cnt + 2;
}
 }
return cnt;
}
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//cout << fixed << setprecision(9);
test
{
int n;
cin>>n;
inarr(a,n);
int andi=a[0];
int ordi=a[0];
rep(i,0,n){
andi&=a[i];
ordi|=a[i];
}
int xordi=andi ^ ordi;
int res=0;
if(xordi==0){
    cout<<"0"<<endl;
    continue;
}
else{
    
    rep(i,0,64){
     int e= xordi>>i;
    //  cout<<j<<endl;
    // }
    int count1=0,count0=0;
    if(e&1){
    rep(j,0,n){
        int x=a[j]>>i;
        if(x&1){
            count1++;
        }
        else{
            count0++;
        }
    }
    //cout<<count0<<" "<<count1<<" "<<i<<endl;
    res+=min(count1,count0);
    }

// //cout<<count0to1<<" "<<count1to0<<endl;
// cout<<min(count1to0,count0to1)<<endl;
}
cout<<res<<endl;
}
}

    return 0;
}

//0 0 1 0
//0 0 0 1
//0 0 0 1
//0 0 1 1
//0 0 1 0
//0 1 0 0 

//1 0 1 0 1 1
//1 0 1 0 1 1
//1 0 1 0 1 1
//1 0 1 0 1 1
//1 0 1 0 1 1
//1 0 1 0 1 1
//1 0 1 0 1 1
//1 0 1 0 0 1
//1 0 1 0 1 0
//1 0 1 1 0 0