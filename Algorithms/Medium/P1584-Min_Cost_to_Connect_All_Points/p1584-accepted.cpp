typedef struct Point {
    int point1;
    int point2;
    int dis;
    Point () : point1(-1), point2(-1), dis(-1) {}
    Point(const int a, const int b, const int c) {
        point1 = a;
        point2 = b;
        dis = c;
    }
} Point;

bool sort_function (Point a, Point b) {
    return (a.dis < b.dis);
};

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
private: 
    int cal_dis (const int x1, const int y1, const int x2, const int y2) {
        return abs(x1-x2) + abs(y1-y2);
    }
    
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        const int lens = points.size();
        vector<Point> point;
        for (int i=0; i<lens; ++i) {
            for (int j=0; j<lens; ++j) {
                if (i == j) continue;
                else {
                    const int tmp = cal_dis(points[i][0], points[i][1],
                                            points[j][0], points[j][1]);
                    point.push_back(Point(i, j, tmp));
                }
            }
        }
        
        sort (point.begin(), point.end(), sort_function);
        
        Disjoint_set set(lens+1);
        int edges_count = 0;
        int dis_count = 0;
                
        int cur_count = 0;
        while (edges_count != lens-1) {
            if (set.union_set(point[cur_count].point1, point[cur_count].point2)) {
                // cout << "test" << endl;
                ++cur_count;
                continue;
            }
            else {
                ++edges_count;
                // cout << "cur_count.dis = " << point[cur_count].dis;
                dis_count += point[cur_count].dis;
                ++cur_count;
            }
        }
        
        // for (int i=0; i<point.size(); ++i) {
        //     cout << point[i].point1 << " " << point[i].point2 << " " << point[i].dis << endl;
        // }
        
        return dis_count;
    }
};