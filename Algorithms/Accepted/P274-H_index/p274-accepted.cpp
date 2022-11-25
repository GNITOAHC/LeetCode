#define debug cout << "debug" << endl;
//counting sort
static inline int Max (int a, int b) {
    return (a > b ? a : b);
}

class Solution {
public:
    void print (vector<int>& a) {
        for (int i=0; i<a.size(); ++i)
            cout << a[i] << " ";
        cout << endl;
        return;
    }
    
    void countingSort (vector<int>& list, int n) {
        int max = INT_MIN;
        for (int i=0; i<n; ++i) max = Max (max, list[i]); // find range
        int RANGE = max + 1; // including 0

        vector<int> counters (RANGE, 0);
        
        for (int i=0; i<n; ++i)
            ++counters[list[i]];
        int k=0;
        for (int i=0; i<RANGE; ++i)
            for (int j=0; j<counters[i]; ++j)
                list[k++] = i;
        return;
    }
    
    int hIndex(vector<int>& citations) {
        countingSort (citations, citations.size());
        print(citations);
        int count = 0, ans = 0;
        
        for (int i=citations.size()-1; i>=0; --i) {
            ++count;
            if (count <= citations[i])
                ans = count > ans ? count : ans;
        }
        
        return ans;
    }
};
