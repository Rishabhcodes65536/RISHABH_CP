#include<bits/stdc++.h>
#define int long long
using namespace std;

int check(int v[],int capacity,int n){
        int days=1,load=0;
        for(int i=0;i<n;i++){
            if(v[i]+load>capacity){
                days++;
                load=v[i];
            }
            else{
                load+=v[i];
            }
        }
        return days;
}


void dosomething(){
int n,days;
cin>>n>>days;
int v[n];
for(int i=0;i<n;i++){
    cin>>v[i];
}

int a=*max_element(v,v+n);
int b=accumulate(v,v+n,0LL);
for(int i=a;i<=b;i++){
    if(check(v,i,n)<=days){
        cout<<i<<endl;
		return;
    }
}
}
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
int t=1;
cin>>t;
while(t--){
dosomething();
}
    return 0;
}