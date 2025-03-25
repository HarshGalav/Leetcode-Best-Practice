class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>temp;
        temp.push_back(intervals[0]);
        for(int i=1;i<n;i++){
            if(intervals[i][0]< temp.back()[1]){
                temp.back()[1]=max(temp.back()[1],intervals[i][1]);
            }
            else{
                temp.push_back(intervals[i]);
            }
        }
        return temp;
    }
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>>hor;
        vector<vector<int>>vert;
        for(auto i:rectangles){
            int x1=i[0];
            int y1=i[1];
            int x2=i[2];
            int y2=i[3];
            hor.push_back({x1,x2});
            vert.push_back({y1,y2});
        }
        vector<vector<int>>ans1=merge(hor);
        vector<vector<int>>ans2=merge(vert);

        return ans1.size()>=3 || ans2.size()>=3;

    }
};