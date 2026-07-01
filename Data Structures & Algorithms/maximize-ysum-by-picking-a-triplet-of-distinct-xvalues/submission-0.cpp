class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        vector<pair<int,int>> best(3, {INT_MIN, INT_MIN});
        for (int i = 0; i < x.size(); i++) {
            int xi = x[i], yi = y[i];
            bool updated = false;
            for (int j = 0; j < 3; j++) {
                if (best[j].first == xi) {
                    if (yi > best[j].second) {
                        best[j].second = yi;
                        sort(best.begin(), best.end(),
                             [](auto &a, auto &b){ return a.second > b.second; });
                    }
                    updated = true;
                    break;
                }
            }
            if (updated) continue;
            if (yi > best[0].second) {
                best.insert(best.begin(), {xi, yi});
                best.pop_back();
            } else if (yi > best[1].second) {
                best.insert(best.begin()+1, {xi, yi});
                best.pop_back();
            } else if (yi > best[2].second) {
                best[2] = {xi, yi};
            }
        }
        if (best[2].second == INT_MIN) return -1;
        return best[0].second + best[1].second + best[2].second;
    }
};