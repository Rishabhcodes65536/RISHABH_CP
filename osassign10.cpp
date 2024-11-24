#include<bits/stdc++.h>
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> indexed_set;
#define endl              '\n'
#define ff                first
#define ss                second
#define pb                emplace_back
#define ppb               pop_back
// #define int               long long
#define float             long double
#define lb                lower_bound
#define ub                upper_bound
#define sz(x)             (int)(x).size()
#define ppc               __builtin_popcountll
#define all(x)            (x).begin(), (x).end()
#define rall(x)           (x).rbegin(), (x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define per(i,a,b)        for(int i=(a);i>=(b);i--)
#define invec(a,n)        vector<int>a(n); rep(i,0,n) cin>>a[i]
#define inarr(a,n)        int a[n]; rep(i,0,n) cin>>a[i]
#define in(k,a) for(auto k : a)
#define disp(a) in(k,a){ cout<<k<<' ';} cout<<endl
const int M=1e9+7;
#define test int t; cin>>t; while(t--)
#define SUMARR(a)   accumulate(a , a+n ,0LL)
#define SUM(v)      accumulate(all(v),0LL)
#define MAXIARR(a,n)  *max_element(a , a+n)
#define MINIARR(a,n)  *min_element(a , a+n)
#define MAX(v)      *max_element((v).begin(),(v).end())
#define MINI(v)     *min_element((v).begin(),(v).end()) 
#define PRESUM(a)    partial_sum(a.begin(),a.end(),a.begin())
#define PI           atan(1)*4
#define INF          INT64_MAX
#define fbo(x)       find_by_order(x)
#define ook(x)       order_of_key(x)
#define out(x)       cout<<x<<endl;
bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
#define f(i,n) for(int i = 0; i < n; i++)
/////खुदी को कर बुलंद इतना के हर तकदीर से पहले खुदा बन्दे से खुद पूछे के बता तेरी रज़ा क्या है;/////
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
int digitsSum(int n) {
int ans = 0;
while(n != 0) {
ans += n%10;
n /= 10;
}
return ans;
}
int binpow(int a, int b, int m){
//take INF if no Modulo
int ans = 1;
while(b>0){
if(b&1){
ans *= a;
if(ans > m) ans %= m;
}
a *= a;
if(a > m) a %= m;
b>>=1;
}
return ans;
}
int inv_mod(int b,int mod){
return binpow(b,mod-2,mod)%mod;
}
const int32_t N = 3e5 + 10;
int FLOOR(const int a, const int b) { if (a > 0 || a % b == 0) return a / b; return (a / b - 1); }
int CEIL(const int a, const int b) {return (a + b - 1) / b;}
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int POW(int a, int b) { return b == 0 ? 1 : a * POW(a, b - 1); }
int mod_exp(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res % mod; }
int mod_mul(int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub(int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int extended_gcd(int a, int b, int &x, int &y) {if (b == 0) {x = 1; y = 0; return x; } int gcd = extended_gcd(b, a % b, y, x); y -= x * (a / b); return gcd; }
int mod_inv(int a, int b) {int r1, r2; int gcd = extended_gcd(a, b, r1, r2); assert(gcd == 1); return r1; }
int mod_div(int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mod_inv(b, m), m) + m) % m;}

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
// #define SUM(v) accumulate(Rng(v),0)
// #define MAX(v) *max_element(Rng(v))
#define MIN(v) *min_element(Rng(v))

#define DIN(v,n) vin v(n); F(i,n) cin>>v[i];

#define W while
#define digs_in_no(n) (int)(log10(n)+1)
#define ret return

using namespace std;
void print(vin v)
{
    string space(1,' ');
    Fa(i,v)
        cout<<i<<space;
}
int pp,n,seq_size;//n->No. of Tracks
int getclosest(vector<int>v,int k)
{
    int s=0,e=v.size()-1,mid,y=v[0];
    while(s<=e)
    {
        mid=s+(e-s)/2;
        if(v[mid]==k)return v[mid];
        if(abs(k-v[mid]) < abs(k-y)) y=v[mid];
        if(v[mid]<k) s=mid+1;
        else if(v[mid]>k) e=mid-1;
    }
    return y;
}
void FirstComeFirstServe(vin v,int pp)
{
    vin sequ=v;
    int hm(0),tm(0);
    char m='a';int ip=pp;
    F(i,v.size())
    {
        if(pp<v[i] && m!='r') m='r',hm++;
        else if(pp>v[i] && m!='l') m='l',hm++;
        tm+=(abs(v[i]-pp));
        pp=v[i];
    }
    addbeg(sequ,ip);
    cout<<"Sequence of movement would be : ";print(v);ce;
    cout<<"Track Movements is : "<<tm;ce;
    cout<<"Head Movements is: "<<hm;
    ce;
}
void ShortestSeekTimeFirst(vin v,int pp)
{
    vin t=v;sort(Rng(t));
    vin sequ;

    int hm(0),tm(0);
    char m='a';
    int ip=pp;
    while(sequ.size()!=v.size())
    {
        int gc=getclosest(t,pp);
        t.erase(find(Rng(t),gc));
        if(pp< gc && m!='r') m='r',hm++;
        else if(pp>gc && m!='l') m='l',hm++;
        tm+=(abs(gc-pp));
        pp=gc;
        psh(sequ,gc);
    }
    addbeg(sequ,ip);
    cout<<"Movement Sequence : ";print(sequ);ce;
    cout<<"Track Movements : "<<tm;ce;
    cout<<"Head Movements : "<<hm;
    ce;
}

void scan(vin v,int pp)
{
    int dir;
    cout<<"Enter Direction(1 for Larger and any key for Smaller) : ";cin>>dir;

    vin t=v;sort(Rng(t));
    vin sequ;
    int hm(1),tm(0);
    int ip=pp,ind;
    ind=UB(t,pp);

    if(dir==1)
    {
        Fab(i,ind,t.size())
        {
            psh(sequ,t[i]);
        }
        t.erase(beg(t)+ind,end(t));
        tm+=(n-ip-1);
        pp=n-1;
        if(!t.empty())
        {
            hm++;
            int ss=t.size();
            for(int i=ss-1;i>=0;i--)
            {
                psh(sequ,t[i]);
                tm+=(abs(pp-t[i]));
                pp=t[i];
            }
        }
    }
    else
    {
        for(int i=ind-1;i>=0;i--)
        {
            psh(sequ,t[i]);
            // t.erase(beg(t)+i);
        }
        t.erase(beg(v),beg(v)+ind);
        tm+=(ip);
        pp=0;
        if(!t.empty())
        {
            hm++;
            for(int i=0;i<t.size();i++)
            {
                psh(sequ,t[i]);
                tm+=(abs(pp-t[i]));
                pp=t[i];
            }
        }

    }
    addbeg(sequ,ip);
    cout<<"Movement Sequence : ";print(sequ);ce;
    cout<<"Track Movements : "<<tm;ce;
    cout<<"Head Movements : "<<hm;
    ce;
}

void look(vin v,int pp)
{
    int dir;
    cout<<"Enter Direction(1 for Larger and any key for Smaller) : ";cin>>dir;

    vin t=v;sort(Rng(t));
    vin sequ;
    int hm(1),tm(0);
    int ip=pp,ind;
    ind=UB(t,pp);
    ce;print(t);ce;pnt(ind);ce;

    if(dir==1)
    {
        Fab(i,ind,t.size())
        {
            psh(sequ,t[i]);
        }
        tm+=abs(t[t.size()-1]-ip);
        pp=t[t.size()-1];
        t.erase(beg(t)+ind,end(t));
        if(!t.empty())
        {
            hm++;
            int ss=t.size();
            for(int i=ss-1;i>=0;i--)
            {
                psh(sequ,t[i]);
                tm+=(abs(pp-t[i]));
                pp=t[i];
            }
        }
    }
    else
    {
        int si=t.size(),x;
        for(int i=ind-1;i>=0;i--)
        {
            psh(sequ,t[i]);
        }
        pp=t[0];
        tm+=abs(ip-t[0]);
        x=si-ind;
        if(x)
        {
            hm++;
            for(int i=ind;i<t.size();i++)
            {
                psh(sequ,t[i]);
                tm+=(abs(pp-t[i]));
                pp=t[i];
            }
        }

    }
    addbeg(sequ,ip);
    cout<<"Movement Sequence : ";print(sequ);ce;
    cout<<"Track Movements : "<<tm;ce;
    cout<<"Head Movements : "<<hm;
    ce;
}

void cscan(vin v,int pp)
{
    char dir;
    cout<<"Enter Direction(l for Larger and s for Smaller) : ";cin>>dir;

    vin t=v;sort(Rng(t));
    vin sequ;
    int hm(1),tm(0);
    int ip=pp,ind;
    ind=UB(t,pp);
    // ce;print(t);ce;pnt(ind);ce;

    if(dir=='l')
    {
        Fab(i,ind,t.size())
        {
            psh(sequ,t[i]);
        }
        tm+=abs(2*(n-1)-ip);
        pp=0;
        t.erase(beg(t)+ind,end(t));
        if(!t.empty())
        {
            hm++;
            int ss=t.size();
            for(int i=0;i<ss;i++)
            {
                psh(sequ,t[i]);
                tm+=(abs(pp-t[i]));
                pp=t[i];
            }
        }
    }
    else
    {
        int si=t.size(),x;
        for(int i=ind-1;i>=0;i--)
        {
            psh(sequ,t[i]);
        }
        pp=n-1;
        tm+=abs(ip+n-1);
        x=si-ind;
        if(x)
        {
            hm++;
            for(int i=si-1;i>=ind;i--)
            {
                psh(sequ,t[i]);
                tm+=(abs(pp-t[i]));
                pp=t[i];
            }
        }

    }
    addbeg(sequ,ip);
    cout<<"Movement Sequence : ";print(sequ);ce;
    cout<<"Track Movements : "<<tm;ce;
    cout<<"Head Movements : "<<hm;
    ce;
}

void clook(vin v,int pp)
{
    int dir;
    cout<<"Enter Direction(1 for Larger and 0 for Smaller) : ";cin>>dir;

    vin t=v;sort(Rng(t));
    vin sequ;
    int hm(1),tm(0);
    int ip=pp,ind;
    ind=UB(t,pp);
    // ce;print(t);ce;pnt(ind);ce;

    if(dir==1)
    {
        Fab(i,ind,t.size())
        {
            psh(sequ,t[i]);
        }
        tm+=abs((2*t[t.size()-1])-ip-t[0]);
        pp=t[0];
        t.erase(beg(t)+ind,end(t));
        if(!t.empty())
        {
            hm++;
            int ss=t.size();
            for(int i=0;i<ss;i++)
            {
                psh(sequ,t[i]);
                tm+=(abs(pp-t[i]));
                pp=t[i];
            }
        }
    }
    else
    {
        int si=t.size(),x;
        for(int i=ind-1;i>=0;i--)
        {
            psh(sequ,t[i]);
        }
        pp=t[si-1];
        tm+=abs(ip-t[0]+t[si-1]-t[0]);
        x=si-ind;
        if(x)
        {
            hm++;
            for(int i=si-1;i>=ind;i--)
            {
                psh(sequ,t[i]);
                tm+=(abs(pp-t[i]));
                pp=t[i];
            }
        }

    }
    addbeg(sequ,ip);
    cout<<"Movement Sequence : ";print(sequ);ce;
    cout<<"Track Movements : "<<tm;ce;
    cout<<"Head Movements : "<<hm;
    ce;
}

int main()
{
    cout<<"<-----Enter thr total number of tracks -----> : ";
    
    int n;
    cin>>n;

    cout<<"<-----Please enter the current position of track-----> : ";
    int pp;
    cin>>pp;


    if(pp>=n){
    cout<<"\nPlease Enter Valid Track Position.Total tracks--> "<<n<<" tracks";ce;
    }

    cout<<"Enter Number of Sequences : ";
    int seq_size;
    cin>>seq_size;

    cout<<"Now , Enter Sequences : ";ce;
    invec(seq,seq_size);
    int ch;
    choice:
    cout<<"----------------------------------------------------------------------"<<endl;
    cout<<"Enter a choice you want to enter for scheduling algorithm: "<<endl<<"1)FirstComeFirstServe"<<endl<<"2)ShortestSeekTimeFirst"<<endl<<"3)scan"<<endl<<"4)look"<<endl<<"5)cscan"<<endl<<"6)clook"<<endl<<"7)-1 for exit"<<endl;
      cout<<"----------------------------------------------------------------------"<<endl;
      cin>>ch;
     switch(ch)
     {
     case 1:
         FirstComeFirstServe(seq,pp);goto choice;break;
     case 2:
        ShortestSeekTimeFirst(seq,pp); goto choice;break;
     case 3:
        scan(seq,pp); goto choice;break;
     case 4:
        look(seq,pp); goto choice;break;
     case 5:
        cscan(seq,pp); goto choice;break;
     case 6:
        clook(seq,pp); goto choice;break;
     case 7:
        exit(0);
     default:
         cout<<"Invalid choice"<<endl; goto choice;

     }
}

//25 90 33 45 4