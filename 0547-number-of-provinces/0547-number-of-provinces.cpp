class Solution {
private:
    class UnionFind {
    private:
        unordered_map<int, int> father;

    public:
        UnionFind() {}

        void add(int x) {
            if (father.find(x) == father.end())
                father[x] = x;
        }

        int find(int x) {
            if (x == father[x])
                return x; 
            int temp = father[x];
            father[x] = find(temp);
            return father[x];
        }

        void unionFind(int x, int y) {
            x = find(x);
            y = find(y);
            father[x] = y; 
        }

        int getAns() {
            int ans = 0;
            for (auto p : father) {
                if (p.second == p.first)
                    ans++;
            }
            return ans;
        }
    };

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind u;
        for (int i=0; i<isConnected.size(); ++i) u.add(i);
        for (int i=0; i<isConnected.size(); ++i) {
            for (int j=0; j<isConnected.size(); ++j) {
                if (isConnected[i][j]) {
                    u.unionFind(i, j);
                }
            }
        }
        return u.getAns();
    }
};