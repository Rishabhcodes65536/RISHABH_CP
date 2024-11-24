

#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

int main()
{

    long long k, b, n, t;

    cin >> k >> b >> n >> t;
    long long r = 1;
    int c = 0;
    for (int i = 1; i <= n; i++)
    {
        r = r * k;
        r += b;
        if (r <= t)
        {
            c++;
        }
        else
        {
            break;
        }
    }
    cout << n - c << endl;
}
