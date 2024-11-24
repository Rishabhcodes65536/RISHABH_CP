#include <bits/stdc++.h>

using namespace std;


int main(){
    string s;
    cin >> s;
    int u[3];
    cin >> u[0] >> u[1] >> u[2];
    int v[3];
    cin >> v[0]>>v[1]>>v[2];
    long long ruble;
    cin >> ruble;

    int arr[3]={0,0,0};
    for (int i = 0; i < s.size();i++){
        if(s[i]=='B'){
            arr[0]++;
        }
        else if(s[i]=='S'){
            arr[1]++;
        }
        else{
            arr[2]++;
        }
    }
    long long l = 0, h = 1e13;
    while(l<=h){
        long long mid = l + (h - l)/2;
        long long sum = 0;
        for (int i = 0; i < 3; i++) {
            long long rem = max(0LL, 1LL*mid*arr[i] - 1ll*u[i]);
            long long buy = rem * v[i];
            sum += buy;
        }
        if(sum <= ruble){
            l = mid + 1;
        }
        else{
            h = mid - 1;
        }
    }
    cout << h << endl;
}