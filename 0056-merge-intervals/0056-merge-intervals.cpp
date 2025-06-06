class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>temp;
        temp.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]<= temp.back()[1]){
                temp.back()[1]=max(temp.back()[1],intervals[i][1]);
            }
            else{
                temp.push_back(intervals[i]);
            }
        }
        return temp;
    }
};