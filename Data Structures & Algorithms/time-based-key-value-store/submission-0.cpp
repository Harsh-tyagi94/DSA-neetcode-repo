class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> ump;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ump[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(!ump.count(key)) {
            return "";
        }

        string res = "";
        int timestore = 0;
        for(auto [t,val]:ump[key]) {
            if(t <= timestamp && timestore < t) {
                timestore = t;
                res = val;
            }
        }
        return res;
    }
};
