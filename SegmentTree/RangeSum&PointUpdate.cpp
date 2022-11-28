#include <bits/stdc++.h>
using namespace std;
class SegmentTree {
    // 0 based-index
    int n;
    vector<int> t;
    int sum(int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return sum(v * 2, tl, tm, l, min(r, tm))
               + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    }

    void update(int v, int tl, int tr, int pos, int new_val) {
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

    void build(vector<int> a, int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

public:
    SegmentTree(int n, vector<int>&a) {
        this->n = n;
        t.resize(4 * n + 1);
        build(a, 1, 0, n - 1);
    }

    int sum(int l, int r) {
        return sum(1, 0, n-1, l, r);
    }
    void update(int pos, int new_val) {
        return update(1, 0, n-1, pos, new_val);
    }


};
int main() {
    int n = 5;
    vector<int> a = {1, 2, 3, 4, 5};
    SegmentTree s(n, a);
    cout << s.sum(0, 4) << endl;
    s.update(2, 5);
    cout << s.sum(2, 2) << endl;
    return 0;

}
