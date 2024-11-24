#include<bits/stdc++.h>
using namespace std;

void dosomething(){
int a[8];
for(int i=0;i<8;i++){
    cin>>a[i];
}
int sum=0;
for(int i=0;i<8;i++){
    sum+=a[i];
}
if(sum/8.0 >=7.5){
    cout<<"YES"<<endl;
}
else{
    cout<<"NO"<<endl;
}
}
 
 
int main(){
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);
freopen("the_input.txt", "r", stdin);
freopen("the_output_cgpa.txt", "w", stdout);
int t=1;
cin>>t;
while(t--){
dosomething();
}
    return 0;
}