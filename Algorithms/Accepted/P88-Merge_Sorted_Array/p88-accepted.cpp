class Solution {
public:    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if ((m == 0 || n == 0) && m == 0){
            for (int i=0; i<n; ++i)
                nums1[i] = nums2[i];
        }
        else {
            vector<int> tmp1 (nums1.begin(), nums1.begin()+m);
            int count = 0, t1bf = 0, n2bf = 0;
            while (t1bf < m && n2bf < n){
                if (tmp1[t1bf] < nums2[n2bf]){
                    nums1[count++] = tmp1[t1bf++];
                }
                else {
                    nums1[count++] = nums2[n2bf++];
                }
            }
            if (t1bf < m){
                while (t1bf < m)
                    nums1[count++] = tmp1[t1bf++];
            }
            else if (n2bf < n){
                while (n2bf < n)
                    nums1[count++] = nums2[n2bf++];
            }
        }
    }
};