#include<bits/stdc++.h>
#include<cmath>
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
cin>>t;
cout << fixed << setprecision(9);
while(t--)
{
    int n;
    cin>>n;
    long double pi= 3.141592653589793238;
    std::cout << std::setprecision(9);
    long double l=(tan(pi/(2*n)));
    long double j=1.0/l;
    cout<<j<<endl;
}
    return 0;
}


//19 18 0 
//17 17 
//15 16
//14 14 
//12 13
//11 11
//9 10
//8 8
//6 7
//5 5
//3 4
//2 2
//0 1

//3 10 
//2 8
//1 6
//0 4