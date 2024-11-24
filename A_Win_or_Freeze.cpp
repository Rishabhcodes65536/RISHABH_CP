#include <bits/stdc++.h>

using namespace std;

int main()
{

    long long n;
    cin >> n;
    long long nn = n;
    long long r = 1;
    int u = 0;
    for (long long h = 2; h * h <= nn; h++)
    {
        while (n % h == 0 && n != h)
        {
            n /= h;
            u++;
            r *= h;
            if (u == 2)
            {
                break;
            }
        }
        if (u == 2)
        {
            break;
        }
    }
    if (u >= 2 && n > 1)
    {
        cout << 1 << endl;
        cout << n << endl;
    }
    else
    {
        if (n == nn)
        {
            cout << 1 << endl;
            cout << 0 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
}
