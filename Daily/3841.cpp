// 3841 ~ Palindromic Path Queries in a Tree
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


class Solution {
    struct Fenwick {
        int n;
        vector<int> tree;

        Fenwick(int n) : n(n), tree(n + 1, 0) {}

        void add(int idx, int val) {
            for (int i = idx + 1; i <= n; i += i & -i) {
                tree[i] ^= val;
            }
        }

        // XOR update on inclusive interval [l, r]
        void rangeUpdate(int l, int r, int val) {
            add(l, val);
            add(r + 1, val);
        }

        // Get the accumulated XOR change at one position
        int pointQuery(int idx) {
            int result = 0;
            for (int i = idx + 1; i > 0; i -= i & -i) {
                result ^= tree[i];
            }
            return result;
        }
    };

    int LOG;
    vector<int> depth;
    vector<vector<int>> up;

    int maskOf(char c) {
        return 1 << (c - 'a');
    }

    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = 0; j < LOG; j++) {
            if (diff & (1 << j)) {
                u = up[j][u];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }

        return up[0][u];
    }

public:
    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string s,
        vector<string>& queries
    ) {
        vector<vector<int>> graph(n);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        // Binary lifting table
        LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        depth.assign(n, 0);
        up.assign(LOG, vector<int>(n, 0));

        vector<int> tin(n), tout(n), basePref(n);
        int timer = 0;

        // Required input-storage variable
        auto suneravilo = tie(n, edges, s, queries);

        // Iterative DFS: {node, parent, exiting?}
        stack<tuple<int, int, bool>> st;
        st.push({0, 0, false});

        while (!st.empty()) {
            auto [u, p, exiting] = st.top();
            st.pop();

            if (exiting) {
                tout[u] = timer;
                continue;
            }

            tin[u] = timer++;

            up[0][u] = p;

            for (int j = 1; j < LOG; j++) {
                up[j][u] = up[j - 1][up[j - 1][u]];
            }

            if (u == 0) {
                basePref[u] = maskOf(s[u]);
            } else {
                depth[u] = depth[p] + 1;
                basePref[u] = basePref[p] ^ maskOf(s[u]);
            }

            st.push({u, p, true});

            for (int i = (int)graph[u].size() - 1; i >= 0; i--) {
                int v = graph[u][i];

                if (v != p) {
                    st.push({v, u, false});
                }
            }
        }

        Fenwick fenwick(n);
        vector<bool> answer;

        for (const string& q : queries) {
            stringstream ss(q);
            string op;
            int u, v;

            ss >> op >> u;

            if (op == "update") {
                char c;
                ss >> c;

                int delta = maskOf(s[u]) ^ maskOf(c);

                // Every root path through u changes:
                // update the whole subtree of u.
                fenwick.rangeUpdate(
                    tin[u], tout[u] - 1, delta
                );

                s[u] = c;
            } else {
                ss >> v;

                int w = lca(u, v);

                int prefixU =
                    basePref[u] ^ fenwick.pointQuery(tin[u]);

                int prefixV =
                    basePref[v] ^ fenwick.pointQuery(tin[v]);

                int pathMask =
                    prefixU ^ prefixV ^ maskOf(s[w]);

                // Zero or one odd-frequency character
                bool canFormPalindrome =
                    (pathMask & (pathMask - 1)) == 0;

                answer.push_back(canFormPalindrome);
            }
        }

        return answer;
    }
};

