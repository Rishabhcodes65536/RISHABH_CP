#include <bits/stdc++.h>
#pragma GCC target("popcnt")

using namespace std;

const int N = 5003;

bitset<N> bi[N];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N;i++){
        cin >> bi[i];
    }
    long long res = 0;
    for (int i = 0; i < N;i++){
        for (int j = i + 1; j < N;j++){
            long long h= (bi[i] & bi[j]).count();
            res += ((h * (h - 1)) >> 1LL);
        }
    }
    cout << res << endl;
}