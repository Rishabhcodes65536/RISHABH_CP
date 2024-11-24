#include <bits/stdc++.h>

using namespace std;

#define ll long long

class SGT
{

public:
    vector<ll> max_seg,min_seg;

    SGT(int n)
    {
        max_seg.resize(4 * n + 1);
        min_seg.resize(4 * n + 1,INT_MAX);
    }

    void build(int ind, int low, int high, vector<int> &arr)
    {
        if (low == high)
        {
            max_seg[ind] = arr[low];
            min_seg[ind] = arr[low];
            return;
        }

        int mid = (low + high) / 2;

        build(2 * ind + 1, low, mid, arr);
        build(2 * ind + 2, mid + 1, high, arr);

        max_seg[ind] = max(max_seg[2 * ind + 1],max_seg[2 * ind + 2]);
        min_seg[ind] = min(min_seg[2 * ind + 1],min_seg[2 * ind + 2]);
    }


    int query(int ind, int low, int high, int l, int r,int dir)
    {

        if (r < low || high < l)
            return (dir ? (0) : (INT_MAX));

        if (low >= l && high <= r){
            return (dir ? (max_seg[ind]) : (min_seg[ind]));
        }
        int mid = (low + high) >> 1;
        int left = query(2 * ind + 1, low, mid, l, r,dir);
        int right = query(2 * ind + 2, mid + 1, high, l, r,dir);

        return (dir ? (max(left,right)) : (min(left,right)));
    }

    // void update(int ind, int low, int high, int i, int val)
    // {
    //     if (low == high)
    //     {
    //         seg[ind] = val;
    //         return;
    //     }

    //     int mid = (low + high) >> 1;

    //     if (i <= mid)
    //         update(2 * ind + 1, low, mid, i, val);

    //     else
    //         update(2 * ind + 2, mid + 1, high, i, val);

    //     seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    // }
};
vector<ll> rando(1e6 + 4);

void build()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, INT64_MAX);
    for (int i = 0; i < 1e6+3;i++){
        rando[i] = dis(gen);
    }
}

class Zobrist{
    public:
    int N;
    vector <ll> zebra;
    Zobrist(int r,int maxi){
        N = r;
        // rando.resize(maxi+3);
        zebra.resize(N + 3,0);
    }


    void build_zebra(vector <int> &v){
        for (int i = 0; i < N;i++){
            zebra[i + 1] = zebra[i] ^ rando[v[i]];
        }
    }

    bool check(int l,int r){
        return zebra[l] == zebra[r + 1];
    }

};

void winterIsComing(){
    int n, q;
    cin >> n >> q;
    vector<int> v;
    int maxi = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        v.push_back(x);
        maxi = max(maxi, x);
    }
    Zobrist zb(n,maxi);
    zb.build_zebra(v);
    while(q--){
        int l, r;
        cin >> l >> r;
        l--,r--;
        if((r-l+1)&1){
            cout << "NO" << endl;
            continue;
        }
        if(zb.check(l,r)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}

int main(){
    int tt;
    cin >> tt;
    build();
    while(tt--){
        winterIsComing();
    }
}
