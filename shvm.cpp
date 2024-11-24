/*████████████████████████████████████████████████████████████████████████████████████
██████████████████████████████████████████████████████████████████████████████████████
███████████████████████████▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓▓▓╬╬╬╬╬╬▓███████████████████████
███████████████████████████▓███████▓▓╬╬╬╬╬╬╬╬╬╬╬╬▓███▓▓▓▓█▓╬╬╬▓███████████████████████
███████████████████████████████▓█████▓▓╬╬╬╬╬╬╬╬▓███▓╬╬╬╬╬╬╬▓╬╬▓███████████████████████
████████████████████████████▓▓▓▓╬╬▓█████╬╬╬╬╬╬███▓╬╬╬╬╬╬╬╬╬╬╬╬╬███████████████████████
███████████████████████████▓▓▓▓╬╬╬╬╬╬▓██╬╬╬╬╬╬▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
████████████████████████████▓▓▓╬╬╬╬╬╬╬▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
███████████████████████████▓█▓███████▓▓███▓╬╬╬╬╬╬▓███████▓╬╬╬╬▓███████████████████████
████████████████████████████████████████▓█▓╬╬╬╬╬▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬███████████████████████
███████████████████████████▓▓▓▓▓▓▓╬╬▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
████████████████████████████▓▓▓╬╬╬╬▓▓▓▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
███████████████████████████▓█▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
█████████████████████████████▓▓▓▓▓▓▓▓█▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████
█████████████████████████████▓▓▓▓▓▓▓██▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬████████████████████████
█████████████████████████████▓▓▓▓▓████▓▓▓█▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬████████████████████████
████████████████████████████▓█▓▓▓▓██▓▓▓▓██╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬████████████████████████
████████████████████████████▓▓███▓▓▓▓▓▓▓██▓╬╬╬╬╬╬╬╬╬╬╬╬█▓╬▓╬╬▓████████████████████████
█████████████████████████████▓███▓▓▓▓▓▓▓▓████▓▓╬╬╬╬╬╬╬█▓╬╬╬╬╬▓████████████████████████
█████████████████████████████▓▓█▓███▓▓▓████╬▓█▓▓╬╬╬▓▓█▓╬╬╬╬╬╬█████████████████████████
██████████████████████████████▓██▓███████▓╬╬╬▓▓╬▓▓██▓╬╬╬╬╬╬╬▓█████████████████████████
███████████████████████████████▓██▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬██████████████████████████
███████████████████████████████▓▓██▓▓▓▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓██████████████████████████
████████████████████████████████▓▓▓█████▓▓╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬╬▓███████████████████████████
█████████████████████████████████▓▓▓█▓▓▓▓▓███▓╬╬╬╬╬╬╬╬╬╬╬▓████████████████████████████
██████████████████████████████████▓▓▓█▓▓▓╬▓██╬╬╬╬╬╬╬╬╬╬╬▓█████████████████████████████
███████████████████████████████████▓▓█▓▓▓▓███▓╬╬╬╬╬╬╬╬╬▓██████████████████████████████
██████████████████████████████████████▓▓▓███▓▓╬╬╬╬╬╬╬╬████████████████████████████████
███████████████████████████████████████▓▓▓██▓▓╬╬╬╬╬╬▓█████████████████████████████████
██████████████████████████████████████████████████████████████████████████████████████
██*********************************SHIVAM-SIKOTRA*********************************██
██████████████████████████████████████████████████████████████████████████████████████*/
#include<bits/stdc++.h>
#define ll long long int
#define int ll 
#define st string
    
#define F(i,n) for(int i=0;i<n;i++)
#define Fe(i,en) for(int i=1;i<=en;i++)
#define Fab(i,a,b) for(int i=a;i<b;i++)
#define Fabe(i,a,b) for(int i=a;i<=b;i++)
#define Fa(i,v) for(auto i:v)
    
#define Fl(i,n) for(ll i=0;i<n;i++)
#define Fel(i,en) for(ll i=1;i<=en;i++)
#define Fabl(i,a,b) for(ll i=a;i<b;i++)
#define Fabel(i,a,b) for(ll i=a;i<=b;i++)
    
#define min3(a,b,c) min(a,(min(b,c)))
#define max3(a,b,c) max(a,(max(b,c)))
#define even(n) n%2 == 0
#define odd(n) n%2 != 0
    
#define vin vector<int>
#define vll vector<long long int>
#define vst vector<string>
#define vpii vector<pair<int,int>>
#define vpss vector<pair<st,st>>
#define vpll vector<pair<long long int,long long int>>
    
#define pii pair<int,int>
#define pss pair<st,st>
#define pcc pair<char,char>
#define psi pair<st,int>
#define pci pair<char,st>
#define pis pair<int,st>
#define pic pair<int,char>
    
#define mpii map<int,int>
#define mpci map<char,int>
#define mpsi map<st,int>
#define mpll map<ll,ll>
    
#define x first
#define y second
    
#define beg(v) v.begin()
#define rbeg(v) v.rbegin()
#define end(v) v.end()
#define rend(v) v.rend()
#define Rng(v) beg(v),end(v)
#define rRng(v) rbeg(v),rend(v)
#define addbeg(v,a) v.emplace(v.begin(),a)
#define addend(v,a) v.emplace_back(a)
#define clr(v) v.clear()
#define psh(v,n) v.push_back(n)
#define popv(v) v.pop_back()
#define pspair(v,a,b) v.push_back(make_pair(a,b))
#define LB(v,val) lower_bound(Rng(v),val) - beg(v)
#define UB(v,val) upper_bound(Rng(v),val) - beg(v)
    
#define ins(s,a) s.insert(a);
#define cnt(s,f) s.count(f);
    
void ip(int& n) {std::cin>>n;}
void ip(int& n,int& m) {std::cin>>n>>m;}
void ip(int& n,int& m,int& k) {std::cin>>n>>m>>k;}
void ip(int& n,int& m,int& k,int&l) {std::cin>>n>>m>>k>>l;}
#define pnt(string) cout<<string
#define pnt_bi(a,b) cout<<a<<" "<<b
#define pnt_tri(a,b,c) cout<<a<<" "<<b<<" "<<c
#define endl '\n' 
#define ce cout<<endl
    
#define init0(a) int a=0
#define init0_bi(a,b) int a=0,b=0
#define init0_tri(a,b,c) int a=0,b=0,c=0
    
#define PRE(v) partial_sum(Rng(v),v.begin())
#define SUM(v) accumulate(Rng(v),0)
#define MAX(v) *max_element(Rng(v))
#define MIN(v) *min_element(Rng(v))
    
#define DIN(v,n) vin v(n); F(i,n) cin>>v[i];
    
#define W while
#define inf INT_MAX
#define ninf INT_MIN
#define digs_in_no(n) (int)(log10(n)+1)
#define ret return
    
using namespace std;
void print(vin v)
{
    string space(1,' ');
    Fa(i,v)
        cout<<i<<space;
}
int n;
int func(vpii&v,int i,vin&dp,int state)
{
    if(i>=n) return 0;
    if(dp[i] != -1)  ret dp[i];
    
    int ans=INT_MIN;
    // Not Take
    ans=max(ans,func(v,i+1,dp,state));
    // Take
    if(v[i].x == 1)//Poisonous
    {
    ans=max(ans,func(v,i+1,dp,state-1)+v[i].y);
    }
    else
    {
    ans=max(ans,func(v,i+1,dp,2)+v[i].y);
    }
    return dp[i]=ans;
}  
signed main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ip(n);
    vpii v(n);
    F(i,n)
    {
        ip(v[i].x,v[i].y);
    }
    vin dp(n+1,-1);
    int op=func(v,0,dp,2);
    cout<<(op<0?-1:op);
}