#include<bits/stdc++.h>
#define rep(i,a,b)        for(int i=a;i<b;i++)
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
#define PI           atan(1)*4
#define INF          INT64_MAX
#define fbo(x)       find_by_order(x)
#define ook(x)       order_of_key(x)
#define out(x)       cout<<x<<endl;
// bool sortbysec(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
#define f(i,n) for(int i = 0; i < n; i++)


using namespace std;
    
int main() {
    
    int numberofprocess,logicaladdressspace,physicaladdressspace,framesize,pagesize;
    map<int,int> entries;

    cout<<"ENTER Logical Adress space  & Physical Address Space : "<<endl;
    cin>>logicaladdressspace>>physicaladdressspace;

    cout<<"ENTER PAGE SIZE : ";
    cin>>pagesize;
    cout<<endl;

    framesize=pagesize;
    cout<<"FRAME SIZE : "<<framesize;
    cout<<endl;

    int numberofpages=logicaladdressspace/pagesize;
    int noframes=physicaladdressspace/framesize;
    cout<<endl;

    cout<<"NO. OF PAGES ARE :"<<numberofpages<<"(0-"<<numberofpages-1<<")"<<endl;

    cout<<"NO. OF FRAMES ARE :"<<noframes<<"(0-"<<noframes-1<<")"<<endl;

    cout<<"ENTER NUMBER OF PROCESSES : ";
    cin>>numberofprocess;

    vector<vector<int>> v(numberofprocess);

    int c=noframes;

    for(int i=0;i<numberofprocess;i++){
        int pg4prcs;
        cout<<"ENTER NO. OF FRAMES FOR PROCESS -> "<<i+1<<"(AVAILABLE FRAMES :"<<c<<") : ";

        above:

        cin>>pg4prcs;
        c-=pg4prcs;
        
        if(c<0)
        {
            cout<<'\n';
            cout<<"MEMORY IS FULL";
            cout<<'\n';
            cout<<"PLEASE ENTER AGAIN FOR THE PROCESS "<<i+1<<" : ";
            c+=pg4prcs;
            goto above;
        }

        cout<<'\n';
        cout<<"ENTER PAGETABLE FOR PROCESS"<<i+1<<" : ";

            for(int j=0;j<pg4prcs;j++)
            {
                int x;
                cin>>x;
                entries[x]=1;
                v[i].push_back(x);
            }

        cout<<'\n';
        cout<<"-> PAGE-TABLE FOR PROCESS "<<i+1<<" <-";
        cout<<'\n';
        cout<<"PAGE NO.\t FRAME NO.";
        cout<<'\n';

            for(int j=0;j<pg4prcs;j++)
                cout<<"  "<<j<<"\t\t  "<<v[i][j]<<endl;
        
        cout<<'\n';
    }

    int prcsno,pgno,offset;

    while(1){
        abv:
        cout<<endl;
        cout<<"ENTER LOGICAL ADDRESS FOR CONVERTING TO PHYSICAL ADDRESS,";
        cout<<endl;
        cout<<"ENTER PROCESS NUMBER , PAGE NO. , OFFSET :";

        cin>>prcsno>>pgno>>offset;

        if(prcsno > numberofprocess){
            cout<<"PLEASE ENTER VALID PROCESS NO.,\n PROGRAM HAS ONLY"<<numberofprocess<<" PROCESSES ";cout<<endl;
            goto abv;
        }
    
        if(pgno >= v[prcsno-1].size()) {
            cout<<"PLEASE ENTER VALID PAGE NO.,\n PROGRAM HAS ONLY "<<v[prcsno-1].size()<<" PAGES";cout<<endl;
            goto abv;
        }
   
        string ans;
        ans+=to_string(v[prcsno-1][pgno]);
        ans+=to_string(offset);

        cout<<endl;
        cout<<"THE PHYSICAL ADDRESS IS --> "<<ans;
        cout<<endl;

        int what_to_do;
        cout<<"PRESS 0 FOR EXIT OR 1 FOR CONTINUE: ";
        cin>>what_to_do;

        if(!what_to_do) 
            exit(0);
    }
}