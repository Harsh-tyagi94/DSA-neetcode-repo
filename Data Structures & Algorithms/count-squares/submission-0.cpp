class CountSquares {
public:
    vector<vector<int>> points;

    long getkey(int x, int y) {
        return (static_cast<long>(x) << 32) | static_cast<long>(y);
    }

    unordered_map<long, int> unique_map;
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        long key = getkey(point[0], point[1]);
        points.push_back(point);
        unique_map[key] += 1;
    }
    
    int count(vector<int> point) {
        int res = 0;
        for(int i=0;i<points.size();i++) {
            int x = points[i][0], y = points[i][1];
            int px = point[0], py = point[1];

            if(abs(x-px) != abs(y-py) || x == px || y == py) continue;

            res += unique_map[getkey(x,py)] * unique_map[getkey(px,y)];
        }
        return res;
    }
};
