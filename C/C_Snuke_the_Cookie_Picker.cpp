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
int n,m;
vst v;
inline bool isvalid(int i,int j)
    {ret (i>=0 && j>=0 && i<n && j<m);}
inline bool isborder(int i,int j){
    ret (i==0 || j==0 || i==n-1 || j==m-1);
}
int dir[5]={-1,0,1,0,-1};
bool check(int i,int j)
{
    int c(0);
    if(!isvalid(i,j)) ret 0;
    for(int op=0;op<4;op++){
        int x=i+dir[op];
        int y=j+dir[op+1];
        if(isvalid(x,y)){
            if(v[x][y] =='.'){
                c++;
            }
            if(c>1) ret 0;            
        }
    }
    ret 1;
}
    
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ip(n,m);
    v.resize(n);
    bool f(0);
    F(i,n)
        cin>>v[i];
    F(i,n)
    {
        F(j,m)
        {
            if(v[i][j] =='.')
            {
                if(check(i,j)){
                    cout<<(i+1)<<" "<<(j+1);
                    return 0;
                }
            }
        }
        
    }
    
    
}