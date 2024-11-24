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
int n,m;
cin>>n>>m;
vector <int> v(n+1,0);
while(m--){
    int r,b,g;
    cin>>r>>b>>g;
    set <int> temp;
    temp.insert(v[r]);
    temp.insert(v[b]);
    temp.insert(v[g]);
    vector <int> mehnat(4,0);
    mehnat[1]=r;
    mehnat[2]=b;
    mehnat[3]=g;
    rep(i,1,4){
        if(v[mehnat[i]]==0){
        rep(j,1,4){
            if(temp.find(j)==temp.end()){
                v[mehnat[i]]=j;
                temp.insert(j);
                break;
            }
        }
        }
    }
        
}
rep(i,1,n+1){
    cout<<max(v[i],1LL)<<" ";
}
cout<<endl;
    return 0;
}

//set 0 0 0
//s.find(i)->1 null rahega to s[r]->1 s.insert(1);
//s.find(i)->2 