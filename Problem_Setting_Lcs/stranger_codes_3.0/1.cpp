#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n,x,k;
    cin>>n>>x>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    sort(v.begin(),v.end());
    int i=0,j=n-1,c=0;
    while(i<=j){
        if(i==j){
            c++;
            break;
        }
        if(v[i]+v[j]<=x){
            c++;i++;j--;
        }
        else{
            c++;
            j--;
        }
    }
    cout<<c*k<<endl;
}