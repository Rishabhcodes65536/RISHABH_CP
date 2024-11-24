#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    sort(a, a + n);
    int i = 0, j = 0;
    int res = n;
    while(j<n){
        while(a[j]-a[i]+1>n){
            i++;
        }
        res = min(res, n - (j - i + 1));
        j++;
    }
    cout << res << endl;
}