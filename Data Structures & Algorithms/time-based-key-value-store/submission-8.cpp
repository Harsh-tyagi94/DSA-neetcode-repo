class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> ump;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ump[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int, string>> vec = ump[key];
        int l = 0, r = vec.size()-1;
        string res = "";
        while(l<=r) {
            int mid = l + (r-l)/2;
            int time = vec[mid].first;
            if(time == timestamp) {
                return vec[mid].second;
            } else if(time < timestamp) {
                res = vec[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};
