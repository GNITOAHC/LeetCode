typedef struct Node {
    int parent;
    int child;
    Node (const int p, const int c) : parent(p), child(c) {}
} Node;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int e[n+1][n+1];
        vector<vector<int> > node;
        
        node.resize(n+1);
        for (int i=0; i<n+1; ++i) {
            for (int j=0; j<n+1; ++j) {
                e[i][j] = (i == j) ? 0 : INT_MAX;
            }
        }
        
        for (int i=0; i<times.size(); ++i) {
            e[times[i][0]][times[i][1]] = times[i][2];
            node[times[i][0]].push_back(times[i][1]);
        }
        
        int dis[n+1];
        int pre[n+1];
        for (int i=0; i<n+1; ++i) {
            dis[i] = INT_MAX;
            pre[i] = INT_MAX;
        }
        dis[k] = 0;
        pre[k] = 0;
        
        queue<int> q;
        q.push(k);
        while (!q.empty()) {
            const int cur = q.front();
            q.pop();
            for (int i=0; i<node[cur].size(); ++i) {
                const int cur_child = node[cur][i];
                dis[cur_child] = (dis[cur_child] < dis[cur] + e[cur][cur_child]) ? 
                    dis[cur_child] : dis[cur] + e[cur][cur_child];
                if (dis[cur_child] == pre[cur_child]) continue;
                else {
                    pre[cur_child] = dis[cur_child];
                    q.push(cur_child);
                }
            }
        }
        
        int ans = INT_MIN;
        for (int i=1; i<n+1; ++i) {
            ans = (ans > dis[i]) ? ans : dis[i];
        }
        
        if (ans == INT_MAX) return -1;
        return ans;
    }
};