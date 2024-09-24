class UnionFind {
private:
    vector<int> father;
public:
    UnionFind(int n) {
        for (int i=0; i<n; ++i)
            father.push_back(i);
    };

    int find(int x) {
        if (father[x] == x) return x;
        int tmp = father[x];
        father[x] = find(tmp);
        return father[x];
    }

    void group(int x, int y) {
        int parent1 = find(x);
        int parent2 = find(y);
        father[parent1] = parent2;
    }

    bool isConnected() {
        int numLeaders = 0;
        for (int i=0; i<father.size(); ++i) {
            if (father[i] == i) numLeaders++;
            if (numLeaders == 2) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n-1) return false;

        UnionFind myUnion(n);

        for (auto &edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];

            myUnion.group(node1, node2);
        }

        return myUnion.isConnected();
    }
};