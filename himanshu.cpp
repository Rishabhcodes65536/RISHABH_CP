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
#define PI atan(1)*4
signed main(){
int t;
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
//int n,k;
//string s
//array arr[n]
//char arr[n]
//cout << fixed << setprecision(9);
// cin>>t;
// while(t--)
// {
// //int n;
// //cin>>n;
// }
// 8 10 15 2 3 107
// 100 200 100 200 100 200 100 100

// You can rearrange tickets in a following way: 100,100,200,200,100,200,100,100
// and the total contribution from the first 6 
// tickets is equal to 100⋅0+100⋅0.1+200⋅0.15+200⋅0.1+100⋅0+200⋅0.25=10+30+20+50=110.
   int n,x,y,a,b,k;
   cin>>n>>x>>y>>a>>b>>k;
   int arr[n];
   map <int,vector<int>> map;
   int D=(a*b)/(__gcd(a,b));
   if(x>y){
    int t;
    t=x;
    x=y;
    y=t;
    int t2;
    t2=a;
    a=b;
    b=t2;
   }
   int countai=0,countbi=0,countci=0;
   rep(i,1,n+1){
    cin>>arr[i];
    if(i%a==0 && i%(D)!=0){
       //cout<<i<<" WEEEEEEEE"<<endl;
       countai++;
       map[i]=vector<int>({countai,countbi,countci});
   }
   if(i%b==0 && i%(D)!=0){
    //cout<<i<<" BEEEEEEEE"<<endl;
    countbi++;
    map[i]=vector<int>({countai,countbi,countci});
   }
    if(i%(D)==0){
    //cout<<i<<" LEEEEEEEE"<<endl;
    countci++;
    map[i]=vector<int>({countai,countbi,countci});
   }

   }
   //cout<<D<<endl;
   sort(arr +1 , arr+n+1);
   for(auto h : map){
    int X=h.second[0];
    int Y=h.second[1];
    int Z=h.second[2];
    //cout<<y<<" "<<u<<" "<<l<<endl;
    int res=0;
    int u=n,v,w;
    for(u=n;u>n-Z;--u){
    res+=(arr[u]/100)*(x+y);
    //cout<<"HI "<<u<<" array value= "<<arr[u]<< " RES= " <<res<<endl;
    }
    v=n-Z;
    for(v;v>n-Y-Z;--v){
    res+=(arr[v]/100)*(y);
    //cout<<"GI "<<v<<" array value= "<<arr[v]<<" RES= "<<res<<endl;
    }
    w=n-(Y+Z);
    for(w;w>n-Y-Z-X;--w){
    res+=(arr[w]/100)*(x);
    //cout<<"LI "<<w<<" array value= "<<arr[w]<<" RES= "<<res<<endl;
    }
    //cout<<res<<endl;
    if(res>=k){
        cout<<h.first<<endl;
        return 0;
    }
   }
   cout<<"-1"<<endl;
   return 0;
}
