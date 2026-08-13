class Solution {
public:
    struct Node {
        char leftChar;
        char rightChar;

        int prefix;
        int suffix;
        int best;
        int len;

        Node() {
            leftChar = '#';
            rightChar = '#';
            prefix = 0;
            suffix = 0;
            best = 0;
            len = 0;
        }
    };

    vector<Node> tree;
    Node merge(Node a, Node b) {

        if (a.len == 0) return b;
        if (b.len == 0) return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefix = a.prefix;

        if (a.prefix == a.len &&
            a.rightChar == b.leftChar) {
            res.prefix = a.len + b.prefix;
        }

        res.suffix = b.suffix;

        if (b.suffix == b.len &&
            a.rightChar == b.leftChar) {
            res.suffix = b.len + a.suffix;
        }

        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {
            res.best = max(
                res.best,
                a.suffix + b.prefix
            );
        }

        return res;
    }

    void build(string &s, int node, int l, int r) {

        if (l == r) {
            tree[node].leftChar = s[l];
            tree[node].rightChar = s[l];

            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;
            tree[node].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(s, 2 * node, l, mid);
        build(s, 2 * node + 1, mid + 1, r);

        tree[node] = merge(
            tree[2 * node],
            tree[2 * node + 1]
        );
    }

    void update(int node, int l, int r, int idx, char ch) {

        if (l == r) {
            tree[node].leftChar = ch;
            tree[node].rightChar = ch;

            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;
            tree[node].len = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid) {
            update(2 * node, l, mid, idx, ch);
        }
        else {
            update(2 * node + 1, mid + 1, r, idx, ch);
        }

        tree[node] = merge(
            tree[2 * node],
            tree[2 * node + 1]
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n + 5);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int index = queryIndices[i];
            char ch = queryCharacters[i];

            s[index] = ch;

            update(1,0,n - 1,index,ch);
            ans.push_back(tree[1].best);
        }

        return ans;
    }
};