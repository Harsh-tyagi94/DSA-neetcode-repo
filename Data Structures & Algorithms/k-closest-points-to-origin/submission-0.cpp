class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> vec;
        priority_queue<pair<double,vector<int>>,vector<pair<double,vector<int>>>,greater<pair<double,vector<int>>>> minheap;
        for(auto p:points){
            double dis=sqrt((p[0])*(p[0])+(p[1])*(p[1]));
            minheap.push({dis,p});
        }
        for(int i=0;i<k;i++){
            vec.push_back(minheap.top().second);
            minheap.pop();
        }
        return vec;
    }
};