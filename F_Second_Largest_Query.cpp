#include <bits/stdc++.h>


using namespace std;

struct Node {
    int max_val;
    int second_max;
    int count;
};

class SegmentTree {
private:
    vector <Node> tree;
    vector <int> arr;
    int n;

    void build(int node, int start, int end) {
        if (start == end) {
            tree[node].max_val = arr[start];
            tree[node].second_max = INT_MIN;
            tree[node].count = 1;
        } else {
            int mid = (start + end) / 2;
            build(2 * node, start, mid);
            build(2 * node + 1, mid + 1, end);
            merge(tree[2 * node], tree[2 * node + 1], tree[node]);
        }
    }

    void merge(Node &left, Node &right, Node &parent) {
        parent.max_val = max(left.max_val, right.max_val);
        parent.second_max = min(max(left.max_val, right.second_max), max(right.max_val, left.second_max));
        parent.count = 0;
        if (left.max_val == parent.second_max) parent.count += left.count;
        if (right.max_val == parent.second_max) parent.count += right.count;
    }

    void update(int node, int start, int end, int index, int value) {
        if (start == end) {
            arr[index] = value;
            tree[node].max_val = value;
        } else {
            int mid = (start + end) / 2;
            if (start <= index && index <= mid)
                update(2 * node, start, mid, index, value);
            else
                update(2 * node + 1, mid + 1, end, index, value);
            merge(tree[2 * node], tree[2 * node + 1], tree[node]);
        }
    }

    Node query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            Node null_node;
            null_node.max_val = INT_MIN;
            null_node.second_max = INT_MIN;
            null_node.count = 0;
            return null_node;
        }
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        Node left = query(2 * node, start, mid, l, r);
        Node right = query(2 * node + 1, mid + 1, end, l, r);
        Node result;
        merge(left, right, result);
        return result;
    }

public:
    SegmentTree(vector<int> &input) {
        n = input.size();
        arr = input;
        tree.resize(4 * n);
        build(1, 0, n - 1);
    }

    void updateValue(int index, int value) {
        update(1, 0, n - 1, index, value);
    }

    int querySecondLargest(int l, int r) {
        Node result = query(1, 0, n - 1, l, r);
        return result.count;
    }
};

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    SegmentTree segTree(A);
    while (q--) {
        int type, p, x, l, r;
        cin >> type;
        if (type == 1) {
            cin >> p >> x;
            segTree.updateValue(p - 1, x);
        } else if (type == 2) {
            cin >> l >> r;
            cout << segTree.querySecondLargest(l - 1, r - 1) << endl;
        }
    }
    return 0;
}
