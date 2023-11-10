class Solution {
private:
    vector<int> orig;
    vector<int> ans;

    int randRange(int min, int max) {
        return rand() % (max - min) + min;
    }

public:
    Solution(vector<int>& _nums) {
        orig = vector<int>(_nums);
        ans = vector<int>(_nums);
    }
    
    vector<int> reset() {
        ans = vector<int>(orig);
        return orig;
    }
    
    vector<int> shuffle() {
        for (int i=0; i<orig.size(); ++i) {
            int j = randRange(i, orig.size());

            swap(ans[i], ans[j]);
        }

        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */