#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

void multiply(vector<vector<long long>> &A, vector<vector<long long>> &B)
{
    vector<vector<long long>> C(2, vector<long long>(2));
    C[0][0] = (A[0][0] * B[0][0] + A[0][1] * B[1][0]) % MOD;
    C[0][1] = (A[0][0] * B[0][1] + A[0][1] * B[1][1]) % MOD;
    C[1][0] = (A[1][0] * B[0][0] + A[1][1] * B[1][0]) % MOD;
    C[1][1] = (A[1][0] * B[0][1] + A[1][1] * B[1][1]) % MOD;
    A = C;
}

vector<vector<long long>> power(vector<vector<long long>> M, long long exp)
{
    vector<vector<long long>> res = {{1, 0}, {0, 1}};
    while (exp)
    {
        if (exp & 1)
            multiply(res, M);
        multiply(M, M);
        exp >>= 1;
    }
    return res;
}

long long fib(long long n)
{
    if (n == 1 || n == 2)
        return 1;
    vector<vector<long long>> M = {{1, 1}, {1, 0}};
    M = power(M, n - 2);
    return (M[0][0] + M[0][1]) % MOD;
}

vector<vector<long long>> precompute()
{
    vector<vector<long long>> divisors(100001);

    for (int k = 1; k <= 100000; ++k)
    {
        long long f1 = 1, f2 = 1, idx = 2;
        if (f1 % k == 0)
            divisors[k].push_back(1);
        if (f2 % k == 0)
            divisors[k].push_back(2);

        while (divisors[k].size() < 100000)
        {
            long long f3 = (f1 + f2) % MOD;
            idx++;
            if (f3 % k == 0)
                divisors[k].push_back(idx);
            f1 = f2;
            f2 = f3;
        }
    }

    return divisors;
}

long long find_nth_fib_divisible(long long n, int k, const vector<vector<long long>> &precomputed)
{
    const vector<long long> &div_by_k = precomputed[k];
    if (n <= div_by_k.size())
    {
        long long idx = div_by_k[n - 1];
        return fib(idx);
    }
    else
    {
        return -1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    vector<vector<long long>> precomputed = precompute();

    while (t--)
    {
        long long n;
        int k;
        cin >> n >> k;

        cout << find_nth_fib_divisible(n, k, precomputed) << endl;
    }

    return 0;
}
