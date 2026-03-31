class Solution {
private:
    bool solve(int course,unordered_map<int,vector<int>>& uom,unordered_set<int>& uset){
        if(uset.find(course)!=uset.end()){
            return false;
        }
        //if no pre-requisites not exist
        if(uom.find(course)==uom.end()){
            return true;
        }
        uset.insert(course);
        //if course have som pre-requisites
        if(uom.find(course)!=uom.end()){
            for(auto c:uom[course]){
                if(!solve(c,uom,uset)){
                    return false;
                }
            }
        }
        uset.erase(course);
        uom.erase(course);
        return true;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> uom;
        for(auto pre:prerequisites){
            uom[pre[0]].push_back(pre[1]);
        }
        unordered_set<int> uset;
        for(int i=0;i<numCourses;i++){
            if(!solve(i,uom,uset)){
                return false;
            }
        }
        return true;
    }
};