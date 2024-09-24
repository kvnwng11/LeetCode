class UnionFind {
private:
    unordered_map<int, int> father;
    int n;

public:
    UnionFind(int _n) : n{_n} {}

    void add(int x, int y) {
        int val = x * n + y;
        if (father.find(val) == father.end())
            father[val] = val;
    }

    int find(int val) {
        if (father[val] == val) return val;
        int tmp = father[val];
        father[val] = find(tmp);
        return father[val];
    }

    void group(int x1, int y1, int x2, int y2) {
        int val1 = x1 * n + y1;
        int val2 = x2 * n + y2;

        if (father.find(val1) == father.end())
            father[val1] = val1;
        if (father.find(val2) == father.end())
            father[val2] = val2;

        int father1 = find(father[val1]);
        int father2 = find(father[val2]);
        father[father1] = father2;
    }

    int getCount() {
        int ans = 0;

        for (auto &[node, parent] : father) {
            if (node == parent)
                ans++;
        }

        return ans;
    }
};


class Solution {
private:
    int add[4][2] = {
        {0, 1},
        {1, 0},
        {-1, 0},
        {0, -1}
    };

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        UnionFind myUnion(n);
        for (int i=0; i<m; ++i) {
            for (int j=0; j<n; ++j) {
                if (grid[i][j] == '0') continue;

                myUnion.add(i, j);

                for (auto dir : add) {
                    int newRow = i + dir[0];
                    int newCol = j + dir[1];

                    if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || grid[newRow][newCol] == '0')
                        continue;
                    
                    myUnion.group(i, j, newRow, newCol);
                }
            }
        }

        return myUnion.getCount();
    }
};