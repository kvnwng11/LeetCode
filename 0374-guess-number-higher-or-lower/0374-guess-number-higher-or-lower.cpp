/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 0;
        int right = n;
        int mid = left + (right - left) / 2;

        while (left <= right) {
            mid = left + (right - left) / 2;
            int result = guess(mid);

            if (result == -1)
                right = mid-1;
            else if (result == 1)
                left = mid+1;
            else
                return mid;
        }

        return -1;
    }
};