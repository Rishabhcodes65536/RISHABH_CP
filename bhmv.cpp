#include <bits/stdc++.h>
using namespace std;

int main() {

int t;cin>>t;

while(t--){
    int a=0,b=0;cin>>a>>b;
    if(a<b){
        swap(a,b);  
    }
    
    double m=(a/b);
    int n=(a/b);
    
    cout<<n<<" "<<m<<endl;
    
    int cnt = 0;
    while(n){
        cnt++;
        n = n&(n-1);
    }
   cout<<cnt<<endl;
   int y=(int)m;
   cout<<n<<" "<<y<<endl;
    if(cnt==1 &&  n==y){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
     
    
}



	return 0;
}