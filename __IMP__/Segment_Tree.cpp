#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    vector<long long> lazy;
    vector<long long> arr;
    int MOD;

    void buildTree(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            buildTree(2 * node, start, mid);
            buildTree(2 * node + 1, mid + 1, end);
            tree[node] = (tree[2 * node] * tree[2 * node + 1]) % MOD;
        }
    }

    void lazyUpdate(int node, int start, int end) {
        if (lazy[node] != 1) {
            tree[node] = (tree[node] * lazy[node]) % MOD;
            if (start != end) {
                lazy[2 * node] = (lazy[2 * node] * lazy[node]) % MOD;
                lazy[2 * node + 1] = (lazy[2 * node + 1] * lazy[node]) % MOD;
            }
            lazy[node] = 1;
        }
    }

    long long queryRange(int node, int start, int end, int l, int r) {
    lazyUpdate(node, start, end);
    if (start > end || start > r || end < l) return 1;
    if (start >= l && end <= r) return tree[node] % MOD; 
    int mid = (start + end) / 2;
    long long p1 = queryRange(2 * node, start, mid, l, r);
    long long p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
    return (p1 * p2) % MOD; 
}

    void updateRange(int node, int start, int end, int l, int r, long long val) {
        lazyUpdate(node, start, end);
        if (start > end || start > r || end < l) return;
        if (start >= l && end <= r) {
            tree[node] = (tree[node] * val) % MOD;
            if (start != end) {
                lazy[2 * node] = (lazy[2 * node] * val) % MOD;
                lazy[2 * node + 1] = (lazy[2 * node + 1] * val) % MOD;
            }
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = (tree[2 * node] * tree[2 * node + 1]) % MOD;
    }

public:
    SegmentTree(const vector<long long>& input, int m) {
        arr = input;
        MOD = m;
        int n = input.size();
        tree.resize(4 * n);
        lazy.resize(4 * n, 1);
        buildTree(1, 0, n - 1);
    }

    long long query(int l, int r) {
        return queryRange(1, 0, arr.size() - 1, l, r);
    }

    void update(int l, int r, long long val) {
        updateRange(1, 0, arr.size() - 1, l, r, val);
    }
};