class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;

        for (int num : asteroids) {
            if (num < 0 and !ans.empty() and ans.back() > 0) {

                while (!ans.empty() and ans.back() > 0 and ans.back() < abs(num)) {
                    ans.pop_back();
                }

                if (ans.empty() || ans.back() < 0) ans.push_back(num);
                if (!ans.empty() and ans.back() == abs(num)) ans.pop_back();
            }
            else ans.push_back(num);
        }

        return ans;
    }
};