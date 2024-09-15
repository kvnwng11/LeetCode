class Solution {
private:
    class UnionFind {
        private:
            unordered_map<int, int> leader;
        public:
            UnionFind() = default;

            int find(int x) {
                if (x == leader[x]) return x;
                int parent = find(leader[x]);
                leader[x] = parent;
                return parent;
            }

            void add(int x) {
                leader[x] = x;
            }

            void add(int x, int y) {
                if (leader.find(x) == leader.end()) leader[x] = x;
                if (leader.find(y) == leader.end()) leader[y] = y;
                leader[find(x)] = find(y);
            }

            int numGroups() const {
                int ans = 0;
                for (auto &[x, parent] : leader) {
                    if (x == parent) ans++;
                }
                return ans;
            }

            ~UnionFind() = default;
    };

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        UnionFind myUnion;
        int n = isConnected.size();
        int m = isConnected.size();

        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (isConnected[i][j]) {
                    myUnion.add(i, j);
                }
            }
        }

        return myUnion.numGroups();
    }
};