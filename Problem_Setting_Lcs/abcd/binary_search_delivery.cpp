#include<bits/stdc++.h>
// #define int long long
using namespace std;

long long check(int v[],long long capacity,int n){
        long long days=1,load=0;
        for(int i=0;i<n;i++){
            if((long long)v[i]+load>capacity){
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

long long a=*max_element(v,v+n);
long long b=accumulate(v,v+n,0LL);
long long lo=a,hi=b;

//binary search on answer

while(lo<=hi){
    long long mid=lo+(hi-lo)/2;
    if(check(v,mid,n)<=days){
        hi=mid-1LL;
    }
    else{
        lo=mid+1LL;
    }
}
cout<<lo<<endl;
}
 
 
signed main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
int t=1;
cin>>t;
while(t--){
dosomething();
}
    return 0;
}