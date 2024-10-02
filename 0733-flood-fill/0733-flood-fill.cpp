class Solution {
private:
    bool inBounds(vector<vector<int>>& image, int r, int c) {
        return r >= 0 && r < image.size() && c >= 0 && c < image[0].size();
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int DIRECTIONS[4][2] = {
            {0, 1},
            {0, -1},
            {1, 0},
            {-1, 0}
        };

        int originalColor = image[sr][sc];
        if (originalColor == color) return image;

        stack<pair<int, int>> s;
        s.push({sr, sc});
        while (!s.empty()) {
            auto [row, col] = s.top();
            s.pop();

            image[row][col] = color;

            for (auto dir : DIRECTIONS) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];

                if (inBounds(image, newRow, newCol) && image[newRow][newCol] == originalColor) {
                    s.push({newRow, newCol});
                }
            }
        }

        return image;
    }
};