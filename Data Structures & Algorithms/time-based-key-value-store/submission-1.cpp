class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> ump;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        ump[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto& res = ump[key];
        int l=0,r=res.size()-1;

        string s = "";
        while(l<=r) {
            int mid = l+(r-l)/2;
            if(res[mid].first <= timestamp) {
                s = res[mid].second;
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return s;
    }
};
