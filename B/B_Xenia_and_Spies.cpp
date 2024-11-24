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
int n,m,s,f;
cin>>n>>m>>s>>f;
int current =s;
string ans;
bool flag=0;
int z=1;
vector<pair<int,pair<int,int>>> input;
rep(i,0,m){
int a,b,c;
cin>>a>>b>>c;
input.pb({a,{b,c}});
}
if(s<f){
    int final=s+1;
    //cout<<"HI"<<endl;
    int ti,l,r;
    rep(i,0,m){
        ti=input[i].first;
        l=input[i].second.first;
        r=input[i].second.second;
        if(ti!=z){
            cout<<ti<<" "<<z<<endl;
            cout<<'R';
            //current++;
            //final++;
        }
        else if(l<=current && r>=current || l<=final &&  r>=final){
            //cout<<l<<r<<"hi"<<endl;
                cout<<'R';
                current++;
                final++;
        }
            else{
            cout<<'X';
            }
        
      
        if(current==f){
            flag=1;
            break;
        }
        z++;
    }
  
}
else{
    int final=s-1;
    int ti,l,r;
    rep(i,0,m){
        ti=input[i].first;
        l=input[i].second.first;
        r=input[i].second.second;
        // 5 3
        //cout<<current<<" "<<final<<" "<<l<<" "<<r<<endl;
         if(ti!=z){
            cout<<'L';
            z--;
            //current--;
            //final--;
        }
        else if(l<=current && r>=current || l<=final &&  r>=final){
            cout<<'X';
        }
        else{
            cout<<'L';
            current--;
            final--;
        }
        if(current==f){
            flag=1;
            break;
        }
    }
}
// for(int i=0;i<ans.length();++i){
//     cout<<ans[i];
// }
// cout<<endl;
    return 0;
}