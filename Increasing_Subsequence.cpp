#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> v;
    v.push_back(arr[0]);

    for (int i = 1; i < n;i++){
        int lb = lower_bound(v.begin(), v.end(), arr[i])-v.begin();
        if(lb==v.size()){
            v.push_back(arr[i]);
        }
        else{
            v[lb] = arr[i];
        }
    }
    cout << v.size() << endl;
}