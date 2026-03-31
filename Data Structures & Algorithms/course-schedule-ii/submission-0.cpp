class Solution {
private:
    bool solve(int course,unordered_map<int,vector<int>>& uom,unordered_set<int>& uset,vector<int>& res,unordered_set<int>& already){
        if(uset.find(course)!=uset.end()){
            return false;
        }
        //if no pre-requisites not exist
        
        if(already.find(course)!=already.end()){
            return true;
        }
        uset.insert(course);
        //if course have som pre-requisites
        if(uom.find(course)!=uom.end()){
            for(auto c:uom[course]){
                if(!solve(c,uom,uset,res,already)){
                    return false;
                }
            }
        }
        uset.erase(course);
        already.insert(course);
        res.push_back(course);
        // uom.erase(course);
        return true;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> uom;
        for(auto pre:prerequisites){
            uom[pre[0]].push_back(pre[1]);
        }
        unordered_set<int> uset;
        unordered_set<int> already;
        vector<int> res;
        for(int i=0;i<numCourses;i++){
            if(!solve(i,uom,uset,res,already)){
                return {};
            }
        }
        return res;
    }
};