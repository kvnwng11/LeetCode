class Solution {
private:
    vector<vector<int>> quickSelect(vector<vector<int>> &points, int k) {
        int left = 0, right = points.size() - 1;
        int pivotIndex = points.size();

        while (pivotIndex != k) {
            pivotIndex = partition(points, left, right);

            if (pivotIndex < k)
                left = pivotIndex;
            else
                right = pivotIndex - 1;
        }

        return vector<vector<int>>(points.begin(), points.begin() + k);
    }

    int partition(vector<vector<int>>& points, int left, int right) {
        vector<int> &pivot = choosePivot(points, left, right);
        int pivotDist = squaredDistance(pivot);
        while (left < right) {
            if (squaredDistance(points[left]) >= pivotDist) {
                points[left].swap(points[right]);
                right--;
            }
            else
                left++;
        }

        if (squaredDistance(points[left]) < pivotDist)
            left++;
        return left;
    }

    vector<int>& choosePivot(vector<vector<int>>& points, int left, int right) {
        return points[left + (right - left) / 2];
    }

    int squaredDistance(vector<int>& point) {
        return point[0] * point[0] + point[1] * point[1];
    }

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return quickSelect(points, k);
    }
};