class UnionFind {
private:
    vector<int> father;
public:
    UnionFind(int n) {
        for (int i=0; i<=n; ++i) father.push_back(i);
    }

    int find(int x) {
        if (father[x] == x) return x;
        int tmp = father[x];
        father[x] = find(tmp);
        return father[x];
    }

    int join(int x, int y) {
        int f1 = find(x);
        int f2 = find(y);
        if (f1 == f2) return -1;
        father[f1] = f2;
        return 1;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        UnionFind graph(n);
        for (auto &edge : edges) {
            if (graph.join(edge[0], edge[1]) == -1) return edge;
        }
        return {};
    }
};