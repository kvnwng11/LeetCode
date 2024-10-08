class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> weights;
        for (int stone : stones)
            weights.push(stone);

        while (weights.size() > 1) {
            int x = weights.top(); weights.pop();
            int y = weights.top(); weights.pop();

            if (x > y)
                weights.push(x - y); 
            else if (x < y)
                weights.push(y - x);
        }

        return weights.empty()? 0 : weights.top();
    }
};