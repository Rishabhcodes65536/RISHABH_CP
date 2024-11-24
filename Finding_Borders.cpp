#include <bits/stdc++.h>

using namespace std;

class ModArithmetic
{
protected:
    static const long long p = 31;
    static const long long M = 1e9 + 7;

    long long mod_mul(long long a, long long b)
    {
        a = a % M;
        b = b % M;
        return (((a * b) % M) + M) % M;
    }

    long long mod_sub(long long a, long long b)
    {
        a = a % M;
        b = b % M;
        return (((a - b) % M) + M) % M;
    }

    long long extended_gcd(long long a, long long b, long long &x, long long &y)
    {
        if (b == 0)
        {
            x = 1;
            y = 0;
            return a;
        }
        long long gcd = extended_gcd(b, a % b, y, x);
        y -= x * (a / b);
        return gcd;
    }

    long long mod_inv(long long a)
    {
        long long x, y;
        long long gcd = extended_gcd(a, M, x, y);
        return (x % M + M) % M;
    }

    long long mod_div(long long a, long long b)
    {
        return mod_mul(a, mod_inv(b));
    }
};

class Rabin : public ModArithmetic
{
public:
    vector<long long> pre_hash, suf_hash;
    vector<long long> p_pow;

    Rabin(const string &s)
    {
        long long n = s.size();
        pre_hash.resize(n + 1, 0);
        suf_hash.resize(n + 1, 0);
        p_pow.resize(n + 1, 1);

        for (long long i = 1; i <= n; i++)
        {
            p_pow[i] = mod_mul(p_pow[i - 1], p);
        }

        for (long long i = 0; i < n; i++)
        {
            pre_hash[i + 1] = (pre_hash[i] + mod_mul((s[i] - 'a' + 1), p_pow[i])) % M;
        }

        for (long long i = 0; i < n; i++)
        {
            suf_hash[i + 1] = (suf_hash[i] + mod_mul((s[n - i - 1] - 'a' + 1), p_pow[i])) % M;
        }
    }

    long long get_prefix_hash(long long l, long long r)
    {
        return mod_div(mod_sub(pre_hash[r + 1], pre_hash[l]), p_pow[l]);
    }

    long long get_suffix_hash(long long l, long long r, long long n)
    {
        long long suffix_r = n - l;
        long long suffix_l = n - r;
        return mod_div(mod_sub(suf_hash[suffix_r], suf_hash[suffix_l]), p_pow[suffix_l]);
    }
};

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> v;
    Rabin r(s);
    for(int i=1;i<s.size();i++){
        long long h1 = r.get_prefix_hash(0, i - 1);
        long long h2 = r.get_prefix_hash(n-i, n - 1);
        if(h1 == h2){
            v.push_back(i);
        }
    }
    for(auto &x:v){
        cout << x << " ";
    }
}