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
// || abs(x1-x2)==4 && abs(y1-y2)==4
test
{
int x1,y1,x2,y2;
cin>>x1>>y1>>x2>>y2;
int g=(x1+y1)%2;
set <pair<int,int>> set1;
set <pair<int,int>> set2;
    if(x1+2<=8 && y1+1<=8){
    set1.insert({x1+2,y1+1});
    }
    if(x1+2<=8 && y1-1>0){
    set1.insert({x1+2,y1-1});
    }
    if(x1-2>0 && y1+1<=8){
    set1.insert({x1-2,y1+1});
    }
    if(x1-2>0 && y1-1>0){
    set1.insert({x1-2,y1-1});
    }
    if(x1+1<=8 && y1+2<=8){
    set1.insert({x1+1,y1+2});
    }
    if(x1+1<=8 && y1-2>0){
    set1.insert({x1+1,y1-2});
    }
    if(x1-1>0 && y1+2<=8){
    set1.insert({x1-1,y1+2});
    }
    if(x1-1>0 && y1-2>0){
    set1.insert({x1-1,y1-2});
    }
  

    if(x2+2<=8 && y2+1<=8){
    set2.insert({x2+2,y2+1});
    }
    if(x2+2<=8 && y2-1>0){
    set2.insert({x2+2,y2-1});
    }
    if(x2-2>0 && y2+1<=8){
    set2.insert({x2-2,y2+1});
    }
     if(x2-2>0 && y2-1>0){
    set2.insert({x2-2,y2-1});
     }
    if(x2+1<=8 && y2+2<=8){
    set2.insert({x2+1,y2+2});
    }
    if(x2+1<=8 && y2-2>0){
    set2.insert({x2+1,y2-2});
    }
    if(x2-1>0 && y2+2<=8){
    set2.insert({x2-1,y2+2});
    }
    if(x2-1>0 && y2-2>0){
    set2.insert({x2-1,y2-2});
    }
    vector <int> s3;
    bool flag=false;
    // for(auto it:set1){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    // for(auto it:set2){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    for(auto it:set1){
        for(auto it1 : set2){
            if(it.ff==it1.ff && it.ss==it1.ss && it.ff>=1 && it.ff<=8 && it1.ff>=1 && it1.ss<=8){
                flag=true;
            }
        }
    }
    if(!flag){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
}
return 0;
}

// 