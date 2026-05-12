class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> ump;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ump[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(!ump.count(key)) return "";
        vector<pair<int, string>> times = ump[key];
        int l = 0, r = times.size()-1;
        string res = "";
        while(l <= r) {
            int mid = l + (r - l)/2;
            if(times[mid].first <= timestamp) {
                res = times[mid].second;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */