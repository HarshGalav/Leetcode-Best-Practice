class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>>v;
        int n=nums.size();
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.rbegin(),v.rend());
        vector<int>idx;
        for(int i=0;i<k;i++){
            idx.push_back(v[i].second);
        }
        sort(idx.begin(),idx.end());
        vector<int>ans;
        for(auto i:idx){
            ans.push_back(nums[i]);
        }
        return ans;
    }
};