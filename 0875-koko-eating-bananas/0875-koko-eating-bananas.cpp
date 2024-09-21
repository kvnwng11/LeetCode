class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = 0;
        for (int pile : piles)
            right = max(right, pile);

        while (left <= right) {
            int k = left + (right - left) / 2;
            int numHoursLeft = h;

            for (int pile : piles) numHoursLeft -= ceil((double) pile / k);
            
            if (numHoursLeft >= 0) right = k-1;
            else left = k+1;
        }

        return left;
    }
};