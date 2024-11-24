#include<bits/stdc++.h>
using namespace std;

void dosomething(){
int n;
cin>>n;
int arr[n];
for(int i=0;i<n;i++){
  cin>>arr[i];
}
int maxi=0;
for(int i=1;i<n;i++){
  maxi=max(maxi,abs(arr[i]-arr[i-1]));
}
cout<<maxi<<endl;
}
 
 
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
freopen("input.txt", "r", stdin);
freopen("output_ninja.txt", "w", stdout);
int t=1;
cin>>t;
while(t--){
dosomething();
}
    return 0;
}