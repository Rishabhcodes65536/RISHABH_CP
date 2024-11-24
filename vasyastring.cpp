#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define endl "\n"

const int MOD2 = 998244353;
const int MOD1 = 1e9 + 7;
const int INF = 9e18; 
const int N=1e5+5;

int A1[N];
int A2[N];
int T1[4*N];
int T2[4*N];

void B1(int n,int s,int e){
    if(s==e){
        T1[n]=A1[s];
        return;
    }

    int m=(s+e)>>1;

    B1(2*n,s,m);
    B1(2*n+1,m+1,e);

    T1[n]=min(T1[2*n] , T1[2*n+1]);
}

void B2(int n,int s,int e){
    if(s==e){
        T2[n]=A2[s];
        return;
    }

    int m=(s+e)>>1;

    B2(2*n,s,m);
    B2(2*n+1,m+1,e);

    T2[n]=min(T2[2*n] , T2[2*n+1]);
}

int Q1(int n,int s,int e,int l,int h){
    if(s > h || e < l)
        return INT_MAX;
    
    if(l<=s && e<=h)
        return T1[n];

    int m=(s+e)>>1;
    
    int q1=Q1(2*n,s,m,l,h);
    int q2=Q1(2*n+1,m+1,e,l,h);

    return min(q1,q2);
}

int Q2(int n,int s,int e,int l,int h){
    if(s>h || e<l)
        return INT_MAX;
    
    if(l <= s && e <= h)
        return T2[n];

    int m=(s+e)>>1;
    int q1=Q2(2*n,s,m,l,h);
    int q2=Q2(2*n+1,m+1,e,l,h);

    return min(q1,q2);
}

void U1(int n,int s,int e,int i,int v){
    if(s==e){
        A1[s]=A1[s]+v;
        T1[n]=A1[s];
        return;
    }

    int m=(s+e)>>1;

    if(i<=m)
        U1(2*n,s,m,i,v);
    else
        U1(2*n+1,m+1,e,i,v);

    T1[n]=min(T1[2*n] , T1[2*n+1]);
}

void U2(int n,int s,int e,int i,int v){
    if(s==e){
        A2[s]=A2[s]+v;
        T2[n]=A2[s];
        return;
    }

    int m=(s+e)>>1;

    if(i<=m)
        U2(2*n,s,m,i,v);
    else
        U2(2*n+1,m+1,e,i,v);

    T2[n]=min(T2[2*n] , T2[2*n+1]);
}

void SOLVE(){
    int n;cin>>n; 
    int m;cin>>m;

    B1(1,0,n-1);
    B2(1,0,n-1);

    int t;
    while(m--){
        cin>>t;
        if(t==1){
            int x,y;
            cin>>x>>y;
            U1(1,0,n-1,--x,1);
            U2(1,0,n-1,--y,1);
        }else if(t==2){
            int x,y;
            cin>>x>>y;
            U1(1,0,n-1,--x,-1);
            U2(1,0,n-1,--y,-1);
        }else{
            int x1,x2,y1,y2;
            cin>>x1>>y1>>x2>>y2;
            if(Q1(1,0,n-1,--x1,--x2)!=0){
                cout<<"Yes"<<endl;
                continue;
            }else if(Q2(1,0,n-1,--y1,--y2)!=0){
                cout<<"Yes"<<endl;
                continue;
            }else{
                cout<<"No"<<endl;
            }
        } 
    }
}

signed main(){

    ios_base::sync_with_stdio(0);
      cin.tie(0);cout.tie(0);  

    #ifndef ONLINE_JUDGE
       freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
    #endif
      
        SOLVE();
   
    return 0;
}