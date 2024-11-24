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
int n;
cin>>n;
int arr[n][2];
rep(i,0,n){
    rep(j,0,2){
        cin>>arr[i][j];
    }
}
int leftsum=0;
int rightsum=0;
string s;
rep(i,0,n){
    int k=arr[i][0];
    int h=arr[i][1];
    
    if(k>h){
        rightsum+=h;
        if(rightsum-leftsum>=500){
            rightsum-=k;
            leftsum+=h;
            s.pb('A');
        }
        else{
        s.pb('G');
        }
    }
    else{
        leftsum+=k;
        if(leftsum-rightsum>=500){
            leftsum-=k;
            rightsum+=h;
            s.pb('G');
        }
        else{
        s.pb('A');
        }
    }

}
if(abs(leftsum-rightsum)<=500){
rep(i,0,s.length()){
    cout<<s[i];
}
}
else{
    cout<<"-1"<<endl;
}

    return 0;
}