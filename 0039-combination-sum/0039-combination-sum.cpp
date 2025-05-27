class Solution {
public:
void f(int ind, int target,vector<vector<int>>&ans, vector<int>&temp,vector<int>& candidates){
    if(ind == candidates.size()){
        if(target==0){
            ans.push_back(temp);
        }
        return;
    }
    if(candidates[ind]<=target){
        temp.push_back(candidates[ind]);
        f(ind,target-candidates[ind],ans,temp,candidates);
        temp.pop_back();
    }
    f(ind+1,target,ans,temp,candidates);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(0,target,ans,temp,candidates);
        return ans;
    }
};