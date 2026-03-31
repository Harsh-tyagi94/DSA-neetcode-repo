class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();

        vector<int> Indegree(numCourses, 0);
        unordered_map<int, vector<int>> umap;
        for(int i=0;i<n;i++) {
            Indegree[prerequisites[i][0]] += 1;
            umap[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }

        queue<int> avail_Courses_Queue;
        for(int i=0;i<numCourses;i++) if(Indegree[i] == 0) avail_Courses_Queue.push(i);

        vector<int> CoursesOrder;
        while(!avail_Courses_Queue.empty() && numCourses) {
            int node = avail_Courses_Queue.front();
            avail_Courses_Queue.pop();

            for(int connected_nodes:umap[node]) {
                Indegree[connected_nodes] -= 1;
                if(!Indegree[connected_nodes]) avail_Courses_Queue.push(connected_nodes);
            }

            numCourses -= 1;
            CoursesOrder.push_back(node);
        }

        if(numCourses) return {};

        return CoursesOrder;
    }
};


/*
numCourses = 4;
prerequisites = [[1,0], [2,0], [2,1], [3,1], [3,2]] -- nodes

Indegree = [0, 0, 0, 0] -- numbers
umap = {
    0: [1, 2], -- completed
    1: [2, 3], -- completed
    2: [3] -- completed
} -- nodes

avail_Courses_Queue = [] -- nodes
node = 3
*/