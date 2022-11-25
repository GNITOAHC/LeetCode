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
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        // Push_back index
        for (int i=0; i<edges.size(); ++i) edges[i].push_back(i);
        
        // Sort by weight edges[i][2]
        sort (edges.begin(), edges.end(), [&](const auto& e1, const auto& e2) {
            return (e1[2] < e2[2]);
        });
        
        // Find cost of MST, in = include, ex = exclude
        auto MST = [&](int in = -1, int ex = -1) -> int {
            Disjoint_set set(n); // Total n nodes
            int cost = 0, edge_count = 0;
            
            // If force include exist
            if (in > 0) {
                cost += edges[in][2]; // cost += weight of forced include edge
                set.union_set(edges[in][0], edges[in][1]); // Union two nodes beside forced edge
                ++edge_count;
            }
            
            for (int i=0; i<edges.size(); ++i) {
                if (i == ex) continue; // Continue if appear forced exclude
                // If unioned before
                if (set.union_set(edges[i][0], edges[i][1])) continue;
                cost += edges[i][2];
                ++edge_count;
            }
            
            // A tree ? cost : INT_MAX
            return (edge_count == n-1) ? cost : INT_MAX;
        };
        
        const int min_cost = MST(); // Min cost of original MST
        vector<int> criticals;
        vector<int> pseudo_criticals;
        for (int i=0; i<edges.size(); ++i) {
            // Can't form tree or increase min_cost without this edge
            if (MST(-1, i) > min_cost) {
                criticals.push_back(edges[i][3]);
            } else if (MST(i, -1) == min_cost) {
                // Including this edge remain min_cost
                pseudo_criticals.push_back(edges[i][3]);
            }
        }
        
        return {criticals, pseudo_criticals};
    }
};