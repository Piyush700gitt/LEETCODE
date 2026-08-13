class SegmentTree {
public:
    struct Node {
        char leftChar, rightChar;
        int leftCnt, rightCnt, mx, len;

        Node() {
            leftChar = rightChar = '#';
            leftCnt = rightCnt = mx = len = 0;
        }
    };

    vector<Node> tree;

    SegmentTree(string &s) {
        tree.resize(4 * s.size());
        build(0, 0, s.size() - 1, s);
    }

    Node merge(Node a, Node b) {
        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;
        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.leftCnt = a.leftCnt;
        res.rightCnt = b.rightCnt;

        if (a.leftCnt == a.len && a.leftChar == b.leftChar)
            res.leftCnt += b.leftCnt;

        if (b.rightCnt == b.len && a.rightChar == b.rightChar)
            res.rightCnt += a.rightCnt;

        res.mx = max(a.mx, b.mx);

        if (a.rightChar == b.leftChar)
            res.mx = max(res.mx, a.rightCnt + b.leftCnt);

        res.mx = max(res.mx, max(res.leftCnt, res.rightCnt));

        return res;
    }

    void build(int node, int l, int r, string &s) {
        if (l == r) {
            tree[node].leftChar = tree[node].rightChar = s[l];
            tree[node].leftCnt = tree[node].rightCnt = tree[node].mx = 1;
            tree[node].len = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(2 * node + 1, l, mid, s);
        build(2 * node + 2, mid + 1, r, s);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int node, int l, int r, int idx, char c) {
        if (l == r) {
            tree[node].leftChar = tree[node].rightChar = c;
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node + 1, l, mid, idx, c);
        else
            update(2 * node + 2, mid + 1, r, idx, c);

        tree[node] = merge(tree[2 * node + 1], tree[2 * node + 2]);
    }

    void update(int idx, char c, int n) {
        update(0, 0, n - 1, idx, c);
    }

    int getMax() {
        return tree[0].mx;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        int n = s.size();

        SegmentTree st(s);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {
            int idx = queryIndices[i];
            char c = queryCharacters[i];

            st.update(idx, c, n);

            ans.push_back(st.getMax());
        }

        return ans;
    }
};