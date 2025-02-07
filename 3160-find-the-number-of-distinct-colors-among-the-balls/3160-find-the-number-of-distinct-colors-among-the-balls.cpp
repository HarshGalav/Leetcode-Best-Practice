class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        set<int>s1;
        set<int>s2;
        vector<int>v;
        for(auto i:queries){
            s1.insert(i[0]);
            s2.insert(i[1]);
            v.push_back(min(s1.size(),s2.size()));
        }
        return v;
    }
};