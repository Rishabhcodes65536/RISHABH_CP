#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    if(n==1){
        cout << -1 << endl;
        return;
    }
    sort(arr,arr+n);
    int diff = arr[1] - arr[0];
    map<int, int> mp;
    mp[diff]++;
    bool flag = 0;
    for (int i = 2; i < n;i++){
        if(arr[i]-arr[i-1]==0){
            flag = 1;
        }
        mp[arr[i] - arr[i - 1]]++;
    }
    if(mp[0]){
        if(mp[0]==n){
            cout << 1 << endl;
            cout << arr[0] << endl;
            return;
        }
    }
}