#include <bits/stdc++.h>

using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    int i = 0, j = 1;
    long long tsum = a[0], curr = a[0];
    long long maxi = 1, ptr = a[0];
    while(j<n){
        tsum += a[j];
        curr = a[j];
        long long r = curr * (j - i + 1);
        while(curr*(j-i+1)-tsum>k){
            tsum -= a[i];
            i++;
        }
        if(j-i+1 > maxi){
            maxi = j - i + 1;
            ptr = a[j];
        }
        j++;
    }
    cout << maxi << " " << ptr<< endl;
}