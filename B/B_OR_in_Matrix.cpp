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
int r,c;
cin>>r>>c;
 vector<vector<int>> arr;
 vector<vector<int>> res( r , vector<int> (c, 1));
 rep(i,0,r){
     vector <int> temp;
    rep(j,0,c){
        int tem;
        cin>>tem;
        temp.pb(tem);
    }
    arr.pb(temp);
 }
 rep(i,0,r){
    rep(j,0,c){
        if(arr[i][j]==0){
            rep(l,0,r){
                res[l][j]=0;
            }
            rep(m,0,c){
                res[i][m]=0;
            }
        }
    }
 }
 rep(i,0,r){
    rep(j,0,c){
        if(arr[i][j]==1){
            bool flag=0;
            rep(l,0,r){
                if(res[l][j]){
                    flag=1;
                }
            }
            rep(m,0,c){
                if(res[i][m]){
                    flag=1;
                }
            }
            if(!flag){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
 }
 cout<<"YES"<<endl;
 rep(i,0,r){
    rep(j,0,c){
        cout<<res[i][j]<<" ";
    }
    cout<<endl;
 }
 
    return 0;
}