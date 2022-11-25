#define pb push_back
#define debug(x) cout << "DEBUG " << x << endl;

class Solution {
private:
    struct Node {
    int x, y;
    bool start;
    Node(const int _x, const int _y, const bool _start)
        : x(_x), y(_y), start(_start) {}
    };

public: 
    static bool info_cmp (Node& front, Node& back) {
        if (front.x != back.x) return front.x < back.x;
        else {
            if (front.start && back.start) // If both is start, higher comes first.
                return front.y > back.y;

            if (!front.start && !back.start) // If both end, lower comes first.
                return front.y < back.y;

            // If one start one end, start goes first.
            return front.start ? true : false;
        }
    };
    
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Node> info;
        for (auto building : buildings) {
            info.pb(Node(building[0], building[2], true));
            info.pb(Node(building[1], building[2], false));
        }
        sort(info.begin(), info.end(), info_cmp);
        
        // for (auto in : info) {
        //     cout << in.x << " " << in.y << " ";
        //     if (in.start) cout << "start\n";
        //     else cout << "end\n";
        // }

        multiset<int> max_ht_queue;
        int prev_max = 0, cur_max = 0;
        const int node_count = info.size();
        vector<vector<int> > ans;
        max_ht_queue.insert(0);

        for (int i = 0; i < node_count; ++i) {
            if (info[i].start) {
                // debug('a');
                max_ht_queue.insert(info[i].y);
                // If cur_max changes, push into final ans
                if (cur_max < info[i].y) {
                    cur_max = info[i].y;
                    ans.pb(vector<int>{info[i].x, cur_max});
                }
            } else {
                // debug('b');
                // Remove the ended height
                auto iter = max_ht_queue.find(info[i].y);
                max_ht_queue.erase(iter);
                prev_max = cur_max;
                cur_max = *(max_ht_queue.rbegin()); // Get biggest
                if (cur_max != prev_max) {
                    ans.pb(vector<int>{info[i].x, cur_max});
                }
            }
        }
        return ans;
    };
};


