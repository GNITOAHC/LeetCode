class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int mask1 = 0x80; // 1000 0000
        int mask2 = 0x20; // 0010 0000
        int mask3 = 0x10; // 0001 0000
        int mask4 = 0x08; // 0000 1000
        int corner_mask = 0xC0; // 1100 0000
        
        const int lens = data.size();
        for (int i=0; i<lens; ++i) {
            if ( (mask1 & data[i]) == 0) {
                // Means data[i] is 0xxxxxxx
                // Checking first bit
                continue;
            }
            int byte = 0;
            if ( (corner_mask & data[i]) == mask1) {
                // Means data[i] is independent 10xxxxxx
                // corner_mask & data[i] could be 10x or 11x
                // Checking second bit
                return false;
            } else if ( (mask2 & data[i]) == 0) {
                // Means data[i] is 110xxxxx
                // Checking third bit
                byte = 2;
            } else if ( (mask3 & data[i]) == 0) {
                // Means data[i] is 1110xxxx
                // Checking forth bit
                byte = 3;
            } else if ( (mask4 & data[i]) == 0) {
                // Means data[i] is 11110xxx
                // Checking fifth bit
                byte = 4;
            } else {
                return false;
            }
            
            for (int n=1; n<byte; ++n) {
                i++;
                if (i >= lens || (corner_mask & data[i]) != mask1) {
                    // i out of lens or not belongs to 10xxxxxx
                    return false;
                }
            }
        }
        
        return true;
    }
};