#include <bits/stdc++.h>
using namespace std;

int main() {

int t=0; cin>>t;

while(t--){
    vector<int>s;
    int a=0;
    cin>>a;
    int arr[a];
    
    
    for(int i=0;i<a;++i){
        cin>>arr[i];
    }
    
//   sort(arr,arr+a);
//   cout<<endl<<arr[0]<<endl;
  
     for(int i=0;i<a-1;++i){  
       for(int j=i+1;j<a;++j){
       int ap= __gcd(arr[j],arr[i] );
       s.push_back(ap);
    }
     }
    //   cout<<arr[0]*a<<endl;
    
    // for(auto k: s){
    //     cout<<k<<endl;
    // }  
    auto k=*min_element(s.begin(),s.end());
    cout<<k * a<<endl;    
//     2
// 2
// 5 10
// 3
// 2 2 6
}

	return 0;
}