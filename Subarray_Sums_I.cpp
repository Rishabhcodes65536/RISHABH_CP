#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n;i++){
        cin >> v[i];
    }
    int i = 0, j = 0,temp=0,res=0;
    while(j<n){
        temp += v[j];
        while(i<n && temp>m){
            temp -= v[i];
            i++;
        }
        if(temp==m){
            res++;
        }
        j++;
    }
    cout << res << endl;
}