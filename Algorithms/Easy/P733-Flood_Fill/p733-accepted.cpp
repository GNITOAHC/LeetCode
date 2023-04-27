#define p push
#define pb push_back
#define mp make_pair
#define db cout << "debug" << endl;
#define inDomainM(a) (a >= 0 && a < M)
#define inDomainN(a) (a >= 0 && a < N)
#define r0 r+dsr[0]
#define r1 r+dsr[1]
#define r2 r+dsr[2]
#define r3 r+dsr[3]
#define c0 c+dsc[0]
#define c1 c+dsc[1]
#define c2 c+dsc[2]
#define c3 c+dsc[3]

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        const int oldColor = image[sr][sc];
        int M = image.size(), N = image[0].size();
        
        vector<vector<bool> > check;
        for (int i=0; i<M; ++i) {
            check.pb(vector<bool>());
            for (int j=0; j<N; ++j)
                check[i].pb(true);
        }
        
        // start bfs
        queue<pair<int, int> > q;
        q.p( mp(sr, sc) );
        image[sr][sc] = newColor;
        
        int dsr[] = {0, 1, 0, -1}, dsc[] = {1, 0, -1, 0}, tmp = 0, count = 1; // 4 direction
        
        while (!q.empty()) {
            tmp = 0;
            for (int i=0; i<count; ++i) {
                int r = q.front().first, c = q.front().second;
                q.pop();
                
                // cout << r << " " << c << endl;
                
                if (inDomainM(r0) && inDomainN(c0) && image[r0][c0] == oldColor && check[r0][c0]) {
                    ++tmp;
                    image[r0][c0] = newColor;
                    q.p( mp(r0, c0) );
                    check[r0][c0] = false;
                }
                if (inDomainM(r1) && inDomainN(c1) && image[r1][c1] == oldColor && check[r1][c1]) {
                    ++tmp;
                    image[r1][c1] = newColor;
                    q.p( mp(r1, c1) );
                    check[r1][c1] = false;
                }
                if (inDomainM(r2) && inDomainN(c2) && image[r2][c2] == oldColor && check[r2][c2]) {
                    ++tmp;
                    image[r2][c2] = newColor;
                    q.p( mp(r2, c2) );
                    check[r2][c2] = false;
                }
                if (inDomainM(r3) && inDomainN(c3) && image[r3][c3] == oldColor && check[r3][c3]) {
                    ++tmp;
                    image[r3][c3] = newColor;
                    q.p( mp(r3, c3) );
                    check[r3][c3] = false;
                }
            }
            count = tmp;
        }
        
        return image;
    }
};