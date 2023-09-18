class Solution {
private:
    class MaxQueue {
        private:
            priority_queue<int> pq;
            unordered_map<int, int> window;
            int k = 0;

        public:
            MaxQueue(int _k) : k{_k} {}

            void insert(int num) {
                pq.push(num);
                window[num] += 1;
            }

            int getMax() {
                if (pq.empty()) {
                    cout << "Emtpy queue\n";
                    return -1;
                }

                int top = pq.top();
                while (window.find(top) == window.end() or window[top] == 0) {
                    pq.pop();
                    top = pq.top();
                }
                return pq.top();
            }

            void pop(int num) {
                window[num] -= 1;
            }

            ~MaxQueue() {}
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        MaxQueue q(k);
        for (int i=0; i<nums.size(); ++i) {
            q.insert(nums[i]);
            
            if (i >= k-1) {
                int m = q.getMax();
                ans.push_back(q.getMax());
                q.pop(nums[i-k+1]);
            }
        }

        return ans;
    }
};