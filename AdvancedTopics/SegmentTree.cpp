#include<bits/stdc++.h>
using namespace std;
class SegmentTree {
public:
    int n;
    vector<int> seg;
    SegmentTree(int size) {
        n = size;
        seg.resize(4 * n, 0);
    }
    void build(int node, int l, int r, vector<int>& arr) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }

    int mid = (l + r) / 2;

    build(2 * node + 1, l, mid, arr);
    build(2 * node + 2, mid + 1, r, arr);

    seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);
}
    void update(int idx, int val, int node, int l, int r) {
        if (l == r) {
            seg[node] = val;
            return;
        }
        int mid = (l + r) / 2;
        if (idx <= mid)
            update(idx, val, 2 * node + 1, l, mid);
        else
            update(idx, val, 2 * node + 2, mid + 1, r);
        seg[node] = max(seg[2 * node + 1], seg[2 * node + 2]);
    }
    int query(int ql, int qr, int node, int l, int r) {
        if (r < ql || l > qr)
            return 0;

        if (ql <= l && r <= qr)
            return seg[node];

        int mid = (l + r) / 2;

        return max(
            query(ql, qr, 2 * node + 1, l, mid),
            query(ql, qr, 2 * node + 2, mid + 1, r)
        );
    }

    void update(int idx, int val) {
        update(idx, val, 0, 0, n - 1);
    }

    int query(int l, int r) {
        return query(l, r, 0, 0, n - 1);
    }
};
int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};

    SegmentTree st(arr.size());

    for (int i = 0; i < arr.size(); i++) {
        st.update(i, arr[i]);
    }

    cout << "Max in range [1,4] = "
         << st.query(1, 4) << endl;

    st.update(2, 20);

    cout << "Max in range [1,4] after update = "
         << st.query(1, 4) << endl;
}