class Solution {
public:
    void f(int ind, set<vector<int>>&s,vector<int>temp,vector<int>& nums,int n){
        if(ind==n){
            s.insert(temp);
            return;
        }
        f(ind+1,s,temp,nums,n);
        temp.push_back(nums[ind]);
        f(ind+1,s,temp,nums,n);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        set<vector<int>>s;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        f(0,s,temp,nums,n);
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};