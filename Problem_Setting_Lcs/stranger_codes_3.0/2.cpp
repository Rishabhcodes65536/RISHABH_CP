
#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
ios_base::sync_with_stdio(false);
cin.tie(0);cout.tie(0);

    long long n;
    cin>>n;
    long long arr[n],ark[n];
    bool flag=false;
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    sort(arr , arr+n);
    for(int j=0;j<n;j++){
        if(arr[j]!=j+1){
            cout<<j+1<<endl;
            flag=true;
            break;
        }
    }
    if(flag==false){
        cout<<arr[n-1]+1<<endl;
    }
    return 0;
}