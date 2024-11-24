// MAY THE CODE BE WITH YOU.
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int M = 1e9 + 7; // 998244353;
const int INF = 1e16;

#ifndef ONLINE_JUDGE
#else
#define debug(...)
#endif

template <typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec)
{
    if (vec.empty())
    {
        out << "[]";
        return out;
    }
    out << '[';
    for (int i = 0; i < vec.size() - 1; i++)
    {
        out << vec[i] << ", ";
    }
    return out << vec.back() << ']';
}

class SegmentTree
{
public:
    vector<int> seg;
    SegmentTree(int n)
    {
        seg.resize(4 * n + 1, 0);
    }
    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            seg[ind] = arr[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }

    int query(int ind, int low, int high, int l, int r)
    {
        if (high < l || low > r)
            return INT_MIN;
        if (low >= l && high <= r)
            return seg[ind];
        int mid = (low + high) / 2;
        return max(query(2 * ind + 1, low, mid, l, r), query(2 * ind + 2, mid + 1, high, l, r));
    }

    void update(int ind, int low, int high, int i, int val)
    {
        if (low == high)
        {
            seg[ind] = val;
            return;
        }
        int mid = (low + high) / 2;
        if (i <= mid)
            update(2 * ind + 1, low, mid, i, val);
        else
            update(2 * ind + 2, mid + 1, high, i, val);
        seg[ind] = max(seg[2 * ind + 1], seg[2 * ind + 2]);
    }
};

inline void solve()
{
    int n, m, k; //10^5 * 10^5 
    cin >> n >> m >> k;
    vector<pair<int, int>> v(k);
    for (auto &i : v)
    {
        cin >> i.first >> i.second;
        i.first--;
        i.second--;
    }
    sort(v.begin(), v.end());
    for(auto &r:v){
        cout << r.first << " " << r.second << endl;
    }
    vector<int> cols(m, 0);

    SegmentTree st(m + 1);
    //0 -> 4*n populate
    st.build(0, 0, m - 1, cols);
    vector<int> par(k, k);
    vector<int> cnt_to_ind(k + 1, k);
    //1 4
    //2 1
    //2 3
    //3 3


    //7
    //6
    //5 
    //4
    //3
    //2
    //1
    //0 -> k
    for (int i = 0; i < k; i++)
    {
        int c = v[i].second;  // column jth 
        //. . . *
        //. . * .
        //. * . .
        //* . . .
        int x = st.query(0, 0, m - 1, 0, c) + 1;
        if (x > cols[c])
        {
            cols[c] = x;
            st.update(0, 0, m - 1, c, x);
            par[i] = cnt_to_ind[x - 1];
            int j = cnt_to_ind[x];
            if (j == k || v[j].second > c)
            {
                cnt_to_ind[x] = i;
            }
        }
        cout << cols << endl;
        cout << cnt_to_ind << endl;
    }

    int cnt = st.query(0, 0, m - 1, 0, m - 1);
    cout << cnt << endl;

    vector<pair<int, int>> path(1, {n - 1, m - 1});

    int z = cnt_to_ind[cnt];
    while (z < k)
    {
        path.push_back(v[z]);
        z = par[z];
    }

    int x = 0, y = 0;
    while (path.size())
    {
        int nx = path.back().first, ny = path.back().second;
        path.pop_back();
        int dx = nx - x, dy = ny - y;
        while (dx--)
            cout << "D";
        while (dy--)
            cout << "R";
        x = nx, y = ny;
    }
    cout << endl;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(9);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin>>t;
    for (int i = 0; i < t; i++)
        solve();
    return 0;
}
/*
    "And I knew exactly what to do.
    But in a much more real sense, I had no idea what to do."
                            - Michael Scott - Nachiket Dodia
*/

//{-1,0,1,0,-1}

// dir -> 1 to n 
//x+dir
//y+dir[i-1]

// #.#.#
// #.#.#
// #.#.#
// #.#.#
// #####

//.#.
//###
//.#.

//##

//#

//count of # less than equal to 2

//### -> ans=1