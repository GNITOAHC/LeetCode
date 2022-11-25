#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define db(a) // cout << "debug"  << " " << a << endl;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lens = height.size() - 1;
        int left = 0, right = lens, bottom = lens;
        int ans = (height[left] < height[right]) ? height[left] * lens : height[right] * lens;
        int tmp;
        while (left < right) {
            if (height[left] < height[right]) {
                tmp = height[left];
                ++left;
                while (height[left] < tmp) {
                    db('a')
                    ++left;
                    --lens;
                    if (left > right)
                        break;
                }
                --lens;
                ans = max (ans, min(height[left], height[right]) * lens);
            }
            else if (height[left] > height[right]) {
                tmp = height[right];
                --right;
                while (height[right] < tmp) {
                    db('b');
                    --right;
                    --lens;
                    if (left > right)
                        break;
                }
                --lens;
                ans = max (ans, min(height[left], height[right]) * lens);
            }
            else if (height[left] == height[right]) {
                db('c');
                ++left;
                --right;
                if (left > right) break;
                lens -= 2;
                ans = max (ans, min(height[left], height[right]) * lens);
            }
        }
        
        return ans;
    }
};