#include<bits/stdc++.h>
using namespace std;

const int N = 2e3 + 50;
int n, f[N][N], pre[N], suf[N];
char s[N];
long long ans;

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);

    for (int i = 1; i <= n; i++) 
        f[i][i - 1] = f[i][i] = f[i + 1][i] = 1;
    
    for (int len = 2; len <= n; len++) {
        for (int i = 1, j = len; j <= n; i++, j++) {
            if (s[i] == s[j]) 
                f[i][j] = f[i + 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (f[j][i] == 1) 
                pre[i]++;
        }
        for (int j = i; j <= n; j++) {
            if (f[i][j] == 1) 
                suf[i]++;
        }
    }


    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            // if (abs(j - i) <= 1) 
                ans += 1LL * pre[i] * suf[j];
        }
    }

    printf("%lld\n", ans);
    return 0;
}
