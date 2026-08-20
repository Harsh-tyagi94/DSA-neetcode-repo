class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> Stack;
        for(string op:operations) {
            if(op == "C") Stack.pop_back();
            else if(op == "D") {
                Stack.push_back(2*Stack.back());
            } else if(op == "+") {
                int t1 = Stack.back(); Stack.pop_back();
                int sum = t1 + Stack.back();
                Stack.push_back(t1);
                Stack.push_back(sum);
            } else Stack.push_back(stoi(op));
        }
        int sum = 0;
        for(int st:Stack) sum += st;
        return sum;
    }
};