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
        int down = 1, up = n;
        int mid = down + ((up - down) / 2);
        while (down < up) {
            switch (guess(mid)) {
                case 0: 
                return mid;
                break;

                case 1: // num is higher
                down = mid + 1;
                break;

                case -1: // num is lower
                up = mid - 1;
                break;

                default:
                break;
            }

            mid = down + ((up - down) / 2);
            if (guess(up) == 0) return up;
            if (guess(down) == 0) return down;
        }

        return mid;
    }
};