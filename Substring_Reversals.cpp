#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef struct item *pitem;
struct item
{
    int prior, value, cnt;
    LL sum;
    bool rev;

    item(int value) : prior(rng()), value(value)
    {
        cnt = 0;
        rev = 0;
        sum = value;
        l = r = nullptr;
    }

    pitem l, r;
};

namespace Treap
{
    int cnt(pitem it)
    {
        return it != nullptr ? it->cnt : 0;
    }
    LL sum(pitem it)
    {
        return it != nullptr ? it->sum : 0;
    }
    void upd_cnt(pitem it)
    {
        if (it != nullptr)
        {
            it->cnt = cnt(it->l) + cnt(it->r) + 1;
            it->sum = sum(it->l) + sum(it->r) + it->value;
        }
    }
    void push(pitem it)
    {
        if (it != nullptr && it->rev == true)
        {
            it->rev = false;
            swap(it->l, it->r);
            if (it->l)
                it->l->rev ^= true;
            if (it->r)
                it->r->rev ^= true;
        }
    }
    void merge(pitem &t, pitem l, pitem r)
    {
        push(l);
        push(r);
        if (l == nullptr || r == nullptr)
            t = (l != nullptr) ? l : r;
        else if (l->prior > r->prior)
            merge(l->r, l->r, r), t = l;
        else
            merge(r->l, l, r->l), t = r;
        upd_cnt(t);
    }
    void split(pitem t, pitem &l, pitem &r, int key, int add = 0)
    {
        if (t == nullptr)
        {
            l = r = nullptr;
            return;
        }
        push(t);
        int cur_key = add + cnt(t->l);

        if (key <= cur_key)
            split(t->l, l, t->l, key, add), r = t;
        else
            split(t->r, t->r, r, key, add + 1 + cnt(t->l)), l = t;
        upd_cnt(t);
    }
    void reverse(pitem &t, int l, int r)
    {
        pitem t1, t2, t3;
        split(t, t1, t2, l);
        split(t2, t2, t3, r - l + 1);
        assert(t2 != NULL);
        t2->rev ^= true;
        merge(t, t1, t2);
        merge(t, t, t3);
    }
    LL query(pitem &t, int l, int r)
    {
        pitem t1, t2, t3;
        split(t, t1, t2, l);
        split(t2, t2, t3, r - l + 1);
        LL ans = t2->sum;
        merge(t, t1, t2);
        merge(t, t, t3);
        return ans;
    }
    void insert(pitem &t, int key, int value)
    {
        pitem x = new item(value);
        pitem L, R;
        split(t, L, R, key);
        merge(L, L, x);
        merge(t, L, R);
        upd_cnt(t);
    }
    int erase(pitem &t, int key)
    {
        assert(cnt(t) > key);
        pitem L, MID, R;
        split(t, L, MID, key);
        split(MID, MID, R, 1);
        merge(t, L, R);
        upd_cnt(t);
        int rt = MID->value;
        delete MID;
        return rt;
    }
    void output(pitem t, string &v)
    {
        if (t == nullptr)
            return;
        push(t);
        output(t->l, v);
        v.push_back(t->value);
        output(t->r, v);
    }
    void output2(pitem t)
    {
        if (t == nullptr)
            return;
        push(t);
        //        cout << "(";
        output2(t->l);
        cout << (t->value) << " ";
        output2(t->r);
        //        cout << ")";
    }
}

void solve()
{
    pitem tr = nullptr;
    int n, q;
    cin >> n >> q;
    char c;
    for (int i = 0; i < n; i++)
    {
        cin >> c;
        Treap::insert(tr, i, c);
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        Treap::reverse(tr, --l, --r);
    }
    string ans;
    Treap::output(tr, ans);
    cout << ans << "\n";
}

int main()
{
    int N, Q;
    string S;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> Q >> S;
    pitem tr = nullptr;
    // string R = S;
    // reverse(R.begin(), R.end());
    int i = 0;
    for (char c : S)
    {
        // merge(root, root, new Node(c));
        Treap::insert(tr, i++, c);
    }
    // for (int i = N - 1; i >= 0;i--)
    // {
    //     merge(rev_root, rev_root, new Node(S[i]));
    // }
    // cout << R << endl;
    while (Q--)
    {
        int l, r;
        cin >> l >> r;
        // Node *a, *b, *c, *d;
        // Node *a_, *b_, *c_, *d_;

        // split(root, a, b, l - 1);
        // split(b, c, d, r - l + 1);
        // l = N - l;
        // r = N - r;
        // // cout << a << endl;
        // // cout << c << endl;
        // // cout << d << endl;
        // split(rev_root, a_, b_, r);
        // split(b_, c_, d_, abs(l - r) + 1);
        // // cout << a_ << endl;
        // // cout << b_ << endl;       
        // // cout << c_ << endl;
        // // cout << d_ << endl;
        // merge(root, a, c_);
        // merge(root, root, d);
        // merge(rev_root, a_, c);
        // merge(rev_root, rev_root, d_);
        // cout << rev_root << '\n';
        Treap::reverse(tr, --l, --r);
    }
    string ans;
    Treap::output(tr, ans);
    cout << ans << endl;
}


//AYBABTU

//__^^___   3 4 

//UTBABYA

//___^^__

//   RL