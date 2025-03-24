class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        
        int n = meetings.size();
        vector<vector<int>> temp;
        
        for (int i = 0; i < n; i++) {
            if (!temp.empty() && temp.back()[1] >= meetings[i][0]) {
                temp.back()[1] = max(temp.back()[1], meetings[i][1]);
            } else {
                temp.push_back(meetings[i]);
            }
        }
        
       int x=0;
       for(auto i: temp){
        x+=i[1]-i[0]+1;
       }
       
        return days-x;
    }
};
