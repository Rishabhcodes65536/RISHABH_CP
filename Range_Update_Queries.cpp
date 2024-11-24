#include <bits/stdc++.h>

using namespace std;

#define int long long

int sums(int k, vector<int> &zz)
{
    int s = 0;
    while (k > 0)
    {
        s += zz[k];
        k -= k & -k;
    }
    return s;
}

void adds(int k, int x, vector<int> &zz)
{
    while (k < zz.size())
    {
        zz[k] += x;
        k += k & -k;
    }
}

signed main()
{
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    vector<int> addi(n + 2, 0), subi(n + 2, 0); // Extra space for 1-based indexing

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < q; i++)
    {
        int u;
        cin >> u;
        if (u == 1)
        {
            int l, r, z;
            cin >> l >> r >> z;
            adds(l, z, addi);
            adds(r + 1, -z, addi);
        }
        else
        {
            int w;
            cin >> w;
            // w++;
            int s = sums(w, addi);
            cout << v[w - 1] + s << endl;
        }
    }
    return 0;
}
