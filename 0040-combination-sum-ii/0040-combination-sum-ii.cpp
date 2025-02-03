class Solution {
public:
void f(int ind,int target,vector<vector<int>>& ans,vector<int>&temp, vector<int>&candidates){
    if(target ==0){
        ans.push_back(temp);
        return;
    }
    for(int i=ind;i<candidates.size();i++){
        if(i>ind && candidates[i]==candidates[i-1]) continue;
        if(candidates[i]>target)break;
        temp.push_back(candidates[i]);
        f(i+1,target-candidates[i],ans,temp,candidates);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        sort(candidates.begin(),candidates.end());
        f(0,target,ans,temp,candidates);
        return ans;
    }
};