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
private:

    int manhattanDistance(vector<vector<int>>& points, int i, int j) {
        int x1 = points[i][0], y1 = points[i][1];
        int x2 = points[j][0], y2 = points[j][1];
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;
        int edgesUsed = 0;

        vector<bool> inMST(n);
        vector<int> minDist(n, INT_MAX);
        minDist[0] = 0;

        while (edgesUsed < n) {
            int currNode = -1;
            int edgeWeight = INT_MAX;

            for (int node=0; node<n; ++node) {
                if (!inMST[node] && minDist[node] < edgeWeight) {
                    currNode = node;
                    edgeWeight = minDist[node];
                }
            }

            ans += edgeWeight;
            edgesUsed++;
            inMST[currNode] = true;

            for (int nextNode=0; nextNode<n; ++nextNode) {
                int weight = manhattanDistance(points, currNode, nextNode);

                if (!inMST[nextNode])
                    minDist[nextNode] = min(minDist[nextNode], weight);
            }
        }

        return ans;
    }
};