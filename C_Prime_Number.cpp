#include <bits/stdc++.h>

using namespace std;

#define int long long

const int M = 1e9 + 7;

int binpow(int a,int b){
    int ans = 1LL;
    while(b>0){
        if(b&1){
            ans *= a;
            ans %= M;
        }
        a *= a;
        a %= M;
        b >>= 1;
    }
    return ans;
}
int mod_mul(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
int extended_gcd(int a, int b, int &x, int &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return x;
    }
    int gcd = extended_gcd(b, a % b, y, x);
    y -= x * (a / b);
    return gcd;
}
int mod_inv(int a, int b)
{
    int r1, r2;
    int gcd = extended_gcd(a, b, r1, r2);
    assert(gcd == 1);
    return r1;
}
int mod_div(int a, int b, int m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, mod_inv(b, m), m) + m) % m;
}

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b, a % b);
}

signed main(){
    int n, k;
    cin >> n >> k;
    int sum = 0;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    // int sum = accumulate(arr, arr + n, 0);

    int h = 0;
    vector<int> b;
    for (int i = 0; i < n;i++){
        b.push_back(sum - arr[i]);
    }
    sort(b.begin(), b.end());
    reverse(b.begin(), b.end());
    while(true){
        int backsy = b.back();
        int c = 0;
        while(b.size() && b.back()==backsy){
            b.pop_back();
            c++;
        }
        if(c%k!=0){
            int u=min(backsy,sum);
            // int u = c;
            int res = binpow(k, u)%M;
            cout << res << endl;
            return 0;
        }
        else{
            int it = c / k;
            for (int j = 0; j < it;j++){
                b.push_back(backsy + 1);
            }
        }
    }
    cout << "Hi" << endl;
    // cout << gcd(u, v) << endl;

}


//(k^sum/k^sum)*((1/z1)+1/z2 + 1/z3)

