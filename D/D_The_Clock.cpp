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
test
{
string s;
cin>>s;
int h_ten=s[0] - 48;
int h_unit=s[1] - 48;
int m_ten=s[3] - 48;
int m_unit=s[4] - 48;
//cout<<h_ten<<" "<<h_unit<<" "<<m_ten<<" "<<m_unit<<endl;
int inhour=10*h_ten+h_unit;
int inmin=10*m_ten+m_unit;
int temp_hr=inhour;
int temp_min=inmin;
int res=0;
int n;
cin>>n;
int minute=0;
int hour=0;
while(n>=60){
    n-=60;
    hour+=1;
}
minute=n;
//cout<<inhour<<" "<<inmin<<" "<<hour<<" "<<minute<<endl;
int ispalin(int , int);

if(ispalin(inhour,inmin)){
   res+=1;
}
temp_hr+=hour;
temp_min+=minute;
while(1){

    if(temp_min > 59){
        temp_min-=60;
        temp_hr+=1;
    }
    if(temp_hr>23){
        temp_hr-=24;
    }
      if(temp_hr == inhour && temp_min == inmin){
        break;
    }
    if(ispalin(temp_hr,temp_min)){
        res++;
    }
    if(res>=16){
        break;
    }
    temp_hr+=hour;
    temp_min+=minute;
 
}
cout<<res<<endl;
}
    return 0;
}


int ispalin(int a,int b){
    //cout<<a<<" palin "<<b<<endl;
    //cout<<a%10<<" "<<b/10<<" "<<b%10<<" "<<a/10<<endl;
    if(a%10==b/10 && b%10==a/10){
        //cout<<a%10<<" "<<b/10<<" "<<b%10<<" "<<a/10<<endl;
        return 1;
    }
    else{
        return 0;
    }
}