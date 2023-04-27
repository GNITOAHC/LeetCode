class Disjoint_set {
public:
    Disjoint_set (const int n) {
        id.resize(n);
        for (int i=0; i<n; ++i) id[i] = i;
    }
    
    bool union_set (const int a, const int b) {
        const int set_a = find_set(a);
        const int set_b = find_set(b);
        if (set_a == set_b) return true;
        id[set_a] = set_b;
        return false;
    }
    
private:
    vector<int> id;
    int find_set(const int a) {
        return (id[a] == a) ? id[a] : find_set(id[a]);
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Disjoint_set set(edges.size() + 1); // from 1 to n, without 0
        
        for (const auto& e : edges) {
            if ( set.union_set(e[0], e[1]) )
                return e;
        }
        throw;
    }
};